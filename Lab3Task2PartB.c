/*
*Alamjit Choat
* 1962902
* 7/27/2020
* This program creates a return to sender effect and lets us type anything
*    into an external putty.
*/
#include "Lab_3_Header.h"
#include "Lab_3_Driver.h"
#include <stdio.h>

/**
 * main.c
 */

// main method to type into the putty. 
int main(void) {
    // Select system clock frequency preset
    //
    // For lab task requirement:
    //   - Select PRESET 2 (60 MHz) to be the initial system clock frequency
    //   - Clock frequency stay at 60 MHz if no user switches are pressed
    //   - Change clock frequency to 12 MHz if SW 1 is pressed
    //   - Change clock frequency to 120 MHz if SW 2 is pressed
    enum frequency freq = PRESET2;
    PLL_Init(freq);             // PLL must be configured before everthing else
    init_UART2();
    
    char chara;
    while (1) {
      chara = readInput(); 
      reprintInput(chara);
    }
}

//initalizes UART2
// returns void
void init_UART2(void) {
  volatile unsigned long delay = 0;
  RCGCUART |= 0x04; // Enable UART0
  RCGCGPIO |= 0x01; // Enable Port A
  delay++;
  delay++;
  
  GPIOAFSEL |= 0xC0;
  GPIOPCTL |=  0x11000000; //PA6 PA7
  GPIODEN |= 0xC0; // Enable Port A pins 6 & 7
  
  UARTCTL2 = 0x0; // Disable the UART
  UARTIBRD2 = 390; //Integer portion
  UARTFBRD2 = 40; // fraction portion
  UARTLCRH2 |= (0x3 << 5); // 8-bit, 1 stop bit, no parity
  UARTCC2 = 0x0; // ALT clock source
  UARTCTL2 |= 0x301; // Enable the UART  
}

// method to read what char is being inputted to the putty
// returns a char storing the typed char
char readInput(void) {
    char c;
    while((UARTFR2 & (0x10)) != 0) {}
       c = UARTDR2;
       return c;        
}

// reprints the stored char to an external putty
// char word - the char storing the typed value
void reprintInput(char word) {
  while((UARTFR2 & (0x20)) != 0) {}
       UARTDR2 = word;        
}
