# LDR- Fotoresistor


   Você já ouviu falar sobre o sensor LDR? O sensor “Resistor Dependente de Luz” ("Light Dependent Resistor"), mais conhecido por sua sigla LDR, é um sensor que mede a intensidade da luz. Nós podemos encontrar esse tipo de sensor em poste de energia, por exemplo, que acende quando percebe a ausência de luz solar.


<div align="center">
<h3>Imagem 1: LDR</h3>	
<img width="250" height="150" alt="Image" src="https://github.com/user-attachments/assets/5259701d-e2c3-4019-9c9c-0db485473154" />
<p>Fonte: https://www.eletrogate.com/sensor-fotoresistor-ldr-de-5mm?utm_source=Site&utm_medium=GoogleMerchant&utm_campaign=GoogleMerchant<p>
</div>
         
O sensor LDR é feito de um material semicondutor,ou seja, material que possui características de condução elétrica intermediárias entre materiais condutores (como metais) e isolantes, normalmente, sulfeto de cádmio (CdS), que tem a  propriedade de variar sua resistência de acordo com a intensidade de luz que incide sobre ele. Assim, quanto mais luz incide sobre o LDR menor sua resistência e maior a quantidade de corrente é permitido passar para o circuito. Desse modo, como um resistor comum, o mesmo não possui polaridade (lado positivo ou negativo definidos) e sua resistência é medida em ohms(Ω).

<div align="center">
<h3>Imagem 2: Fluxo de corrente</h3>	
<img width="500" height="200" alt="Image" src="https://github.com/user-attachments/assets/6d673018-d3f9-4d68-94a9-22052a91a257" />
<p>Fonte: https://www.kitsarduino.com.br/cmp/ldr.html*<p>
</div>

## Entendendo o LDR a nível atômico:  

Para entender melhor essa parte, primeiro temos que entender alguns conceitos químicos:   

<div align="center">
<h3>Imagem 3: Estrutura do Átomo</h3>	
<img width="300" height="200" alt="Image" src="https://github.com/user-attachments/assets/fdc1d5de-3391-4019-92f5-d7d407f7a28b" />
<p>Fonte: https://brasilescola.uol.com.br/quimica/atomistica.htm<p>
</div>

									
- **Elétron:** é a partícula subatômica de carga negativa que se encontra na parte externa do átomo (eletrosfera).
- **Camada de valência:** é a camada mais afastada do núcleo e que apresenta um nível de energia mais baixo.
- **Camada de condução:** é a região que fica os elétrons livres e que apresenta um nível de energia mais alto.

Agora sim, podemos começar!

A luz é formada por fótons, partículas que transportam energia, ao atingir o sensor LDR esses fótons são absorvidos pelos elétrons do sulfeto de cádmio que estão na camada de valência, com isso os elétrons ficam excitados (com energia necessária para sair da camada de valência) e vão para a camada de condução, onde conseguem se mover livremente, o que permite uma maior condução de energia. Portanto, quanto mais luz atingir o sensor mais elétrons vão mudar de camada e menor será sua resistência.

## Materiais necessários
- Arduino UNO
- Protoboard
- 1 LED
- 8 Jumpers
- Cabo de alimentação do Arduino
- 2 Resistores (um de 10kΩ e um de 1kΩ)



Funcionamento do circuito:

<div align="center">
<h3>Imagem 4: Circuito LDR</h3>	
<img width="500" height="200" alt="Image" src="https://github.com/user-attachments/assets/0d315dfc-9d20-49ab-a0e5-6ccc9e86a5de" />
<p>*(Fonte: Autoria própria (Tinkercad))*<p>
</div>

Para montar o circuito, vamos começar alimentando a protoboard ligando a fileira indicada com o sinal negativo ao GND do arduino e a fileira indicada com o sinal positivo no 5V. 
Cuidado, se sua protoboard for um modelo maior, ela pode possuir uma divisória no meio dos pinos de alimentação. Assim, lembre-se de interligar as duas fileiras de alimentação para sobrepor a divisão.

**Imagem 5: Conexão Protoboard**
*(Fonte: Autoria própria (Tinkercad))*

Após isso, vamos conectar o LED na fileira onde se encontra o lado negativo, normalmente com a perna mais curta, a um resistor de 1kΩ e na outra perna do resistor se conecta a fileira negativa da protoboard. Na outra perna do LED, o lado positivo, normalmente com a perna maior, nós vamos ligá-lo à porta 4 do arduino. Para o LDR vamos conectar o resistor de 10kΩ em uma perna e na outra vamos conectar na fileira de alimentação positiva da protoboard. Na mesma fileira vertical em que conectamos o resistor de 10kΩ devemos colocar um jumper ligando o LDR para a porta analógica A2 e da outra perna do resistor vamos ligar para a fileira de alimentação negativa.

Vale ressaltar que essa configuração faz com que o led acenda com a ausência de luz, caso você queira que o led acenda indicando que tem luz você deve trocar os lados das alimentações, ou seja, a perna do resistor deve ser ligada na fileira positiva e a outra perna do LDR deve ser ligada na fileira negativa da protoboard.
     
<div align="center">
<h3>Imagem 6: Circuito LDR</h3>	
<img width="500" height="200" alt="Image" src="https://github.com/user-attachments/assets/0d315dfc-9d20-49ab-a0e5-6ccc9e86a5de" />
<p>*(Fonte: Autoria própria (Tinkercad))*<p>
</div>

## Código do circuito:

Agora, vamos para a parte do código, nesta parte vamos aprender a programar nosso Arduino para poder usar o LDR. Vamos começar, primeiro declarando uma variável inteira com o nome “ValorSensor” e inicializá-la com o valor 0, essa prática é ideal para conseguir retirar ou eliminar resíduos dos compiladores. Em seguida, vamos utilizar o comando define para definir as variáveis LDR e LED que não poderão ser alteradas durante a execução do código, pois as conexões do LDR e LED não vão ser trocadas enquanto o código estiver em andamento.

```cpp
int ValorSensor = 0;
int Valor=0;
#define LED  4
#define LDR A2
```

Agora vamos passar para a função setup(), inicializada apenas quando o Arduino é ligado ou reiniciado. Nesta parte do código, utilizamos da função pinMode() para definir o estado dos pinos do LDR e do LED. Sendo, o pino analógico do LDR definido como entrada e o pino digital do LED como saída.
Temos também nosso monitor serial, uma ferramenta que nos permite enviar e transferir informações do Arduino para o computador ou vice versa. Para utilizá-la é preciso definir a taxa de transferência de bits entre o microcontrolador e o computador, utilizando do comando Serial.begin(9600). 

```cpp
void setup()
{
  pinMode(LDR, INPUT);
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}
``` 
Finalmente, temos a função loop() que será executada até que o Arduino seja desligado ou reiniciado. 

Em primeiro lugar, vamos utilizar o comando analogRead() para ler o valor do pino analógico especificado e armazenar o valor a cada leitura na nossa variável “ValorSensor”. Logo, temos em seguida o comando Serial.println() responsável por imprimir todos os dados coletados do LDR no monitor serial .

Em segundo lugar, vamos aplicar a função map()  que permite levar um número de um intervalo para outro. Neste caso, estamos levando da faixa 0 a 1023 para a faixa 0 a 255 com o intuito de controlar o LED por PWM (Conferir o nosso post sobre PWM para mais informações)

```cpp
void loop()
{
  ValorSensor = analogRead(LDR);
  Serial.println(ValorSensor);
  Valor = map(ValorSensor, 0, 1023, 0, 255);
  analogWrite(LED, Valor);
 delay(100);
}
```

Finalmente, por meio do nosso comando analogWrite() o qual envia o comando da tarefa a ser realizada, vamos conseguir mudar a intensidade do nosso LED de acordo com a intensidade de luz que o nosso LDR esteja recebendo.




