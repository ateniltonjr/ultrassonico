#include "H/exibicao.h"

// Função para ler e exibir a leitura do sensor ultrassônico
void ler_exibir() {
  float distance = get_distance();
  char distance_str[20];

  if (distance < 0) {
      printf("Erro na medição ou timeout\n");
      ssd1306_fill(&ssd, false); // Limpa o display
      escrever(&ssd, "Erro", 52, 10, cor);
      escrever(&ssd, "na", 60, 25, cor);
      escrever(&ssd, "Medicao", 36, 40, cor);
  } else {
      if(distance < 15) {
          gpio_put(buzzer, 1);
          state(1,0,0);
          printf("Distância: %.2f cm\n", distance);
          snprintf(distance_str, sizeof(distance_str), "Dist: %.0f cm", distance);
          ssd1306_fill(&ssd, false);
          escrever(&ssd, distance_str, 2, 10, cor);
          escrever(&ssd, "vai", 57, 25, cor);
          escrever(&ssd, "bater", 46, 40, cor);
      }
      else if(distance > 15 && distance < 50) {
          state(1,1,0);
          printf("Distância: %.2f cm\n", distance);
          snprintf(distance_str, sizeof(distance_str), "Dist: %.0f cm", distance);
          ssd1306_fill(&ssd, false);
          escrever(&ssd, distance_str, 2, 10, cor);
          escrever(&ssd, "Tenha", 50, 25, cor);
          escrever(&ssd, "Atencao", 40, 40, cor);
      }
      else if(distance > 50 && distance < 100) {
          state(0,0,1);
          printf("Distância: %.2f cm\n", distance);
          snprintf(distance_str, sizeof(distance_str), "Dist: %.0f cm", distance);
          ssd1306_fill(&ssd, false);
          escrever(&ssd, distance_str, 2, 10, cor);
          escrever(&ssd, "Tudo", 46, 25, cor);
          escrever(&ssd, "tranquilo", 28, 40, cor);
      }
      else {
          state(0,1,0);
          printf("Distância: %.2f cm\n", distance);
          snprintf(distance_str, sizeof(distance_str), "Dist: %.0f cm", distance);
          ssd1306_fill(&ssd, false);
          escrever(&ssd, distance_str, 2, 10, cor);
          escrever(&ssd, "Distancia", 32, 25, cor);
          escrever(&ssd, "Segura", 42, 40, cor);
      }
  }
}