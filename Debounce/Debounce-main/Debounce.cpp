int contador = 0;
const int botao_led = 10;
const int led_V = 4;
const int led_B = 5;
const int led_G = 6;

void setup()
{
  Serial.begin(9600);
  pinMode(botao_led, INPUT);
  pinMode(led_V, OUTPUT);
  pinMode(led_B, OUTPUT);
  pinMode(led_G, OUTPUT);
}

void loop()
{
  if(digitalRead(botao_led)==1){
    while(digitalRead(botao_led)==1){ }
    contador ++;
    Serial.println(contador);  
}
  if(contador==1){
    digitalWrite(led_V,HIGH);
    digitalWrite(led_B,LOW);
    digitalWrite(led_G,LOW);
  }
  if(contador==2){
    digitalWrite(led_B,HIGH);
    digitalWrite(led_V,LOW);
    digitalWrite(led_G,LOW);
  }
  if(contador==3){
    digitalWrite(led_G,HIGH);
    digitalWrite(led_B,LOW);
    digitalWrite(led_V,LOW);
  }
  if(contador==4){
    digitalWrite(led_V,LOW);
    digitalWrite(led_B,LOW);
    digitalWrite(led_G,LOW);
    contador = 0;
  }
  	}