///este codigo eh referente aos modos pullup e pulldown externo do botao

#define botao 2
int estado_botao = 0;
void setup()
{
  pinMode(botao, INPUT);
  Serial.begin(9600);
}

void loop()
{
  
Serial.println(digitalRead(botao));
}
