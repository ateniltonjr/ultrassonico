#include "H/sensor_ultrassonico.h"

void init_hcsr04() {
    gpio_init(TRIG_PIN);
    gpio_set_dir(TRIG_PIN, GPIO_OUT);
    gpio_init(ECHO_PIN);
    gpio_set_dir(ECHO_PIN, GPIO_IN);
}

float get_distance() {
    // Envia pulso de trigger
    gpio_put(TRIG_PIN, 0);
    sleep_us(2);
    gpio_put(TRIG_PIN, 1);
    sleep_us(10);
    gpio_put(TRIG_PIN, 0);

    // Espera pelo início do echo
    uint64_t start_time = time_us_64();
    while (gpio_get(ECHO_PIN) == 0) {
        if (time_us_64() - start_time > TIMEOUT) {
            return -1; // Timeout
        }
    }
    start_time = time_us_64();

    // Espera pelo fim do echo
    while (gpio_get(ECHO_PIN)) {
        if (time_us_64() - start_time > TIMEOUT) {
            return -1; // Timeout
        }
    }
    uint64_t end_time = time_us_64();

    // Calcula a distância em cm (velocidade do som = 343 m/s = 0.0343 cm/us)
    return (float)(end_time - start_time) * 0.0343 / 2;
}