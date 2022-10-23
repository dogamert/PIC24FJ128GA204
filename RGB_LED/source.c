/* 
 * File: source.c
 * Author: dogamert
 * Created on August 2021
 */

#include "config.h"
#include <xc.h>
#define FCY 1000000UL
#include <libpic30.h>

#define redLED _LATC5
#define greenLED _LATC6
#define blueLED _LATC7

int main(void){
_TRISC5 = 0; //config RC5 (RED) as output
_LATC5= 0; //RC5 initially initially LOW

_TRISC6 = 0; //config RC6 (GREEN) as output
_LATC6 = 0; //RC6 initially LOW

_TRISC7 = 0; //config RC7 (BLUE) as output
_LATC7 = 0; //RC7 initially LOW

while (1){ //infinite while loop 
    //red LED
    redLED = 1;
    __delay_ms(2000); //Generate 2 second delay
    redLED = 0;
   
    //green LED
    greenLED = 1;
    __delay_ms(2000); //Generate 2 second delay
    greenLED = 0;
      
    //blue LED
    blueLED = 1;
    __delay_ms(2000); //Generate 2 second delay
    blueLED = 0;
      
    //yellow (red+green) LEDs
    redLED = 1;
    greenLED = !_LATC6;
    __delay_ms(2000); //Generate 2 second delay
    redLED = 0;
    greenLED = 0;
      
    //magenta (red+blue) LEDs
    redLED= 1;
    blueLED = 1;
    __delay_ms(2000); //Generate 2 second delay
    redLED = 0;
    blueLED = 0;
      
    //cyan (green+blue) LEDs
    greenLED = 1;
    blueLED = 1;
    __delay_ms(2000); //Generate 2 second delay
    greenLED = 0;
    blueLED = 0; 
    }
}

