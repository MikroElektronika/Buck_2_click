/*
    __buck2_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __buck2_driver.h
@brief    Buck2 Driver
@mainpage Buck2 Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   BUCK2
@brief      Buck2 Click Driver
@{

| Global Library Prefix | **BUCK2** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Jan 2018.**      |
| Developer             | **MikroE Team**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _BUCK2_H_
#define _BUCK2_H_

/** 
 * @macro T_BUCK2_P
 * @brief Driver Abstract type 
 */
#define T_BUCK2_P    const uint8_t*

/** @defgroup BUCK2_COMPILE Compilation Config */              /** @{ */

//  #define   __BUCK2_DRV_SPI__                            /**<     @macro __BUCK2_DRV_SPI__  @brief SPI driver selector */
//  #define   __BUCK2_DRV_I2C__                            /**<     @macro __BUCK2_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __BUCK2_DRV_UART__                           /**<     @macro __BUCK2_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup BUCK2_VAR Variables */                           /** @{ */

// Mode
extern const uint8_t _BUCK2_MODE_ACTIVE;
extern const uint8_t _BUCK2_MODE_SLEEP;
// VOSET
extern const uint8_t _BUCK2_VOSET_LOW;
extern const uint8_t _BUCK2_VOSET_HIGH;
// FREQ
extern const uint8_t _BUCK2_FREQ_790KHz;
extern const uint8_t _BUCK2_FREQ_565KHz;

                                                                       /** @} */
/** @defgroup BUCK2_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup BUCK2_INIT Driver Initialization */              /** @{ */

#ifdef   __BUCK2_DRV_SPI__
void buck2_spiDriverInit(T_BUCK2_P gpioObj, T_BUCK2_P spiObj);
#endif
#ifdef   __BUCK2_DRV_I2C__
void buck2_i2cDriverInit(T_BUCK2_P gpioObj, T_BUCK2_P i2cObj, uint8_t slave);
#endif
#ifdef   __BUCK2_DRV_UART__
void buck2_uartDriverInit(T_BUCK2_P gpioObj, T_BUCK2_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void buck2_gpioDriverInit(T_BUCK2_P gpioObj);
                                                                       /** @} */
/** @defgroup BUCK2_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Function settings VOSET 0 pin
 *
 * @param[in] state     value to which the pin will be set
 */
void buck2_setVoset_0(uint8_t state);

/**
 * @brief Function settings VOSET 0 pin
 *
 * @param[in] state     value to which the pin will be set
 */
void buck2_setVoset_1(uint8_t state);

/**
 * @brief Function settings Frequency
 *
 * @param[in] state     value to which the pin will be set
 *
 *  Function sets the frequency,
    Frequency:
       565kHz - if the pin FQ is set to LOW
       790kHz - if the pin FQ is set to HIGH
 */
void busk2_setFreq(uint8_t state);

/**
 * @brief Function settings chip mode
 *
 * @param[in] mode     mode to which the pin will be set
 *
 *  Options:
       Mode ACTIVE,
       Mode SLEEP
 */
void buck2_setMode(uint8_t mode);

/**
 * @brief Function for reset chip
 */
void back2_reset();

/**
 * @brief Function reads state PG pin
 *
 * @return 1 - power good output voltage
 * @return 0 - not a good input voltage, set the input voltage to a minimum of 4500mV.
 *
 */
uint8_t buck2_getPowerGood();

/**
 * @brief Function settings output voltage on 3300mV
 */
void buck2_setVOUT_3300mV();

/**
 * @brief Function settings output voltage on 2500mV
 */
void buck2_setVOUT_2500mV();

/**
 * @brief Function settings output voltage on 1800mV
 */
void buck2_setVOUT_1800mV();

/**
 * @brief Function settings output voltage on 1500mV
 */
void buck2_setVOUT_1500mV();




                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Buck2_STM.c
    @example Click_Buck2_TIVA.c
    @example Click_Buck2_CEC.c
    @example Click_Buck2_KINETIS.c
    @example Click_Buck2_MSP.c
    @example Click_Buck2_PIC.c
    @example Click_Buck2_PIC32.c
    @example Click_Buck2_DSPIC.c
    @example Click_Buck2_AVR.c
    @example Click_Buck2_FT90x.c
    @example Click_Buck2_STM.mbas
    @example Click_Buck2_TIVA.mbas
    @example Click_Buck2_CEC.mbas
    @example Click_Buck2_KINETIS.mbas
    @example Click_Buck2_MSP.mbas
    @example Click_Buck2_PIC.mbas
    @example Click_Buck2_PIC32.mbas
    @example Click_Buck2_DSPIC.mbas
    @example Click_Buck2_AVR.mbas
    @example Click_Buck2_FT90x.mbas
    @example Click_Buck2_STM.mpas
    @example Click_Buck2_TIVA.mpas
    @example Click_Buck2_CEC.mpas
    @example Click_Buck2_KINETIS.mpas
    @example Click_Buck2_MSP.mpas
    @example Click_Buck2_PIC.mpas
    @example Click_Buck2_PIC32.mpas
    @example Click_Buck2_DSPIC.mpas
    @example Click_Buck2_AVR.mpas
    @example Click_Buck2_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __buck2_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */