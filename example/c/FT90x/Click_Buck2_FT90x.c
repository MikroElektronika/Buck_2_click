/*
Example for Buck2 Click

    Date          : Jan 2018.
    Author        : MikroE Team

Test configuration FT90x :
    
    MCU                : FT900
    Dev. Board         : EasyFT90x v7 
    FT90x Compiler ver : v2.2.1.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes CS pin, RST pin, PWM pin, AN pin as OUTPUT and INT pin as INPUT
- Application Initialization - Initializes Driver init and settings chip mode as ACTIVE
- Application Task - (code snippet) - Sets a different range of input voltages every 2 s and checks if it has reached the set output voltage.

*/

#include "Click_Buck2_types.h"
#include "Click_Buck2_config.h"

uint8_t PG_State;
char text[256];
void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_OUTPUT );
    mikrobus_logInit( _LOG_USBUART, 9600 );
    Delay_ms( 100 );
}

void applicationInit()
{
    buck2_gpioDriverInit( (T_BUCK2_P)&_MIKROBUS1_GPIO );
    buck2_setMode(_BUCK2_MODE_ACTIVE);
    Delay_100ms();
}

void applicationTask()
{
     PG_State = buck2_getPowerGood();
     if ( PG_State != 0 )
     {
          mikrobus_logWrite("Power good output voltage", _LOG_LINE);
     }
     buck2_setVOUT_3300mV();
     Delay_ms( 3000 );
     buck2_setVOUT_2500mV();
     Delay_ms( 3000 );
     buck2_setVOUT_1800mV();
     Delay_ms( 3000 );
     buck2_setVOUT_1500mV();
     Delay_ms( 3000 );
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}
