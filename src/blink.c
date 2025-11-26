#include <stdio.h>
#include <FreeRTOS.h>
#include <semphr.h>
#include <task.h>
#include <pico/stdlib.h>
#include <pico/multicore.h>
#include <pico/cyw43_arch.h>
#define LED_PIN 17


int on;

int main(){
    stdio_init_all();
    gpio_init(LED_PIN);
    
    // 3. Set the GPIO Pin to be an output
    gpio_set_dir(LED_PIN, GPIO_OUT);

    if (cyw43_arch_init() != PICO_OK) {
        printf("Wi-Fi init failed\n");
        return 1;
    }
    int on = 0; // Initialize the state
while(1){
    gpio_put(LED_PIN, on);
    sleep_ms(100);
    on = !on;
}
return 0;
}