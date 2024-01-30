# Repositório do Sensor LDR - Fotoresistor

## Introdução
Você já ouviu falar sobre o sensor LDR? O sensor "Resistor Dependente de Luz" (LDR), conhecido por sua sigla em inglês, é um dispositivo que mede a intensidade da luz. Ele é comumente encontrado em postes de energia, acendendo quando detecta a ausência de luz solar.

![LDR](https://i.pinimg.com/564x/cc/73/8f/cc738f4ab7ee4489361d7685118690b4.jpg)

O LDR é composto por um material semicondutor, geralmente sulfeto de cádmio (CdS), que varia sua resistência conforme a intensidade de luz incidente. Sua resistência diminui com a maior incidência de luz, permitindo uma maior corrente no circuito.

![Fluxo de Corrente](https://www.kitsarduino.com.br/imagens/ldr-arduino-pg2.png)

## Entendendo o LDR a nível atômico
Para compreender melhor o funcionamento, é necessário conhecer alguns conceitos químicos:

- Elétron: Partícula subatômica de carga negativa na eletrosfera.
- Camada de Valência: Camada mais afastada do núcleo com menor nível de energia.
- Camada de Condução: Região com elétrons livres e maior nível de energia.

A luz, composta por fótons, ao atingir o LDR, faz com que elétrons absorvam energia, movendo-se da camada de valência para a camada de condução. Isso resulta em uma menor resistência do LDR, permitindo maior condução de energia.

## Materiais Necessários
- Arduino UNO
- Protoboard
- 1 LED
- 8 Jumpers
- Cabo de alimentação do Arduino
- 2 Resistores (10kΩ e 1kΩ)

## Funcionamento do Circuito
1. Alimente a protoboard conectando a fileira negativa ao GND e a fileira positiva ao 5V do Arduino.

2. Conecte o LED: Cátodo (lado negativo) à fileira negativa com o resistor de 1kΩ. O ânodo (lado positivo) conectado à porta 4 do Arduino.

3. Para o LDR, conecte o resistor de 10kΩ em uma perna e a outra perna à fileira de alimentação positiva. Conecte o LDR à porta A2 com um jumper e conecte a outra perna do resistor à fileira de alimentação negativa.


>Observação: O LED acenderá na ausência de luz; para indicar a presença de luz, inverta as conexões das alimentações.

Este repositório fornece informações sobre o sensor LDR e um guia para montagem do circuito com Arduino. Experimente e explore as possibilidades deste sensor versátil!