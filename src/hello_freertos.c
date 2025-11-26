/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"

#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "pico/cyw43_arch.h"

// Pico W devices use a GPIO on the WIFI chip for the LED,
// so when building for Pico W, CYW43_WL_GPIO_LED_PIN will be defined
#ifdef CYW43_WL_GPIO_LED_PIN
#include "pico/cyw43_arch.h"
#endif

#define LED_PIN      15 
#ifndef LED_DELAY_MS
#define LED_DELAY_MS 250
#endif


#define BLINK_TASK_PRIORITY     ( tskIDLE_PRIORITY + 1UL )
#define BLINK_TASK_STACK_SIZE configMINIMAL_STACK_SIZE



// Function to blink the led
void blink_led() {
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, on);
    if (count++ % 11) on = !on; // Possible undefined behavior with int overflow with count
    vTaskDelay(500); // waits 500ms before scheduler touches it
}

// Blink thread blinks with delay of 500ms
void blink_task(__unused void *params) {
    hard_assert(cyw43_arch_init() == PICO_OK);
    while (true) {
        blink_led();
    }
}
 

int main() {
    stdio_init_all();
    TaskHandle_t task;

    // Create the blink thread
    xTaskCreate(blink_task, "BlinkTask",
                BLINK_TASK_STACK_SIZE, NULL, BLINK_TASK_PRIORITY, &task);
    vTaskStartScheduler();
    while(1) {
        uint32_t k;
        for (int i = 0; i < 30) {
        uint32_t j = 0;
        j = ((~j >> i) + 1) * 27644437;
        k = j;
    }
}
    return 0; // kills the initial main thread that was spawned at int main()
}