# Buzzer

Sara Cunha Leite

O som está fortemente presente nas tecnologias do nosso cotidiano, seja na melodia de jogos, alertas sonoros e em alguns dispositivos eletrodomésticos que utilizam as ondas sonoras para se comunicar de algum jeito com o usuário. Você já se perguntou como colocar sons em seus projetos? Conheça então o buzzer e como tocar sua primeira música pelo arduino! 
O buzzer é um sonorizador que recebe sinais elétricos e os converte em ondas sonoras, por meio de vibrações, seja em uma bobina ou um disco piezoelétrico, por exemplo, com uma frequência específica para cada som. Essas vibrações são amplificadas pela própria caixa do dispositivo, que cobre todos os seus componentes. O dispositivo possui dois pinos: Terra (GND) e Terminal de sinal (indicado por um sinal de + no topo do buzzer).

# Buzzer passivo ou ativo
No mercado, pode-se encontrar dois principais tipos de buzzer: o ativo e o passivo. É importante diferenciá-los, pois seu funcionamento utilizando o arduino será diferente, com isso, deve ser levado em consideração qual desses se aplica melhor aos projetos .

Tendo isso em vista, o buzzer passivo depende especialmente da frequência enviada pelo arduino para que seja funcional, precisando, assim, montar um circuito oscilante. Essa dependência também implica em uma maior versatilidade, visto que a função “tone” - que será explicada mais à frente - será a responsável por moldar as frequências desejadas. Logo, esse buzzer passivo é mais utilizado para criar melodias ou músicas específicas e esta aplicação do componente será utilizada no desafio.
Já o buzzer ativo tem um diferencial importante em sua estrutura: ele possui um circuito próprio, de modo que sua oscilação não depende da corrente elétrica, o que facilita a sua ativação, de modo a se assemelhar com a declaração de um LED. Entretanto, esse oscilador interno impede modificações no som, ou seja, a função “tone” não é capaz de mudar a frequência, pelo contrário, utilizar este comando no código causará falhas em como o buzzer soará. Assim, o tipo ativo serve para projetos que não demandam mudança de frequência e sua aplicação pode ser ligada a alarmes mais simples, como o som de um microondas ou de uma air fryer, em que não há mudança de tom. 

<div align="center">
<h3>Figura 1: Buzzer ativo x Buzzer passivo
</h3>	 
<img width="749" height="394" alt="image" src="<img width="461" height="166" alt="image" src="https://github.com/user-attachments/assets/f6814478-1cf0-4155-a42a-3699435e2638" />
" />
<h4>Fonte: Kit makers </h4>
</div>
