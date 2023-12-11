# Servo Motor SG90 9G: Robótica Dinâmica
![Captura de tela 2023-11-18 193417](https://github.com/siriacfreitas/Arduino/assets/123579270/7c0e2611-b9b0-41d0-93e0-06e3ad6367b3)

## Visão Geral

Este README fornece informações sobre o servo motor SG90 9g, um componente crucial na robótica dinâmica. O servo motor converte energia elétrica em movimento mecânico preciso, sendo aplicável em projetos como garras robóticas e aeromodelismo.

## Funcionamento do Servo Motor

- Deslocamento controlado por ângulos predefinidos através de código.
- Componentes: potenciômetro, circuito de controle, sistema de engrenagens e trava de segurança.

## PWM (Pulse Width Modulation)

- A posição do servo é determinada por um sinal elétrico PWM.
- Largura de pulso varia de 1 a 2 milissegundos.
- O sinal PWM define o ângulo de rotação do servo.

## Controle com Arduino

- Utilização de portas digitais do Arduino (marcadas com "~") para controlar o servo.
- Materiais necessários: Arduino UNO, Micro Servo Motor SG90 9g, 3 Jumpers, Cabo de alimentação do Arduino.

## Montagem do Circuito

1. Conexão VCC do servo ao pino 5V do Arduino.
2. Conexão GND do servo ao pino GND do Arduino.
3. Conexão do sinal (amarelo) do servo a um pino digital PWM do Arduino.

## Código de Controle

```cpp
#include <Servo.h>

#define PINO_SERVO 9
#define TEMPO_GIRO 30
int pos;
Servo meu_servo;

void setup() {
   meu_servo.attach(PINO_SERVO);
}

void loop() {
   for (pos = 0; pos <= 180; ++pos) {
      meu_servo.write(pos);
      delay(TEMPO_GIRO);
   }
   for (pos = 180; pos >= 0; --pos) {
      meu_servo.write(pos);
      delay(TEMPO_GIRO);
   }
}
```
## Contribuidores
- [Síria Cabral](https://github.com/siriacfreitas)
- [Lisandry Azuaje](https://github.com/lisandry)
