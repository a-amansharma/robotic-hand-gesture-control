#include <Servo.h>

Servo s[5];

void setup() {
  Serial.begin(9600);

  int pins[5] = {3, 5, 6, 9, 10};

  for (int i = 0; i < 5; i++) {
    s[i].attach(pins[i]);
    s[i].write(0);
  }
}

void loop() {
  if (Serial.available()) {
    String data = Serial.readStringUntil('\n');

    if (data.length() == 5) {
      for (int i = 0; i < 5; i++) {
        if (data[i] == '1') {
          s[i].write(180); // finger open
        } else {
          s[i].write(0);   // finger closed
        }
      }
    }
  }
}