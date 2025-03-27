#ifndef LED_BUZZER_H
#define LED_BUZZER_H

#include <stdbool.h>
#include "pico/stdlib.h"

//Leds e buzzer:
#define red 13
#define green 11
#define blue 12
#define buzzer 21

void iniciar_led();
void state(bool r, bool g, bool b);

#endif