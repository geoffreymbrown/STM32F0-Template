#include <stm32f0xx.h>
#include <stm32f0xx_rcc.h>
#include <stm32f0xx_gpio.h>

void delay(void);

int main(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;
  int n = 0;
  int button;

  // Initialize GPIO clock  
  // see stm32f0xx_rcc.h

  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC|RCC_AHBPeriph_GPIOA, ENABLE);

  // Initialize LD3 Pin
  // see stm32f0xx_gpio.h

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  /* main while      */

  while(1)
  {
    delay();
    button = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0);
    n++;
    GPIO_WriteBit(GPIOC, GPIO_Pin_8, n & 1 ? Bit_SET : Bit_RESET);
    GPIO_WriteBit(GPIOC, GPIO_Pin_9, (n&4) && button ? Bit_SET : Bit_RESET);
  }
}

void delay(void) 
{
  int i = 200000;/* About 1/4 second delay */
  while (i-- > 0) {
    asm("nop");/* This stops it optimising code out */
  }
}

/*
 * Debug help -- if asserts are enabled, assertion failure
 * from standard peripheral  library ends up here 
 */


#ifdef  USE_FULL_ASSERT
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* Infinite loop */
  /* Use GDB to find out why we're here */
  while (1)
  {
  }
}
#endif

