#include <Servo.h>

#define PINO_SERVO 9
#define TEMPO_GIRO 30

int pos;
Servo meu_servo;

void setup()
{
	meu_servo.attach(PINO_SERVO);
}

void loop()
{
	 for (pos = 0; pos <= 180;++pos) {
   		meu_servo.write(pos);
    		delay(TEMPO_GIRO);
 	}
 for (pos = 180; pos >= 0; –pos) {
   	meu_servo.write(pos);
    	delay(TEMPO_GIRO);
  }
}
