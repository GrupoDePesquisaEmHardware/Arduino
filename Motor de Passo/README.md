# Motor de Passo

 Fala pessoal! Vocês já ouviram falar sobre o motor de passo? Esse motor é utilizado em vários tipos de circuitos elétricos e equipamentos, como nas impressoras 3D e braços robóticos. Bora entender um pouco mais sobre ele?
                                    
<div align="center">
<h3>Figura 1: Motor de Passo 28BYJ-48 e Driver ULN2003</h3>	
<img width="1263" height="545" alt="Image" src="https://github.com/user-attachments/assets/a89f23be-dacd-4385-a058-538c1f86ab81" />
<h4>Fonte: Autoria Própria </h4>
</div>

Como o próprio nome já diz, esse tipo de motor é dividido em pequenos ângulos, que formam os "passos". Esses passos permitem uma precisão maior e uma grande variedade de aplicações.

Quando configuramos o motor, fazemos um cálculo no início do código, consideramos uma volta completa com 360º e determinamos quantos passos por volta queremos. Neste projeto, vamos escolher 200 passos por volta e realizar o cálculo 360º/200, para descobrir quantos graus compõem um passo do motor. Assim, cada passo a realizar terá um ângulo de 1,8º, mas esse valor pode ser diferente dependendo da sua aplicação.
 

# Materiais Necessários:
- Protoboard (Placa de ensaio);
- 2 resistores de 1KΩ;
- 2 botões;
- 1 arduino;
- 1 Motor de passo 28BYJ-48
- 1  Driver ULN2003 ;
- Jumper (Fios).


# Circuito:
No circuito que iremos montar trouxemos a ideia de utilizar dois botões para realizar o controle do motor de passo, como mostra a figura 2. Este controle seria o sentido de rotação do motor de passo, sentido horário e antihorário, ajudando desta forma um maior entendimento em como podemos usar o motor de passo em diversas situações do cotidiano.


<div align="center">
<h3>Figura 2:  Circuito de ativação do motor a partir de dois botões.</h3>	
<img width="1263" height="545" alt="Image" src="https://github.com/user-attachments/assets/a89f23be-dacd-4385-a058-538c1f86ab81" />
<h4>Fonte: Circuito autoral </h4>
</div>

Para montar esse circuito, vamos começar alimentando a protoboard, para isso conectamos a fileira indicada com o ‘+’ no pino de 5 volts do arduino e a fileira com o símbolo de ‘-’ no GND da placa. 

Feito isso, podemos iniciar a montagem dos botões, primeiro iremos utilizar dois resistores de 1kΩ para conectar um dos terminais do botão na parte negativa da protoboard, então com um fio (vermelho, no nosso caso) conectamos a outro terminal na fileira do Vcc. Por fim iremos conectar o terminal de cima, do mesmo lado do resistor, nas portas digitais do arduino (4 e 5), que trabalham com valores 0 ou 1, ou seja, ligado ou desligado, para que o circuito possa funcionar apertando o botão.

Para montar o motor de passo, iremos aproveitar a ligação que realizamos na parte positiva e o GND da protoboard e ligar os fios vermelho e preto do motor de passo, respectivamente. Além disso, o fio verde, o terra do codificador, será conectado na porta 8, os fios  amarelo e roxo, canais A e B que auxiliam no controle do motor, nas porta 10 e 9, nesta ordem, por último o laranja, a potência do codificador, na porta 10.


# Código:

Agora, para tornar nossa explicação e demonstração mais interativa, para que vocês entendam explicaremos o passo a passo que foi utilizado em nosso código.

```cpp
#include <Stepper.h>
 
const int PassosPorVolta = 100;
const int botao_horario = 4;
const int botao_antihorario = 5;
 
Stepper myStepper(PassosPorVolta, 8, 10, 9, 11);


```
Inicialmente, é necessário incluir  a biblioteca do motor de passo, para isso usamos o comando “include” seguido do nome da biblioteca que será utilizada, “Stepper.h”. Depois, vamos fazer a definição das constantes que iremos usar ao longo do código, que neste caso foram, os dois botões (“botao_horario” e “botao_antihorario”) e o número de passos (“PassosPorVolta”) do motor, com esses pontos finalizados, realizaremos a definição de quais portas digitais do Arduino vamos utilizar no projeto. 

```cpp
void setup()
{
  Serial.begin(9600);
  pinMode(botao_horario, INPUT);
  pinMode(botao_antihorario, INPUT);
}
```

No void setup, através do “Serial.begin” vamos realizar a comunicação com o monitor serial, para facilitar a observação do funcionamento do circuito. Também é necessário definir os botões como entrada, ou seja, eles irão enviar um comando para o Arduino, para isso utilizamos a função pinMode () e dentro dela escrevemos o nome da constante e seu estado.

```cpp
void loop()
{
  if(digitalRead(botao_horario)== 1){
	Serial.println("Horario");
 	myStepper.step(PassosPorVolta);
  }
	else if(digitalRead(botao_antihorario)== 1){
  	Serial.println("Anti horario");
       myStepper.step(-PassosPorVolta);
  }
}
```

No void loop, fazemos duas condições utilizando as funções “if” e “else if”, que no português significam “se” e “senão se”, respectivamente. Na primeira condição, se o “botão_horario” for pressionado, ele deve enviar o comando para o motor de passo girar no sentido horário, já na segunda condição, se o “botao_antihorario” for pressionado, ele deve enviar o comando para o motor de passo girar no sentido anti horário. 

Bom pessoal, se vocês realizaram todos os passos corretamente, neste momento o circuito deve estar funcionando e todos que leram puderam aprender um pouco sobre o motor de passo e ainda construíram um circuito do zero no simulador. Espero que tenham gostado e até o próximo circuito.

Link do circuito no tinkercad:
https://www.tinkercad.com/things/biymleWXH5U-dazzling-esboo?sharecode=M-_91GnyS-j_bzo2xpJXqVxpqSPt9ZZg3NOE-ocnPR4

# Contribuidor

- <p><a href="https://github.com/RonaldLucas19">Ronald Lucas</a></p>