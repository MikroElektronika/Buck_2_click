/*
    __buck2_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__buck2_driver.h"
#include "__buck2_hal.c"

/* ------------------------------------------------------------------- MACROS */

// Mode
const uint8_t _BUCK2_MODE_ACTIVE = 0x01;
const uint8_t _BUCK2_MODE_SLEEP  = 0x00;
// VOSET
const uint8_t _BUCK2_VOSET_LOW   = 0x00;
const uint8_t _BUCK2_VOSET_HIGH  = 0x01;
// FREQ
const uint8_t _BUCK2_FREQ_790KHz = 0x01;
const uint8_t _BUCK2_FREQ_565KHz = 0x00;

/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __BUCK2_DRV_I2C__
static uint8_t _slaveAddress;
#endif

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __BUCK2_DRV_SPI__

void buck2_spiDriverInit(T_BUCK2_P gpioObj, T_BUCK2_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __BUCK2_DRV_I2C__

void buck2_i2cDriverInit(T_BUCK2_P gpioObj, T_BUCK2_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __BUCK2_DRV_UART__

void buck2_uartDriverInit(T_BUCK2_P gpioObj, T_BUCK2_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif

// GPIO Only Drivers - remove in other cases
void buck2_gpioDriverInit(T_BUCK2_P gpioObj)
{
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
}

/* ----------------------------------------------------------- IMPLEMENTATION */

void buck2_setVoset_0(uint8_t state)
{
    hal_gpio_anSet(state);
}
void buck2_setVoset_1(uint8_t state)
{
    hal_gpio_rstSet(state);
}
void busk2_setFreq(uint8_t state)
{
     hal_gpio_pwmSet(state);
}
void buck2_setMode(uint8_t mode)
{
     hal_gpio_csSet(mode);
}
void back2_reset()
{
    buck2_setMode(_BUCK2_VOSET_LOW);
    Delay_100ms();
    buck2_setMode(_BUCK2_VOSET_HIGH);
    Delay_100ms();
}
uint8_t buck2_getPowerGood()
{
    return hal_gpio_intGet();
}

void buck2_setVOUT_3300mV()
{
    back2_reset();
    buck2_setVoset_0(_BUCK2_VOSET_LOW);
    buck2_setVoset_1(_BUCK2_VOSET_LOW);
    busk2_setFreq(_BUCK2_FREQ_790KHz);
    Delay_100ms();
}

void buck2_setVOUT_2500mV()
{
    back2_reset();
    buck2_setVoset_0(_BUCK2_VOSET_HIGH);
    buck2_setVoset_1(_BUCK2_VOSET_LOW);
    busk2_setFreq(_BUCK2_FREQ_790KHz);
    Delay_100ms();
}

void buck2_setVOUT_1800mV()
{
    back2_reset();
    buck2_setVoset_0(_BUCK2_VOSET_LOW);
    buck2_setVoset_1(_BUCK2_VOSET_HIGH);
    busk2_setFreq(_BUCK2_FREQ_565KHz);
    Delay_100ms();
}

void buck2_setVOUT_1500mV()
{
    back2_reset();
    buck2_setVoset_0(_BUCK2_VOSET_HIGH);
    buck2_setVoset_1(_BUCK2_VOSET_HIGH);
    busk2_setFreq(_BUCK2_FREQ_565KHz);
    Delay_100ms();
}


/* -------------------------------------------------------------------------- */
/*
  __buck2_driver.c

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