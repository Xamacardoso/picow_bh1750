# 🌞 Sistema de Monitoramento de Luminosidade (BH1750) + Controle de Servo Motor

Este projeto implementa um sistema de monitoramento de luminosidade utilizando o sensor BH1750 e um servo motor SG90, rodando em um Raspberry Pi Pico (RP2040). O sistema lê a luminosidade ambiente e ajusta o ângulo do servo motor proporcionalmente ao valor de lux medido.

## 🛠️ Funcionalidades
- Leitura de luminosidade (lux) com sensor BH1750 via I2C
- Controle de servo motor SG90 via PWM
- Mapeamento automático do valor de lux para ângulo do servo (0° a 180°)
- Mensagens de status e leitura exibidas no terminal serial

## 📁 Estrutura do Projeto
- `src/main.c`: Código principal do sistema
- `src/drivers/bh1750/bh1750.h` e `.c`: Interface e implementação do sensor BH1750
- `src/drivers/servo/servo.h` e `.c`: Interface e implementação do controle do servo motor

## 🔗 Dependências
- [Pico SDK](https://github.com/raspberrypi/pico-sdk)
- Sensor BH1750 (I2C)
- Servo motor SG90 (PWM)

## 💻 Como compilar e executar

### ✅ Pré-requisitos
- Raspberry Pi Pico (RP2040)
- Sensor BH1750 conectado via I2C (I2C1)
- Servo motor SG90 conectado a um pino PWM do Pico (Expansão I2C0)
- Ambiente de desenvolvimento C/C++ para Pico (Pico SDK)

### 📋 Passos
1. **Clone o repositório e configure o Pico SDK:**
   ```sh
   git clone <este-repo>
   cd u3-i1-bh1750
   mkdir build && cd build
   cmake ..
   make
   ```
2. **Grave o arquivo `.uf2` gerado na Pico:**
   - Conecte a Pico em modo BOOTSEL
   - Copie o arquivo `.uf2` para a unidade USB que aparecer

3. **Conecte o hardware:**
   - Sensor BH1750 nos pinos I2C do Pico (I2C 0)
   - Servo motor SG90 em um pino PWM (verifique o pino definido em `servo.h`)

4. **Execute:**
   - O sistema iniciará automaticamente, exibindo as leituras de luminosidade e o ângulo do servo no terminal serial.

## 🔎 Observações
- Certifique-se de que o sensor BH1750 e o servo estejam corretamente conectados e alimentados.
- O mapeamento de lux para ângulo pode ser ajustado na função `map_lux_to_angle` em `main.c`.
