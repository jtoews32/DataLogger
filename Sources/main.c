/* ###################################################################
**     Filename    : main.c
**     Project     : DataLogger
**     Processor   : MK64FN1M0VLQ12
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-12-11, 16:36, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
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
#include "LEDB.h"
#include "LEDpin4.h"
#include "BitIoLdd4.h"
#include "RUNTI.h"
#include "TimerIntLdd3.h"
#include "TU4.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PDD_Includes.h"
#include "Init_Config.h"
#include "DataLogger.h"

int recordOn = 0;
int playBackOn = 0;
int doubleClick = 10;
int doubleClickInterruptInit = 1;
int doubleClickTimer = 11;
int removeDataFile = 0;
int initailizationComplete = 0;


void Application_Init() {
	Inhr1_SetRatio8(0x00);
	for (int i = 0; i < 2; i++) {
		LEDG_Neg();
		WAIT1_Waitms(400);
		LEDG_Neg();
		WAIT1_Waitms(200);
	}
}


/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
	/* Write your local variable definition here */
	/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
	PE_low_level_init();
	/*** End of Processor Expert internal initialization.                    ***/

	/* Write your code here */
	Application_Init();

	FAT1_FATFS fileSystemObject;

	if (FAT1_Init() != ERR_OK) { /* initialize FAT driver */
		DataLoggerError();
	}

	if (FAT1_mount(&fileSystemObject, (const TCHAR*) "0", 1) != FR_OK) { /* mount file system */
		DataLoggerError();
	}

	initailizationComplete = 1;


	uint16_t adcInput = 0;
	uint8_t adcInputRatio = 0,
			*adcRatioData;

	/*** End of Processor Expert internal initialization.                    ***/
	for (;;) {
		if (recordOn == 1 || playBackOn == 1) {
			(void) AD1_Measure(TRUE); /* do conversion and wait for the result */
			(void) AD1_GetValue16(&adcInput); /* get the result into value variable */
			adcInputRatio = (adcInput >> 9);
			Inhr1_SetRatio8(adcInputRatio);
			WAIT1_Waitms(200);
		}

		if (recordOn == 1) {
			LogToDataFile(adcInputRatio);
		}

		if (playBackOn == 1) {
			int length, i = 0;
			adcRatioData = DataFileContentArray(&length);

			while (i < length && playBackOn == 1) {
				uint8_t playbackRatio = *(adcRatioData + i);
				Inhr1_SetRatio8(playbackRatio);
				WAIT1_Waitms(200);
				++i;
			}

			if(playBackOn == 1  ) {
				LEDG_Neg();
				playBackOn = 0;
			}
		}
	}

	/*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.4 [05.09]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
