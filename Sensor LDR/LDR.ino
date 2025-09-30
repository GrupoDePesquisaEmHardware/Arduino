int ValorSensor = 0;
int Valor=0;
#define LED  4
#define LDR A2

void setup()
{
  pinMode(LDR, INPUT);
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}
void loop()
{
  ValorSensor = analogRead(LDR);
  Serial.println(ValorSensor);
  Valor = map(ValorSensor, 0, 1023, 0, 255);
  analogWrite(LED, Valor);
 delay(100);
}
