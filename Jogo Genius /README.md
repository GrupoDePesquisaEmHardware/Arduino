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
<h3>Figura 3: Montagem do circuito. </h3>	
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

```cpp
#include <LiquidCrystal.h>
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
```

Em seguida, utilizamos diretivas “#define” para associar os nomes aos pinos utilizados no projeto. Dessa forma, o código fica mais organizado e fácil de compreender. Os LEDs verde, amarelo, azul e vermelho são conectados às digitais 2, 3, 4 e 5. De mesmo modo, os quatro botões são definidos nas portas digitais 6, 7, 8 e 9 e o buzzer, responsável pelos efeitos sonoros do jogo, é conectado à porta digital 10.

```cpp
// LEDs
#define ledG 2
#define ledY 3
#define ledB 4
#define ledR 5

// Botões
#define pushR 6
#define pushB 7
#define pushY 8
#define pushG 9

// Buzzer
#define buz 10
```

Para armazenar a sequência de cores gerada pelo jogo, criamos um vetor chamado “sequencia”, com capacidade para armazenar até 90 posições, permitindo que o jogo chegue à fase 90.

```cpp
int sequencia[90];
```

Também são declaradas algumas variáveis de controle. A variável “rodada” indica o nível atual do jogo, “recorde” armazena a maior pontuação alcançada e “gameOver” indica se o jogador perdeu a partida.

```cpp
int rodada = 0;
int recorde = 0;
bool gameOver = false; 
```

Os vetores “leds” e “tons” são utilizados para relacionar cada LED a uma frequência sonora específica do buzzer.

```cpp
int leds[4] = {ledG, ledR, ledY, ledB};
int tons[4] = {392, 440, 554, 659};
```

Na função “setup()”, executada apenas uma vez quando o Arduino é ligado, configuramos os LEDs como saídas, os botões como entradas e o buzzer como saída.

```cpp
void setup() {
pinMode(ledG, OUTPUT);
pinMode(ledR, OUTPUT);
pinMode(ledY, OUTPUT);
pinMode(ledB, OUTPUT);

pinMode(pushG, INPUT);
pinMode(pushR, INPUT);
pinMode(pushY, INPUT);
pinMode(pushB, INPUT);

pinMode(buz, OUTPUT); 
```

Em seguida, inicializamos o display LCD informando que ele possui 16 colunas e 2 linhas.

```cpp
lcd.begin(16, 2);
```

Logo após, é exibida a mensagem inicial do jogo. O método “print()” escreve o texto na posição atual do cursor e “setCursor()” define a posição onde a próxima mensagem será exibida.

```cpp
lcd.clear();
lcd.print("JOGO GENIUS");
lcd.setCursor(0, 1);
lcd.print("Press Verde"); 
```

O programa permanece aguardando até que o botão verde seja pressionado para iniciar a partida. Já a função “randomSeed()” utiliza o tempo de execução do Arduino para gerar números aleatórios diferentes a cada partida.

```cpp
while (digitalRead(pushG) == LOW);

  randomSeed(millis());

  delay(300);
}//encerramento do setup()
```

A função “loop()” é responsável pelo funcionamento principal do jogo e será executada continuamente enquanto o Arduino estiver ligado. Inicialmente, o programa aguarda o jogador pressionar o botão verde para iniciar uma nova partida. Em seguida, as variáveis são reinicializadas e uma mensagem de início é exibida no display.

```cpp
void loop() {

  while (digitalRead(pushG) == LOW);

  delay(300);

  rodada = 0;
  gameOver = false;

  lcd.clear();
  lcd.print("Iniciando...");
  delay(1000);
```

O laço “while(!gameOver)” mantém o jogo em execução enquanto o jogador não comete erros. Dentro do laço, a cada rodada, uma nova cor aleatória é adicionada ao vetor “sequencia”.

```cpp
 while (!gameOver) {

    sequencia[rodada] = random(4);
    rodada++;
```

O display exibe a pontuação atual, o recorde e o nível em que o jogador se encontra.

```cpp
    lcd.clear();
    lcd.print("P:");
    lcd.print(rodada - 1);

    lcd.print(" R:");
    lcd.print(recorde);

    lcd.setCursor(0, 1);
    lcd.print("Nivel ");
    lcd.print(rodada);

    delay(1000);
```

Em seguida, a função “mostrarSequencia()” é chamada para acender os LEDs e reproduzir os sons correspondentes à sequência gerada. Após essa ação, o display informa que é a vez do jogador repetir a sequência.

```cpp
    mostrarSequencia();

    lcd.clear();
    lcd.print("P:");
    lcd.print(rodada - 1);

    lcd.print(" R:");
    lcd.print(recorde);

    lcd.setCursor(0, 1);
    lcd.print("Sua vez!");
```

A função “jogadorAcertou()” verifica se o jogador reproduziu corretamente toda a sequência. Em caso de erro, o programa atualiza o recorde, exibe a mensagem “GAME OVER” e realiza um efeito visual e sonoro piscando todos os LEDs e acionando o buzzer três vezes. Após alguns segundos, o display retorna à tela inicial aguardando uma nova partida.

```cpp
if (!jogadorAcertou()) {

      if ((rodada - 1) > recorde) {
        recorde = rodada - 1;
      }

      gameOver = true;

      lcd.clear();
      lcd.print("GAME OVER");

      lcd.setCursor(0, 1);
      lcd.print("P:");
      lcd.print(rodada - 1);

      lcd.print(" R:");
      lcd.print(recorde);

      for (int i = 0; i < 3; i++) {

        tone(buz, 150);

        digitalWrite(ledG, HIGH);
        digitalWrite(ledR, HIGH);
        digitalWrite(ledY, HIGH);
        digitalWrite(ledB, HIGH);

        delay(300);

        noTone(buz);

        digitalWrite(ledG, LOW);
        digitalWrite(ledR, LOW);
        digitalWrite(ledY, LOW);
        digitalWrite(ledB, LOW);

        delay(300);
      }

      delay(4000);

      lcd.clear();
      lcd.print("Press Verde");

      while (digitalRead(pushG) == LOW);

      delay(300);
    }
```

O laço condicional “if()” a seguir confere se o jogador atingiu o nível máximo do jogo e, caso isso ocorra, imprime “PARABENS!” e também emite uma sequência em que todos os LEDs acendem e o buzzer emite som 4 vezes.

```cpp
if (rodada == 90) {

      if ((rodada - 1) > recorde) {
        recorde = rodada - 1;
      }

      lcd.clear();
      lcd.print("PARABENS!");

      lcd.setCursor(0, 1);
      lcd.print("Fase 90");

      int notas[] = {523, 659, 784, 1047};
      int dur[] = {200, 200, 200, 500};

      for (int i = 0; i < 4; i++) {

        tone(buz, notas[i]);

        digitalWrite(ledG, HIGH);
        digitalWrite(ledR, HIGH);
        digitalWrite(ledY, HIGH);
        digitalWrite(ledB, HIGH);

        delay(dur[i]);

        noTone(buz);

        digitalWrite(ledG, LOW);
        digitalWrite(ledR, LOW);
        digitalWrite(ledY, LOW);
        digitalWrite(ledB, LOW);

        delay(150);
      }
```

Para finalizar o “loop()”, o laço “while (true)” mantém a mensagem de vitória exibida definitivamente até que o Arduino seja reiniciado ou desligado, impedindo que uma nova partida inicie automaticamente. Já o “delay” final (note que está fora do “if()” de vitória) faz uma pausa de 800ms antes de iniciar a próxima rodada.

```cpp
while (true);
    }

    delay(800);
  }
}
```

Encerrado o “loop()”, a função “mostrarSequencia()” é responsável por apresentar ao jogador a sequência gerada pelo jogo. Utilizando o laço for, cada posição do vetor “sequencia” é percorrida. Para cada elemento, o LED correspondente é aceso através do comando “digitalWrite()”, enquanto o buzzer reproduz o tom associado usando a função “tone()”. Por fim, após um intervalo de tempo, o LED é apagado e o som interrompido, permitindo que o jogador visualize e escute a sequência que deverá repetir.

```cpp
void mostrarSequencia() {

  for (int i = 0; i < rodada; i++) {

    digitalWrite(leds[sequencia[i]], HIGH);

    tone(buz, tons[sequencia[i]]);

    delay(600);

    digitalWrite(leds[sequencia[i]], LOW);

    noTone(buz);

    delay(250);
  }
}
```

A outra função utilizada é a “jogadorAcertou()”, responsável por verificar as entradas do jogador. Para cada posição da sequência, o programa aguarda até que algum botão seja pressionado e, quando detectado, atribui-se um valor correspondente à cor selecionada.

```cpp
bool jogadorAcertou() {

  for (int i = 0; i < rodada; i++) {

    int resposta = -1;

    while (resposta == -1) {

      if (digitalRead(pushG) == HIGH) resposta = 0;
      if (digitalRead(pushR) == HIGH) resposta = 1;
      if (digitalRead(pushY) == HIGH) resposta = 2;
      if (digitalRead(pushB) == HIGH) resposta = 3;
    }
```

Após a leitura do botão pressionado, o LED correspondente é aceso e o buzzer reproduz seu respectivo tom, fornecendo um retorno visual e sonoro ao jogador. Em seguida, o programa compara a resposta dada com a posição correspondente da sequência armazenada. Caso haja qualquer diferença, a função retorna “false”, indicando erro. Se todas as posições forem respondidas corretamente, a função retorna “true”, permitindo que o jogador avance para a próxima rodada.

```cpp
digitalWrite(leds[resposta], HIGH);

    tone(buz, tons[resposta]);

    delay(300);

    digitalWrite(leds[resposta], LOW);

    noTone(buz);

    while (
      digitalRead(pushG) == HIGH ||
      digitalRead(pushR) == HIGH ||
      digitalRead(pushY) == HIGH ||
      digitalRead(pushB) == HIGH
    );

    if (resposta != sequencia[i]) {
      return false;
    }
  }

  return true;
}
```

Dessa forma, o código implementa o funcionamento do jogo Genius, controlando o display LCD, os LEDs, os botões e o buzzer para criar uma experiência interativa de memória e repetição de sequências.

## Link do circuito no Tinkercad

https://www.tinkercad.com/things/19y8SbSat9f-jogo-genius?sharecode=FLN4oIqt3LbkPyG3KWFDv71C90uxKMTQ-K9q6nKwod0

## Contribuidor
- [Mariana Ferreira](https://github.com/MarianaFerrreira)
