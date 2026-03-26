# Controle de Motores DC com Arduino

O controle de motores de corrente contínua (DC) é amplamente utilizado em projetos de robótica e automação, permitindo a movimentação de sistemas de forma precisa e controlada. 

Neste projeto, será apresentado o funcionamento de motores DC controlados por Arduino, abordando conceitos como controle de velocidade por PWM (Pulse Width Modulation) e controle de direção utilizando drivers baseados em ponte H.

<div align="center">
<h3>Figura 01: Motor DC</h3>
<img src="https://github.com/Valdemar-Neto/Code-Recognition-color-/assets/108936921/c5f6112b-f8a3-468c-8cee-bd2483b4fc78" width="250" height="250"/>
<p>Fonte: Autoria própria</p>
</div>

### Conexões

- **Motor DC** → Conectado ao driver de motor  
- **Driver (Ponte H)** → Interface entre Arduino e motor  
- **Pinos PWM** → Controle de velocidade  
- **Pinos digitais** → Controle de direção  
- **Fonte externa** → Alimentação do motor  

## Materiais Necessários
- Arduino (Uno, Mega, etc.)
- Motor DC
- Driver de motor (ex: L298N, L293D)
- Fonte de alimentação (bateria ou fonte DC)
- Jumpers
- Protoboard (opcional)

## Funcionamento do circuito

<div align="center">
<h3>Figura 02: Controle do Motor</h3>
<img src="https://github.com/Valdemar-Neto/Code-Recognition-color-/assets/108936921/502962f1-00c0-4801-bcb4-262caa19ee09" width="50%"/>
<p>Fonte: Autoria própria</p>
</div>

Um motor DC converte energia elétrica em energia mecânica. O controle do seu comportamento pode ser feito de duas formas principais:

- **Velocidade**: Controlada via PWM, variando a largura do pulso aplicado ao motor  
- **Direção**: Controlada pela inversão da polaridade da tensão  

O Arduino envia sinais digitais e PWM para um driver de motor, que atua como interface de potência, permitindo controlar o motor com segurança e eficiência.

### Ponte H

<div align="center">
<h3>Figura 03: Ponte H</h3>
<img src="https://github.com/Valdemar-Neto/Code-Recognition-color-/assets/108936921/f55be084-a234-440e-9960-81aac3ff93b8" width="250" height="250"/>
<p>Fonte: Adaptado de <a href="https://arduinoecia.com.br/motor-dc-com-encoder-arduino/"> Arduino e Cia </a></p>
</div>

A ponte H é um circuito eletrônico que permite inverter a polaridade da tensão aplicada ao motor, possibilitando seu funcionamento em dois sentidos:

- Sentido horário  
- Sentido anti-horário  

Drivers como **L298N** e **L293D** já possuem ponte H integrada, facilitando o controle bidirecional.

## Código

O código abaixo demonstra o controle de direção e velocidade de motores DC utilizando sinais PWM.

O bloco abaixo demonstra a configuração dos pinos analógicos utilizados injeção de valores para o controle do motor, assim como  a valocidade e o tempo de duração de cada atividade, a fim de movimentar um robõ para frente, para trás, para o lado direito e para o lado esquerdo.

```cpp
#define AIA  3 
#define AIB  9 
#define BIA 10 
#define BIB  6

int speed = 255;
int temp = 100;

```

Na função `setup()`, executada apenas uma vez quando o Arduino é ligado ou reiniciado, atribuímos cada pino analógico escolhido como saída e, para questão de seguranaça, a função `stop` é utilizada para validar os motores.
```cpp

void setup() 
{
  Serial.begin(9600);
  
  pinMode(AIA, OUTPUT);
  pinMode(AIB, OUTPUT);
  pinMode(BIA, OUTPUT);
  pinMode(BIB, OUTPUT);

  stop();
}

```

A função loop() será executada após a setup() e irá repetir o código dentro dela até o Arduino ser desligado ou reiniciado Porém, há uma particularidade nela que é a modularidade das funções que são usadas como `forward`, `backward`, `forward_dir`, `forward_esq` e `setop`. As funções são ativiadas sequencialmente de forma a simular o robô ir para frente, para trás, para direta, para esquerda e parar.

```cpp
void loop()
{
    forward();
    delay(temp);

    backward();
    delay(temp);
  
    forward_dir();
    backward_esq();
    delay(temp);

    forward_esq();
    backward_dir();
    delay(temp);

    stop();
    delay(temp);
}

```

A função backward() é responsável por movimentar o robô para trás. Para isso, ela inverte a polaridade aplicada aos motores, fazendo com que ambos girem no sentido contrário ao da função forward. Isso é feito aplicando o sinal PWM nos pinos responsáveis pelo sentido reverso de cada motor.

```cpp
void backward()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, speed);
  analogWrite(BIA, 0);
  analogWrite(BIB, speed);
}

```
A função forward() realiza o movimento do robô para frente. Nela, o sinal PWM é aplicado nos pinos que definem o sentido direto dos motores, enquanto os pinos opostos recebem valor zero, garantindo o giro correto.

```cpp
void forward()
{
  analogWrite(AIA, speed);
  analogWrite(AIB, 0);
  analogWrite(BIA, speed);
  analogWrite(BIB, 0);
}

```
A função backward_esq() é utilizada para movimentar o robô para trás com desvio à esquerda. Nesse caso, apenas um dos motores é acionado no sentido reverso, enquanto o outro permanece desligado, provocando a rotação do robô.

```cpp

void backward_esq()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, speed);
}

```
A função backward_dir() tem como objetivo movimentar o robô para trás com desvio à direita. De forma semelhante à função anterior, apenas o motor correspondente ao lado direito é acionado no sentido reverso.

```cpp

void backward_dir()
{
  analogWrite(BIA, 0);
  analogWrite(BIB, speed);
}

```

A função forward_esq() é responsável por movimentar o robô para frente com desvio à esquerda. Para isso, apenas o motor do lado esquerdo é acionado no sentido direto, enquanto o outro permanece desligado.

```cpp
void forward_esq()
{
  analogWrite(AIA, speed);
  analogWrite(AIB, 0);
}

```
A função forward_dir() realiza o movimento do robô para frente com desvio à direita. Nesse caso, apenas o motor do lado direito é acionado no sentido direto.

```cpp
void forward_dir()
{
  analogWrite(BIA, speed);
  analogWrite(BIB, 0);
}

```

Por fim, a função stop() é responsável por interromper completamente o movimento do robô. Ela define todos os pinos de controle dos motores com valor zero, garantindo que nenhum sinal seja enviado e que os motores parem de girar.

```cpp
void stop()
{
  analogWrite(BIA, 0);
  analogWrite(BIB, 0);
  analogWrite(AIA, 0);
  analogWrite(AIB, 0);
}

```

## Funcionamento do Código

O código implementa diferentes movimentos do motor por meio de funções específicas:

1. Movimento para frente (`forward`)

- Aplica PWM nos dois motores para avanço.

2. Movimento para trás (`backward`)

- Inverte a polaridade dos sinais.

3. Controle direcional

- `forward_dir()` e `forward_esq()` ajustam o movimento lateral

- `backward_dir()` e `backward_esq()` fazem o mesmo em ré

4. Parada (`stop`)

Zera todos os sinais PWM.

## Principais Funções Utilizadas

`pinMode()` → Configura pinos como entrada ou saída

`analogWrite()` → Gera sinal PWM para controle de velocidade

`Serial.begin()` → Inicializa comunicação serial

`delay()` → Define tempo entre ações

## Aplicações

O controle de motores DC é utilizado em:

- Robótica móvel

- Veículos autônomos

- Sistemas embarcados

- Automação industrial

- Projetos educacionais

## Requisitos de Funcionamento
### Alimentação

- Tensão compatível com o motor (ex: 6V a 12V)

### Componentes de Controle

- Driver de motor (ponte H)

- Arduino ou microcontrolador equivalente

## Contribuidor
<p><a href="https://github.com/Valdemar-Neto/">Valdemar Neto</a></p>
