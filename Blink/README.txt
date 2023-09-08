The code for the blinking of the LED is given inside components\blink.c

Change the GPIO pin numbers from the components\blink.h header file according to the pin number you have connected the LED to.

If you want to change the blink duration, use the menuconfig. Alternatively, use BLINK_ON_TIME instead of CONFIG_BLINK_ON_TIME in the blink.c file and same for BLINK_ON_TIME.

