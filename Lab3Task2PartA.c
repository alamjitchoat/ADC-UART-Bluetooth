/*
*Alamjit Choat
* 1962902
* 7/27/2020
* This program prints the internal temperature values of the TIVA board to 
*    an external putty.
*/

#include "Lab_3_Header.h"
#include "Lab_3_Driver.h"
#include <stdio.h>

/**
 * main.c
 */

// main method to print temperature values to external putty
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
    init_ADC();;
    init_UART();
    int lengthOfString = 0;
    float temp = 0;
    
    while (1) {    
      temp = (147.5 - (247.5 * ADCSSFIFO3) / 4096.0);
      char buffer[50];
      lengthOfString = sprintf(buffer, "Temp in C: %f\n\r", temp);
       for (int i = 0; i < lengthOfString; i++) {
         while((UARTFR & (0x1 << 5)) != 0) {} 
         UARTDR = buffer[i];
       }
    }
}

//initalizes ADC
// returns void
void init_ADC(void) {
  volatile unsigned short delay = 0;
  delay++;
  delay++;
  RCGCADC |= 0x1; // Enable the ADC clock
  ADCACTSS = 0x0; // Disabling the sample sequencer
  ADCCC = 0x2; // Select PISOC in ADCCC
  ADCEMUX |= (0xf << 12); // Software trigger
  ADCSSMUX3 = 0x0; // Select ADC input channel
  ADCSSCTL3 |= 0xE; //Single ended option
  ADCACTSS |= 0x08; //Enable sequencer SS3
  ADCPSSI |= 0x08; // New conversion 
  ADCSSTSH3 = 0x4; // PART B
  
}

//initalizes UART0
// returns void
void init_UART(void) {
  volatile unsigned long delay = 0;
  RCGCUART |= 0x01; // Enable UART0
  RCGCGPIO |= 0x01; // Enable Port A
  delay++;
  delay++;
  
  GPIOAFSEL |= 0x03;
  GPIOPCTL |= 0x1; //PA0
  GPIOPCTL |= (1 << 4); // PA1
  GPIODEN |= 0x3; // Enable Port A pins 1 and 0
  
  UARTCTL = 0x0; // Disable the UART
  UARTIBRD = 0x08; //Integer portion
  UARTFBRD = 44; // fraction portion
  UARTLCRH |= (0x3 << 5); // 8-bit, 1 stop bit, no parity
  UARTCC = 0x5; // ALT clock source
  UARTCTL |= 0x301; // Enable the UART  
}