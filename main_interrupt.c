#include "main.h"

void TIM2_IRQHandler(void)
{


	 if (((TIM2->SR&TIM_SR_UIF)==1))
	  {

		 //uint32_t odr = READ_REG(GPIOA->ODR);
		 //WRITE_REG(GPIOA->BSRR, ((odr &  GPIO_BSRR_BS5) << 16u) | (~odr & GPIO_BSRR_BS5));
		  GPIOA->ODR^=GPIO_ODR_OD5;
		  TIM2->SR=0;

	  }


}

int main(void)
{

		RCC->CR|=RCC_CR_MSION;

		/*TIMER2*/
		RCC->APB1ENR1|=RCC_APB1ENR1_TIM2EN;
		RCC->AHB2ENR|=RCC_AHB2ENR_GPIOAEN;
		//TIM2->PSC=0xFFFF;
		TIM2->DIER|=TIM_DIER_UIE;

		TIM2->ARR=0x7A11FF;
		TIM2->CR1|=TIM_CR1_ARPE|TIM_CR1_CEN;

		GPIOA->MODER&=~GPIO_MODER_MODER5_1;

		//GPIOA->AFR[0]=0;
		NVIC_SetPriorityGrouping(0);
		NVIC_SetPriority(TIM2_IRQn, 0);

		NVIC_EnableIRQ(TIM2_IRQn);

  while (1)
  {
	  


  }

}
