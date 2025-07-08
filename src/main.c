#include <stdio.h>
#include "pico/stdlib.h"
#include "bh1750/bh1750.h"
#include "servo/servo.h"

// Função para mapear lux para ângulo do servo
static uint map_lux_to_angle(float lux) {
    if (lux < 0) lux = 0;
    if (lux > 1000) lux = 1000;
    return (uint)(lux * 180.0 / 1000.0);
}

int main()
{
    stdio_init_all();
    sleep_ms(1000);
    printf("Sistema de Monitoramento LUX + Servo Motor\n");
    sleep_ms(500);
    printf("[MAIN] Iniciando...\n");
    // Inicializar sensor bht1750
    i2c_inst_t *i2c = bh1750_init(i2c0);
    bh1750_init(i2c0);
    sleep_ms(200);
    
    servo_init();
    float lux;

    while (true) {
        bh1750_read_lux(i2c, &lux);
        printf("[MAIN] Luminosidade: %.2f lux\n", lux);

        // Aqui você pode adicionar o código para controlar o servo motor com base no valor de lux
        uint angle = map_lux_to_angle(lux);
        servo_set_angle(angle);
        printf("[MAIN] Servo ajustado para %u graus\n", angle);
        
        sleep_ms(250); // Atualizar a cada 1/4 de segundo
    }
}

