#include "H/led_buzzer.h"

void iniciar_led() {
  gpio_init(red);
  gpio_set_dir(red, GPIO_OUT);

  gpio_init(green);
  gpio_set_dir(green, GPIO_OUT);

  gpio_init(blue);
  gpio_set_dir(blue, GPIO_OUT);

  gpio_init(buzzer);
  gpio_set_dir(buzzer, GPIO_OUT);
}

  void state(bool r, bool g, bool b) {
    gpio_put(red, r);
    gpio_put(green, g);
    gpio_put(blue, b);
  }