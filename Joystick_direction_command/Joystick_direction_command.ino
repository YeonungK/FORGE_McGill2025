/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-joystick
 */

#include <ezButton.h>

#define VRX_PINL  A1 // Arduino pin connected to VRX pin
#define VRY_PINL  A0 // Arduino pin connected to VRY pin
#define SW_PINL   2  // Arduino pin connected to SW  pin

#define VRX_PINR  A2 // Arduino pin connected to VRX pin
#define VRY_PINR  A3 // Arduino pin connected to VRY pin
#define SW_PINR   4  // Arduino pin connected to SW  pin

#define LEFT_THRESHOLD  400
#define RIGHT_THRESHOLD 600
#define UP_THRESHOLD    600
#define DOWN_THRESHOLD  400

#define COMMAND_NO     0x00
#define COMMAND_LEFT   0x01
#define COMMAND_RIGHT  0x02
#define COMMAND_UP     0x04
#define COMMAND_DOWN   0x08
#define COMMAND_BUTTON  0x10


int LmotorPinB = 3;
int LmotorPinF = 5;

int RmotorPinB = 6;
int RmotorPinF = 9;


ezButton button1(SW_PINL);
ezButton button2(SW_PINR);

int xValueL = 0; // To store value of the X axis
int yValueL = 0; // To store value of the Y axis
int bValueL = 0; // To store value of the button
int Lcommand = COMMAND_NO;

int xValueR = 0; // To store value of the X axis
int yValueR = 0; // To store value of the Y axis
int bValueR = 0; // To store value of the button
int Rcommand = COMMAND_NO;

void setup() {
  Serial.begin(9600) ;
  button1.setDebounceTime(50); // set debounce time to 50 milliseconds
  button2.setDebounceTime(50); // set debounce time to 50 milliseconds

  Serial.println("Initializing motor driver...");
  pinMode(LmotorPinB, OUTPUT);
  pinMode(LmotorPinF, OUTPUT);
  pinMode(RmotorPinB, OUTPUT);
  pinMode(RmotorPinF, OUTPUT);

  //reset motors
  analogWrite(LmotorPinB, 0);
  analogWrite(LmotorPinF, 0);
  analogWrite(RmotorPinB, 0);
  analogWrite(RmotorPinF, 0);
}

void loop() {
  button1.loop(); // MUST call the loop() function first
  button2.loop(); // MUST call the loop() function first

  // read analog X and Y analog values
  xValueL = analogRead(VRX_PINL);
  yValueL = analogRead(VRY_PINL);

  xValueR = analogRead(VRX_PINR);
  yValueR = analogRead(VRY_PINR);

  // Read the button value
  bValueL = button1.getState();
  bValueR = button2.getState();

  Lcommand = COMMAND_NO;
  Rcommand = COMMAND_NO;

  // check left/right commands
  if (xValueL < LEFT_THRESHOLD)
    Lcommand = Lcommand | COMMAND_LEFT;
  else if (xValueL > RIGHT_THRESHOLD)
    Lcommand = Lcommand | COMMAND_RIGHT;

  // check up/down commands
  if (yValueL > UP_THRESHOLD)
    Lcommand = Lcommand | COMMAND_UP;
  else if (yValueL < DOWN_THRESHOLD)
    Lcommand = Lcommand | COMMAND_DOWN;

  if (bValueL == 0) {
    Lcommand = Lcommand | COMMAND_BUTTON;
  }

    // check left/right commands
  if (xValueR < LEFT_THRESHOLD)
    Rcommand = Rcommand | COMMAND_LEFT;
  else if (xValueR > RIGHT_THRESHOLD)
    Rcommand = Rcommand | COMMAND_RIGHT;

  // check up/down commands
  if (yValueR > UP_THRESHOLD)
    Rcommand = Rcommand | COMMAND_UP;
  else if (yValueR < DOWN_THRESHOLD)
    Rcommand = Rcommand | COMMAND_DOWN;

  if (bValueR == 0) {
    Rcommand = Rcommand | COMMAND_BUTTON;
  }
  // Serial.println(Lcommand);
  // writeJoyDirection (Lcommand, Rcommand);
  // writeJoyValue(xValueL,yValueL,bValueL,xValueR,yValueR,bValueR);

  if 

  delay(100);
}

void motorStop() {              
  digitalWrite(LmotorPinB, LOW);
  digitalWrite(LmotorPinF, LOW);
  digitalWrite(RmotorPinB, LOW);
  digitalWrite(RmotorPinF, LOW);
  delay(1000);
}

void writeMotorSpeed(int Lcommand, int Rcommand) {

}

void writeJoyDirection (int Lcommand, int Rcommmand) {
  switch (Lcommand) {
    case 0x00:
      Serial.print("No action, No button");
      break;
    case 0x01:
      Serial.print("Left, No button");
      break;
    case 0x02:
      Serial.print("Right, No button");
      break;
    case 0x04:
      Serial.print("Up, No button");
      break;
    case 0x08:
      Serial.print("Down, No button");
      break;
    case 0x05:
      Serial.print("Up-Left, No button");
      break;
    case 0x09:
      Serial.print("Down-Left, No button");
      break;
    case 0x06:
      Serial.print("Up-Right, No button");
      break;
    case 0x0A:
      Serial.print("Down-Right, No button");
      break;
    case 0x10:
      Serial.print("No action, Yes button");
      break;
    case 0x11:
      Serial.print("Left, Yes button");
      break;
    case 0x12:
      Serial.print("Right, Yes button");
      break;
    case 0x14:
      Serial.print("Up, Yes button");
      break;
    case 0x18:
      Serial.print("Down, Yes button");
      break;
    case 0x15:
      Serial.print("Up-Left, Yes button");
      break;
    case 0x19:
      Serial.print("Down-Left, Yes button");
      break;
    case 0x16:
      Serial.print("Up-Right, Yes button");
      break;
    case 0x1A:
      Serial.print("Down-Right, Yes button");
      break;
    default:
      Serial.print("default");
      break;
  }

Serial.print("  |  ");

  switch (Rcommand) {
    case 0x00:
      Serial.print("No action, No button");
      break;
    case 0x01:
      Serial.print("Left, No button");
      break;
    case 0x02:
      Serial.print("Right, No button");
      break;
    case 0x04:
      Serial.print("Up, No button");
      break;
    case 0x08:
      Serial.print("Down, No button");
      break;
    case 0x05:
      Serial.print("Up-Left, No button");
      break;
    case 0x09:
      Serial.print("Down-Left, No button");
      break;
    case 0x06:
      Serial.print("Up-Right, No button");
      break;
    case 0x0A:
      Serial.print("Down-Right, No button");
      break;
    case 0x10:
      Serial.print("No action, Yes button");
      break;
    case 0x11:
      Serial.print("Left, Yes button");
      break;
    case 0x12:
      Serial.print("Right, Yes button");
      break;
    case 0x14:
      Serial.print("Up, Yes button");
      break;
    case 0x18:
      Serial.print("Down, Yes button");
      break;
    case 0x15:
      Serial.print("Up-Left, Yes button");
      break;
    case 0x19:
      Serial.print("Down-Left, Yes button");
      break;
    case 0x16:
      Serial.print("Up-Right, Yes button");
      break;
    case 0x1A:
      Serial.print("Down-Right, Yes button");
      break;
    default:
      Serial.print("default");
      break;
  }

  Serial.println(" ");
}

void writeJoyValue(int xValueL, int yValueL, int bValueL, int xValueR, int yValueR, int bValueR){
    // print data to Serial Monitor on Arduino IDE
    Serial.print("xL = ");
    Serial.print(xValueL);
    Serial.print(", yL = ");
    Serial.print(yValueL);
    Serial.print(" : buttonL = ");
    Serial.print(bValueL);

    Serial.print("   |   ");

    Serial.print("xR = ");
    Serial.print(xValueR);
    Serial.print(", yR = ");
    Serial.print(yValueR);
    Serial.print(" : buttonR = ");
    Serial.println(bValueR);
}

