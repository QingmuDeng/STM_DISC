// hello world
#ifndef _STM32F4XX_H
#define _STM32F4XX_H

#include <stdint.h>
#define GPIOA_BASE 0x40020000
#define GPIOD_BASE 0x40020C00

//typedef unsigned int uint32_t;
//typedef unsigned short int uint16_t;

typedef struct{
	uint32_t MODER;
	uint32_t OTYPER;
	uint32_t OSPEEDR;
	uint32_t PURDR;
	uint16_t IDRL;
	uint16_t IDRH;
	uint32_t ODR;
	uint16_t BSRR_L;
	uint16_t BSRR_H;
	uint32_t LCKR;
	uint32_t AFRL;
	uint32_t AFRH;
}GPIO_typedef;

#define GPIOA  ((GPIO_typedef *)GPIOA_BASE)
#define GPIOD  ((GPIO_typedef *)GPIOD_BASE)
#endif /* _STM32F4XX_H */
