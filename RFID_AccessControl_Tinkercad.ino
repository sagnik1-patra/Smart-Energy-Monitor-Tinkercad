/*
  RFID Access Control Simulation
  In Tinkercad, we'll emulate RFID scans with Serial input.
  Type "1234" in Serial Monitor to simulate correct RFID.
*/

const String validTag = "1234";
String inputTag = "";

void setup() {
  Serial.begin(9600);
  Serial.println("RFID Access Control System");
}

void loop() {
  if (Serial.available()) {
    inputTag = Serial.readStringUntil('\n');
    inputTag.trim();

    if (inputTag == validTag) {
      Serial.println("Access Granted");
    } else {
      Serial.println("Access Denied");
    }
  }
}
