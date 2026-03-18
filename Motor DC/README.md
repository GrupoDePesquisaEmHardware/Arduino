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

O código abaixo demonstra o controle de direção e velocidade de motores DC utilizando sinais PWM:

```cpp
#define AIA  3 
#define AIB  9 
#define BIA 10 
#define BIB  6  

int speed = 255;
int temp = 100;

void setup() 
{
  Serial.begin(9600);
  
  pinMode(AIA, OUTPUT);
  pinMode(AIB, OUTPUT);
  pinMode(BIA, OUTPUT);
  pinMode(BIB, OUTPUT);

  stop();
}

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

void backward()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, speed);
  analogWrite(BIA, 0);
  analogWrite(BIB, speed);
}

void forward()
{
  analogWrite(AIA, speed);
  analogWrite(AIB, 0);
  analogWrite(BIA, speed);
  analogWrite(BIB, 0);
}

void backward_esq()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, speed);
}

void backward_dir()
{
  analogWrite(BIA, 0);
  analogWrite(BIB, speed);
}

void forward_esq()
{
  analogWrite(AIA, speed);
  analogWrite(AIB, 0);
}

void forward_dir()
{
  analogWrite(BIA, speed);
  analogWrite(BIB, 0);
}

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
