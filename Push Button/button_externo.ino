///este codigo eh referente aos modos pullup e pulldown externo do botao

int botao = 2;
void setup()
{
  pinMode(botao, INPUT);
  Serial.begin(9600);
}

void loop()
{
  
Serial.println(digitalRead(botao));
}
