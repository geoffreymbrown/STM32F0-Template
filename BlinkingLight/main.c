#include <stm32f0xx.h>
#include <stm32f0xx_rcc.h>
#include <stm32f0xx_gpio.h>

void delay(void);

int main(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;
  int n = 0;

  // Initialize GPIO clock  
  // see stm32f0xx_rcc.h

  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);

  // Initialize LED pins
  // see stm32f0xx_gpio.h

  GPIO_StructInit(&GPIO_InitStructure);

  // Pin PC9

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  // Pin PC8

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  while(1)
  {
    n++;
    delay();

    GPIO_WriteBit(GPIOC, GPIO_Pin_8, (n&1) ? Bit_SET : Bit_RESET);
    GPIO_WriteBit(GPIOC, GPIO_Pin_9, (n&4) ? Bit_SET : Bit_RESET);
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

