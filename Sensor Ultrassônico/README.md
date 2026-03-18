# Sensor Ultrassônico

Os sensores ultrassônicos são componentes fundamentais em sistemas de detecção de objetos e medição de distância, sendo amplamente utilizados em aplicações como robótica, automação e sistemas de segurança. 

Esses sensores operam por meio da emissão de ondas sonoras em alta frequência (acima de 20 kHz), permitindo calcular distâncias com boa precisão a partir do tempo de retorno do sinal refletido. Neste projeto, será apresentado o funcionamento do sensor ultrassônico, bem como sua aplicação prática com microcontroladores.

<div align="center">
<h3>Figura 01: Sensor Ultrassônico</h3>
<img src="https://github.com/Valdemar-Neto/Valdemar-Neto/assets/108936921/1c9cdde5-b8c6-43ef-a60a-858578ba3139" width="250" height="250"/>
<p>Fonte: Autoria própria</p>
</div>

### Conexões

- **VCC** → Alimentação (5V)  
- **GND** → Terra  
- **TRIG** → Pino digital de saída  
- **ECHO** → Pino digital de entrada 

## Materiais Necessários
- Sensor ultrassônico (HC-SR04)
- Placa Arduino (Uno ou similar)
- Jumpers macho-macho
- Protoboard
- Cabo USB para alimentação

## Funcionamento do circuito

<div align="center">
<h3>Figura 02: Diagrama de Funcionamento</h3>
<img src="https://github.com/user-attachments/assets/dd75245f-0450-4245-8827-c0603ef1cffc" />
<p>Fonte: Adaptado de <a href="https://cursos.mcielectronics.cl/2022/12/06/como-funciona-el-sensor-ultrasonico-hc-sr04-y-como-se-conecta-con-arduino/">MCI Education</a></p>
</div>

O sensor ultrassônico funciona a partir da emissão e recepção de ondas sonoras. O processo ocorre em quatro etapas principais:

1. **Emissão do Pulso**: O pino TRIG envia um pulso ultrassônico.  
2. **Propagação e Reflexão**: O pulso percorre o ar até encontrar um obstáculo e retorna ao sensor.  
3. **Recepção do Pulso**: O pino ECHO recebe o sinal refletido.  
4. **Cálculo da Distância**: O tempo entre envio e recepção é utilizado para determinar a distância.  

## Cálculo da Distância

A distância é calculada com base no tempo de ida e volta da onda sonora:
<center> d = (t × v) / 2 </center>

Onde:
- **d** é a distância  
- **t** é o tempo medido  
- **v** é a velocidade do som (aproximadamente 343 m/s)  

## Código

Para demonstrar o funcionamento do sensor, o código abaixo realiza a leitura da distância e imprime o valor no monitor serial:

```cpp
#define TRIG 11
#define ECHO 10

float distance;

// Função para ler a duração do pulso ultrassônico e calcular a distância
int ler() {
  unsigned long timeInicio, timeDuracao;

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  while (digitalRead(ECHO) == LOW) {}

  timeInicio = micros();

  while (digitalRead(ECHO) == HIGH) {}

  timeDuracao = micros() - timeInicio;
  Serial.println(timeDuracao);

  return (timeDuracao / 55);
}

void setup() {
  Serial.begin(9600);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  digitalWrite(TRIG, LOW);
}

void loop() {
  distance = ler();

  Serial.print("Distancia: ");
  Serial.println(distance);

  delay(100);
}
```

## Funcionamento do Código

A função ler() executa três etapas principais:

1. Emissão do Pulso Ultrassônico
   - O pino TRIG é ativado por 10 microsegundos.

2. Medição do Tempo
   - Aguarda o sinal de retorno no pino ECHO.
   - Mede o tempo utilizando a função micros().

3. Cálculo da Distância
   - O tempo é convertido em distância utilizando um fator de escala (divisão por 55).

## Principais Funções Utilizadas

- pinMode() → Define o modo do pino (entrada ou saída)

- digitalWrite() → Envia sinal HIGH ou LOW

- digitalRead() → Lê o estado do pino

- delayMicroseconds() → Pausa em microssegundos

- micros() → Retorna o tempo em microssegundos

- Serial.begin() → Inicializa comunicação serial

- Serial.print() → Imprime dados

- Serial.println() → Imprime dados com quebra de linha

- delay() → Pausa em milissegundos

## Aplicações

Os sensores ultrassônicos podem ser utilizados em diversas áreas:

- Robótica: Navegação e prevenção de colisões

- Automação Industrial: Medição de nível e detecção de objetos

- Automóveis: Sensores de estacionamento

- Segurança: Detecção de presença

- Domótica: Automação residencial

## Requisitos de Funcionamento
Alimentação

- Tensão: 5V

- Corrente: 10mA a 50mA

Condições Ambientais

- Temperatura: -15°C a +70°C

- Umidade: 5% a 95%

# Contribuidor

- <p><a href="https://github.com/Valdemar-Neto/\">Valdemar Neto</a></p>
