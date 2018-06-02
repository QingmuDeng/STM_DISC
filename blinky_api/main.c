#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"

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
	RCC_AHB1ENR |= (1<<0);

	/* Set PD12, 13, 14, 15 to output by setting the bits in GPIOD_MODER */
	// GPIOD->MODER |= (1 << (2*12));
	// GPIOD->MODER |= (1 << (2*13));
	// GPIOD->MODER |= (1 << (2*14));
	// GPIOD->MODER |= (1 << (2*15));
	GPIO_InitTypeDef GPIO_InitStruct12;
	GPIO_InitStruct12.GPIO_PIN = GPIO_Pin_12;
	GPIO_InitStruct12.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct12.GPIO_PuPd = GPIO_PULL_NO;
	GPIO_InitStruct12.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct12.GPIO_Speed = GPIO_Speed_L;

	GPIO_InitTypeDef GPIO_InitStruct13;
	GPIO_InitStruct13.GPIO_PIN = GPIO_Pin_13;
	GPIO_InitStruct13.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct13.GPIO_PuPd = GPIO_PULL_NO;
	GPIO_InitStruct13.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct13.GPIO_Speed = GPIO_Speed_L;

	GPIO_InitTypeDef GPIO_InitStruct_PA0;
	GPIO_InitStruct_PA0.GPIO_PIN = GPIO_Pin_0;
	GPIO_InitStruct_PA0.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStruct_PA0.GPIO_PuPd = GPIO_PULL_NO;

	GPIO_Init(GPIOD, &GPIO_InitStruct12);
	GPIO_Init(GPIOD, &GPIO_InitStruct13);
	GPIO_Init(GPIOD, &GPIO_InitStruct_PA0);
	while(1)
	{
		/* Flip the outputs of PD12, 13, 14, 15 */
		GPIO_SetBits(GPIOD, GPIO_Pin_12);
//		delay(2000000);
//		GPIO_ClearBits(GPIOD, GPIO_Pin_12);
//		delay(2000000);

		if(GPIO_ReadBits(GPIOA, GPIO_Pin_0))
		{
			GPIO_SetBits(GPIOD, GPIO_Pin_13);
			delay(2000000);
			GPIO_ClearBits(GPIOD, GPIO_Pin_13);
			delay(2000000);
		}
		// GPIOD->ODR ^= (1<<14);
		// delay(2000000);
		// GPIOD->ODR ^= (1<<15);
		// delay(2000000);
	}

	return 0;
}

void SystemInit(void)
{
	/***/
}
