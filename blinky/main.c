#include "stm32f4xx.h"

#define RCC_AHB1ENR *(unsigned int*)(0x40023800+0x30)
#define GPIOD_MODER *(unsigned int*)(0x40020C00+0x00)
#define GPIOD_ODR   *(unsigned int*)(0x40020C00+0x14)

int main(void)
{

	*( unsigned int*)(0x40023800+0x30) |= (1<<3);
	*( unsigned int*)(0x40020C00+0x00) &= ((0x03) << (2*13));
	*( unsigned int*)(0x40020C00+0x00) |= (1 << (2*13));
	
	//while(1)
	//{
		*(unsigned int*)(0x40020C00+0x14) |= (1<<13);
	//}
	
	return 0;
}

void SystemInit(void)
{
	/***/
}
