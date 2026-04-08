# Aplicando Debounce no botão:

  Fala, pessoal! Vocês já ouviram falar do botão utilizando a técnica debounce? Este procedimento nos permite ter um comportamento confiável do botão, evitando leituras falsas e possíveis erros no projeto que está sendo desenvolvido.
                                    
<div align="center">
<h3>Figura 1: Circuito no Tinkercad</h3>	
<img width="1263" height="545" alt="Image" src="https://github.com/user-attachments/assets/a89f23be-dacd-4385-a058-538c1f86ab81" />
<h4>Fonte: Circuito autoral </h4>
</div>

O botão debounce é uma aplicação que permite maior controle no circuito, realizar várias funções dentro do código utilizando um único botão, permitindo um circuito menor com várias funcionalidades, o exemplo é o que vai ser montado e explicado neste documento. 

# Materiais Necessários:
- Protoboard (Placa de ensaio);
- 1 resistor de 1KΩ;
- 2 resistores de 330Ω;
- 1 botão;
- 1 arduino;
- 1 led rgb;
- Jumper macho-macho.

# Circuito:
Nesta parte, utilizaremos o led rgb que nos permite entender melhor a lógica e ter uma visualização melhor do funcionamento proposto para o circuito.

<div align="center">
<h3>Figura 1: Circuito no Tinkercad</h3>	
<img width="1263" height="545" alt="Image" src="https://github.com/user-attachments/assets/a89f23be-dacd-4385-a058-538c1f86ab81" />
<h4>Fonte: Circuito autoral </h4>
</div>

Para montar esse circuito, vamos começar alimentando a protoboard, para isso conectamos a fileira indicada com o símbolo positivo, ‘+’, no pino de 5 volts do arduino e a fileira com o símbolo negativo, ‘-’, no GND da placa. 

Agora podemos começar a montar o botão. Primeiro, utilizaremos um resistor de 1kΩ para conectar um dos terminais do botão na parte negativa da protoboard. Depois, com um outro fio (vermelho, no nosso caso), conectamos o outro terminal na fileira do Vcc. Por fim, conectaremos o terminal de cima, do mesmo lado do resistor, pois estamos utilizando um botão pull down no circuito, no qual só permite a passagem da corrente quando está sendo pressionado, na porta digital do Arduino (10), que trabalha com valores 0 ou 1, ou seja, ligado ou desligado, para que o circuito possa funcionar pressionando o botão.

Após realizar a montagem dos botões, iremos para a parte onde o funcionamento do botão debounce irá ser mostrado através do led RGB. A montagem deste led é simples e pode ser feita rapidamente, ao analisarmos o componente (Led RGB), pode-se perceber que o mesmo tem um terminal maior, onde iremos conectar o GND “-”. Com essa etapa finalizada, podemos prosseguir com a montagem do circuito, um ponto importante é que este led tem 3 cores diferentes, por isso o seu nome, RGB, (R - red, G - green e B - blue), como mostrado na figura do circuito, realizei a ligação com os jumpers nas suas cores correspondentes, lembrando a vocês que é necessário a utilização de resistores, neste caso, utilizei os de 330Ω. 

Bom pessoal, se realizaram todos os passos acima corretamente, o circuito já está pronto para funcionamento, o que falta neste momento é a explicação do código.

# Código:

Agora, para tornar nossa explicação e demonstração mais interativa, para que vocês entendam explicaremos o passo a passo que foi utilizado em nosso código.

```cpp
int contador = 0;
const int botao_led = 10;
const int led_V = 4;
const int led_B = 5;
const int led_G = 5;
```
Para iniciar o nosso código e garantir o funcionamento das constantes necessárias para o circuito, iremos definir essas constantes que iremos utilizar ao decorrer do nosso código. Para definir, iremos utilizar o comando “#define” para avisar ao nosso código que iremos definir algo que não vai mudar ao longo do código, tornando mais fácil realizar o restante da programação. Com isso, começamos definindo o valor inicial do contador em zero, para que não tenha o risco do nosso circuito começar em outro valor, fazendo com que o código não seja eficiente e prático. Depois,  definimos os nomes dos componentes por meio de uma variável para o botão (botao_led) e para os leds leds (led_V, led_B, led_G) e sua respectiva porta digital, que é o local onde se conecta os jumpers no arduino.  

```cpp
void setup()
{
    Serial.begin(9600);	
    pinMode(botao_led, INPUT);
    pinMode(led_V, OUTPUT);
    pinMode(led_B, OUTPUT);
    pinMode(led_G, OUTPUT);
}
```

No void setup, através do “Serial.begin” vamos realizar a comunicação com o monitor serial, para facilitar a observação do funcionamento do circuito e realizar o monitoramento do circuito, facilitando a aprendizagem e a explicação para outras pessoas. Também é necessário definir os botões como entrada, ou seja, eles irão enviar um comando para o Arduino, e definir os leds como saída, ou seja, eles vão receber um comando do Arduino como as demais, porém como essas portas foram definidas como “OUTPUT”, torna-se possível a demonstração em forma de luz, no nosso caso, mas poderia ser em forma de som ou algum movimento também e, para que isso seja possível,  utilizamos a função pinMode () e dentro dela escrevemos o nome da constante e seu o seu tipo de dado.

```cpp
	void loop()
{
	if(digitalRead(botao_led)==1){
	while(digitalRead(botao_led)==1){ }
	contador++;
	Serial.println(contador);
}
	if(contador==1){
	  digitalWrite(led_V, HIGH);
	  digitalWrite(led_B, LOW);
	  digitalWrite(led_G, LOW);
}
	if(contador==2){
	  digitalWrite(led_B, HIGH);
	  digitalWrite(led_V, LOW);
	  digitalWrite(led_G, LOW);
}
	if(contador==3){
	  digitalWrite(led_G, HIGH);
	  digitalWrite(led_B, LOW);
	  digitalWrite(led_V, LOW);
}
	if(contador==4){
	  digitalWrite(led_V, LOW);
	  digitalWrite(led_B, LOW);
	  digitalWrite(led_G, LOW);
	  contador = 0;
}
}
```

No void loop, fazemos cinco condições utilizando a função “if”, que no português significa “se”. E, foi utilizada a função “while”, que no português significa “enquanto”. Na primeira condição, se o “botao_led” for pressionado e enquanto ele for pressionado, o botão deve ir incrementando 1 na soma do contador, para que as condições que foram criadas, sejam utilizadas.

Nas condições restantes, utilizamos a função “if” juntamente com o “contador” para que em cada uma dessas condições uma cor do led fosse ligada, para que isso aconteça, utilizados os estados “HIGH” e “LOW”, que neste caso significam 1 ou 0, ou seja, ligado ou desligado, para que eu possa fazer com que meus leds liguem. E, na última condição, coloquei que o contador seja igual a 0 no final, para que o ciclo possa ser reiniciado.

Bom pessoal, se vocês realizaram todos os passos corretamente, neste momento o circuito deve estar funcionando e todos que leram puderam aprender um pouco sobre o botão debounce e ainda construíram um circuito do zero no simulador. Espero que tenham gostado e até o próximo circuito.

Link do circuito no tinkercad:
https://www.tinkercad.com/things/ckqOqVj8PFR-desafio-2-gph?sharecode=uvGA8DQBbyjPcz5R2TsloALujyMTMqzlwSg-vFZ75BY
