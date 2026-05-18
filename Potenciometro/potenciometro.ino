#include <Servo.h>	
#define potenciometro_pin A0
Servo meu_servo;
int leitura_potenciometro = 0;
int anguloservo = 0;

void setup(){
  meu_servo.attach(3);
  meu_servo.write(0);
  

}

  
void loop(){
  leitura_potenciometro = analogRead(potenciometro);
  anguloservo = map(leitura_potenciometro, 0, 1023, 0, 180);
  meu_servo.write(anguloservo);
}
  
