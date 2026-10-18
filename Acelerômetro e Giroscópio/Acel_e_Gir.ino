#include <Wire.h>
#include <Adafruit_ADXL345_U.h>

void setup() {
  Serial.begin(9600);
  if(!accel.begin()) {
    Serial.println("Erro ao iniciar o ADXL345");
    while(1);
  }
}

void loop(void) {
  sensors_event_t event;
  accel.getEvent(&event);
  
Serial.print("Aceleracao X na rolagem: "); 
  Serial.print(event.acceleration.x); 
  Serial.print(" m/s^2 | ");
  
  Serial.print("Aceleracao Y na arfagem: "); 
  Serial.print(event.acceleration.y); 
  Serial.print(" m/s^2 | ");
  
  Serial.print("Z: "); 
  Serial.print(event.acceleration.z); 
  Serial.println(" m/s^2");

  delay(500);
}
