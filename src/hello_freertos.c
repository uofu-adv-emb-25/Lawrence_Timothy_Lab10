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
#define SIG_IN_PIN 14

static volatile bool led_state = false;

void irq_callback(uint gpio, uint32_t event_mask)
{
     if (gpio == SIG_IN_PIN && (events & GPIO_IRQ_EDGE_RISE)) {
        led_state = !led_state;
        gpio_put(LED_PIN, led_state);
     }
}

int main() {
    stdio_init_all();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN, 0);

    gpio_init(SIG_IN_PIN);
    gpio_set_dir(SIG_IN_PIN, GPIO_IN);
    
    gpio_set_irq_enabled_with_callback(SIG_IN_PIN, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL , true, irq_callback);
    while(1) __wfi();
    return 0;
}x