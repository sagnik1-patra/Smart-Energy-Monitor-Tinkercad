/*
  Automatic Plant Watering Simulation
  - Potentiometer simulates soil moisture sensor.
  - LED represents the water pump.
  - If soil moisture < threshold, LED turns ON (watering).
*/

const int moisturePin = A0;  // Potentiometer (soil sensor)
const int pumpPin = 8;       // LED as pump
int threshold = 400;         // Adjust threshold for dryness

void setup() {
  pinMode(pumpPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Automatic Plant Watering System Started");
}

void loop() {
  // Read moisture value (0 - 1023)
  int moisture = analogRead(moisturePin);
  
  // Display in Serial Monitor
  Serial.print("Soil Moisture: ");
  Serial.println(moisture);

  // If soil is dry
  if (moisture < threshold) {
    digitalWrite(pumpPin, HIGH);  // Pump ON
    Serial.println("Soil is dry - Pump ON");
  } else {
    digitalWrite(pumpPin, LOW);   // Pump OFF
    Serial.println("Soil is wet - Pump OFF");
  }

  delay(500);
}
