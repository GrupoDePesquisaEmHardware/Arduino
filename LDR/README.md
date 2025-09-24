# Repositório do Sensor LDR - Fotoresistor

## Introdução

   Você já ouviu falar sobre o sensor LDR? O sensor “Resistor Dependente de Luz” ("Light Dependent Resistor"), mais conhecido por sua sigla LDR, é um sensor que mede a intensidade da luz. Nós podemos encontrar esse tipo de sensor em poste de energia, por exemplo, que acende quando percebe a ausência de luz solar.

![LDR](https://i.pinimg.com/564x/cc/73/8f/cc738f4ab7ee4489361d7685118690b4.jpg)

O sensor LDR é feito de um material semicondutor,ou seja, material que possui características de condução elétrica intermediárias entre materiais condutores (como metais) e isolantes, normalmente, sulfeto de cádmio (CdS), que tem a  propriedade de variar sua resistência de acordo com a intensidade de luz que incide sobre ele. Assim, quanto mais luz incide sobre o LDR menor sua resistência e maior a quantidade de corrente é permitido passar para o circuito. Desse modo, como um resistor comum, o mesmo não possui polaridade (lado positivo ou negativo definidos) e sua resistência é medida em ohms(Ω).

![Fluxo de Corrente](https://www.kitsarduino.com.br/imagens/ldr-arduino-pg2.png)

## Entendendo o LDR a nível atômico
Para entender melhor essa parte, primeiro temos que entender alguns conceitos químicos:                                                                            
									
Elétron: é a partícula subatômica de carga negativa que se encontra na parte externa do átomo (eletrosfera).

Camada de valência: é a camada mais afastada do núcleo e que apresenta um nível de energia mais baixo.
Camada de condução: é a região que fica os 	elétrons livres e que apresenta um nível de energia mais alto.

Agora sim, podemos começar!

A luz é formada por fótons, partículas que transportam energia, ao atingir o sensor LDR esses fótons são absorvidos pelos elétrons do sulfeto de cádmio que estão na camada de valência, com isso os elétrons ficam excitados (com energia necessária para sair da camada de valência) e vão para a camada de condução, onde conseguem se mover livremente, o que permite uma maior condução de energia. Portanto, quanto mais luz atingir o sensor mais elétrons vão mudar de camada e menor será sua resistência.

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
