#include <Arduino.h>

int moistValue;
int mappedMoistValue;
int delayTime = 3000;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
}

void loop() {
  digitalWrite(13, HIGH);
  delay(200);

  moistValue = analogRead(A1);
  mappedMoistValue = map(moistValue, 0, 1024, 100, 0);

  Serial.print("moist=");
  Serial.println(String(mappedMoistValue));

  digitalWrite(13, LOW);
  delay(delayTime);
}