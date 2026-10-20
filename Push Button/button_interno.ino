///este codigo eh referente ao modo pullup interno do botao

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
