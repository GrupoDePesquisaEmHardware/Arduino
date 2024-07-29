#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

String mens;

void setup() 
{
  mens = "Ola";
  
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print(mens);
}

void loop() 
{
  
  for(int i=0; i<=13; i++)
  {
    lcd.setCursor(i, 0);
    lcd.print(mens);
    delay(200);
    lcd.clear();
  };
  
  for(int i=13; i>=0; i--)
  {
    lcd.setCursor(i, 1);
    lcd.print(mens);
    delay(200);
    lcd.clear();
  };
  
}
