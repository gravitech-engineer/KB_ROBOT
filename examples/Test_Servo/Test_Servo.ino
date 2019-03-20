#include "Adafruit_Crickit.h"
#include "seesaw_servo.h"

Adafruit_Crickit crickit;
seesaw_Servo myservo1(&crickit);
seesaw_Servo myservo2(&crickit);
seesaw_Servo myservo3(&crickit);
seesaw_Servo myservo4(&crickit);
void setup() {
  Serial.begin(115200);

  if (!crickit.begin()) {
    Serial.println("ERROR!");
    while (1);
  }
  else Serial.println("Crickit started");

  myservo1.attach(CRICKIT_SERVO1);
  myservo2.attach(CRICKIT_SERVO2);
  myservo3.attach(CRICKIT_SERVO3);
  myservo4.attach(CRICKIT_SERVO4); // attaches the servo to CRICKIT_SERVO1 pin
}

void loop() {
  myservo1.write(0);
  myservo2.write(0);
  myservo3.write(0);
  myservo4.write(0);
  delay(500);
  myservo1.write(180);
  myservo2.write(180);
  myservo3.write(180);
  myservo4.write(180);
  delay(500);
}
