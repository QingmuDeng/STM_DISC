#ifndef STM32F44XX_GPIO_H
#define STM32F44XX_GPIO_H

#include "stm32f4xx.h"

#define    GPIO_Pin_0          ( (uint16_t )(1<<0) )
#define    GPIO_Pin_1          ( (uint16_t )(1<<1) )
#define    GPIO_Pin_2          ( (uint16_t )(1<<2) )
#define    GPIO_Pin_3          ( (uint16_t )(1<<3) )
#define    GPIO_Pin_4          ( (uint16_t )(1<<4) )
#define    GPIO_Pin_5          ( (uint16_t )(1<<5) )
#define    GPIO_Pin_6          ( (uint16_t )(1<<6) )
#define    GPIO_Pin_7          ( (uint16_t )(1<<7) )
#define    GPIO_Pin_8          ( (uint16_t )(1<<8) )
#define    GPIO_Pin_9          ( (uint16_t )(1<<9) )
#define    GPIO_Pin_10         ( (uint16_t )(1<<10) )
#define    GPIO_Pin_11         ( (uint16_t )(1<<11) )
#define    GPIO_Pin_12         ( (uint16_t )(1<<12) )
#define    GPIO_Pin_13         ( (uint16_t )(1<<13) )
#define    GPIO_Pin_14         ( (uint16_t )(1<<14) )
#define    GPIO_Pin_15         ( (uint16_t )(1<<15) )
#define    GPIO_Pin_All        ( (uint16_t )(0xffff) )

typedef enum
{
  GPIO_Mode_IN = 0x00,
  GPIO_Mode_OUT = 0x01,
  GPIO_Mode_AF = 0x02,
  GPIO_Mode_AN = 0x03
}GPIOMODER_TypeDef;

typedef enum
{
  GPIO_OType_PP = 0x00,
  GPIO_OType_OD = 0x01
}GPIOOTYPER_TypeDef;

typedef enum
{
  GPIO_Speed_L = 0x00,
  GPIO_Speed_M = 0x01,
  GPIO_Speed_H = 0x02,
  GPIO_Speed_VH = 0x03
}GPIOOSPEEDR_TypeDef;

typedef enum
{
  GPIO_PULL_NO = 0x00,
  GPIO_PULL_UP = 0x01,
  GPIO_PULL_DOWN = 0x02
}GPIOPUPDR_TypeDef;


typedef struct
{
  uint16_t             GPIO_PIN;
  GPIOMODER_TypeDef    GPIO_Mode;
  GPIOPUPDR_TypeDef    GPIO_PuPd;
  GPIOOSPEEDR_TypeDef  GPIO_Speed;
  GPIOOTYPER_TypeDef   GPIO_OType;
}GPIO_InitTypeDef;

void GPIO_SetBits(GPIO_typedef *GPIOx, uint16_t GPIO_Pin);
void GPIO_ClearBits(GPIO_typedef *GPIOx, uint16_t GPIO_Pin);
void GPIO_Init(GPIO_typedef *GPIOx, GPIO_InitTypeDef *GPIO_InitStruct);
uint8_t GPIO_ReadBits(GPIO_typedef *GPIOx, uint16_t GPIO_Pin);
#endif
