#include "stm32f4xx.h"

#define RCC_AHB1ENR *(unsigned int*)(0x40023800+0x30)
	/*
#define GPIOD_MODER *(unsigned int*)(0x40020C00+0x00)
#define GPIOD_ODR   *(unsigned int*)(0x40020C00+0x14)*/

void delay(unsigned  int time)
{	/* Software delay by subtracting to 0 */
	while(time--);
}

int main(void)
{
	/* Set GPIOD EN bit on RCC AHB1 peripheral clock register */
	RCC_AHB1ENR |= (1<<3);
	
	/* Set PD12, 13, 14, 15 to output by setting the bits in GPIOD_MODER */
	GPIOD->MODER |= (1 << (2*12));
	GPIOD->MODER |= (1 << (2*13));
	GPIOD->MODER |= (1 << (2*14));
	GPIOD->MODER |= (1 << (2*15));
	
	while(1)
	{	
		/* Flip the outputs of PD12, 13, 14, 15 */
		GPIOD->ODR ^= (1<<12);
		delay(2000000);
		GPIOD->ODR ^= (1<<13);
		delay(2000000);
		GPIOD->ODR ^= (1<<14);
		delay(2000000);
		GPIOD->ODR ^= (1<<15);
		delay(2000000);
	}
	
	return 0;
}

void SystemInit(void)
{
	/***/
}
