
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "main.h"
#include "blink_fn.h"

void app_main(void) {
  blink_init_gpio();
  xTaskCreate(blink_start_blink, "blink_start_blink", 2048, NULL, 5, NULL);

  while(1) {
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}