#include "DataLogger.h"
#include "Cpu.h"
#include "Init_Config.h"
#include "PDD_Includes.h"
#include "Events.h"
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "FAT1.h"
#include "SD1.h"
#include "SS1.h"
#include "CD1.h"
#include "TmDt1.h"
#include "UTIL1.h"
#include "WAIT1.h"
#include "TMOUT1.h"
#include "CS1.h"
#include "TI1.h"
#include "TimerIntLdd1.h"
#include "TU1.h"
#include "SM1.h"
#include "AD1.h"
#include "AdcLdd1.h"
#include "EInt1.h"
#include "ExtIntLdd1.h"
#include "LEDG.h"
#include "LEDpin1.h"
#include "BitIoLdd1.h"
#include "LEDR.h"
#include "LEDpin2.h"
#include "BitIoLdd2.h"
#include "LEDPWM.h"
#include "Inhr1.h"
#include "PwmLdd1.h"
#include "TU2.h"
#include "WAIT2.h"
#include "DBCLK.h"
#include "TimerIntLdd2.h"
#include "TU3.h"

#ifdef __cplusplus
extern "C" {
#endif

#define BUFFER_SIZE 32000

void DataLoggerError(void) {
	for (;;) {}
}

/*
void LogToLoggerFile(int16_t x) {
	FIL fpLogger;
	uint8_t write_buf[48];
	UINT bw;
	TIMEREC time;

	if (FAT1_open(&fpLogger, "./log.txt", FA_OPEN_ALWAYS|FA_WRITE) != FR_OK) {
		Err();
	}


	if (FAT1_lseek(&fpLogger, fpLogger.fsize) != FR_OK
			|| fpLogger.fptr != fpLogger.fsize) {
		Err();
	}

	if (TmDt1_GetTime(&time) != ERR_OK) {
		Err();
	}

	write_buf[0] = '\0';
	UTIL1_strcatNum8u(write_buf, sizeof(write_buf), time.Hour);
	UTIL1_chcat(write_buf, sizeof(write_buf), ':');
	UTIL1_strcatNum8u(write_buf, sizeof(write_buf), time.Min);
	UTIL1_chcat(write_buf, sizeof(write_buf), ':');
	UTIL1_strcatNum8u(write_buf, sizeof(write_buf), time.Sec);
	UTIL1_chcat(write_buf, sizeof(write_buf), '\t');

	UTIL1_strcatNum16s(write_buf, sizeof(write_buf), x);
	UTIL1_strcat(write_buf, sizeof(write_buf), (unsigned char*) "\r\n");

	if (FAT1_write(&fpLogger, write_buf, UTIL1_strlen((char*)write_buf), &bw)
			!= FR_OK) {
		(void) FAT1_close(&fpLogger);
		Err();
	}

	(void) FAT1_close(&fpLogger);
}
*/

/* User includes (#include below this line is not maintained by Processor Expert) */
void LogToDataFile(int16_t x) {
	FIL fpData;
	uint8_t write_buf[48];
	UINT bw;

	if (FAT1_open(&fpData, "./data.txt", FA_OPEN_ALWAYS|FA_WRITE) != FR_OK) {
		DataLoggerError();
	}

	if(removeDataFile == 1) {

		if (FAT1_truncate(&fpData) != FR_OK) {
			DataLoggerError();
		}
		removeDataFile=0;
	}

	if (FAT1_lseek(&fpData, fpData.fsize) != FR_OK
			|| fpData.fptr != fpData.fsize) {
		DataLoggerError();
	}

	write_buf[0] = '\0';

	UTIL1_strcatNum16s(write_buf, sizeof(write_buf), x);

	UTIL1_strcat(write_buf, sizeof(write_buf), (unsigned char*) "\r\n");
	if (FAT1_write(&fpData, write_buf, UTIL1_strlen((char*)write_buf), &bw)
			!= FR_OK) {
		(void) FAT1_close(&fpData);
		DataLoggerError();
	}

	(void) FAT1_close(&fpData);
}

// FRESULT
uint8_t *DataFileContentArray(int *length) {
	// FAT1_FATFS fileSystemObject;
	FIL fpData;
	FRESULT result;
	char buffer[BUFFER_SIZE];
	UINT fileSize= 0;
	uint8_t array[32000];
	int digitLength = 0, offset = 0, dataCount = 0;

	/* open file */
	if (FAT1_open(&fpData, "./data.txt", FA_OPEN_ALWAYS|FA_READ) != FR_OK) {
		DataLoggerError();
	}

	if (FAT1_read(&fpData, buffer, BUFFER_SIZE, &fileSize) != FR_OK) {
		DataLoggerError();
	}

	while(offset < fileSize) {
		uint8_t value = 0;
		stringToIntConverter(buffer, &offset, &digitLength, &value);

		if(digitLength > 0) {
			array[dataCount++] = value;
		}
	}

	*length = dataCount;
	/* closing file */
	(void) FAT1_close(&fpData);
	return array;
}

void stringToIntConverter(char *buffer, int *offset, int *len, uint32_t *total) {
	int i= *offset,
			j= 0,
			k= 0,
			length = 0;

	while(buffer[i] >= '0' && buffer[i] <= '9') {
		++i;
		++length;
	}

	k = length-1;
	for(j=*offset; j<i; j++) {
		uint8_t multiple = 1, ktmp=k;
		while(ktmp--) {
			multiple *= 10;
		}
		--k;
		uint8_t tmp = buffer[j] - 48;
		tmp *= multiple;
		*total += tmp;
	}
	if(length==0) {
		*offset = *offset + 1;
	} else {
		*offset = *offset + length;
	}

	*len = length;
}

#ifdef __cplusplus
}  /* extern "C" */
#endif



