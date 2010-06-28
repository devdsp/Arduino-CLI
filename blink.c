#include "config.h"
#include <avr/io.h>
#include <util/delay.h>

/*
    PB5 is digital 13 (which is where the onboard LED is connected)
    on my m328 based Duemilanove and Lilypad. You may need to change
    the ports and pins to match your Arduino.
    
    As an example; the Arduino Megas, which use the m1280 avr, have
    the LED connected to PB7.

    I'm not using the PBx or the DDBx/PORTBx defines in this code 
    because WinAVR and Debian ship different versions of the avr-libc
    and one uses PBx and the other users the DDXx/PORTBx conventions.
*/

int main(void) {
  DDRB |= 1<<5; 
  while(1) {
    PORTB ^= 1<<5;
    _delay_ms(100); 
  }
  return 0;
}

