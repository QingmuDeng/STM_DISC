#include "stm32f4xx_gpio.h"

void GPIO_SetBits(GPIO_typedef *GPIOx, uint16_t GPIO_Pin)
{
  GPIOx->BSRR_L |= GPIO_Pin;
}

void GPIO_ClearBits(GPIO_typedef *GPIOx, uint16_t GPIO_Pin)
{
  GPIOx->BSRR_H |= GPIO_Pin;
}

uint8_t GPIO_ReadBits(GPIO_typedef *GPIOx, uint16_t GPIO_Pin)
{
  return ((GPIOx->IDRL & GPIO_Pin) ? 1 : 0);
}

void GPIO_Init(GPIO_typedef *GPIOx, GPIO_InitTypeDef *GPIO_InitStruct)
{
  uint16_t pinpos = 0x00, pos = 0x00, currentpin = 0x00;

  for(pinpos=0x00; pinpos < 16; pinpos++)
  {
    pos = (1<<pinpos);
    currentpin = (GPIO_InitStruct->GPIO_PIN) & pos;

    if(currentpin == pos)
    {
      GPIOx->MODER |= (((uint32_t)GPIO_InitStruct->GPIO_Mode) << (2*pinpos));

      GPIOx->PURDR |= (((uint32_t)GPIO_InitStruct->GPIO_PuPd) << (2*pinpos));

      if ((GPIO_InitStruct->GPIO_Mode == GPIO_Mode_OUT) || (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_AF))
      {
        GPIOx->OTYPER |= (((uint32_t)GPIO_InitStruct->GPIO_OType) << (pinpos));

        GPIOx->OSPEEDR |= (((uint32_t)GPIO_InitStruct->GPIO_Speed) << (2*pinpos));
      }
    }
  }
}
