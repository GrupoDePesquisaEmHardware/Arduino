# Display LCD 16x2
Você já ouviu falar sobre display LCD? Os displays LCD (Liquid Crystal Display) podem ser utilizados em diversos dispositivos como celulares, monitores, televisores, calculadoras e relógios digitais, entre outros. 

Em projetos com microcontroladores, os mais utilizados são os displays LCD 16X2. Eles são muito úteis quando se precisa de uma resposta visual do que está sendo desenvolvido já que podem exibir caracteres, letras e números de forma nítida e clara. Esses displays contam com 16 colunas e 2 linhas, podendo ter sua luz de fundo (backlight) azul ou verde e as letras brancas ou pretas.

<div align="center">
<h3>Figura 01: Display LCD 16X2</h3>
<img width="600" height="300" alt="Image" src="https://github.com/user-attachments/assets/a970b6c3-9aa2-40b0-9a43-93c107a78a6a" />
<p>Fonte: https://www.usinainfo.com.br/display-arduino/display-lcd-16x2-com-fundo-azul-2304.html<p>
</div>

## Materiais Necessários
- Placa Arduino Uno
- Cabo de alimentação
- Protoboard
- Display LCD 16×2
- 1 Potenciômetro de 10 KΩ
- 1 Resistor de 220 Ω
- 15 Jumpers macho-macho

## Funcionamento do circuito

<div align="center">
<h3>Figura 02: Montagem  do circuito</h3>	
<img width="1774" height="590" alt="montagem_do_circuito" src="https://github.com/user-attachments/assets/e3b124e2-e3ac-45c3-a7c6-170a058d5279" />
<p>Fonte: Autoria própria<p>
</div>

Para conectar o display ao Arduino, começamos pela alimentação. Utilizamos jumpers para conectar os pinos VSS e VDD do display às portas GND e VCC do Arduino, respectivamente. 

Este display possui quatro pinos de controle. O terceiro pino, V0, é responsável por controlar o contraste entre a luz de fundo e as letras, então ele é ligado ao terminal central do potenciômetro permitindo ajustar o contraste para melhor visualização, os outros terminais do potenciômetro serão ligados um no VCC e outro no GND. O pino RS define se a informação passada será o texto a ser exibido ou comandos para controlar o comportamento do display, ele é conectado à porta digital 2 do Arduino. O pino RW controla de será feita uma escrita ou leitura de informação do display, como será realizado apenas escrita ele pode ser ligado ao GND. Já o pino E (*enable*) define quando a informação será enviada para o display, ele é ligado à porta digital 3.

Os pinos D0 a D7 são pinos de dados, para aplicações mais simples como essa, não são necessário usar todos os 8, apenas os 4 últimos, então os pinos D4, D5, D6 e D7 são ligados, respectivamente, às portas digitais 4, 5, 6 e 7.

Os dois últimos pinos controlam a luz de fundo, ou seja, ligam os LEDs responsáveis por iluminar o display. Como qualquer LED, o pino A (ânodo) deve ser ligado ao VCC passando um resistor, enquanto o pino K (catodo) é ligado ao GND.

## Código
Para ver o display funcionando, vamos fazer um código que exibe uma mensagem que se desloca ao longo da tela. Inicialmente, precisamos incluir a biblioteca do Arduino “LiquidCrystal.h”, para isso utilizamos o comando include seguido do nome da biblioteca.

```cpp
#include <LiquidCrystal.h>
```

Após  incluir a biblioteca, criamos um objeto “LCD” do tipo “LiquidCrystal”, que possibilita utilizar as funcionalidades da biblioteca, e indicamos quais portas do Arduino serão utilizadas seguindo a sequência dos pinos de controle (RS e E) e de dados (D4, D5, D6 e D7) do display.

```cpp
LiquidCrystal LCD(2, 3, 4, 5, 6, 7);
```

Para facilitar a escrita da mensagem, criamos uma string “mens” que irá armazenar a mensagem que será exibida.

```cpp
String mens;
```

Na função setup(), executada apenas uma vez quando o Arduino é ligado ou reiniciado, atribuímos o que queremos exibir à “mens” e, com o método begin(), inicializamos o objeto “LCD” informando a quantidade de colunas e linhas do display utilizado.

```cpp
void setup() {
  mens = "Ola";
  LCD.begin(16, 2);
}
```

A função loop() será executada após a setup() e irá repetir o código dentro dela até o Arduino ser desligado ou reiniciado. Nela criamos um laço for para incrementar a variável “i” de 0 a 13, dentro desse laço é definido por “i” onde o cursor irá começar a escrever a mensagem e exibi-la através do método print(), após 200 milissegundos o display é limpo e exibirá a mensagem na nova posição fazendo um deslocamento para a direita. 

Depois que o primeiro for encerrar, começará o segundo que decrementa a variável “i”, fazendo deslocar para a esquerda, e escreve na segunda linha do display. Resumidamente, a mensagem ficará “circulando” pela tela como exemplificado na figura 03.

```cpp
void loop() {
  for (int i=0; i<=13; i++) {
    LCD.setCursor(i, 0);
    LCD.print(mens);
    delay(200);
    LCD.clear();
  };

  for (int i=13; i>=0; i--) {
    LCD.setCursor(i, 1);
    LCD.print(mens);
    delay(200);
    LCD.clear();
  };
}
```

<div align="center">
<h3>Figura 03: Movimento no display</h3>	
<img width="1337" height="406" alt="movimento_do_display" src="https://github.com/user-attachments/assets/63a63b18-2580-445d-8292-d08033827ff4" />
<p>Fonte: Autoria própria<p>
</div>

## Contribuidor
- [Vinicius Oliveira](https://github.com/VOCruz)
