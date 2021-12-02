/*
*Alamjit Choat
* 1962902
* 7/27/2020
* This program prints the internal temperatuer values of the TIVA board.
*/

#include "Lab_3_Header.h"
#include "Lab_3_Driver.h"
#include <stdio.h>

/**
 * main.c
 */

// main method to calculate and print TIVA board temperature 
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
    init_ADC();
    float temp = 0;
    
    while (1) {
      if (ADCRIS == 0x08) {
        temp = (147.5 - (247.5 * ADCSSFIFO3) / 4096.0);
        ADCISC = 0x08;
        ADCACTSS |= 0x08;
      }
      printf("Temperature in C: %f\n", temp);
   }
}

// initalizes the ADC
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
  ADCSSTSH3 = 0x4; 
}

