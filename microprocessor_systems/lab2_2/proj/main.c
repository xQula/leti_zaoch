#include "stm32f4xx.h"  // Include STM32F4 device header

// Function to initialize GPIO settings
static inline void Setup(void)
{
    // Enable clock for GPIOA and GPIOC
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; // Enable GPIOA peripheral clock
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN; // Enable GPIOC peripheral clock

    // Configure PC13 as input (button)
    GPIOC->MODER &= ~GPIO_MODER_MODE13_0; // Clear mode bit 0 for PC13
    GPIOC->MODER &= ~GPIO_MODER_MODE13_1; // Clear mode bit 1 for PC13 (input mode: 00)
    GPIOC->PUPDR |= 0x400;                // Enable pull-up resistor for PC13 (bits 27:26 = 01)

    // Configure PA5 as output (LED)
    GPIOA->MODER |= GPIO_MODER_MODER5_0;  // Set mode bit 0 for PA5 (output mode: 01)
    GPIOA->MODER &= ~GPIO_MODER_MODER5_1; // Clear mode bit 1 for PA5
}

// Function to turn off the LED
static inline void led_off(void)
{
    GPIOA->ODR = 0;  // Clear all output data bits for GPIOA (turn off all LEDs on port A)
}

int main(void)
{
    Setup();  // Initialize GPIOs

    while(1)  // Infinite loop to control the LED
    {
        // Check if the button (PC13) is pressed
        if ((GPIOC->IDR & GPIO_IDR_IDR_13) == 0)
        {   
            GPIOA->ODR = (1 << 5);  // Turn on LED connected to PA5
        } 
        else // If button is released
        {
            led_off();   // Turn off the LED
        }
    }
}
