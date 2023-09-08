#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#define LED_PIN 22
#define PUSH_BUTTON_PIN 19
#define ON 1
#define OFF 0
#include "main.h"
#include "blink_fn.h"

void app_main(void) {
	gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);   
	gpio_set_direction(PUSH_BUTTON_PIN, GPIO_MODE_INPUT);

    while(1) {       
        if (gpio_get_level(PUSH_BUTTON_PIN) == ON)
        {  
            gpio_set_level(LED_PIN, ON);        
        } 
        else
        {
            gpio_set_level(LED_PIN, OFF);        
        }

        vTaskDelay(1);
    }
}