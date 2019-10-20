# Bootloader and Interrupts
### Flashing Arduino
#### Using ICE (In-Circuit Emulator)
![ICE](https://rh6stzxdcl1wf9gj1fkj14uc-wpengine.netdna-ssl.com/wp-content/uploads/2016/12/ICE-Diagram-768x274.jpg)
* use hardware device or in-circuit emulator to debug the software of the embedded system
* emulate the CPU/IC
* plugging in the socket
* the goal is bebug, and checking the change of the register
* unconvenient
* why the ICE is so big
    * it is useful to experiment
* JTag
    * communicate to microcontroller
    * no need to remove and plug-in the IC usually
#### Bootloader
* in the FLASH memory
* pre-installed code
```
#define F_CPU 16000000L // Specify oscillator frequency
#include <avr/io.h>
#include <util/delay.h>
 
int main(void)
{
    DDRB = 0b10000000; // configure pin 7 of PORTB as output (digital pin 13 on the Arduino Mega2560)
     
    while(1)
    {
        PORTB = 0b10000000; // set 7th bit to HIGH
        _delay_ms(500);
        PORTB = 0b00000000; // set 7th bit to LOW
        _delay_ms(500);
    }
}
```
* Digital pin 13 is PortB 5th bit, which is DDRB = 0b00100000
* if there is no bootloader, what will happen?
    * bootloader is a code in FLASH
    * there is a method to download the bootloader through the ICE, and then we can load code into the Arduino without ICE
---
### Interrupt
Q: Why the ISR is short?
A: It need to serve the request the service as soon as possible
#### Hardware Interrupt (External)
* there is the signal coming from the pin
    * in UNO, there are only two external interrupt pins
    * ISR doesn't neet to read the input pin
* Pin Change Interrupts 
    * If we need 20 interrupts, we could group the first 10 pins and last pins as another group.
    * Then checking which pin send the interrupt signal.
    * ISR needs to have software logic steps to determine which pin caused the interrupt
#### Software Interrupt (Internal)
* attachInterrupt()
    ```
    attachInterrupt(digitalPinToInterrupt(interruptPin), blink, CHANGE); 
    ```
    * 1st parameter: the IC number
    * 2nd parameter: interrupt action
    * 3rd parameter: interrupt signal
---
### Others
#### Priority of interrupts
* when two interrupt occur on the same time, which one should do first
#### Example
* Reset button
* Watchdog
    * When emebedded system crashed, watchdog will restart it.
    * If system doesn't crash, it will reset the timer. So, when we find the timer is overflow, it means the system crashed then restart it.
* Timer
    * programming timer register to decide whether to create interrupt or not
* User define
---
### Homework
#### Q1. 

#### Q2. print message