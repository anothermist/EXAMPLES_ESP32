#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "sdkconfig.h"

void app_main(void)
{
	int led_gpio = CONFIG_BLINK_GPIO;
	int button_gpio = CONFIG_BUTTON_GPIO;
	gpio_reset_pin(led_gpio);
	gpio_reset_pin(button_gpio);
	gpio_set_direction(led_gpio, GPIO_MODE_OUTPUT);
	gpio_set_direction(button_gpio, GPIO_MODE_INPUT);
	gpio_set_pull_mode(button_gpio, GPIO_PULLUP_ONLY);
	while (1) {
		if(gpio_get_level(button_gpio)) gpio_set_level(led_gpio, 0);
		else gpio_set_level(led_gpio, 1);
		vTaskDelay(10 / portTICK_PERIOD_MS);
	}
}
