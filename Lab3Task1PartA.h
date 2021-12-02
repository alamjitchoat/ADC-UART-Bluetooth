/*
*Alamjit Choat
* 1962902
* 7/27/2020
* Header file for Task 1 part A
*/
#ifndef _Lab_3_HEADER_
#define _Lab_3_HEADER_

#include <stdint.h>

// ******************** CLOCK CONTROL REGISTERS ********************** //
#define MOSCCTL                 (*(volatile uint32_t *) 0x400FE07C)
#define RIS                     (*(volatile uint32_t *) 0x400FE050)
#define RSCLKCFG                (*(volatile uint32_t *) 0x400FE0B0)
#define PLLFREQ0                (*(volatile uint32_t *) 0x400FE160)
#define PLLFREQ1                (*(volatile uint32_t *) 0x400FE164)
#define PLLSTAT                 (*(volatile uint32_t *) 0x400FE168)
#define MEMTIM0                 (*(volatile uint32_t *) 0x400FE0C0)

// ***************** ADC REGISTERS ****************** //
#define RCGCADC                 (*(volatile uint32_t *) 0x400FE638)
#define ADCACTSS                (*(volatile uint32_t *) 0x40038000)
#define PLLFREQ0                (*(volatile uint32_t *) 0x400FE160)
#define ADCCC                   (*(volatile uint32_t *) 0x40038FC8)
#define ADCEMUX                 (*(volatile uint32_t *) 0x40038014)
#define ADCSSMUX3               (*(volatile uint32_t *) 0x400380A0)
#define ADCSSCTL3               (*(volatile uint32_t *) 0x400380A4)
#define ADCPSSI                 (*(volatile uint32_t *) 0x40038028)
#define ADCSSFIFO3              (*(volatile uint32_t *) 0x400380A8)
#define ADCRIS                  (*(volatile uint32_t *) 0x40038004)
#define ADCISC                  (*(volatile uint32_t *) 0x4003800C)
#define ADCSSTSH3               (*((volatile uint32_t *)0x400380BC)) 

// ***************** TIVA LEDS ****************** //
#define RCGCGPIO                (*((volatile uint32_t *)0x400FE608))
#define GPIODIR_J               (*((volatile uint32_t *)0x40060400))
#define GPIODIR_N               (*((volatile uint32_t *)0x40064400))
#define GPIODIR_F               (*((volatile uint32_t *)0x4005D400)) 
#define GPIODIR_E               (*((volatile uint32_t *)0x4005C400)) 
#define GPIODEN_J               (*((volatile uint32_t *)0x4006051C))
#define GPIODEN_N               (*((volatile uint32_t *)0x4006451C))
#define GPIODEN_F               (*((volatile uint32_t *)0x4005D51C)) 
#define GPIODEN_E               (*((volatile uint32_t *)0x4005C51C)) 
#define GPIOPUR_J               (*((volatile uint32_t *)0x40060510))          
#define GPIOPUR_N               (*((volatile uint32_t *)0x40064510))
#define GPIOPUR_F               (*((volatile uint32_t *)0x4005D510))
#define GPIOPUR_E               (*((volatile uint32_t *)0x4005C510))
#define GPIODATA_J              (*((volatile uint32_t *)0x400603FC))         
#define GPIODATA_N              (*((volatile uint32_t *)0x400643FC))
#define GPIODATA_F              (*((volatile uint32_t *)0x4005D3FC)) 
#define GPIODATA_E              (*((volatile uint32_t *)0x4005C3FC)) 
#define GPIOAMSEL_E             (*((volatile uint32_t *)0x4005C528)) 
#define GPIOAFSEL_E             (*((volatile uint32_t *)0x4005C420)) 

// ***************** METHODS ****************** //
void init_ADC(void);
void init_LEDS(void);
void init_Timer(void);
void init_PortE(void);

// ***************** TIMER ****************** //
#define RCGCTIMER               (*((volatile uint32_t *)0x400FE604))
#define GPTMCTL_0               (*((volatile uint32_t *)0x4003000C))
#define GPTMCFG_0               (*((volatile uint32_t *)0x40030000))
#define GPTMTAMR_0              (*((volatile uint32_t *)0x40030004))
#define GPTMRIS_0               (*((volatile uint32_t *)0x4003001C))
#define GPTMTAILR_0             (*((volatile uint32_t *)0x40030028)) 
#define GPTMICR_0               (*((volatile uint32_t *)0x40030024)) 
#define GPTMIMR_0               (*((volatile uint32_t *)0x40030018)) 

#endif /* _Lab_3_HEADER_ */