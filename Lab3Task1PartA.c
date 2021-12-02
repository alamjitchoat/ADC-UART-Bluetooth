/*
*Alamjit Choat
* 1962902
* 7/27/2020
* This program uses a potentiometer to adjust the resistance values and toggle
*   the proper on board TIVA Leds based on the resistance. 
*/

#include "Lab_3_Header.h"
#include "Lab_3_Driver.h"
#include <stdio.h>

/**
 * main.c
 */

// main method to toggle LEDs based on resistance value
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
    init_LEDS();
    init_Timer();
    init_PortE();
    float resistance = 0;
    int count = 0;
    
    while (1) {
      if ((GPTMRIS_0 & 0x01) == 0x01) {
        GPTMICR_0 |= 0x01;
        count++;
       }
       if (ADCRIS == 0x08) {
          resistance = ADCSSFIFO3 / (409.5);
          ADCISC = 0x08;
          ADCACTSS |= 0x08;
        }
        if(count == 1) {
           if (resistance < 2.5) {
             GPIODATA_N = 0x2;
           } else if (resistance < 5) {
             GPIODATA_N = 0x3;
           } else if (resistance < 7.5) {
             GPIODATA_N = 0x3;
             GPIODATA_F = 0x10;        
           } else if (resistance < 10) {
             GPIODATA_N = 0x3;
             GPIODATA_F = 0x11;
           }
       } else if (count == 2) {
         GPIODATA_N = 0x00;
         GPIODATA_F = 0x00;
         count = 0;
       }
    }
}

// method to initalize ADC
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
  ADCSSCTL3 |= 0x06; //Single ended option
  ADCACTSS |= 0x08; //Enable sequencer SS3
  ADCPSSI |= 0x08; // New conversion 
}

// method to on board LEDs
// returns void
void init_LEDS(void) {
  volatile unsigned short delay = 0;
  RCGCGPIO  |= 0x1120;   
  delay++;
  delay++;

  GPIODIR_F = 0x11;  
  GPIODEN_F = 0x11;   
  GPIODIR_N = 0x03;      
  GPIODEN_N = 0x03;      
  GPIODIR_J = 0x00;      
  GPIODEN_J = 0x03;          
}

// method to initalize Timer
// returns void
void init_Timer(void) {
  volatile unsigned short delay = 0;
  delay++;
  delay++;
  
  RCGCTIMER = 0x01; 
  GPTMCTL_0 = 0x00;
  GPTMCFG_0 = 0x00000000;
  GPTMTAMR_0 = 0x2;
  GPTMTAILR_0 = 0xF42400;
  GPTMCTL_0 |= (1<<0);
}

// method to initalize PORT E
// returns void
void init_PortE(void) {
  volatile unsigned long delay = 0;
  RCGCGPIO |= 0x10; //enable PortE GPIO
  delay++;
  delay++;
  GPIODIR_E = 0x0; // Set PE0 to output
  GPIODEN_E = 0x0; // Set PE0 to digital port
  GPIOAMSEL_E = 0x08;
  GPIOAFSEL_E = 0x08;
}
