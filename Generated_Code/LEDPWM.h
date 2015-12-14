/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : LEDPWM.h
**     Project     : DataLogger
**     Processor   : MK64FN1M0VLQ12
**     Component   : LED
**     Version     : Component 01.066, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-12-13, 13:08, # CodeGen: 5
**     Abstract    :
**          This component implements a universal driver for a single LED.
**     Settings    :
**          Component name                                 : LEDPWM
**          Turned On with initialization                  : no
**          HW Interface                                   : 
**            On/Off                                       : Disabled
**            PWM                                          : Enabled
**              PWM                                        : PWM
**            High Value means ON                          : no
**          Shell                                          : Disabled
**     Contents    :
**         Init       - void LEDPWM_Init(void);
**         Deinit     - void LEDPWM_Deinit(void);
**         On         - void LEDPWM_On(void);
**         Off        - void LEDPWM_Off(void);
**         Neg        - void LEDPWM_Neg(void);
**         Get        - uint8_t LEDPWM_Get(void);
**         Put        - void LEDPWM_Put(uint8_t val);
**         SetRatio16 - void LEDPWM_SetRatio16(uint16_t ratio);
**
**     License   : Open Source (LGPL)
**     Copyright : Erich Styger, 2013-2015, all rights reserved.
**     Web       : www.mcuoneclipse.com
**     This an open source software implementing a driver using Processor Expert.
**     This is a free software and is opened for education, research and commercial developments under license policy of following terms:
**     * This is a free software and there is NO WARRANTY.
**     * No restriction on use. You can use, modify and redistribute it for personal, non-profit or commercial product UNDER YOUR RESPONSIBILITY.
**     * Redistributions of source code must retain the above copyright notice.
** ###################################################################*/
/*!
** @file LEDPWM.h
** @version 01.00
** @brief
**          This component implements a universal driver for a single LED.
*/         
/*!
**  @addtogroup LEDPWM_module LEDPWM module documentation
**  @{
*/         

#ifndef __LEDPWM_H
#define __LEDPWM_H

/* MODULE LEDPWM. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "Inhr1.h"

#include "Cpu.h"

#define LEDPWM_ClrVal()    Inhr1_SetRatio16(0x0) /* put the pin on low level */
#define LEDPWM_SetVal()    Inhr1_SetRatio16(0xffff) /* put the pin on high level */
#define LEDPWM_SetInput()  /* not possible! */ /* use the pin as input pin */
#define LEDPWM_SetOutput() /* not possible! */ /* use the pin as output pin */
extern uint16_t LEDPWM_currPWM; /* current 16bit PWM value */

#define LEDPWM_PARSE_COMMAND_ENABLED  0 /* set to 1 if method ParseCommand() is present, 0 otherwise */


#define LEDPWM_On() LEDPWM_SetRatio16(0xffff)
/*
** ===================================================================
**     Method      :  LEDPWM_On (component LED)
**     Description :
**         This turns the LED on.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define LEDPWM_Off() LEDPWM_SetRatio16(0x0)
/*
** ===================================================================
**     Method      :  LEDPWM_Off (component LED)
**     Description :
**         This turns the LED off.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define LEDPWM_Neg() LEDPWM_SetRatio16(0xffff-LEDPWM_currPWM)
/*
** ===================================================================
**     Method      :  LEDPWM_Neg (component LED)
**     Description :
**         This negates/toggles the LED
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define LEDPWM_Get() (LEDPWM_currPWM!=0)
/*
** ===================================================================
**     Method      :  LEDPWM_Get (component LED)
**     Description :
**         This returns logical 1 in case the LED is on, 0 otherwise.
**     Parameters  : None
**     Returns     :
**         ---             - Status of the LED (on or off)
** ===================================================================
*/

#define LEDPWM_Init() LEDPWM_Off()
/*
** ===================================================================
**     Method      :  LEDPWM_Init (component LED)
**     Description :
**         Performs the LED driver initialization.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define LEDPWM_Put(val)  ((val) ? LEDPWM_On() : LEDPWM_Off())
/*
** ===================================================================
**     Method      :  LEDPWM_Put (component LED)
**     Description :
**         Turns the LED on or off.
**     Parameters  :
**         NAME            - DESCRIPTION
**         val             - value to define if the LED has to be on or
**                           off.
**     Returns     : Nothing
** ===================================================================
*/

void LEDPWM_Deinit(void);
/*
** ===================================================================
**     Method      :  LEDPWM_Deinit (component LED)
**     Description :
**         Deinitializes the driver
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void LEDPWM_SetRatio16(uint16_t ratio);
/*
** ===================================================================
**     Method      :  LEDPWM_SetRatio16 (component LED)
**     Description :
**         Method to specify the duty cycle. If using a PWM pin, this
**         means the duty cycle is set. For On/off pins, values smaller
**         0x7FFF means off, while values greater means on.
**     Parameters  :
**         NAME            - DESCRIPTION
**         ratio           - Ratio value, where 0 means 'off' and
**                           0xffff means 'on'
**     Returns     : Nothing
** ===================================================================
*/

/* END LEDPWM. */

#endif
/* ifndef __LEDPWM_H */
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
