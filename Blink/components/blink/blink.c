#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "rom/gpio.h"
#include "sdkconfig.h"

#include "blink.h"
#include "blink_fn.h"

void blink_init_gpio(void) {
  gpio_pad_select_gpio(BLINK_GPIO);
  gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
  gpio_pulldown_en(BLINK_GPIO);
  gpio_set_level(BLINK_GPIO, LOW);
}

void blink_start_blink(void *_) {
  while(1) {
    gpio_set_level(BLINK_GPIO, HIGH);
    vTaskDelay(pdMS_TO_TICKS(CONFIG_BLINK_ON_TIME));      // Change the value 'CONFIG_BLINK_ON_TIME' according to the time you want the LED to be ON or remove 'CONFIG_' to use the time given in header file.
    gpio_set_level(BLINK_GPIO, LOW);
    vTaskDelay(pdMS_TO_TICKS(CONFIG_BLINK_OFF_TIME));     // Change the value 'CONFIG_BLINK_OFF_TIME' according to the time you want the LED to be OFF or remove 'CONFIG_' to use the time given in header file.
  }
}