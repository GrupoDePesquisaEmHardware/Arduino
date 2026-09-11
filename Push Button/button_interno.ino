///este codigo eh referente ao modo pullup interno do botao

#define botao 2
int estado_botao = 0;
void setup()
{
  pinMode(botao, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop()
{
  
Serial.println(digitalRead(botao));
}
