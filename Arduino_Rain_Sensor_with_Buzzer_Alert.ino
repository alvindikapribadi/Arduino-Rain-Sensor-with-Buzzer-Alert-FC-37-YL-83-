/*
========================================================
 Arduino Rain Sensor with Buzzer Alert
========================================================

Description:
A simple Arduino project to detect rain using a rain sensor module.
When water is detected, the buzzer will sound as an alert.
When dry, the buzzer remains off.

========================================================
Components:
- Arduino UNO / Nano
- Rain Sensor Module (YL-83 / FC-37)
- Active Buzzer
- Jumper Wires

========================================================
Wiring:

Rain Sensor:
- VCC -> 5V
- GND -> GND
- DO  -> D2

Buzzer:
- (+) -> D8
- (-) -> GND

========================================================
Notes:
- Typically:
  LOW  = Rain detected
  HIGH = No rain
- Logic may vary depending on module adjustment
========================================================
*/

#define RAIN_PIN 2
#define BUZZER_PIN 8

void setup() {
  pinMode(RAIN_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(9600);
  Serial.println("Rain Sensor System Ready");
}

void loop() {
  int rainState = digitalRead(RAIN_PIN);

  if (rainState == LOW) {
    // Rain detected
    Serial.println("Status: RAIN DETECTED");

    // Buzzer beep pattern
    digitalWrite(BUZZER_PIN, HIGH);
    delay(200);
    digitalWrite(BUZZER_PIN, LOW);
    delay(200);

  } else {
    // No rain
    Serial.println("Status: NO RAIN");

    digitalWrite(BUZZER_PIN, LOW);
    delay(300);
  }
}