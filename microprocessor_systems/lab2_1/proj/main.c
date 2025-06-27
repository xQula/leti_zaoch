#include "stm32f4xx.h"  // Include STM32F4 device header
// Variant 3
// GPIO initialization function
void initGPIO(void) {
    // Enable clock for GPIOB
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;  // Set GPIOBEN bit to enable peripheral clock
    
    // Configure PB0-PB7 as general purpose outputs
    GPIOB->MODER &= ~(  // Clear mode bits for pins 0-7
        GPIO_MODER_MODER0 | GPIO_MODER_MODER1 | GPIO_MODER_MODER2 | GPIO_MODER_MODER3 |
        GPIO_MODER_MODER4 | GPIO_MODER_MODER5 | GPIO_MODER_MODER6 | GPIO_MODER_MODER7
    );
    GPIOB->MODER |= (  // Set mode to output (01) for pins 0-7
        GPIO_MODER_MODER0_0 | GPIO_MODER_MODER1_0 | GPIO_MODER_MODER2_0 | GPIO_MODER_MODER3_0 |
        GPIO_MODER_MODER4_0 | GPIO_MODER_MODER5_0 | GPIO_MODER_MODER6_0 | GPIO_MODER_MODER7_0
    );
}

// Running light effect implementation
void runningLight(void) {
    // LED patterns for running light effect
    uint8_t led_pattern[4] = {
        0b10000001,  // Outer LEDs on
        0b01000010,  // Next inner pair
        0b00100100,  // Middle pairs
        0b00011000   // Center LEDs
    };

    while (1) {  // Infinite animation loop
        for (int i = 0; i < 4; i++) {
            GPIOB->ODR = led_pattern[i];  // Output current pattern to PORTB
            for (int j = 0; j < 100000; j++);  // Busy-wait delay (rename inner variable)
        }
    }
}

int main(void) {
    SystemInit();  // Initialize system core clock
    initGPIO();    // Configure GPIO pins

    while (1) {    // Main loop
        runningLight();  // Start LED animation
    }
}
