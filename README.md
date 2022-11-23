# STM32-Fan-PWM-ADC-LCD-Proteus
Proteus simulation for fan with both manual and automatic mode

# Proteus fan simulation!

Hi! You are looking at Proteus simulation of STM32F103.
I used Eclipse for building and debuging. If you want to change the code using my files make sure to **change makefile line 74** to **your toolchain path**!
LCD used is LM020L.
Com port is software attached using [Com0Com](https://sourceforge.net/projects/com0com/) simulator.

# Files

Every file is clearly labeled. This project **is not relised using STM32CubeMX**.
Header file is also including with exact bits to change in order to make simulation work.
This simulation is bit more limited than real STM32F103, so you have only 1 ADC etc...

Every single line is explained in detail in comments. (on Serbian, but you can also see the page number from [STM32f10x Reference Manual](https://www.google.com/search?client=firefox-b-d&q=stm32f10x%20reference%20manual) )
