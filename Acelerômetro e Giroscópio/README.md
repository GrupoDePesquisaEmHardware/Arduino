# Acelerômetro e Giroscópio

  Por acaso você já parou para pensar como o seu celular sabe que você o girou para assistir a um vídeo em tela cheia? Ou como os drones conseguem se manter estáveis e se localizar no ar? O segredo por trás disso tudo está em dois componentes fundamentais: o acelerômetro e o giroscópio. Neste guia, vamos entender como eles funcionam e como extraímos dados deles para os nossos projetos de hardware.

  O acelerômetro é um sensor que mede a aceleração linear, ou seja, a taxa de variação da velocidade em um determinado eixo. Ele consegue detectar se o dispositivo está parado, em movimento ou inclinado em relação à gravidade da Terra. Já o giroscópio mede a velocidade angular, que nada mais é do que a rapidez com que algo está girando em torno de um eixo.

  Mas, como funciona? Para compreendermos, imagine uma pequena caixa em formato de cubo com uma bola em seu interior. As paredes dessa estrutura são revestidas por cristais piezoelétricos, que possuem a propriedade de gerar eletricidade quando sofrem pressão física. Assim, sempre que você inclina ou movimenta a caixa, a gravidade ou a inércia força a bola a colidir contra uma das paredes.  A seguir, a figura 1 mostra de forma visual como funciona a teoria.

<div align="center">
<h3> Figura 1 - Efeito Piezoelétrico </h3>	
<img width="627" height="330" alt="image" src="https://github.com/user-attachments/assets/e04633b4-a703-4772-8fc5-e4cb2ae11580" />
<h4> Fonte: Adaptado de Lousada (2020) </h4>
</div>

No momento desse impacto, a parede atingida converte a pressão da bola em uma pequena corrente elétrica. Como o sensor tem três dimensões, ele possui três pares de paredes opostas, cada uma representando um eixo no espaço (X, Y e Z). O segredo do componente está em  analisar qual parede foi pressionada e qual a força exercida sobre ela.

Já conhecemos o acelerômetro, agora, vamos entender o que é e como funciona o giroscópio!  Um giroscópio é um sensor que mede a **taxa de rotação** em relação a um sistema de referência inercial, ou seja, em repouso. Com isso, ele captura todas as mudanças subsequentes na orientação quando rotacionado. Na eletrônica, são usados os giroscópios MEMS ( sistemas microeletromecânicos de estrutura vibratória), que usam o princípio do **Efeito de Coriolis** para detectar as rotações. Dentro do dispositivo, pequenas placas de silício são mantidas em vibração para que, quando houver uma rotação, a força de Coriolis, uma pseudoforça que surge devido ao movimento de rotação do referencial não-inercial ( um sistema que está em rotação, como a Terra ), cause uma variação no movimento dessas placas, gerando um sinal de tensão que será convertido em valores de velocidade angular.

<div align="center">
<h3> Figura 2 - Funcionamento do Giroscópio MEMS </h3>	
<img width="328" height="321" alt="image" src="https://github.com/user-attachments/assets/50918ca1-7519-4731-b017-1856246affc0"/>
<h4> Fonte : Adaptado de Stuhler (2022) </h4>
</div>

Nesse momento você deve estar se perguntando: "Mas como eu consigo fazer uma aplicação disso em projetos eletrônicos?" Para tirar essa tecnologia da teoria e levá-la para a prática, utilizamos módulos (dispositivos eletrônicos dos sensores) prontos que facilitam a comunicação entre esses sensores e os microcontroladores como o Arduino ou o ESP32.

Na tabela abaixo estão os três módulos mais comuns no mercado e nos projetos e suas principais características e diferenças.

<div align="center">
<h1> Tabela 1 - Definição dos módulos utilizados na prática </h1>

| Módulo | Tipo de Sensor | Diferencial |
|:---:|---|---|
| MPU-6050 | Acelerômetro e Giroscópio | O mais popular e barato; ótimo para estabilização de robôs. |
| MPU-9250 | Acelerômetro, Giroscópio e Magnetômetro | Possui uma bússola integrada, sendo ideal para drones e sistemas de navegação. |
| ADXL345 | Acelerômetro | Baixo consumo de energia; ideal para projetos simples de inclinação. |
<h2> Fonte: Autoria própria </h2>
</div>

Agora que conhecemos o acelerômetro, o giroscópio,  os seus respectivos componentes eletrônicos respectivos e o seu funcionamento, por que não fazer um projeto?

O projeto que vamos fazer será de um **Sistema de Controle de Atitude para Aviões** (Monitoramento de Inclinação dos Eixos do avião). A proposta é  criar um protótipo que leia a aceleração nos eixos da aeronave e a angulação da **Arfagem** (Movimento de “subir e descer” a ponta do avião) e da **Rolagem** (Inclinação das asas para esquerda ou direita) e apresentar esses dados no monitor serial. 

# Materiais necessários

Para o projeto, precisamos dos seguintes componentes:

- Módulo ADXL345  (Acelerômetro);
- Arduino UNO (ou qualquer outro Arduino);
- Protoboard 400 pontos;
- Cabo USB Mini-B;
- Jumpers Macho-Macho.
