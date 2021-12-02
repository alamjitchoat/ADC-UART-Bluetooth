/*
*Alamjit Choat
* 1962902
* 7/27/2020
* Header file for Task 2 part A
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

// ***************** METHODS ****************** //
void init_ADC(void);
void init_UART(void);

// ***************** UART ****************** //
#define RCGCGPIO                (*((volatile uint32_t *)0x400FE608))
#define RCGCUART                (*((volatile uint32_t *)0x400FE618))
#define UARTCTL                 (*((volatile uint32_t *)0x4000C030))
#define UARTIBRD                (*((volatile uint32_t *)0x4000C024))
#define UARTFBRD                (*((volatile uint32_t *)0x4000C028))
#define UARTLCRH                (*((volatile uint32_t *)0x4000C02C))
#define UARTCC                  (*((volatile uint32_t *)0x4000CFC8))
#define UARTDR                  (*((volatile uint32_t *)0x4000C000))
#define UARTFR                  (*((volatile uint32_t *)0x4000C018))
#define GPIOAFSEL               (*((volatile uint32_t *)0x40058420))
#define GPIOPCTL                (*((volatile uint32_t *)0x4005852C))
#define GPIODEN                 (*((volatile uint32_t *)0x4005851C))
#define GPIODIR                 (*((volatile uint32_t *)0x40058400))

#endif /* _Lab_3_HEADER_ */
