# Display LCD 16X2
![image](https://github.com/user-attachments/assets/dae99037-0c7d-4d7e-870d-4e7794564676)


## Introdução
Os displays LCD (Liquid Crystal Display) os mais utilizados em projetos com microcontroladores são os displays LCD 16X2. Eles são muito úteis quando se precisa de uma resposta visual do que está sendo desenvolvido já que podem exibir caracteres, letras e números de forma nítida e clara. Esses displays contam com 16 colunas e 2 linhas, podendo ter sua luz de fundo (backlight) azul ou verde e as letras brancas ou pretas.


## Materiais Necessários
- Placa Arduino Uno
- Cabo de alimentação
- Protoboard
- Display LCD 16×2
- 1 Potenciômetro de 10 KΩ
- 1 Resistor de 220 Ω
- 15 Jumpers macho-macho


## Montagem do circuito
1. Pino VSS do display conectado à porta GND do Arduino.
2. Pino VDD do display à porta VCC do Arduino.
3. Pino V0 ao terminal central do potenciômetro, os outros terminais serão ligados um no VCC e outro no GND.
4. Pino RS à porta digital 2 do Arduino.
5. Pino RW à porta GND.
6. Pino E à porta digital 3.
7. Pino D4 à porta digital 4.
8. Pino D5 à porta digital 5.
9. Pino D6 à porta digital 6.
10. Pino D7 à porta digital 7.
11. Pino A à porta VCC, passando um resistor.
12. Pino K à porta GND.


## Código

'''
#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

String mens;

void setup() 
{
  mens = "Ola";
  
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print(mens);
}

void loop() 
{
  
  for(int i=0; i<=13; i++)
  {
    lcd.setCursor(i, 0);
    lcd.print(mens);
    delay(200);
    lcd.clear();
  };
  
  for(int i=13; i>=0; i--)
  {
    lcd.setCursor(i, 1);
    lcd.print(mens);
    delay(200);
    lcd.clear();
  };
  
} 
'''
