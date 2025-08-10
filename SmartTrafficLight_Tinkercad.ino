/*
  Smart Traffic Light System
  - Normal mode: cycles between red → green → yellow
  - Pedestrian button: stops traffic to allow crossing
  - Night mode: flashing yellow
*/

const int redPin = 2, yellowPin = 3, greenPin = 4;
const int pedButton = 5;
const int ldrPin = A0; // Light sensor for night mode

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(pedButton, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int lightLevel = analogRead(ldrPin);
  Serial.print("Light: "); Serial.println(lightLevel);

  if (lightLevel < 300) {
    // Night mode: Flash yellow
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, HIGH);
    delay(500);
    digitalWrite(yellowPin, LOW);
    delay(500);
  } else {
    // Day mode: Normal traffic + pedestrian button
    if (digitalRead(pedButton) == LOW) {
      // Pedestrian crossing
      digitalWrite(greenPin, LOW);
      digitalWrite(yellowPin, LOW);
      digitalWrite(redPin, HIGH);
      delay(5000);
    } else {
      // Normal cycle
      digitalWrite(redPin, HIGH); delay(3000);
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, HIGH); delay(5000);
      digitalWrite(greenPin, LOW);
      digitalWrite(yellowPin, HIGH); delay(2000);
      digitalWrite(yellowPin, LOW);
    }
  }
}
