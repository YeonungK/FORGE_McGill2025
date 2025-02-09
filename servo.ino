#include <Servo.h>


Servo leftservo;  
Servo rightservo;


void setup() {
  Serial.begin(9600);
  
  leftservo.attach(9);  //rename pins
  rightservo.attach(10);  
  
  leftservo.write(90);
  rightservo.write(90);
}

void loop() {
  //kick ball, need to calibrate speed.
  if (bValueR == LOW && bValueL == LOW){
    leftservo.write(170);
    rightservo.write(80);
    delay(1000);    
    leftservo.write(80);
    rightservo.write(170);
    delay(1000);  
  }
  
  if (bValueL == LOW){
    leftservo.write(170);
    delay(1000);    
    leftservo.write(80);
    delay(1000);  
  }

  if (bValueR == LOW){
    rightservo.write(80);
    delay(1000);   
    rightservo.write(170);
    delay(1000);   
  }
  
}


  




