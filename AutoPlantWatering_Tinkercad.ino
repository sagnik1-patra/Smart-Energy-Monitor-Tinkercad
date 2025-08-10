/*
  Automatic Plant Watering Simulation
  Uses potentiometer as soil moisture sensor.
  Turns pump (LED) ON when soil is dry.
*/

const int moisturePin = A0;
const int pumpPin = 8; // LED instead of pump

void setup() {
  pinMode(pumpPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int moisture = analogRead(moisturePin);
  Serial.print("Moisture: "); Serial.println(moisture);

  if (moisture < 400) {
    digitalWrite(pumpPin, HIGH); // Pump ON
  } else {
    digitalWrite(pumpPin, LOW); // Pump OFF
  }

  delay(500);
}
