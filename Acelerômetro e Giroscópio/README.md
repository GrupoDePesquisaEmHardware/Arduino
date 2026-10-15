# Acelerômetro e Giroscópio

  Por acaso você já parou para pensar como o seu celular sabe que você o girou para assistir a um vídeo em tela cheia? Ou como os drones conseguem se manter estáveis e se localizar no ar? O segredo por trás disso tudo está em dois componentes fundamentais: o acelerômetro e o giroscópio. Neste guia, vamos entender como eles funcionam e como extraímos dados deles para os nossos projetos de hardware.

  O acelerômetro é um sensor que mede a aceleração linear, ou seja, a taxa de variação da velocidade em um determinado eixo. Ele consegue detectar se o dispositivo está parado, em movimento ou inclinado em relação à gravidade da Terra. Já o giroscópio mede a velocidade angular, que nada mais é do que a rapidez com que algo está girando em torno de um eixo.

  Mas, como funciona? Para compreendermos, imagine uma pequena caixa em formato de cubo com uma bola em seu interior. As paredes dessa estrutura são revestidas por cristais piezoelétricos, que possuem a propriedade de gerar eletricidade quando sofrem pressão física. Assim, sempre que você inclina ou movimenta a caixa, a gravidade ou a inércia força a bola a colidir contra uma das paredes.  A seguir, a figura 1 mostra de forma visual como funciona a teoria.

<div align="center">
<h3> Figura 1 - Efeito Piezoelétrico </h3>	
<img width="627" height="330" alt="image" src="https://github.com/user-attachments/assets/e04633b4-a703-4772-8fc5-e4cb2ae11580" />
<h4> Fonte: Adaptado de Lousada (2020)e </h4>
</div>
