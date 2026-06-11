<img width="499" height="232" alt="SENSOR" src="https://github.com/user-attachments/assets/7adb1bc2-9129-4855-96af-00701670a814" /># Módulo RFID RC522

**Autor:** Marcius Gayber de Lima Pinto Júnior

---

## Introdução

Provavelmente muitos de vocês nunca tenham ouvido falar sobre RFID, mas, se alguém aqui já pegou um ônibus e usou a carteirinha de estudante para pagar a meia-entrada, ou até mesmo utilizou a carteirinha para realizar refeições no RU (Restaurante Universitário), então já teve contato com essa tecnologia sem perceber.

A tecnologia RFID é amplamente utilizada de forma eficiente em diversos contextos. Seus principais usos incluem:

### Logística

Utilizada para identificação e rastreamento de produtos e pacotes, tornando as operações mais ágeis, precisas e automatizadas.

### Controle de acesso

Aplicada tanto em ambientes corporativos, restringindo o acesso de funcionários a áreas específicas, quanto em situações do cotidiano, como no uso de carteirinhas estudantis para entrada em locais ou serviços.

---

# Módulo RFID

A sigla **RFID (Radio Frequency Identification)** define uma tecnologia capaz de identificar objetos utilizando ondas de rádio.

O sistema é composto por duas partes principais:

* **Tag RFID:** formada por uma antena e um chip contendo informações.
* **Leitor RFID:** formado por um módulo de radiofrequência e uma antena geradora de campo eletromagnético.

Quando a tag se aproxima do leitor, o campo eletromagnético gerado induz uma corrente elétrica na antena da tag, alimentando o chip. Após ser energizado, o chip transmite seus dados por radiofrequência ao leitor, que interpreta essas informações e as envia para processamento.

### Figura 1– Funcionamento do Sensor RFID
<img width="494" height="243" alt="RFIDEXPL" src="https://github.com/user-attachments/assets/9838fa2b-0794-4f64-a000-fd5889e3de09" />
*Fonte: [GTA UFRJ]([https://meusite.com](https://www.gta.ufrj.br/grad/07_1/rfid/RFID_arquivos/como%20funciona.htm))*

---

## Identificação por UID

Cada tag RFID possui um código único chamado **UID (Unique Identifier)**, que funciona como um CPF digital emitido de fábrica.

Além do UID, algumas tags possuem memória interna para armazenar:

* Dados personalizados;
* Permissões de acesso;
* Créditos ou saldos.

Embora o princípio de funcionamento seja o mesmo, as tags RFID podem ser classificadas de acordo com sua alimentação:

### Tags Passivas

* Não possuem bateria.
* São energizadas pelo campo eletromagnético do leitor.
* Possuem menor alcance.
* São as mais utilizadas.

### Tags Ativas

* Possuem bateria própria.
* Alcançam maiores distâncias.

### Tags Semi-passivas

* Possuem bateria para alimentar o circuito interno.
* Dependem do leitor para transmitir os dados.

---

## Faixas de Frequência RFID

### Low Frequency (LF)

* Frequência: 125–134 kHz
* Alcance: poucos centímetros
* Alta resistência a interferências

### High Frequency (HF)

* Alcance de até 1 metro
* Comunicação mais rápida
* Muito utilizada em cartões de acesso

### Ultra High Frequency (UHF)

* Alcance entre 3 e 15 metros
* Permite leitura simultânea de várias tags
* Utilizada em pedágios e centros de distribuição

---

# Interface de Comunicação e Pinagem

No módulo **RC522**, a comunicação com o Arduino é realizada através do protocolo **SPI (Serial Peripheral Interface)**.

### Pinos do módulo

| Pino     | Função                                |
| -------- | ------------------------------------- |
| RST      | Reinicializa o módulo                 |
| MOSI     | Envia dados do Arduino para o RC522   |
| MISO     | Envia dados do RC522 para o Arduino   |
| SCK      | Clock de sincronização da comunicação |
| SDA (SS) | Seleção do dispositivo SPI            |
| IRQ      | Pino de interrupção                   |

### Figura 2 – Sensor RFID com pinos identificados
<img width="499" height="232" alt="SENSOR" src="https://github.com/user-attachments/assets/8d303930-0ee3-4219-b7a0-dcc3c44331a5" />


*Fonte:[DIY Engineers]([https://meusite.com](https://www.diyengineers.com/2021/04/15/learn-how-to-read-an-rfid-tag-with-rc522-and-arduino/))*

---

# Materiais Necessários

* Arduino Uno
* Protoboard
* 1 LED
* 1 Resistor de 220 Ω
* 1 Módulo RFID RC522
* 1 Tag RFID
* 7 Jumpers macho-fêmea
* 4 Jumpers macho-macho

---

# Montando o Circuito

Agora vamos colocar a teoria em prática montando um circuito simples utilizando o módulo RFID RC522.

### Figura 3 – Circuito montado
<img width="631" height="457" alt="CIRCUITO" src="https://github.com/user-attachments/assets/d845be8b-808c-458e-8511-d9154de35647" />


*Fonte: Autoria própria (Wokwi)*

---

## Ligação do LED

1. Conecte o resistor ao terminal negativo (cátodo) do LED.
2. Ligue o resistor ao GND.
3. Conecte o terminal positivo (ânodo) à porta digital 2 do Arduino.

Dessa forma, o LED acenderá apenas quando o Arduino enviar o comando correspondente.

---

## Ligação do Módulo RFID

A alimentação do módulo é feita da seguinte forma:

* 3.3V do RC522 → 3.3V do Arduino
* GND do RC522 → GND do Arduino

### Tabela 1 – Ligação Arduino × RC522

| Pino RC522 | Arduino       | Cor (Identificação) |
| ---------- | ------------- | ------------------- |
| RST        | D7            | Amarelo             |
| MOSI       | D11           | Rosa                |
| MISO       | D12           | Verde               |
| SCK        | D13           | Azul                |
| SDA (SS)   | D10           | Laranja             |
| IRQ        | Não utilizado | —                   |

---

# Código

## Bibliotecas Utilizadas

```cpp
#include <SPI.h>
#include <MFRC522.h>
```

* **SPI.h**: Biblioteca oficial responsável pela comunicação SPI.
* **MFRC522.h**: Biblioteca específica para controle do sensor RFID.

---

## Definição dos Pinos

```cpp
#define SDA_PIN 10
#define RST_PIN 9
#define LED_PIN 2
```

Essas diretivas criam apelidos para os pinos utilizados, facilitando a leitura e manutenção do código.

---

## Instanciação do Sensor

```cpp
MFRC522 rfid(SDA_PIN, RST_PIN);
```

Essa linha cria o objeto responsável por controlar o módulo RFID.

Os demais pinos SPI (MOSI, MISO e SCK) são gerenciados automaticamente pela biblioteca SPI.

---

## Função Setup

```cpp
void setup() {
  Serial.begin(9600);

  SPI.begin();

  rfid.PCD_Init();

  pinMode(LED_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);

  Serial.println("Aproxime a tag");
}
```

### Explicação

* `Serial.begin(9600)` inicia a comunicação serial.
* `SPI.begin()` inicializa o protocolo SPI.
* `rfid.PCD_Init()` prepara o RC522 para leitura de tags.
* `pinMode(LED_PIN, OUTPUT)` configura o LED como saída.
* `digitalWrite(LED_PIN, LOW)` mantém o LED apagado inicialmente.
* `Serial.println("Aproxime a tag")` exibe uma mensagem ao usuário.

---

## Função Loop

```cpp
void loop() {

  if (!rfid.PICC_IsNewCardPresent()) {
    return;
  }

  if (!rfid.PICC_ReadCardSerial()) {
    return;
  }

  digitalWrite(LED_PIN, HIGH);

  delay(2000);

  digitalWrite(LED_PIN, LOW);
}
```

### Explicação

A função `loop()` é executada continuamente enquanto o Arduino estiver ligado.

1. `PICC_IsNewCardPresent()` verifica se existe uma nova tag próxima ao leitor.
2. Caso não exista nenhuma tag, o programa retorna ao início do loop.
3. Quando uma tag é detectada, `PICC_ReadCardSerial()` realiza a leitura de seus dados.
4. Se a leitura for bem-sucedida:

   * O LED é aceso.
   * Permanece ligado por 2 segundos.
   * Em seguida é apagado.
5. O programa retorna ao estado de espera para uma nova leitura.

---

# Resultado

Ao aproximar uma tag RFID do módulo RC522:

* A tag é detectada.
* Seus dados são lidos pelo Arduino.
* O LED acende por 2 segundos indicando uma leitura bem-sucedida.
* O sistema retorna ao modo de espera para uma nova identificação.

---

# Conclusão

O módulo RFID RC522 é uma solução simples e de baixo custo para sistemas de identificação por radiofrequência. Sua integração com o Arduino permite desenvolver aplicações como controle de acesso, autenticação de usuários, automação residencial, controle de presença e rastreamento de objetos.

Por meio deste projeto foi possível compreender os conceitos fundamentais da tecnologia RFID, sua comunicação através do protocolo SPI e a implementação prática de um sistema básico de identificação utilizando Arduino.
