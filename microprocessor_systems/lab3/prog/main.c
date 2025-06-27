//0x40000000, 0x400FFFFF
#include "stm32f4xx.h"

int state = 0;

void EXTI15_10_IRQHandler(void) {
	EXTI->PR |= EXTI_PR_PR13; 
	if (state == 0){	
	state = 1;
	} else {
		state = 0;
	} 
}

inline static void set_rcc(void){
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN; 
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; 
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
}

inline static void set_led(void){
	GPIOC->MODER |= GPIO_MODER_MODER0_0; 
	GPIOC->MODER |= GPIO_MODER_MODER1_0;
	GPIOC->MODER |= GPIO_MODER_MODER2_0;
	GPIOC->MODER |= GPIO_MODER_MODER3_0;
	GPIOC->MODER |= GPIO_MODER_MODER4_0;	
	GPIOC->MODER |= GPIO_MODER_MODER5_0;
}

inline static void init_proj(void){
	GPIOC->PUPDR |= GPIO_PUPDR_PUPD13_0;
	SYSCFG->EXTICR[3] |= SYSCFG_EXTICR4_EXTI13_PC;
	//unmask
	EXTI->IMR |= EXTI_IMR_MR13; 
	//set C13 interrupt to front
	EXTI->RTSR |= EXTI_RTSR_TR13; 
	NVIC_EnableIRQ(EXTI15_10_IRQn);
	__enable_irq();
}

void func(void){
	if (state == 0){
			// off LED
			GPIOC->ODR &= ~GPIO_ODR_OD0 & ~GPIO_ODR_OD1 & ~GPIO_ODR_OD2 & ~GPIO_ODR_OD3 & ~GPIO_ODR_OD4 & ~GPIO_ODR_OD5;
			for (int i = 0; i < 6; i++){
				GPIOC->ODR = 0x1UL << i;
				for (int j = 0; j < 50000; j++);
			}
			if ((GPIOC->IDR & GPIO_IDR_ID13) == 0) {
				GPIOC->ODR |= GPIO_ODR_OD5;
			} else {
				GPIOC->ODR &= ~GPIO_ODR_OD5;
			}
		} else {
			// off LED
			GPIOC->ODR &= ~GPIO_ODR_OD0 & ~GPIO_ODR_OD1 & ~GPIO_ODR_OD2 & ~GPIO_ODR_OD3 & ~GPIO_ODR_OD4 & ~GPIO_ODR_OD5;
			// switch LED
			GPIOC->ODR |= GPIO_ODR_OD1 | GPIO_ODR_OD3 | GPIO_ODR_OD4;
	}
}

int main(void) {

	set_rcc();
	set_led();
	init_proj();

	while (1) {
		func();
	}
}