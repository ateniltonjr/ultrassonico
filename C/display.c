#include "H/display.h"
#include <stdio.h>
#include "pico/stdlib.h"
#include "H/font.h"
#include "hardware/i2c.h"

ssd1306_t ssd;  // Estrutura global para controle do display
bool cor = true; // Variável global para cor do texto

// Inicializa o I2C e o display OLED SSD1306
void display_init(void) {
    i2c_init(I2C_PORT, 400 * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    ssd1306_init(&ssd, WIDTH, HEIGHT, true, ENDERECO, I2C_PORT);
    ssd1306_config(&ssd);
    ssd1306_fill(&ssd, false); // Limpa o display (fundo preto)
    ssd1306_send_data(&ssd);
}

void escrever(ssd1306_t *display, const char *texto, uint8_t x, uint8_t y, bool cor) {
    ssd1306_draw_string(display, texto, x, y);
    ssd1306_send_data(display);
}