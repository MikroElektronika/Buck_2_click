![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Buck2 Click

- **CIC Prefix**  : BUCK2
- **Author**      : Katarina Perendic
- **Verison**     : 1.0.0
- **Date**        : Jan 2018.

---

### Software Support

We provide a library for the Buck2 Click on our [LibStock](https://libstock.mikroe.com/projects/view/2308/buck-2-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

Library caries all neccesary functions for control over Buck 2 click board.

Key functions :

- ``` void buck2_setMode(uint8_t mode) ``` - Setup working mode
- ``` void buck2_setVOUT_3300mV() ``` - Setup output voltage to 3.3 V
- ``` void buck2_setVOUT_2500mV() ``` - Setup output voltage to 2.5 V
- ``` void buck2_setVOUT_1800mV() ``` - Setup output voltage to 1.8 V
- ``` void buck2_setVOUT_1500mV() ``` - Setup output voltage to 1.5 V

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes CS pin, RST pin, PWM pin, AN pin as OUTPUT and INT pin as INPUT
- Application Initialization - Initializes Driver init and settings chip mode as ACTIVE
- Application Task - (code snippet) - Sets a different range of input voltages every 3 sec and checks if it 
has reached the set output voltage.

```.c
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
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2308/buck-2-click) page.

mikroE Libraries used in the example:

- UART

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
### Architectures Supported

#### mikroC

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

#### mikroBasic

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

#### mikroPascal

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

---
---
