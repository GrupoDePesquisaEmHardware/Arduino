#include <LiquidCrystal.h>

// LCD
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);

// LEDs
#define ledG 2
#define ledY 3
#define ledB 4
#define ledR 5

// Botões
#define pushR 6
#define pushB 7
#define pushY 8
#define pushG 9

// Buzzer
#define buz 10

// Até a fase 90
int sequencia[90];

int rodada = 0;
int recorde = 0;
bool gameOver = false;

int leds[4] = {ledG, ledR, ledY, ledB};
int tons[4] = {392, 440, 554, 659};

void setup() {

  pinMode(ledG, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledB, OUTPUT);

  pinMode(pushG, INPUT);
  pinMode(pushR, INPUT);
  pinMode(pushY, INPUT);
  pinMode(pushB, INPUT);

  pinMode(buz, OUTPUT);

  lcd.begin(16, 2);

  lcd.clear();
  lcd.print("JOGO GENIUS");
  lcd.setCursor(0, 1);
  lcd.print("Press Verde");

  while (digitalRead(pushG) == LOW);

  randomSeed(millis());

  delay(300);
}

void loop() {

  while (digitalRead(pushG) == LOW);

  delay(300);

  rodada = 0;
  gameOver = false;

  lcd.clear();
  lcd.print("Iniciando...");
  delay(1000);

  while (!gameOver) {

    sequencia[rodada] = random(4);
    rodada++;

    lcd.clear();
    lcd.print("P:");
    lcd.print(rodada - 1);

    lcd.print(" R:");
    lcd.print(recorde);

    lcd.setCursor(0, 1);
    lcd.print("Nivel ");
    lcd.print(rodada);

    delay(1000);

    mostrarSequencia();

    lcd.clear();
    lcd.print("P:");
    lcd.print(rodada - 1);

    lcd.print(" R:");
    lcd.print(recorde);

    lcd.setCursor(0, 1);
    lcd.print("Sua vez!");

    if (!jogadorAcertou()) {

      if ((rodada - 1) > recorde) {
        recorde = rodada - 1;
      }

      gameOver = true;

      lcd.clear();
      lcd.print("GAME OVER");

      lcd.setCursor(0, 1);
      lcd.print("P:");
      lcd.print(rodada - 1);

      lcd.print(" R:");
      lcd.print(recorde);

      for (int i = 0; i < 3; i++) {

        tone(buz, 150);

        digitalWrite(ledG, HIGH);
        digitalWrite(ledR, HIGH);
        digitalWrite(ledY, HIGH);
        digitalWrite(ledB, HIGH);

        delay(300);

        noTone(buz);

        digitalWrite(ledG, LOW);
        digitalWrite(ledR, LOW);
        digitalWrite(ledY, LOW);
        digitalWrite(ledB, LOW);

        delay(300);
      }

      delay(4000);

      lcd.clear();
      lcd.print("Press Verde");

      while (digitalRead(pushG) == LOW);

      delay(300);
    }

    if (rodada == 90) {

      if ((rodada - 1) > recorde) {
        recorde = rodada - 1;
      }

      lcd.clear();
      lcd.print("PARABENS!");

      lcd.setCursor(0, 1);
      lcd.print("Fase 90");

      int notas[] = {523, 659, 784, 1047};
      int dur[] = {200, 200, 200, 500};

      for (int i = 0; i < 4; i++) {

        tone(buz, notas[i]);

        digitalWrite(ledG, HIGH);
        digitalWrite(ledR, HIGH);
        digitalWrite(ledY, HIGH);
        digitalWrite(ledB, HIGH);

        delay(dur[i]);

        noTone(buz);

        digitalWrite(ledG, LOW);
        digitalWrite(ledR, LOW);
        digitalWrite(ledY, LOW);
        digitalWrite(ledB, LOW);

        delay(150);
      }

      while (true);
    }

    delay(800);
  }
}

void mostrarSequencia() {

  for (int i = 0; i < rodada; i++) {

    digitalWrite(leds[sequencia[i]], HIGH);

    tone(buz, tons[sequencia[i]]);

    delay(600);

    digitalWrite(leds[sequencia[i]], LOW);

    noTone(buz);

    delay(250);
  }
}

bool jogadorAcertou() {

  for (int i = 0; i < rodada; i++) {

    int resposta = -1;

    while (resposta == -1) {

      if (digitalRead(pushG) == HIGH) resposta = 0;
      if (digitalRead(pushR) == HIGH) resposta = 1;
      if (digitalRead(pushY) == HIGH) resposta = 2;
      if (digitalRead(pushB) == HIGH) resposta = 3;
    }

    digitalWrite(leds[resposta], HIGH);

    tone(buz, tons[resposta]);

    delay(300);

    digitalWrite(leds[resposta], LOW);

    noTone(buz);

    while (
      digitalRead(pushG) == HIGH ||
      digitalRead(pushR) == HIGH ||
      digitalRead(pushY) == HIGH ||
      digitalRead(pushB) == HIGH
    );

    if (resposta != sequencia[i]) {
      return false;
    }
  }

  return true;
}
