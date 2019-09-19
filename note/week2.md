# GPIO, Timer, and Clock
## Von Neumann
#### Architecture
![architecture](https://www.mpoweruk.com/images/von-Neumann.gif)
* other architecture
    * Modified Harvard architecture: seperate catches or seperate access path for data instructions
        * Both the concepts are similar except the way they access memories.
        * Harvard architecture is to split the memory into two parts – one for data and another for programs.
    * Modern Hybrid Architecture
        * caches: seperate data and intruction
        * memory: a common space for both
* other components
    * memory mapping I/O
    * streamlining
    * SoC(system on chip)
    * catch between the CPU and the main memory
    * branch predictor algorithms and logic
## Arduino
![pin](https://i.stack.imgur.com/GDsC6.png)
#### Flash, SRAM and EEPROM
* Flash(program memore)
    * store program image
    * initialize data 
* [SRAM](https://craftofcoding.wordpress.com/2015/12/07/memory-in-c-the-stack-the-heap-and-static/)
    * store data
    * static data: globaland static variables
    * heap: dynamically allocated data
    * stack
        * local variables
        * interrupts/calls
        * grows from the top of memory down towards the heap
    ![stack](https://cdn-learn.adafruit.com/assets/assets/000/010/263/medium800/learn_arduino_Free_Memory.gif?1448055797)
* EEPROM
    * non-volatile memory
    * read byte-by-byte
    * finite lifetime of about 100,000 write cycles
#### [I/O Memory Address Location](https://www.arduino.cc/en/Reference/PortManipulation)
* Data Register - PORTx
    * read/write
    * control whether the pin is HIGH or LOW
* Data Direction Register - DDRx
    * read/write
    * determine whether it is input or output
* Port Input Pins - PINx
    * read only
    * read data from pin
#### Homework
* 週一前繳交
* lab02_系所_學號_名字
* Q1. [Describe at least two methods that you used to blink the LED.](https://forum.arduino.cc/index.php?topic=4114.0)
    * Waiting: Light the LED. Do some action that takes 1 second. Shut off the LED. (repeat)
        * Use delay() function to blink the LED.
        * delay() is a blocking function.
        * Use millis() function to blink the LED.
    * Polling: Use a library like TimedAction, EventFuse, Scheduler or simply 'Blink without delay'
    * Interrupt
        * Use a timer to blink the LED.
        * Use an external interrupt wired to an external source that toggles a logic state each second. (Any clock should be a good source.)
* Q2. How many timer in ATmega 328p? What is the usage of timer0 in Arduino world.
    * 3?
    * 0: delay, 1: servo control
* Q4. Explain why we should use the cross-compiler.
    * picture which explains the cross-compiler, 幾台PC之間
* Q5. Explain your plan of [de-bouncing](https://www.arduino.cc/en/Tutorial/Debounce) the push button.
    * using flow chart or plan or pseudo code
* Q6. Reading Assigments:
    * ATmega 328p datasheet, read chapter 7, AVR CPU Core
    * ATmega 328p datasheet, read chapter 8, AVR Memories

#### 電阻
* 紅紅棕金 220 5%
* 棕黑橘今 10000 5%
* 發光二極體 長腳是正 短腳是負
##### EX1
* shift 1<<5: 0000 0001 &rarr; 0001 0000
* nor ~(1<<5): 0001 0000 &rarr; 1110 1111
* (1) PORTB &= ~(1<<5): PORTB = PORTB & (~(1<<5))
* (2) PORTB |= (1<<5): PORTB = PORTB | (1<<5) >= 0001 0000
* PRTB = 1111 0000
    * (2) 1111 0000: Bit 5(PB5) is high
    * (1) 1110 0000: Bit 5(PB5) is low
* PRTB = 1111 1111
    * (2) 1111 1111: Bit 5(PB5) is high
    * (1) 1110 1111: Bit 5(PB5) is low
![figure 1](https://i.imgur.com/mDLWdOb.png)
##### EX2
* #define _BV(bit) (1 << (bit))
* [timer](http://www.avrbeginners.net/architecture/timers/timers.html)
    * arduino 晶片中會有多個 timer
    * timer 不是無時無刻接受脈衝(接受脈衝會加一)，而是要自己設定頻率
    * 基於 CPU 本身的 clock(prescaler) 去設定他的頻率
    * TCCR1A: the mode of counter
    * TCCR1B: set the prescaler, timer increment action(add 1 on T1 pin when falling or rising edge)
    * set the prescaler of time &rarr; clock of timer = CPU clock/1024
        ```
        TCCR1B |= _BV(CS12);
        TCCR1B &= ~_BV(CS11);
        TCCR1B |= _BV(CS10);
        ```
#### EX5
ledState = HIGH
buttonState = None
lastButtonState = LOW

reading = HIGH
* led 亮
lastButtonState = HIGH
ledState = HIGH
buttonState = None

reading = HIGH/LOW
buttonState = HIGH/None
ledState = LOW/HIGH
lastButtonState = HIGH/LOW
* led暗/亮沒變

reading = HIGH
