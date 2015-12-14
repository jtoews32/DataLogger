/* ###################################################################
**     Filename    : Events.c
**     Project     : DataLogger
**     Processor   : MK64FN1M0VLQ12
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-12-11, 16:36, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         Cpu_OnNMI - void Cpu_OnNMI(void);
**
** ###################################################################*/
/*!
** @file Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"
#include "Init_Config.h"
#include "PDD_Includes.h"
#include "DataLogger.h"

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */

/*
** ===================================================================
**     Event       :  Cpu_OnNMI (module Events)
**
**     Component   :  Cpu [MK64FN1M0LQ12]
*/
/*!
**     @brief
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the [NMI
**         interrupt] property is set to 'Enabled'.
*/
/* ===================================================================*/
void Cpu_OnNMI(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  SM1_OnBlockSent (module Events)
**
**     Component   :  SM1 [SPIMaster_LDD]
*/
/*!
**     @brief
**         This event is called after the last character from the
**         output buffer is moved to the transmitter. This event is
**         available only if the SendBlock method is enabled.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer is passed
**                           as the parameter of Init method. 
*/
/* ===================================================================*/
void SM1_OnBlockSent(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  TI1_OnInterrupt (module Events)
**
**     Component   :  TI1 [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TI1_OnInterrupt(void)
{
	TmDt1_AddTick();
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  Inhr1_OnEnd (module Events)
**
**     Component   :  Inhr1 [PWM]
**     Description :
**         This event is called when the specified number of cycles has
**         been generated. (Only when the component is enabled -
**         <Enable> and the events are enabled - <EnableEvent>). The
**         event is available only when the <Interrupt service/event>
**         property is enabled and selected peripheral supports
**         appropriate interrupt.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Inhr1_OnEnd(void)
{
  /* Write your code here ... */
}


/*
** ===================================================================
**     Event       :  EInt1_OnInterrupt (module Events)
**
**     Component   :  EInt1 [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void EInt1_OnInterrupt(void) {
	if( doubleClickInterruptInit == 1) {
		doubleClickInterruptInit = 0;
		return;
	}

	if(recordOn==1) {
		LEDR_Neg();
		recordOn = 0;
		return;
	}
	if(playBackOn == 1) {
		LEDG_Neg();
		playBackOn = 0;
		return;
	}

	if(doubleClick == 0 || doubleClick == 1 ) {  /*|| doubleClick == 2*/
		++doubleClick;
	} else {
		doubleClick = 0;
	}
	doubleClickTimer = 0;
}

/*
** ===================================================================
**     Event       :  AD1_OnEnd (module Events)
**
**     Component   :  AD1 [ADC]
**     Description :
**         This event is called after the measurement (which consists
**         of <1 or more conversions>) is/are finished.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void AD1_OnEnd(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  AD1_OnCalibrationEnd (module Events)
**
**     Component   :  AD1 [ADC]
**     Description :
**         This event is called when the calibration has been finished.
**         User should check if the calibration pass or fail by
**         Calibration status method./nThis event is enabled only if
**         the <Interrupt service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void AD1_OnCalibrationEnd(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  DBCLK_OnInterrupt (module Events)
**
**     Component   :  DBCLK [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void DBCLK_OnInterrupt(void)
{
	if( doubleClick == 10) {
		return;
	}

	++doubleClickTimer;
	if( doubleClickTimer == 1000) {
		doubleClickTimer = 11;
	}
	if( doubleClickTimer == 8) {

		if ( doubleClick == 1 ) {
			playBackOn = 1;
			LEDG_Neg();
			doubleClick = 10;
			return;
		}
		if( doubleClick == 0 ) {
			removeDataFile = 1;
			recordOn = 1;
			LEDR_Neg();
			doubleClick = 10;
			return;
		}
	}
}

/*
** ===================================================================
**     Event       :  RUNTI_OnInterrupt (module Events)
**
**     Component   :  RUNTI [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void RUNTI_OnInterrupt(void)
{
	if( initailizationComplete == 0 ) {
		return;
	}

	/*
	uint16_t adcInput = 0;
	uint8_t adcInputRatio = 0,
			*adcRatioData;

	for (;;) {
		if (recordOn == 1 || playBackOn == 1) {
			(void) AD1_Measure(TRUE);
			(void) AD1_GetValue16(&adcInput);
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

	 */


  /* Write your code here ... */
}

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

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
