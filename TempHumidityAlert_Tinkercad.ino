/*
  Simulated Temperature & Humidity Monitor
  Uses two potentiometers to emulate temperature & humidity sensors.
  Alerts with buzzer if thresholds exceeded.
*/

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int tempPot = A0;
const int humPot = A1;
const int buzzer = 8;

void setup() {
  lcd.begin(16, 2);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  float temp = map(analogRead(tempPot), 0, 1023, -10, 50);
  float hum = map(analogRead(humPot), 0, 1023, 0, 100);

  lcd.setCursor(0, 0);
  lcd.print("Temp: "); lcd.print(temp); lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("Hum: "); lcd.print(hum); lcd.print("%");

  if (temp > 35 || hum > 80) {
    tone(buzzer, 1000);
  } else {
    noTone(buzzer);
  }

  delay(500);
}
