 # Servo Motor  SG90 9G: Robótica Dinâmica
Você já ouviu falar sobre servos motores? O servo motor é um dispositivo eletromecânico responsável por converter energia elétrica em mecânica, sendo utilizado em projetos que exigem grande precisão, como garra robótica e aeromodelismo. O deslocamento de servos, como o do modelo SG90 9g, se dá através de ângulos previamente determinados por código e o mesmo tende a se manter na mesma posição até que seja lhe dado outro comando.

Imagem 1: Braço Robótico

Fonte: https://www.smartkits.com.br/kit-braco-robotico-em-acrilico


O deslocamento do servo é baseado em sistema integrado formado por um potenciômetro, circuito de controle, sistema de engrenagens e uma trava de segurança. Cada parte do sistema tem sua respectiva função, como detalhado a seguir:

Potênciometro: registrar a posição atual do servo, pois a resistência dele varia com o ângulo.
Circuito de controle: interpretar os comandos enviados para o servo e alterar a sua posição quando necessário.
Sistema de engrenagens: transmitir o movimento do motor para o eixo de rotação do servo.
Trava de segurança: consiste numa peça de plástico acoplada às engrenagens que limita o deslocamento, geralmente entre 0 e 180 graus.
        
A posição do servo se dá através da leitura de um sinal elétrico com largura de pulso que varia de 1 a 2 milissegundos. Esse tipo de sinal é chamado de PWM (do inglês, Pulse Width Modulation) e é responsável por definir o ângulo de rotação do nosso servo. Ficou confuso sobre o que é PWM? No momento, saiba que a largura desse pulso define um ângulo como apresentado na imagem a seguir. Para melhor compreensão desta etapa, confira aqui uma publicação detalhada sobre o assunto.

Imagem 3: Sinais de controle do servo motor

Fonte: https://forum.arduino.cc/t/creating-your-own-pwm-to-control-a-servo/129869

Agora que conhecemos o servo motor, vamos compreender o papel do Arduino para  o controle desse dispositivo. Para definir o seu movimento, utilizamos das portas digitais precedidas do símbolo “~" do microcontrolador. Essas portas possuem a função PWM quando definidas para funcionarem como saídas digitais, responsáveis por enviar os sinais elétricos que representam ângulos específicos no servo.

## Materiais Necessários
- Arduino UNO
- Micro Servo Motor SG90 9g
-  3 Jumpers 
- Cabo de alimentação do Arduino 
- Funcionamento do circuito
  
Imagem 2: Circuito do Servo

Fonte: autoria própria


Para montar o circuito, vamos começar pela alimentação do servo. A entrada do meio do conector, geralmente marcada por um fio de cor vermelha, é conhecida como VCC, será conectada ao pino de 5V do Arduino. Em seguida, vamos conectar o GND, geralmente marcado por um fio marrom ou preto, que será conectado ao pino da placa marcado por esse mesmo nome. Feita essas conexões, já estamos fornecendo energia para o nosso servo.
Por último, é preciso conectar a entrada do sinal, geralmente marcada por um fio amarelo, ao pino digital do Arduino. Lembrando que o pino precisa ser do tipo PWM, com a marcação “~" antes do número de identificação.

## Código do Servo
Após compreender melhor o funcionamento do servo motor e como podemos utilizar o Arduino para controlá-lo, podemos colocar tudo isso em prática dentro de um código. Então, vamos fazer com que o servo fique variando sua posição de 0 a 180 graus, e vice-versa.
No início do código, vamos incluir a biblioteca “Servo.h” do próprio Arduino para o controle do servo motor . Para conseguir utilizar a biblioteca utiliza-se  o comando include seguido do nome da biblioteca, assim poderemos ter acesso às funções e rotinas padronizadas.

```cpp
#include <Servo.h>
```

Após incluir a biblioteca, criamos as constantes chamadas PINO_SERVO e TEMPO_GIRO para armazenar o pino digital que conectamos o servo motor e o intervalo para a mudança de ângulo. Essas constantes são criadas utilizando o comando define e não poderão ser alteradas durante a execução do código, pois a conexão entre o dispositivo e o microcontrolador não sofre mudanças, assim como o tempo de espera neste código. Depois de definir as constantes, criamos uma variável chamada “pos” para guardar o valor inteiro da posição atual do servo.

```cpp
#define PINO_SERVO 9
#define TEMPO_GIRO 30
int pos;
```
Na sequência,  criamos um objeto “meu_servo” que representa a biblioteca Servo para poder utilizarmos de suas funcionalidades.
Servo meu_servo;
Na função setup(), inicializada apenas quando o Arduino é ligado ou reiniciado, utilizamos o método attach() para relacionar o nosso objeto “meu_servo” com o pino digital utilizado.

```cpp
void setup()
{
	meu_servo.attach(PINO_SERVO);
}
```

Finalmente, temos a função loop() que será executada até que o Arduino seja desligado ou reiniciado. Dentro da função, criamos um um laço de repetição for para incrementar a posição do servo em 1 posição a cada TEMPO_GIRO, utilizando do método write() que permite definir posições entre 0 e 180 apenas. Quando a posição chegar em 180 o laço seguinte faz com que a posição volte para 0 decrementado 1 posição como a repetição anterior.

```cpp
void loop()
{
	 for (pos = 0; pos <= 180;++pos) {
   		meu_servo.write(pos);
    		delay(TEMPO_GIRO);
 	}
 for (pos = 180; pos >= 0; –pos) {
   	meu_servo.write(pos);
    	delay(TEMPO_GIRO);
}
}
```
Agora, temos um código em funcionamento que faz com que o servo fique girando entre as posições de 0 a 180 graus até que o Arduino seja desligado.

## Contribuidores
- [Síria Cabral](https://github.com/siriacfreitas)
- [Lisandry Azuaje](https://github.com/lisandry)
