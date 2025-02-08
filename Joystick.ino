//#include <ezButton.h>
/*horizontal arm 
#include <Servo.h>

Servo leftservo;  
Servo rightservo;
*/

//need to change pins accordingly
#define VRX_PIN  A1 // Arduino pin connected to VRX pin
#define VRY_PIN  A0 // Arduino pin connected to VRY pin

#define LEFT_THRESHOLD  400
#define RIGHT_THRESHOLD 800
#define UP_THRESHOLD    400
#define DOWN_THRESHOLD  800

#define COMMAND_NO     0x00
#define COMMAND_LEFT   0x01
#define COMMAND_RIGHT  0x02
#define COMMAND_UP     0x04
#define COMMAND_DOWN   0x08

int xValue = 0 ; // To store value of the X axis
int yValue = 0 ; // To store value of the Y axis
int command = COMMAND_NO;

//wheels
/*
int motor1pin1 = 3;
int motor1pin2 = 5;

int motor2pin1 = 6;
int motor2pin2 = 9;*/

void setup() {
  Serial.begin(9600);
  /* 
  Serial.println("Initializing motor driver...");
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  //change to analog?
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);*/

  /*//horizontal arm initialize make sure good pins
  leftservo.attach(9);  
  rightservo.attach(10); 
  //initial stop.
  leftservo.write(90);
  rightservo.write(90);
  */
}

/*
//function of stop

void Stop() {              
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
  delay(1000);
}
*/

void loop() {
  /*
  Serial.println("Motors running forward");
  analogWrite(motor1pin1, 100);
  analogWrite(motor1pin2, 0);
  analogWrite(motor2pin1, 0);
  analogWrite(motor2pin2, 100);
  delay(1000);

  Stop();

  Serial.println("Motors running backward");
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  delay(1000);

  Stop();
  
  */

  // read analog X and Y analog values
  xValue = analogRead(VRX_PIN);
  yValue = analogRead(VRY_PIN);

  // converts the analog value to commands
  // reset commands
  command = COMMAND_NO;

  // check left/right commands
  if (xValue < LEFT_THRESHOLD)
    command = command | COMMAND_LEFT;
  else if (xValue > RIGHT_THRESHOLD)
    command = command | COMMAND_RIGHT;

  // check up/down commands
  if (yValue < UP_THRESHOLD)
    command = command | COMMAND_UP;
  else if (yValue > DOWN_THRESHOLD)
    command = command | COMMAND_DOWN;

  // NOTE: AT A TIME, THERE MAY BE NO COMMAND, ONE COMMAND OR TWO COMMANDS

  // testing the Joystick. change to case? case is faster.
  if (command == '0101'){
    Serial.println("COMMAND LEFT 45deg");
  }

  if (command == '0110'){
    Serial.println("COMMAND RIGHT 45deg");
  }

  if (command == '0001') {
    Serial.println("COMMAND LEFT");
    // TODO: add your task here
  }

  if (command == '0010') {
    Serial.println("COMMAND RIGHT");
    // TODO: add your task here
  }

  if (command == '0100') {
    Serial.println("COMMAND UP");
    // TODO: add your task here
  }

}



