/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : SM1.h
**     Project     : DataLogger
**     Processor   : MK64FN1M0VLQ12
**     Component   : SPIMaster_LDD
**     Version     : Component 01.111, Driver 01.08, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-12-11, 18:33, # CodeGen: 4
**     Abstract    :
**         This component "SPIMaster_LDD" implements MASTER part of synchronous
**         serial master-slave communication.
**     Settings    :
**          Component name                                 : SM1
**          Device                                         : SPI1
**          Interrupt service/event                        : Enabled
**            Input interrupt                              : INT_SPI1
**            Input interrupt priority                     : medium priority
**            Output interrupt                             : INT_SPI1
**            Output interrupt priority                    : medium priority
**          Settings                                       : 
**            Input pin                                    : Enabled
**              Pin                                        : ADC1_SE5a/PTE1/LLWU_P0/SPI1_SOUT/UART1_RX/SDHC0_D0/TRACE_D3/I2C1_SCL/SPI1_SIN
**              Pin signal                                 : 
**            Output pin                                   : Enabled
**              Pin                                        : ADC0_DM2/ADC1_SE7a/PTE3/SPI1_SIN/UART1_RTS_b/SDHC0_CMD/TRACE_D1/SPI1_SOUT
**              Pin signal                                 : 
**            Clock pin                                    : 
**              Pin                                        : ADC0_DP2/ADC1_SE6a/PTE2/LLWU_P1/SPI1_SCK/UART1_CTS_b/SDHC0_DCLK/TRACE_D2
**              Pin signal                                 : 
**            Chip select list                             : 0
**            CS external demultiplexer                    : Disabled
**            Attribute set list                           : 2
**              Attribute set 0                            : 
**                Width                                    : 8 bits
**                MSB first                                : yes
**                Clock polarity                           : Low
**                Clock phase                              : Capture on leading edge
**                Parity                                   : None
**                Chip select toggling                     : no
**                Clock rate index                         : 0
**                Delay between chars index                : 0
**                CS to CLK delay index                    : 0
**                CLK to CS delay index                    : 0
**              Attribute set 1                            : 
**                Width                                    : 8 bits
**                MSB first                                : yes
**                Clock polarity                           : Low
**                Clock phase                              : Capture on leading edge
**                Parity                                   : None
**                Chip select toggling                     : no
**                Clock rate index                         : 1
**                Delay between chars index                : 0
**                CS to CLK delay index                    : 0
**                CLK to CS delay index                    : 0
**            Clock rate                                   : 375 kHz
**            Delay between chars                          : 0.095367 µs
**            CS to CLK delay                              : 0.095367 µs
**            CLK to CS delay                              : 0.095367 µs
**            HW input buffer size                         : 1
**            HW input watermark                           : 1
**            HW output buffer size                        : 1
**            HW output watermark                          : 1
**          Initialization                                 : 
**            Initial chip select                          : 0
**            Initial attribute set                        : 0
**            Enabled in init. code                        : yes
**            Auto initialization                          : yes
**            Event mask                                   : 
**              OnBlockSent                                : Enabled
**              OnBlockReceived                            : Enabled
**              OnError                                    : Disabled
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component disabled
**            Clock configuration 2                        : This component disabled
**            Clock configuration 3                        : This component disabled
**            Clock configuration 4                        : This component disabled
**            Clock configuration 5                        : This component disabled
**            Clock configuration 6                        : This component disabled
**            Clock configuration 7                        : This component disabled
**     Contents    :
**         Init                - LDD_TDeviceData* SM1_Init(LDD_TUserData *UserDataPtr);
**         Deinit              - void SM1_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         SendBlock           - LDD_TError SM1_SendBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData...
**         ReceiveBlock        - LDD_TError SM1_ReceiveBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData...
**         SelectConfiguration - LDD_TError SM1_SelectConfiguration(LDD_TDeviceData *DeviceDataPtr, uint8_t...
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file SM1.h
** @version 01.08
** @brief
**         This component "SPIMaster_LDD" implements MASTER part of synchronous
**         serial master-slave communication.
*/         
/*!
**  @addtogroup SM1_module SM1 module documentation
**  @{
*/         

#ifndef __SM1_H
#define __SM1_H

/* MODULE SM1. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */

#include "Cpu.h"
#include "SPI_PDD.h"

#ifdef __cplusplus
extern "C" {
#endif 


/*! Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define SM1_PRPH_BASE_ADDRESS  0x4002D000U
  
/*! Device data structure pointer used when auto initialization property is enabled. This constant can be passed as a first parameter to all component's methods. */
#define SM1_DeviceData  ((LDD_TDeviceData *)PE_LDD_GetDeviceStructure(PE_LDD_COMPONENT_SM1_ID))

/* Methods configuration constants - generated for all enabled component's methods */
#define SM1_Init_METHOD_ENABLED        /*!< Init method of the component SM1 is enabled (generated) */
#define SM1_Deinit_METHOD_ENABLED      /*!< Deinit method of the component SM1 is enabled (generated) */
#define SM1_SendBlock_METHOD_ENABLED   /*!< SendBlock method of the component SM1 is enabled (generated) */
#define SM1_ReceiveBlock_METHOD_ENABLED /*!< ReceiveBlock method of the component SM1 is enabled (generated) */
#define SM1_SelectConfiguration_METHOD_ENABLED /*!< SelectConfiguration method of the component SM1 is enabled (generated) */

/* Events configuration constants - generated for all enabled component's events */
#define SM1_OnBlockSent_EVENT_ENABLED  /*!< OnBlockSent event of the component SM1 is enabled (generated) */
#define SM1_OnBlockReceived_EVENT_ENABLED /*!< OnBlockReceived event of the component SM1 is enabled (generated) */

#define SM1_CHIP_SELECT_COUNT 0U       /*!< Number of chip selects */
#define SM1_CONFIGURATION_COUNT 2U     /*!< Number of predefined configurations */

/* Communication error data type */


/*
** ===================================================================
**     Method      :  SM1_Init (component SPIMaster_LDD)
*/
/*!
**     @brief
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc.
**         If the "Enable in init. code" is set to "yes" value then the
**         device is also enabled(see the description of the Enable()
**         method). In this case the Enable() method is not necessary
**         and needn't to be generated. 
**         This method can be called only once. Before the second call
**         of Init() the Deinit() must be called first.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     @return
**                         - Device data structure pointer.
*/
/* ===================================================================*/
LDD_TDeviceData* SM1_Init(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Method      :  SM1_Deinit (component SPIMaster_LDD)
*/
/*!
**     @brief
**         This method deinitializes the device. It switches off the
**         device, frees the device data structure memory, interrupts
**         vectors, etc.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
*/
/* ===================================================================*/
void SM1_Deinit(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  SM1_ReceiveBlock (component SPIMaster_LDD)
*/
/*!
**     @brief
**         This method specifies the number of data to receive. The
**         method returns ERR_BUSY until the specified number of
**         characters is received. The method <CancelBlockReception>
**         can be used to cancel a running receive operation.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         BufferPtr       - Pointer to A buffer where
**                           received characters will be stored.
**     @param
**         Size            - Size of the block
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_DISABLED - Component is disabled
**                           ERR_BUSY - The previous receive request is
**                           pending
*/
/* ===================================================================*/
LDD_TError SM1_ReceiveBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr, uint16_t Size);

/*
** ===================================================================
**     Method      :  SM1_SendBlock (component SPIMaster_LDD)
*/
/*!
**     @brief
**         This method sends a block of characters. The method returns
**         ERR_BUSY when the previous block transmission is not
**         completed. The method <CancelBlockTransmission> can be used
**         to cancel a transmit operation.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         BufferPtr       - Pointer to the block of data
**                           to send.
**     @param
**         Size            - Number of characters in the buffer.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_DISABLED - Component is disabled
**                           ERR_BUSY - The previous transmit request is
**                           pending
*/
/* ===================================================================*/
LDD_TError SM1_SendBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr, uint16_t Size);

/*
** ===================================================================
**     Method      :  SM1_SelectConfiguration (component SPIMaster_LDD)
*/
/*!
**     @brief
**         This method selects attributes of communication from the
**         <Attribute set list> and select a chip select from the <Chip
**         select list>. Once any configuration is selected, a
**         transmission can be started multiple times. This method is
**         available if number of chip selects or number of attribute
**         set is greater than 1. If the device doesn't support chip
**         select functionality the ChipSelect parameter is ignored.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         ChipSelect      - Chip select index from the
**                           <Chip select list>.
**     @param
**         AttributeSet    - Communication attribute
**                           index from the <Attribute set list>
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_DISABLED - Component is disabled
**                           ERR_PARAM_CHIP_SELECT - Chip select index
**                           is out of range
**                           ERR_PARAM_ATTRIBUTE_SET - Attribute set
**                           index is out of range
**                           ERR_BUSY - Transmission is in progress
*/
/* ===================================================================*/
LDD_TError SM1_SelectConfiguration(LDD_TDeviceData *DeviceDataPtr, uint8_t ChipSelect, uint8_t AttributeSet);

/*
** ===================================================================
**     Method      :  SM1_Interrupt (component SPIMaster_LDD)
**
**     Description :
**         The ISR function handling the device receive/transmit 
**         interrupt.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
/* {Default RTOS Adapter} ISR function prototype */
PE_ISR(SM1_Interrupt);

/* END SM1. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif
/* ifndef __SM1_H */
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
