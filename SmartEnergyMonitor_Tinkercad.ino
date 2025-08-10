/*
  Smart Energy Monitor (Tinkercad Simulation)
  Simulates Voltage & Current readings using potentiometers or random values.
  Calculates Power & Energy and displays on Serial Monitor + LCD.
*/

#include <LiquidCrystal.h>

// LCD Pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Potentiometer pins for simulation
const int voltagePotPin = A0;
const int currentPotPin = A1;

// Variables
float voltage = 0.0;
float current = 0.0;
float power = 0.0;
float energy = 0.0; // in Wh
unsigned long lastUpdate = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Energy Monitor");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Simulated voltage (0-250V)
  voltage = map(analogRead(voltagePotPin), 0, 1023, 0, 250);

  // Simulated current (0-15A)
  current = map(analogRead(currentPotPin), 0, 1023, 0, 1500) / 100.0;

  // Calculate power (W)
  power = voltage * current;

  // Energy calculation (Wh) every second
  unsigned long currentMillis = millis();
  if (currentMillis - lastUpdate >= 1000) {
    energy += power / 3600.0; // Wh increment per second
    lastUpdate = currentMillis;
  }

  // Display on Serial Monitor
  Serial.print("Voltage: "); Serial.print(voltage); Serial.print(" V, ");
  Serial.print("Current: "); Serial.print(current); Serial.print(" A, ");
  Serial.print("Power: "); Serial.print(power); Serial.print(" W, ");
  Serial.print("Energy: "); Serial.print(energy); Serial.println(" Wh");

  // Display on LCD
  lcd.setCursor(0, 0);
  lcd.print("V:"); lcd.print(voltage, 1); lcd.print(" I:"); lcd.print(current, 1);
  lcd.setCursor(0, 1);
  lcd.print("P:"); lcd.print(power, 1); lcd.print("W");
  lcd.print(" E:"); lcd.print(energy, 1);

  delay(500);
}
