# Módulo GPS

Você já ouviu falar sobre o GPS? Se você já compartilhou sua localização com um familiar, acompanhou uma corrida por aplicativo, rastreou a entrega de uma encomenda em tempo real ou fez um post nas redes sociais com a sua localização atual, você estava fazendo uso dessa tecnologia e, talvez, nem imaginasse!

Mas afinal, o que é o GPS? É uma sigla para *Global Positioning System* (ou Sistema de Posicionamento Global, em português) e, apesar de estar presente em várias funcionalidades do nosso cotidiano poucas pessoas conhecem o funcionamento por trás desse sistema de geolocalização.

Nesse projeto, vamos conhecer um pouco de como essa tecnologia ajudou a impulsionar a vida em sociedade e entender como podemos usar o GPS, por meio do Módulo GPS Neo-6M, para trabalhar com localização em nossos projetos eletrônicos. Para isso, utilizaremos uma placa Arduino como base para a aplicação prática.

## O que é o GPS?

O Sistema de Posicionamento Global (GPS) é um sistema de navegação por satélite capaz de definir a localização geográfica de um objeto com precisão de, aproximadamente, 5 metros.

<div align="center">
<h3>Figura 1 - Satélites do GPS</h3>	 
<img width="749" height="394" alt="image" src="https://files.tecnoblog.net/wp-content/uploads/2023/10/orbitas-satelites-gps-700x597.jpg/" />
<h4>Fonte: www.gps.gov </h4>
</div>

Do ponto de vista físico, o GPS consiste em um conjunto de 24 satélites que orbitam a Terra a uma distância aproximada de 20.000 quilômetros, como ilustra a figura acima. Cada satélite circunda o planeta duas vezes por dia e transmite um sinal que pode ser captado por dispositivos receptores, como o nosso módulo GPS, e usado para determinar a sua localização. Mas de que forma esse cálculo é feito?

O cálculo das coordenadas do receptor, a partir dos sinais recebidos pelos satélites, se dá por um processo chamado de triangulação. De forma resumida, se o dispositivo conseguir receber dados de pelo menos 4 satélites diferentes, ele pode encontrar a sua distância até cada um deles e relacioná-las para, depois de alguns cálculos trigonométricos, obter sua latitude e longitude.

No entanto, você não precisa ser um especialista no funcionamento do GPS para poder aproveitar os benefícios dessa tecnologia. Com esses conhecimentos iniciais, já estamos prontos para aplicar o GPS em um projeto prático com Arduino.

## Módulo GPS Neo-6M

O módulo GPS Neo-6M utiliza os sinais dos satélites para determinar a posição exata em latitude, longitude e altitude. Além da localização, ele também pode fornecer informações adicionais, como velocidade, direção e hora precisa.

Ele integra um receptor de GPS a pinos de alimentação e comunicação, podendo se conectar com diferentes placas de prototipagem e microcontroladores.

> **Figura 2** - Módulo GPS GY-NEO6MV2  
> **Fonte:** Adaptado de [AutoCore Robótica](https://http2.mlstatic.com/D_NQ_NP_765319-MLA99988235169_112025-O.webp)

### Conexões

- VCC → Alimentação (5V)
- GND → Terra
- TX → Transmissão serial de dados
- RX → Recepção serial de dados

### Materiais necessários

- Arduino (Uno, Mega, etc.)
- 4 fios macho-fêmea
- 1 Módulo GPS NEO-6M com Antena

## Funcionamento do circuito

Agora vamos montar o circuito necessário para utilizar o módulo GPS com o Arduino. Primeiro, conecte com um fio o pino GND do Arduino ao GND do módulo. Conecte também o pino 5V da placa ao pino VCC do Neo-6M.

Além disso, precisamos apenas fazer as conexões para estabelecer a comunicação Serial entre a nossa placa e o GPS. Para isso, basta conectar o RX do módulo ao pino 2 do Arduino e o TX ao pino 3 (A montagem completa está ilustrada na Figura 3, para você se basear). Feito isso, a nossa montagem estará pronta: você já tem um circuito de GPS funcional!

> **Figura 3** - Circuito eletrônico para ligação do Módulo GPS Neo-6M  
> **Fonte:** Adaptado de [S.T.A. Sistemas e Tecnologia Aplicada](https://www.sta-eletronica.com.br/resources/artigos/comoutilizaromodulogpsneo-6mcomoarduino-5.jpg)

## Código do circuito

A última parte que precisamos ajustar é a programação do Arduino. É por ela que vamos dar instruções para a nossa placa, passo a passo, sobre como receber, processar e imprimir corretamente as informações emitidas pelo GPS.

Primeiramente, os dados de GPS que o módulo envia estão todos codificados. Para interpretar essas mensagens e transformá-las em informações que sejam úteis para nós, portanto, vamos precisar de uma biblioteca chamada **TinyGPSPlus**. Essa biblioteca divide os dados "crus" recebidos pelo GPS em várias partes, chamadas de sentenças, e usa um algoritmo para traduzi-las em dados úteis, como latitude, longitude, data e hora.

Além disso, também vamos usar a biblioteca **SoftwareSerial** para realizar a comunicação Serial entre o módulo e o Arduino.

Desse modo, no início do código, precisamos importar essas bibliotecas:

```cpp
#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>
```

Em seguida, vamos definir constantes para informar quais os pinos da placa que vão receber (RXPin) e transmitir (TXPin) dados para o módulo, e definir a velocidade da comunicação Serial. Para o módulo Neo-6M, a taxa padrão é de 9600 *Baud*, mas, se você estiver usando um módulo diferente, não esqueça de consultar a taxa ideal para ele na sua respectiva documentação.

```cpp
static const int RXPin = 3, TXPin = 2;
static const uint32_t GPSBaud = 9600;
```

Vamos também criar objetos das duas bibliotecas. A instância da TinyGPSPlus será referenciada aqui como "gps". Para criar uma instância da SoftwareSerial, que será a responsável pela comunicação entre o módulo e o Arduino, precisamos informar os pinos de comunicação Serial utilizados.

```cpp
TinyGPSPlus gps;
SoftwareSerial ss(RXPin, TXPin);
```

Agora, vamos definir na função `setup()` o código de inicialização do projeto. A função `Serial.begin(115200)` inicializa a comunicação Serial com o monitor da Arduino IDE, e a velocidade de transmissão sendo passada é de 115200 *Baud*. Será nesse monitor que os dados recebidos e interpretados vão ser impressos e que vamos ver o resultado final do nosso projeto. A função `ss.begin(GPSBaud)`, por sua vez, inicializa a comunicação entre a placa e o módulo, à velocidade que definimos no início do código.

```cpp
void setup() {
  Serial.begin(115200);
  ss.begin(GPSBaud);
}
```

Com todas as configurações iniciais prontas, podemos escrever na função `loop()` a lógica principal do projeto. Primeiro, ela confere se a comunicação Serial foi devidamente inicializada e se está disponível. Se sim, tenta fazer a leitura dos dados com a função `read()`. Os resultados dessa leitura são passados como parâmetro para a função `encode()`, da TinyGPSPlus, que tenta decodificá-la. Se a função conseguir formar sentenças completas com os dados recebidos, retornando um valor diferente de zero, o código chama a função `displayInfo()`, que organiza e imprime os dados no monitor Serial.

```cpp
void loop() {
  while (ss.available() > 0)
    if (gps.encode(ss.read())) {
      displayInfo();
    }
```

Também vamos preparar o código para lidar com alguns casos de erro. Se houver mais de 5 segundos desde que o Arduino foi ligado e quase nenhum caractere tiver sido processado ainda, vamos considerar que nenhum GPS foi detectado. Com isso, finalizamos a função `loop`.

```cpp
  if (millis() > 5000 && gps.charsProcessed() < 10) {
    Serial.println(F("No GPS detected: check wiring."));
    while(true);
  }
}
```

Por fim, vamos dar uma olhada na função `displayInfo()`. O objetivo dela é formatar e imprimir três dados principais: as coordenadas, com latitude e longitude, a data e a hora. Para isso, usaremos as funções `Serial.println()` e `Serial.print()`, passando como parâmetro as informações que queremos imprimir, sendo que uma pula a linha no final da impressão e a outra não.

Note também que, antes de imprimir cada uma delas, nós conferimos se os dados recebidos são válidos através da função `isValid()`, da TinyGPSPlus; caso contrário, a string "INVALID" será impressa.

```cpp
void displayInfo() {
  Serial.print(F("Coordenadas: "));
  if (gps.location.isValid()) {
    Serial.print(gps.location.lat(), 6);
    Serial.print(F(","));
    Serial.println(gps.location.lng(), 6);
  } else {
    Serial.print(F("INVALID"));
  }

  Serial.print(F("Data/Hora: "));
  if (gps.date.isValid()) {
    Serial.print(gps.date.month());
    Serial.print(F("/"));
    Serial.print(gps.date.day());
    Serial.print(F("/"));
    Serial.print(gps.date.year());
  } else {
    Serial.println(F("INVALID"));
  }

  Serial.print(F(" "));
  if (gps.time.isValid()) {
    if (gps.time.hour() < 10) Serial.print(F("0"));
    Serial.print(gps.time.hour());
    Serial.print(F(":"));
    if (gps.time.minute() < 10) Serial.print(F("0"));
    Serial.print(gps.time.minute());
    Serial.print(F(":"));
    if (gps.time.second() < 10) Serial.print(F("0"));
    Serial.print(gps.time.second());
    Serial.print(F("."));
    if (gps.time.centisecond() < 10) Serial.print(F("0"));
    Serial.println(gps.time.centisecond());
  } else {
    Serial.println(F("INVALID"));
  }

  Serial.println();
}
```

Com o código pronto, você já pode fazer o upload para o Arduino. Pode ser que o módulo leve um tempo para inicializar e começar a captar os dados, mas, assim que ele receber os primeiros sinais, você verá algum feedback no monitor.

Lembrando também que a recepção de sinais pelo GPS pode ser dificultada se estiver dentro de prédios, casas, debaixo de árvores densas, ou sob áreas cobertas em geral; por isso, prefira fazer os seus testes em ambientes abertos e demais lugares que não tenham cobertura.

Se tudo der certo, você deve obter algo parecido com a Figura 4 como saída no Monitor Serial. A data e hora exibidas são do relógio atômico recebidos diretamente dos satélites e estão no formato UTC, um horário-padrão internacional. No entanto, a TinyGPSPlus possui funções para convertê-las para o horário local, se você quiser ampliar o projeto.

> **Figura 4** - Impressão dos dados captados pelo GPS no monitor serial  
> **Fonte:** Autoria própria (https://drive.google.com/file/d/1KQFjJOSzcsHoxgPToDlEb3DWgaZ3IJ3N/view?usp=sharing)

Com isso, você já tem um sistema básico de geolocalização funcionando. A partir daqui, é possível expandir o projeto para aplicações como rastreamento, navegação ou IoT.
