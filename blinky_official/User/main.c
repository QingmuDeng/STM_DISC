#include "stm32f4xx.h"

void delay(unsigned long count)
{
	while(count--);
}

int main(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	GPIO_InitTypeDef GPIO_InitD12;
	GPIO_InitTypeDef GPIO_InitA0;

	GPIO_InitD12.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitD12.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitD12.GPIO_OType = GPIO_OType_PP;
	GPIO_InitD12.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitD12.GPIO_Speed = GPIO_Low_Speed;

	GPIO_InitA0.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitA0.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitA0.GPIO_PuPd = GPIO_PuPd_NOPULL;

	GPIO_Init(GPIOD, &GPIO_InitD12);
	GPIO_Init(GPIOA, &GPIO_InitA0);
  while(1)
	{
		if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0))
		{
			GPIO_SetBits(GPIOD, GPIO_Pin_12);
			delay(0xFFFFF);
			GPIO_ResetBits(GPIOD, GPIO_Pin_12);
			delay(0xFFFFF);
		}
	}

}
