#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#define LED_PIN 22
#define PUSH_BUTTON_PIN 19
#define ON 1
#define OFF 0
#include "main.h"
#include "blink_fn.h"

void app_main(void)
{
  	gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);   
    gpio_set_direction(PUSH_BUTTON_PIN, GPIO_MODE_INPUT);
    int val=0;
	while(1)
	{
		if(gpio_get_level(PUSH_BUTTON_PIN)==ON && val==0)
		{
			val=1;
			vTaskDelay(pdMS_TO_TICKS(300));									// Keep the button press duration within 300ms or change the value accordingly.
		}
		else if (gpio_get_level(PUSH_BUTTON_PIN) == ON && val==1)
		{
			val=0;
			vTaskDelay(pdMS_TO_TICKS(300));									// Keep the button press duration within 300ms or change the value accordingly.
		}
		while(val==1)
		{
			if(gpio_get_level(PUSH_BUTTON_PIN)==ON && val==0)
			{
				val=1;
				vTaskDelay(pdMS_TO_TICKS(300));								// Keep the button press duration within 300ms or change the value accordingly.
			}
			else if (gpio_get_level(PUSH_BUTTON_PIN) == ON && val==1)
			{
				val=0;
				vTaskDelay(pdMS_TO_TICKS(300));								// Keep the button press duration within 300ms or change the value accordingly.
			}
			gpio_set_level(LED_PIN, ON);
			vTaskDelay(pdMS_TO_TICKS(100));									// The LED will stay ON for 100ms. Change this value accordingly.
			gpio_set_level(LED_PIN, OFF);
			vTaskDelay(pdMS_TO_TICKS(100));									// The LED will stay OFF for 100ms. Change this value accordingly.
		}
	}
}