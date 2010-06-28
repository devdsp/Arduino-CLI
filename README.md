Intro
=====

I've been playing with the Arduino development boards and tools. I'm not a fan
of their IDE at all and I'm still not convinced either way regarding the
practicality of the Wiring library. On the one hand it makes the time to first
upload really short, but on the other hand it's slow as a dog and on the
gripping hand there is a whole lot of code writing around those libraries to
support very interesting hardware. I'm really keen to see if I can get by just
using make, Vim and avr-libc. This repository is where I'm going to be doing
that experimentation.

Currently there's rather a large barrier to go from the dead simple Arduino
IDE - which handles all of the project management, compiling, linking and
uploading with one button - to writing raw avr-libc code, compiling, linking
and uploading to the boards. I'm currently working on a Makefile which reads
the boards.txt file shipped with the Arduino IDE to configure the parameters
needed for compiling and uploading to the different Arduino Development
boards. This will hopefully address the C-Code to Arduino-Board steps and let
me get my hands dirty with programming straight on top of avr-libc.

Currently the Makefile in this repository is capable of building and uploading
a .hex file to my Arduino. It has only been tested with my Atmega328p based
16MHz Duemilanove but I'll try it out on my Atmega328V based 8MHz Lilypad
soon and then get the other members of Make, Hack, Void to lend my their
Arduinos for a minute or two while I test them.

Instructions
============

Platform Dependant Steps
------------------------

###Windows###

Install WinAVR and make sure that your PATH environment variable has been
updated to include the gnu bin-utils, avr-libc and gcc-avr directories.

###Linux###

Install gcc-avr, avr-libc and avrdude from your favorite package manager.

###MacOSX###

I don't actually know. I'll see if I can get someone to test this.

Platform Independent Stuff
--------------------------

Edit the ARDUINO_VERSION and the AVRDUDE_PORT variables in the top of the
Makefile; to match the first section (everything up to the first '.') of the
board definition that matches the Arduino you are using; and the location of
the port that your Arduino is connected to respectively. 

On Windows you can see the COM port numbers in the Device Manager and on Linux
they appear as /dev/ttyUSB* device nodes. Again, I'll have to follow up on
correct port on MacOSX.

Change to the directory you have downloaded/cloned the repository to and run:

  make
  make program # at the some time as you reset your Arduino

This should load the blink test program into your Arduino. If not, raise an
issue on this repository and I'll look into it.

What now?
---------
Blinking LEDs are great but you're probably looking at this repository because
you want to do more than just blink an LED.

The first thing I would suggest doing is messing around with the delay time to
make sure that rebuilding and programming really is working.

If you want to start a new project with a new name you will need to change the
TARGET variable in the makefile to match the name of the new .c file you're
working with. Do not include the extension or the Makefile will get really
confused. The Makefile automatically creates a config.h file which includes
the '#define F_CPU' macro based on the clock speed specified in the boards.txt
file, you'll want to make sure you '#include "config.h"' at the top of your
$(TARGET).c or some of the avr-libc functions and macros wont work.

TODO
====
  * Test with more Arduinos
  * Pulse the DTR line on the COM/ttyUSB port to reset before uploading.
  * Support for more than one Source file
  * Support for a 'libraries' like directory
  * Support for MacOSX
  * Automatically link in the Wiring libraries?

