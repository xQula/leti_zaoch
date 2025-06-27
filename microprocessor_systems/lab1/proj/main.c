#include "stm32f4xx.h"  // Include header for STM32F4 device definitions

// A5 - diode (LED connected to pin PA5)

int main(void)
{
    // Enable clock for GPIOA port
    RCC->AHB1ENR = RCC->AHB1ENR | 0x00000001;  // Set bit 0 (GPIOAEN) in RCC_AHB1ENR register
    
    // Configure PA5 as a general purpose output
    GPIOA->MODER = GPIOA->MODER | GPIO_MODER_MODER5_0;  // Set MODER5[1:0] = 01 (output mode)

    while(1)  // Infinite loop
    {
        // Turn on the LED (set ODR5 bit)
        GPIOA->ODR = GPIOA->ODR | GPIO_ODR_ODR_5;  // Set bit 5 to 1
        
        // Simple delay (busy-wait loop)
        for(int i = 0; i < 100000; i++);
        
        // Turn off the LED (clear ODR5 bit)
        GPIOA->ODR = GPIOA->ODR & ~GPIO_ODR_ODR_5;  // Set bit 5 to 0
        
        // Simple delay (busy-wait loop)
        for(int i = 0; i < 100000; i++);
    }
}