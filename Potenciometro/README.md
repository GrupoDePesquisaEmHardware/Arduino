# Potenciômetro

Você já ouviu falar no potenciômetro? Ele é um componente eletrônico muito utilizado em nosso dia a dia, desde o controle de volume em aparelhos de som como rádios e guitarras até o movimento dos controles analógicos de videogame! Mas como exatamente ele funciona?

Em termos simples, ele é um resistor variável, ou seja, sua resistência pode ser alterada por meio de um movimento mecânico, geralmente ao girar o seu eixo. Além disso, também pode atuar como divisor de tensão, pois possui três terminais, dois nas extremidades e um central, o que permite um fornecimento variável de tensão de saída entre `0V` e `5V` no terminal central, proporcionando, por exemplo, a obtenção de diferentes intensidades de luz ao manipulá-lo.

Algo interessante é que, devido à variedade de aplicações, outros tipos de potenciômetros são necessários, com diferentes formas de funcionamento e construção. Que tal conhecer alguns dos tipos mais comuns de potenciômetros para entender melhor suas aplicações possíveis?



# Tipos de Potenciômetros

## Quanto à operação

### Potenciômetro deslizante

Possui um controle deslizante que passa por uma trilha resistiva, que varia a resistência com a movimentação do controle. Este tipo é utilizado em mesas de som e controladores de áudio.

<div align="center">
<h3>Figura 1 - Potenciômetro deslizante</h3>
<img width="400" height="300" alt="Image" src="https://www.usinainfo.com.br/1024442-thickbox_default/modulo-potenciometro-deslizante-10k-para-arduino.jpg" />
<h4>Fonte: https://www.usinainfo.com.br/modulo-potenciometro/modulo-potenciometro-deslizante-10k-para-arduino-4605.html</h4>
</div>



### Potenciômetro rotativo

Este tipo possui um controle giratório, com três terminais, que permite a variação da resistência ao rotacionar o eixo para um lado ou para o outro. Este tipo é comumente utilizado em instrumentos musicais como guitarras e amplificadores.

<div align="center">
<h3>Figura 2 - Potenciômetro rotativo</h3>
<img width="400" height="300" alt="Image" src="http://3.bp.blogspot.com/-tR8sU4b2lW8/TmWYixnWE_I/AAAAAAAACww/-wgGKAVqCac/s1600/Potenciomentro.jpg" />
<h4>Fonte: https://www.squids.com.br/arduino/projetos-arduino/squids-hub/basico/325-hub-009-piscar-led-de-acordo-com-o-potenciometro-arduino</h4>
</div>



### Trimpot

É um tipo de potenciômetro de pequeno porte projetado para ajustes finos e precisos em circuitos eletrônicos, por isso, geralmente não é manipulado com frequência. É muito presente em calibrações de sistemas de ganho ou tensão em circuitos de precisão.

<div align="center">
<h3>Figura 3 - Trimpot</h3>
<img width="400" height="300" alt="Image" src="https://encrypted-tbn2.gstatic.com/shopping?q=tbn:ANd9GcTVaWp4jIKdZUcprfEVWZKIMVWZAltC8F3iy4arTLZQ-gtlZre_ev1kC3N0MLcOyXCVdvh7bDYZ5su0UiSl7jxilLppYwsEoJ0roJvnz7hjIustsIExF6fX" />
<h4>Fonte: https://www.eletrogate.com/potenciometro-trimpot-10k-horizontal</h4>
</div>



### Potenciômetro digital

Este tipo de potenciômetro simula um potenciômetro convencional, mas utiliza sinais digitais para variar a resistência ao invés do controle mecânico. Geralmente estão presentes em sistemas eletrônicos e automatizados.

<div align="center">
<h3>Figura 4 - Potenciômetro digital</h3>
<img width="400" height="300" alt="Image" src="https://cdn.awsli.com.br/600x700/468/468162/produto/73535741/276b75881f.jpg" />
<h4>Fonte: https://www.eletrogate.com/modulo-potenciometro-digital-100k-x9c104s</h4>
</div>



### Potenciômetro Encoder

Também é um potenciômetro digital, mas possui um eixo giratório sem limite de rotações, que permite o envio de pulsos digitais com base na noção da posição atual, obtida pela conversão da quantidade de giros analógicos e o local em que o movimento cessou.

Este equipamento é muito comum para controle de áudio, navegação em menus, automação industrial e precisão em projetos robóticos.

<div align="center">
<h3>Figura 5 - Potenciômetro Encoder</h3>
<img width="400" height="300" alt="Image" src="https://images.tcdn.com.br/img/img_prod/900872/potenciometro_encoder_sem_fim_3_terminais_687_2_a799b42d719f0be558f642471abd5fa9_20250818175651.jpg" />
<h4>Fonte: https://www.eletrodex.net/passivos/potenciometros/encoder/potenciometro-encoder-sem-fim-3-terminais</h4>
</div>



# Quanto ao tipo de variação de resistência

## Potenciômetro linear

Neste tipo, a variação da resistência é proporcional ao movimento físico aplicado, ou seja, ao girar ou deslizar o controle, a resistência será alterada de forma linear. São usados no controle de brilho e de posição com sensores.



## Potenciômetro logarítmico

Já neste caso, a resistência não varia de forma proporcional ao movimento do eixo, pois não segue uma distribuição uniforme no percurso e sim logarítmica.

Assim, ao girar ou deslizar o controle, a variação ocorre de forma gradual em certas partes e mais intensa em outras. Essa característica acompanha melhor a forma como percebemos o som, o que garante a sua melhor aplicação em instrumentos musicais e sistemas de controle de áudio.

<div align="center">
<h3>Figura 6 - Tipos de variação de resistência com potenciômetros</h3>
<img width="500" height="300" alt="Image" src="https://newtoncbraga.com.br/images/stories/desafio/duv0131_01.png" />
<h4>Fonte: https://newtoncbraga.com.br/index.php/duvidas/2228-duv131</h4>
</div>



# Potenciômetro com Arduino

Mas e com o Arduino? Nesse caso, diversas aplicações são possíveis com o potenciômetro. Uma das mais comuns é a variação de intensidade de LEDs, mas outras aplicações também são relevantes, como a movimentação de um servo motor, permitindo, por exemplo, variar sua posição em até `180 graus`.

<div align="center">
<h3>Figura 7 - Servo Motor</h3>
<img width="350" height="300" alt="Image" src="https://www.electronicwings.com/storage/PlatformSection/TopicContent/134/icon/Servo%20Motor.jpg" />
<h4>Fonte: https://www.electronicwings.com/sensors-modules/servo-motor</h4>
</div>

Para melhor compreensão do funcionamento do Servo Motor, acesse:

```txt
https://github.com/GrupoDePesquisaEmHardware/Arduino/blob/e0204e56985815fe103ebe67429752b5ce46302b/Servo%20Motor%20SG90/README.md
```

Com isso, vamos começar a entender a aplicação prática do uso do nosso potenciômetro e o que iremos precisar para a execução do experimento.



# Materiais necessários

- 1 Arduino Uno R3
- 1 Protoboard simples
- 1 Potenciômetro
- 1 Servo motor SG90
- 8 Jumpers
- 1 Fonte de alimentação para o Arduino



# Aplicação

<div align="center">
<h3>Figura 8 - Circuito com potenciômetro e servo motor</h3>
<img width="550" height="350" alt="Image" src="https://raw.githubusercontent.com/sadinet125/Images-Pot/refs/heads/main/Captura%20de%20tela%202026-05-18%20161618.png"/>
<h4>Fonte: Autoria própria</h4>
</div>

Primeiramente, nesta aplicação utilizaremos um potenciômetro linear, pois precisamos que a variação da posição do servo seja proporcional ao movimento do eixo. Além disso, usaremos a protoboard para melhor organização do circuito, posicionando o `GND` e o `5V` do Arduino no barramento de alimentação (parte inferior, com sinais `-` e `+` respectivamente) e, por convenção, os jumpers de aterramento são de cor cinza ou preta para `GND` e vermelha para o `VCC`.

Ao conectar os terminais extremos do potenciômetro ao barramento de alimentação da protoboard (`VCC` e `GND`), o terminal central passa a fornecer um sinal variável, atuando como um circuito divisor de tensão. Esse valor de saída depende da posição do eixo do potenciômetro, permitindo obter diferentes valores de tensão ao girá-lo. 

Depois dessa etapa, vamos seguir com o servo motor. Esse equipamento também possui três terminais:

- Alimentação (`VCC`), no centro
- Terra (`GND`), na direita
- Terminal de sinal, à esquerda

O terminal de sinal deve ser conectado ao pino digital `3` (com símbolo `~`), o qual permite o funcionamento do circuito por meio da tecnologia PWM (*Pulse Width Modulation*), ideal para o controle preciso da posição do servo motor.

Ela utiliza pulsos elétricos com larguras entre `1ms` e `2ms` para definir a posição do eixo do servo com base na variação da largura dos pulsos.

Assim, com os componentes devidamente conectados, devemos partir para o código, que garantirá a lógica de funcionamento do circuito.



# Código

Primeiramente, abaixo vamos iniciar a biblioteca ideal para trabalhar com o servo, otimizando o uso do PWM com esse equipamento e outras ferramentas úteis do próprio Arduino.

```cpp
#include <Servo.h>
```

Depois de adicionar a biblioteca, devemos criar a constante `potenciometro_pin` e associá-la a um pino analógico, que será responsável por captar a variação de tensão e enviá-la ao Arduino para conversão usando o ADC (*Conversor Analógico-Digital*), responsável por transformar o sinal analógico lido no pino em valores entre `0` e `1023`.

O uso do `#define` permite que, ao utilizarmos as funções de leitura dos sinais, não seja necessário identificar o pino analógico a todo momento, e sim a constante.

```cpp
#define potenciometro_pin A0
```

Agora que fizemos a parte introdutória do código, vamos finalmente criar as variáveis, que também associamos a pinos digitais, responsáveis por interpretar os sinais utilizando o PWM.

Então, criaremos as variáveis `meu_servo`, `leitura_potenciometro` e `anguloservo`.

As duas últimas são inicializadas com o valor `0`, garantindo um estado inicial definido sempre que o código é executado.

A primeira não usa o comando `int` e sim a classe `Servo` da biblioteca que adicionamos.

```cpp
Servo meu_servo;
int leitura_potenciometro = 0;
int anguloservo = 0;
```

Na sequência, iremos aplicar os comandos iniciais de funcionamento utilizando a função `setup()`, que é executada apenas uma vez ao ligar ou reiniciar o Arduino.

Dentro da função `setup`, colocaremos o objeto `meu_servo` atrelado às funções `attach(3)` e `write(0)` para respectivamente identificar o pino digital conectado e o valor inicial recebido pelo servo motor ao ligar o Arduino.

```cpp
void setup(){
  meu_servo.attach(3);
  meu_servo.write(0);
}
```

Agora chegamos na parte final do código, que possibilitará a continuidade da operação entre o potenciômetro e o servo motor.

Para isso, utilizaremos a função `loop()`, que repetirá continuamente os comandos associados a ela até que a alimentação do Arduino seja desligada. Dentro da função `loop`, aplicamos a função `analogRead()`, para que o valor analógico lido no pino seja convertido em valores digitais de `0` a `1023`.

Depois, utilizamos a função `map()`, que converterá os valores lidos para graus, de `0` a `180`.

```cpp
void loop(){
  leitura_potenciometro = analogRead(potenciometro_pin);
  anguloservo = map(leitura_potenciometro, 0, 1023, 0, 180);
  meu_servo.write(anguloservo);
}
```

Por fim, atrelamos ao objeto `meu_servo` a função `.write(valor)`, que envia ao servo a posição desejada.

Então, por meio do PWM gerado automaticamente pela biblioteca, funções nativas convertem o valor em pulsos elétricos adequados, movimentando o eixo do servo de forma proporcional ao giro do potenciômetro.

Ao terminar todo o código, essa aplicação do potenciômetro com o servo motor estará pronta para execução e demonstrará, de forma prática, como o potenciômetro pode ser utilizado em sistemas embarcados, unindo programação com Arduino e conceitos de eletrônica.



## Colaboradores

- [Sadi Medeiros](https://github.com/sadinet125)