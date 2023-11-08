
# Blink: Os primeiros passos com o Arduino
![circuito](https://github.com/matzsis/Arduino/assets/148489229/4ce3f7fd-e92d-4457-9e27-f1451783db9d)

Este é um guia introdutório para aprender sobre o conceito de "Blink" e como começar a programar o Arduino para controlar LEDs. O Blink é o ato de ligar e desligar um LED em um determinado período de tempo e é um exemplo clássico para iniciantes que desejam entrar no mundo dos microcontroladores com o Arduino.

## Introdução

O Arduino é um microcontrolador programável usado para processar entradas e saídas entre o dispositivo e os componentes eletrônicos externos conectados a ele, como LEDs, botões e sensores. Este guia se concentra em entender o conceito do Blink, suas aplicações e como realizá-lo.

## Por que o Blink é importante?

O Blink é uma ferramenta fundamental para aprender códigos simples, sendo o equivalente ao "Hello World" dos microcontroladores. Ele fornece uma base sólida para entender a linguagem de programação e o funcionamento do Arduino. Além disso, o Blink tem várias aplicações práticas, como sinalização de luz em semáforos e indicadores de status.

## Materiais Necessários

- Arduino UNO
- Protoboard (pode ser de qualquer tamanho)
- 1 LED
- 3 Jumpers macho-macho
- Cabo de alimentação do Arduino
- Resistor

## Funcionamento do Circuito

Para que um circuito funcione corretamente, é importante entender como a energia flui. O texto explica as portas digitais do Arduino, o uso de resistores para proteger o LED e a conexão ao "fio terra" (GND).

## Código do Blink

O código para o Blink é apresentado e explicado em detalhes, incluindo a definição da variável LED, a configuração das portas digitais no setup() e a criação do loop() que aciona o LED em intervalos regulares.

```cpp
#define LED 3

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
  delay(1000);
}
