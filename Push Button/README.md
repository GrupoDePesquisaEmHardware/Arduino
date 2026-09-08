# Push Button
Você sabe o que é Push Button?  Vem cá que eu te explico! 

Push button, botão de pressão ou ainda chave táctil, é um interruptor simples, o qual fará ações de permitir ou interromper a passagem de corrente elétrica ao pressionar ou soltar o botão. 
<div align="center">
<h3>Figura 1: Botão e seus terminais </h3> 
<img width="800" height="345" alt="Image" src="https://github.com/user-attachments/assets/3952e89b-443b-4bc9-bd27-22409dea0b7f" />
<h4>Fonte: ROBOCORE (Módulo Relé Serial - Acionamento por Botão) </h4>
</div>

# Como Funciona?
O botão possui 4 terminais divididos em dois pares interligados internamente A-C e B-D, pelos quais a corrente passa continuamente, independente do estado do botão.  Para utilizar o botão como chave, as conexões externas devem ser feitas entre pinos de pares diferentes, podendo operar em duas estruturas:

**Normalmente Fechados (NF):** O push button do tipo NF permite a passagem de corrente em seu estado de repouso (figura 2) até que o botão seja pressionado (figura 3), abrindo assim o circuito e impedindo a passagem de corrente.
<div align="center">
<table border="0">
  <tr>
    <td width="50%" align="center" valign="top">
      <h3>Figura 2 - Circuito NF (repouso)</h3>
    </td>
    <td width="50%" align="center" valign="top">
      <h3>Figura 3 - Circuito NF (pressionado)</h3>
    </td>
  </tr>
  <tr>
      <td align="center" valign="top">
        <img src="https://github.com/user-attachments/assets/647ff680-32a1-4099-b166-f976febe77db" /> 
      </td>
      <td align="center" valign="top">
        <img src="https://github.com/user-attachments/assets/6b938147-984c-48ab-9b74-6b2d72477616" />  
      </td>
    </tr>
</table>
  <h4>Fonte: autoria própria </h4>
</div>

**Normalmente Abertos (NA):** Para NA, o estado de repouso é diferente, pois fica desconectado (figura 4),  pois não há ligações entre os terminais até que o botão seja pressionado e a corrente consiga passar normalmente (figura 5).
<div align="center">
<table border="0">
  <tr>
    <td width="50%" align="center" valign="top">
      <h3>Figura 2 - Circuito NF (repouso)</h3>
    </td>
    <td width="50%" align="center" valign="top">
      <h3>Figura 3 - Circuito NF (pressionado)</h3>
    </td>
  </tr>
  <tr>
      <td align="center" valign="top">
        <img src="https://github.com/user-attachments/assets/5a966289-7985-4821-9eaa-e6568ebfa26e" />
      </td>
      <td align="center" valign="top">
        <img src="https://github.com/user-attachments/assets/5da48156-2e6d-430a-ad04-c1649c703bc7" />
      </td>
    </tr>
</table>
  <h4>Fonte: autoria própria </h4>
</div>

# Materiais Necessários:
- Arduino uno;
- 1 Botão;
- 1 LED;
- 1 Resistor 1 kΩ ;
- Cabo de alimentação do Arduino.

Normalmente, o Arduino utiliza pinos configurados como saída (OUTPUT) como no caso dos leds e entrada (INPUT) como no caso dos push buttons,  para enviar e receber sinais, respectivamente. Há três maneiras de se conectar o botão, sendo eles: 

# Modo Pull-Down Externo

Neste modo, utilizamos um resistor externo para deixar o pino em nível lógico 0. Quando tiver pressão, a chave táctil permite a passagem de energia, mostrando o valor 1.

# Circuito:

Para conectar o push button ao arduíno em pull-down externo, iremos ligar o 5v do microcontrolador ao terminal C do botão, a porta digital 2 ao terminal B e o GND ao resistor conectado ao terminal D (figura 6).

<div align="center">
<h3>Figura 6: Circuito Pull-Down Externo </h3> 
<img width="540" height="345" alt="Image"src="https://github.com/user-attachments/assets/8f8ff69e-1230-4d1a-94ee-0362a9986c09" />
<h4>Fonte: autoria própria  </h4>
</div>

# Modo Pull-UP Externo:

Funciona de maneira semelhante ao Pull-Down externo, com a diferença de que agora o resistor vai deixar o nível lógico em 1 quando o push button estiver em repouso. Quando o botão é pressionado, o valor lido passa a ser 0.
# Circuito: 

Para conectar o push button ao arduíno utilizando a configuração pull-up externa, o resistor deve ser conectado entre o pino de alimentação 5V  e o terminal C do botão. Em seguida, a porta digital 2 do arduino deve ser conectada ao terminal A, enquanto o GND deve ser conectado ao terminal D (figura 7).

<div align="center">
<h3>Figura 7 - Circuito Pull-UP Externo </h3> 
<img width="540" height="345" alt="Image"src="https://github.com/user-attachments/assets/e0ca6d34-ac34-4d1e-a30c-b40b9c99b483" />
<h4>Fonte: autoria própria  </h4>
</div>

# Código

Agora vamos montar o código?  Este código funciona para os dois primeiros modos de pull que já aprendemos. Iniciamos definindo uma variável “botao” como a porta digital 2 que está ligada ao botão:

```cpp
int botao = 2;
```

Em seguida, no ```cpp void setup()```, iremos configurar o modo de operação do pino do botão como INPUT e a comunicação serial:

```cpp
pinMode(botao, INPUT);
Serial.begin(9600);
```
Na função ```cpp void loop()```, por hora queremos apenas testar os modos de funcionamento do push button, vamos com a ajuda do Serial.println() ver a leitura do estado atual do botão com o “digitalRead”:

```cpp
Serial.println(digitalRead(botao));
```

# Modo Pull-UP Interno: 

**Explicação:**  Este modo serve para mostrar as mesmas leituras do pull-up externo. O que vai diferenciar é que utilizaremos uma configuração chamada INPUT_PULLUP para utilizarmos um resistor interno do arduino, dispensando assim o uso de um componente externo do resistor e do 5v que também será fornecido internamente pelo arduíno.

# Circuito: 

Para conectar o push button ao arduíno em pull-up interno, iremos ligar a porta digital 2 ao terminal A e o GND será conectado ao terminal D no botão (figura 8).

<div align="center">
<h3>Figura 8 - Circuito Pull-UP Interno </h3> 
<img width="540" height="345" alt="Image"src="https://github.com/user-attachments/assets/4f2f947a-762e-4c10-8a45-f15d09b9c996" />
<h4>Fonte: autoria própria  </h4>
</div>

# Código

Para o pull-up interno, teremos o seguinte código:

```cpp

int botao = 2;
void setup()
{
  pinMode(botao, INPUT_PULLUP);
  Serial.begin(9600);
}


void loop()
{
  Serial.println(digitalRead(botao));
}
``` 
Parecido com o anterior, não é mesmo? O resultado é igual, mas tem uma diferença, em void setup mudamos o modo de operação pinMode para INPUT_PULLUP:

```cpp
pinMode(botao, INPUT_PULLUP);
```

Agora, se entenderam e seguiram todas as instruções, vocês conseguiram ligar o botão de maneira correta e funcionando bem. Contudo, a depender do projeto em que você queira adicionar o push button, pode haver um problema de leitura, pois os botões são feitos de pequenas placas metálicas que podem causar pequenas vibrações e por consequência, várias leituras indesejadas. Isso é chamado de  efeito “bouncing”, mas não se preocupe, existe uma maneira de resolver isso através do “debounce”, que é explicado neste material [Debounce Button](https://github.com/GrupoDePesquisaEmHardware/Arduino/tree/6eccbfedbeac836ce2f4a751d2a1707bf2e20419/Debounce%20Button). Agradeço a leitura e até a próxima.

Link do circuito pull-up externo no tinkercad:

https://www.tinkercad.com/things/hAnxHzENGbJ-cool-stantia-rottis?sharecode=3Iu_9VK-pS53y6Ate3SuCoe_7bVEcmhb2N5Gwht5FvM

Link do circuito pull-up externo no tinkercad:

https://www.tinkercad.com/things/klDDDvqrcbe-shiny-turing?sharecode=q2ijc8HkVCTr99aes9_KCirOMbL5O5Q6Sc21t9wKJYY

Link do circuito pull-up interno no tinkercad:

https://github.com/GrupoDePesquisaEmHardware/Arduino/tree/6eccbfedbeac836ce2f4a751d2a1707bf2e20419/Debounce%20Button

# Contribuidor

<p><a href = https://github.com/Vitor-Silva706> Vitor Manoel </a></p>
