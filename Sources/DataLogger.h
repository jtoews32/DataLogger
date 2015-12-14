#ifdef __DataLogger_H
#define __DataLogger_H

#ifdef __cplusplus
extern "C" {
#endif

void DataLoggerError(void);
uint8_t *DataFileContentArray(int *length);
void LogToDataFile(int16_t x);
// void LogToLoggerFile(int16_t x);
void stringToIntConverter(char *buffer, int *offset, int *len,  uint32_t *total);

#ifdef __cplusplus
}  /* extern "C" */
#endif

#endif
