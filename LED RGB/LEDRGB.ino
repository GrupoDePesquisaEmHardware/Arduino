#define vermelho 9
#define azul 10
#define verde 11

void setup()
{
   pinMode(vermelho, OUTPUT);
   pinMode(verde, OUTPUT);
   pinMode(azul, OUTPUT);
}

void loop()
{ 
  red();
  delay(700);
  green();
  delay(700);
  blue();
  delay(700);
  roxo();
  delay(700);
}
void red(){
  analogWrite(azul, 0);
  analogWrite(verde, 0);
  analogWrite(vermelho, 255);
}
void green(){
  analogWrite(azul, 0);
  analogWrite(verde, 255);
  analogWrite(vermelho, 0);
}
void blue(){
  analogWrite(azul, 255);
  analogWrite(verde, 0);
  analogWrite(vermelho, 0);
}
void roxo(){
  analogWrite(azul, 255);
  analogWrite(verde, 0);
  analogWrite(vermelho, 255);
  delay(700);
  analogWrite(azul, 10);
  analogWrite(verde, 0);
  analogWrite(vermelho, 200);
}