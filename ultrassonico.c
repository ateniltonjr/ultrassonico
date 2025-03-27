#include "H/exibicao.h"

int main() {
    stdio_init_all();
    iniciar_led();
    init_hcsr04();
    display_init();

    while (true) {
        ler_exibir();
        sleep_ms(500); // Espera 500ms entre medições
    }

    return 0;
}