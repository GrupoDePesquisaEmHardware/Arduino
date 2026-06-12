# Jogo Genius
Que tal aprimorar suas habilidades makers enquanto se diverte jogando? Neste repositório você irá conhecer a história do famoso Jogo do Genius, enquanto utiliza componentes eletrônicos anteriormente citados em nossos repositórios para montar o seu próprio modelo.

## A história por trás do Genius
O Genius, um dos brinquedos eletrônicos mais populares da história, foi criado por Ralph H. Baer, popularmente conhecido por desenvolver o primeiro sistema de vídeo game, em parceria com Howard Morrison. A ideia surgiu quando os inventores conheceram um jogo de fliperama da Atari chamado Touch Me (Figura 1), que exibia uma sequência de luzes e sons que o jogador precisava repetir. Porém, apesar de considerarem uma ótima ideia, notaram que o jogo não tinha um visual atraente e emitia sons desagradáveis. Assim, Bear e Morrison decidiram criar uma nova versão portátil em torno desse mesmo princípio.

<div align="center">
<h3>Figura 1: Touch Me, Atari. </h3>	
<img width="415" height="569" alt="image" src="https://github.com/user-attachments/assets/cdc96c63-815d-4964-8df0-4a788204414a" />
<h4>Fonte: IMDb (2026).</h4>
</div>

Uma das preocupações era escolher sons agradáveis, e Bear encontrou a solução nas notas de uma corneta, que tocava somente quatro notas. Ademais, o programador Lenny Cope desenvolveu o software do aparelho, e seu nome, originalmente intitulado como “Follow Me”, foi substituído por Simon (em referência à brincadeira infantil “Simons Says”, “O mestre mandou” em português).

Lançado originalmente em 1978 pela empresa Milton Bradley, o jogo chegou às lojas brasileiras somente em 1980 pela Brinquedos Estrela, onde ganhou o nome de “Genius” e tornou-se o pioneiro nos jogos eletrônicos de massa. Com seu icônico formato de “ovni”, consiste em um disco com quatro botões coloridos (azul, amarelo, verde e vermelho) que acendem e emitem sons em sequência (Figura 2).

<div align="center">
<h3>Figura 2: Jogo Genius, da Brinquedos Estrela. </h3>	
<img width="770" height="569" alt="image" src="https://github.com/user-attachments/assets/644e6c51-f55a-446c-a2db-fae588d40ed4" />
<h4>Fonte: Amazon (2026).</h4>
</div>

## Materiais Necessários
- Placa Arduino Uno;
- Cabo de alimentação;
- Protoboard;
- Display LCD 16x2;
- Potenciômetro de 10 kΩ;
- Buzzer;
- 4 Leds (vermelho, azul, amarelo e verde);
- 2 Resistores de 220 Ω;
- 4 Resistores de 150 Ω;
- 4 Resistores de 10 kΩ;
- Jumpers.

## Funcionamento do Circuito

<div align="center">
<h3>Figura 3: Funcionamento do circuito. </h3>	
<img width="922" height="571" alt="image" src="https://github.com/user-attachments/assets/53573d61-189e-4ce3-bf4a-9a62c88623b3" />
<h4>Fonte: Autoria própria.</h4>
</div>

Para a montagem do circuito do jogo Genius com Arduino, começamos pela alimentação da protoboard. Utilizamos jumpers para conectar o pino 5V do Arduino aos barramentos positivos da protoboard e o pino GND aos barramentos negativos, distribuindo energia para todos os componentes do circuito.

O sistema possui um display LCD 16x2, responsável por exibir mensagens do jogo. O pino GND e VCC são conectados aos seus respectivos barramentos. O pino V0, que controla o contraste das letras, é ligado ao terminal central do potenciômetro. Os outros dois terminais do potenciômetro são conectados ao 5V e ao GND, permitindo ajustar a visibilidade do texto no display.

Os pinos de controle do display também são conectados ao Arduino. O pino RS é ligado a uma porta digital para selecionar entre comandos e caracteres. O pino RW é conectado diretamente ao GND, pois o display será utilizado apenas para escrita. Já o pino E (Enable) é ligado a outra porta digital do Arduino, sendo responsável por informar ao display quando os dados devem ser recebidos.

Para a transmissão das informações, o display opera no modo de 4 bits. Dessa forma, apenas os pinos D4, D5, D6 e D7 são utilizados, sendo conectados às portas digitais do Arduino através dos fios roxos observados no circuito. Os pinos do LED catódico e anodo, responsáveis pela iluminação de fundo do display, são ligados ao 5V (com um resistor de 220Ω) e ao GND, respectivamente.

O jogo utiliza quatro LEDs coloridos (vermelho, azul, amarelo e verde), que indicam a sequência que o jogador deve repetir. Cada LED é conectado a uma porta digital do Arduino e, através de um resistor de 150Ω, os terminais negativos dos LEDs são ligados ao GND.

Logo acima dos LEDs encontram-se quatro botões de pressão, utilizados para que o jogador reproduza a sequência apresentada. Cada botão é ligado a uma entrada digital do Arduino. Para garantir leituras estáveis, são utilizados resistores de pull-down (10 kΩ), mantendo o sinal em nível lógico baixo quando o botão não está pressionado.

O circuito também possui um buzzer piezoelétrico, responsável pela emissão dos sons característicos do jogo. Seu terminal positivo é ligado a uma porta digital do Arduino, através do resistor de 220Ω, o que permite a geração de diferentes frequências, enquanto o terminal negativo é conectado ao GND.

Com todas essas conexões realizadas, o Arduino passa a controlar os LEDs, ler os botões pressionados pelo jogador, emitir sons pelo buzzer e exibir informações no display LCD, formando o funcionamento completo do jogo Genius eletrônico.

## Código

Para executarmos corretamente o jogo Genius, precisamos compreender o funcionamento do código passo a passo. Primeiramente, incluímos a biblioteca “LiquidCrystal.h”, responsável por fornecer as funções necessárias para controlar o display LCD. Após esse passo, criamos o objeto “lcd” do tipo Liquid Crystal, informando quais pinos do Arduino estão conectados aos pinos de controle e de dados do display.

---cpp
#include <LiquidCrystal.h>
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
---
