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


#define LED_PIN 17

#define BLINK_TASK_PRIORITY     ( tskIDLE_PRIORITY + 1UL )
#define BLINK_TASK_STACK_SIZE configMINIMAL_STACK_SIZE

int on;

// Blink thread blinks with delay of 100ms
void blink_task(__unused void *params) {
    while (true) {
        gpio_put(LED_PIN, on);
        sleep_ms(100);
        on = !on;
    }
}

int main() {
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN, 0);
    TaskHandle_t task;

    // Create the blink thread
    xTaskCreate(blink_task, "BlinkTask",
                BLINK_TASK_STACK_SIZE, NULL, BLINK_TASK_PRIORITY, &task);
    vTaskStartScheduler();
    // while(1) {
    //     uint32_t k;
    //     for (int i = 0; i < 30) {
    //     uint32_t j = 0;
    //     j = ((~j >> i) + 1) * 27644437;
    //     k = j;
    // }
    return 0; // kills the initial main thread that was spawned at int main()
}