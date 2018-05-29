// hello world
#ifndef _STM32F4XX_H
#define _STM32F4XX_H

#include <stdint.h>
#define GPIOD_BASE 0x40020C00

//typedef unsigned int uint32_t;
//typedef unsigned short int uint16_t;

typedef struct{
	uint32_t MODER;
	uint32_t OTYPER;
	uint32_t OSPEEDR;
	uint32_t PURDR;
	uint32_t IDR;
	uint32_t ODR;
	uint16_t BSRR_L;
	uint16_t BSRR_H;
	uint32_t LCKR;
	uint32_t AFRL;
	uint32_t AFRH;
}GPIO_typedef;

#define GPIOD  ((GPIO_typedef *)GPIOD_BASE)
#endif /* _STM32F4XX_H */
