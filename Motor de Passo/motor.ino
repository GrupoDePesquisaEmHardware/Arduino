#include <Stepper.h>

const int PassosPorVolta = 100;
const int botao_horario = 4;
const int botao_antihorario = 5;

Stepper myStepper(PassosPorVolta, 8, 10, 9, 11);

void setup()
{
  Serial.begin(9600);
  pinMode(botao_horario, INPUT);
  pinMode(botao_antihorario, INPUT);
}

void loop()
{
  if(digitalRead(botao_horario)== 1){
    Serial.println("Horario");
     myStepper.step(PassosPorVolta);
  }
    else if(digitalRead(botao_antihorario)== 1){
      Serial.println("Anti horario");
       myStepper.step(-PassosPorVolta);
  }
}
