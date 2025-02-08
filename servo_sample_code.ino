#include <Servo.h>

Servo myservo;  // create Servo object to control a servo
// twelve Servo objects can be created on most boards

int pos = 90;    // variable to store the servo position

void setup() {
  Serial.begin(9600);
  myservo.attach(2);
  Serial.println("working...");  // attaches the servo on pin 2 to the Servo object
}

void loop() {
  myservo.write(90);
  Serial.println("stop");
  delay(500);
  myservo.write(0);
  Serial.println("max one way");
  delay(500);
  myservo.write(180);
  Serial.println("max other way");
  delay(500);
}
