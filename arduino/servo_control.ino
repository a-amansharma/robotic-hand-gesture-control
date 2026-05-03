#include <Servo.h>

Servo servo1;  // Thumb
Servo servo2;  // Index
Servo servo3;  // Middle
Servo servo4;  // Ring
Servo servo5;  // Pinky

void setup() {
  Serial.begin(9600);

  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
  servo5.attach(10);

  // Initial position (all closed)
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
  servo4.write(0);
  servo5.write(0);
}

void loop() {
  if (Serial.available() > 0) {
    char data = Serial.read();

    // Each finger control
    if (data == '1') servo1.write(180); else servo1.write(0);
    if (data == '2') servo2.write(180); else servo2.write(0);
    if (data == '3') servo3.write(180); else servo3.write(0);
    if (data == '4') servo4.write(180); else servo4.write(0);
    if (data == '5') servo5.write(180); else servo5.write(0);
  }
}