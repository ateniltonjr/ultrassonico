#ifndef SENSOR_ULTRASSONICO_H
#define SENSOR_ULTRASSONICO_H

#include "pico/stdlib.h"

#define TRIG_PIN 9
#define ECHO_PIN 8
#define TIMEOUT 30000

void init_hcsr04();
float get_distance();

#endif