# Buzzer

Sara Cunha Leite

O som está fortemente presente nas tecnologias do nosso cotidiano, seja na melodia de jogos, alertas sonoros e em alguns dispositivos eletrodomésticos que utilizam as ondas sonoras para se comunicar de algum jeito com o usuário. Você já se perguntou como colocar sons em seus projetos? Conheça então o buzzer e como tocar sua primeira música pelo arduino! 
O buzzer é um sonorizador que recebe sinais elétricos e os converte em ondas sonoras, por meio de vibrações, seja em uma bobina ou um disco piezoelétrico, por exemplo, com uma frequência específica para cada som. Essas vibrações são amplificadas pela própria caixa do dispositivo, que cobre todos os seus componentes. O dispositivo possui dois pinos: Terra (GND) e Terminal de sinal (indicado por um sinal de + no topo do buzzer).

## Buzzer passivo ou ativo
No mercado, pode-se encontrar dois principais tipos de buzzer: o ativo e o passivo. É importante diferenciá-los, pois seu funcionamento utilizando o arduino será diferente, com isso, deve ser levado em consideração qual desses se aplica melhor aos projetos .

Tendo isso em vista, o buzzer passivo depende especialmente da frequência enviada pelo arduino para que seja funcional, precisando, assim, montar um circuito oscilante. Essa dependência também implica em uma maior versatilidade, visto que a função “tone” - que será explicada mais à frente - será a responsável por moldar as frequências desejadas. Logo, esse buzzer passivo é mais utilizado para criar melodias ou músicas específicas e esta aplicação do componente será utilizada no desafio.
Já o buzzer ativo tem um diferencial importante em sua estrutura: ele possui um circuito próprio, de modo que sua oscilação não depende da corrente elétrica, o que facilita a sua ativação, de modo a se assemelhar com a declaração de um LED. Entretanto, esse oscilador interno impede modificações no som, ou seja, a função “tone” não é capaz de mudar a frequência, pelo contrário, utilizar este comando no código causará falhas em como o buzzer soará. Assim, o tipo ativo serve para projetos que não demandam mudança de frequência e sua aplicação pode ser ligada a alarmes mais simples, como o som de um microondas ou de uma air fryer, em que não há mudança de tom. 

<div align="center">
<h3>Figura 1: Buzzer ativo x Buzzer passivo
</h3>	 
<img width="749" height="394" alt="image" src="https://github.com/user-attachments/assets/f6814478-1cf0-4155-a42a-3699435e2638"/>
<h4>Fonte: Kit makers </h4>
</div>

## Função “tone”
	Essa função é fundamental para o funcionamento do buzzer passivo, a qual declara a frequência e o tempo de duração em que o componente funcionará. Sua sintaxe básica é: “tone(pino,frequência,duração em ms)”.
É importante apresentar também a função “noTone”, a qual interrompe o sinal de onda enviada pelo “tone”. A sintaxe básica é: “noTone(pino)”.

# Projeto - Tocando Garota de Ipanema
Com todas as informações citadas, já é possível fazer melodias utilizando poucos componentes e ligações simples. Sendo assim, será utilizado como exemplo uma das músicas mais célebres da Música Popular Brasileira: Garota de Ipanema - Tom Jobim e Vinicius de Moraes.
### Materiais Utilizados:
- Arduino UNO R3;
- 2 jumpers;
- 1 protoboard mini;
- 1 resistor (1 kΩ); 
- 1 buzzer passivo.
### Montagem do Circuito

	Na protoboard, foi escolhido dois pontos quaisquer para colocar os pinos do buzzer. Após isso, o  resistor é conectado na mesma coluna do polo positivo ou negativo do buzzer (nesse exemplo está no positivo), a fim de proteger os componentes. Por fim, o jumper roxo será ligado em uma das portas digitais, no caso a porta digital 3, e na protoboard na coluna do resistor. Já o jumper preto será conectado no GND do arduino e na coluna do pino negativo do buzzer. Espera-se como resultado algo parecido com o seguinte modelo:

<div align="center">
<h3>Figura 2:Circuito
</h3>	 
<img width="456" height="173" alt="image" src="https://github.com/user-attachments/assets/16e79a29-5a0c-43db-9e63-c836a6bec3dc" />
/>
<h4>Fonte: Autoria própria </h4>
</div>

# Código
Primeiramente, é necessário definir essas partes importantes  do código, para que seja possível a criação de qualquer melodia.
Quanto à frequência das notas musicais:

	```cpp
// Oitava 4 (Oitava Central)
#define NOTA_C4 262
#define NOTA_CS4 277
#define NOTA_D4 294
#define NOTA_DS4 311
#define NOTA_E4 330
#define NOTA_F4 349
#define NOTA_FS4 370
#define NOTA_G4 392
#define NOTA_GS4 415
#define NOTA_A4 440
#define NOTA_AS4 466
#define NOTA_B4 494
// Oitava 5
#define NOTA_C5 523
#define NOTA_CS5 554
#define NOTA_D5 587
#define NOTA_DS5 622
#define NOTA_E5 659
#define NOTA_F5 698
#define NOTA_FS5 740
#define NOTA_G5 784
#define NOTA_GS5 831
#define NOTA_A5 880
#define NOTA_AS5 932
#define NOTA_B5 988
Quanto aos tempos das notas:
#define t4 2000 //semibreve
#define t2 1000 //mínima
#define t1 500 //semínima
#define t05 250 //colcheia
#define t025 125//semicocheia
 ```

Após essas configurações iniciais, declare as variáveis buzzer, ritmo, nota e duração.

	```cpp
int buzzer = 3;
int ritmo = 1.5;//serve para acelerar ou desacelerar a música
int nota;  //será utilizada depois
int duracao; //também será utilizada depois
	```

Chegamos na parte principal do código: Escrever o código para a criação da música. Para isso, serão declarados dois vetores: no primeiro vetor será colocado as notas musicais, o segundo fará referência ao tempo que essa nota irá soar. Assim, o resultado para a música Garota de Ipanema será:

 	```cpp
int notas[] = {
 	NOTA_D5, NOTA_B4,NOTA_B4,NOTA_A4,
	NOTA_D5, NOTA_B4,NOTA_B4,NOTA_B4,NOTA_A4,
	NOTA_D5, NOTA_B4,NOTA_B4,NOTA_A4,
	NOTA_D5, NOTA_B4,NOTA_B4,NOTA_B4,NOTA_A4,
	NOTA_C5, NOTA_A4, NOTA_A4,NOTA_A4,NOTA_G4, 
	NOTA_B4, NOTA_G4,NOTA_G4,NOTA_G4,
	NOTA_F4, NOTA_G4
};
int tempos[]{
  t2,t05,t1,t05,
  t1,t05,t1,t05,t1,
  t1,t1,t1,t05,
  t1,t05,t1,t05,
  t1, t1, t1, t05, t05,
  t1,t1,t1,t05,t05,
  t1,t4
};
```

Na sequência, vamos declarar a porta de entrada do buzzer:

```cpp
void setup()
{
  pinMode(buzzer, OUTPUT);
}
```

Por fim, utilizaremos a função “for” para unir os dois vetores formando a melodia:

 ```cpp
void loop()
{
  //sizeof(notas) = valor das notas dentro do vetor em bits
  //sizeof(int) = valor de um elemento inteiro em bits
  //divisão = número da nota dentro do vetor notas
  for(nota = 0;nota<(sizeof(notas)/sizeof(int)); nota++){
    duracao = tempos[nota]/ritmo;
    tone(buzzer,notas[nota],duracao);
    delay(duracao*1.5);
    noTone(buzzer);
  }  
  delay(5000);// tempo para a melodia começar de novo
}
	```

Pronto! Agora já temos um código que tocará uma parte da música Garota de Ipanema. Caso tenha se interessado em fazer outras canções, abaixo seguem informações de teoria musical básica. Além disso, para facilitar a escrita da música, separe os compassos da melodia em linhas diferentes nos vetores nota e tempo.
Oitavas: Forma de separar a escala musical de dó até si. A 4ª oitava é a principal para a maioria das músicas.
<div align="center">
<h3>Figura 4:Nome das notas
</h3>	 
<img width="197" height="230" alt="image" src="https://github.com/user-attachments/assets/52e9c472-4eb1-46a1-a255-bbc0eae63cd0" />
 />
 />
/>
<h4>Fonte: Autoria própria </h4>
</div>

Então, seguindo os conceitos musicais anteriores, o dó na 4ª oitava seria representado em nosso código com C4. Obs: “S” depois da letra da nota se refere ao seu sustenido.
Tempo/valor das notas musicais:


