/*
*Alamjit Choat
* 1962902
* 7/27/2020
* Header file for Task 2 part B
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

// ***************** METHODS ****************** //
void init_UART2(void);
char readInput(void);
void reprintInput(char input);

// ***************** UART2 ****************** //
#define RCGCGPIO                (*((volatile uint32_t *)0x400FE608))
#define RCGCUART                (*((volatile uint32_t *)0x400FE618))
#define GPIOAFSEL               (*((volatile uint32_t *)0x40058420))
#define GPIOPCTL                (*((volatile uint32_t *)0x4005852C))
#define GPIODEN                 (*((volatile uint32_t *)0x4005851C))

#define UARTCTL2                (*((volatile uint32_t *)0x4000E030))
#define UARTIBRD2               (*((volatile uint32_t *)0x4000E024))
#define UARTFBRD2               (*((volatile uint32_t *)0x4000E028))
#define UARTLCRH2               (*((volatile uint32_t *)0x4000E02C))
#define UARTCC2                 (*((volatile uint32_t *)0x4000EFC8))
#define UARTDR2                 (*((volatile uint32_t *)0x4000E000))
#define UARTFR2                 (*((volatile uint32_t *)0x4000E018))

#endif /* _Lab_3_HEADER_ */

