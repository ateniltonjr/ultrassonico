#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>
#include <stdbool.h>
#include "H/ssd1306.h"

// Definições dos pinos para comunicação I2C
#define I2C_PORT i2c1         // Porta I2C utilizada
#define I2C_SDA 14            // Pino para SDA (Serial Data Line)
#define I2C_SCL 15            // Pino para SCL (Serial Clock Line)
#define ENDERECO 0x3C         // Endereço I2C do display SSD1306

extern ssd1306_t ssd;  // Estrutura global para controle do display
extern bool cor;       // Variável global para cor do texto

// Inicializa o display OLED SSD1306
void display_init(void);

// Escreve texto no display
void escrever(ssd1306_t *display, const char *texto, uint8_t x, uint8_t y, bool cor);

#endif // DISPLAY_H