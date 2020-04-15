# FastShiftOut

Arduino library for (AVR) optimized shiftOut - e.g. 74HC595

## Description

This class has optimized code for AVR to shift out data faster 
than the normal shiftOut.

If not a **ARDUINO_ARCH_AVR** or **ARDUINO_ARCH_MEGAAVR** the class falls back 
to the default shiftOut implementation.

The interface exists of the following functions:

* **size_t write(const uint8_t data);**
* **size_t writeLSBFIRST(const uint8_t data);** // most optimized
* **size_t writeMSBFIRST(const uint8_t data);** // most optimized

Furthermore an FastShiftOut object implements the print interface
so one can also call
* **FSO.print(any type);** or 
* **FSO.println(any type);**

to send e.g. a float with 4 digits over the line.

## Operation

See examples

