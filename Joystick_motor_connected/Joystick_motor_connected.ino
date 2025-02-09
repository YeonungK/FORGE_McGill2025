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


int LmotorBpin = 6;
int LmotorFpin = 9;

int RmotorBpin = 3;
int RmotorFpin = 5;


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

int LmotorBspeed = 0;  // Motor speeds
int LmotorFspeed = 0;
int RmotorBspeed = 0;
int RmotorFspeed = 0;

void setup() {
  Serial.begin(9600) ;
  button1.setDebounceTime(50); // set debounce time to 50 milliseconds
  button2.setDebounceTime(50); // set debounce time to 50 milliseconds

  Serial.println("Initializing motor driver...");
  pinMode(LmotorBpin, OUTPUT);
  pinMode(LmotorFpin, OUTPUT);
  pinMode(RmotorBpin, OUTPUT);
  pinMode(RmotorFpin, OUTPUT);

  //reset motors
  analogWrite(LmotorBpin, 0);
  analogWrite(LmotorFpin, 0);
  analogWrite(RmotorBpin, 0);
  analogWrite(RmotorFpin, 0);
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

 int Lcom_dir = Lcommand % 0x10;  // Just get the direction
 int Rcom_dir = Rcommand % 0x10;
 int Lbutton = Lcommand / 0x10;  // Just get the button status
 int Rbutton = Rcommand / 0x10;

//  Serial.print(Lcom_dir);
//  Serial.println("  " + Rcom_dir);

  if (Lcom_dir == 0) { // when the left joystick is not moved
    LmotorBspeed = 0;
    LmotorFspeed = 0;
    RmotorBspeed = 0;
    RmotorFspeed = 0;
    if (Rcom_dir == 1 || Rcom_dir == 5 || Rcom_dir == 9) { // turn left
      LmotorBspeed = 0;
      LmotorFspeed = -110;
      RmotorBspeed = 0;
      RmotorFspeed = 110;
    }
    else if (Rcom_dir == 2 || Rcom_dir == 6 || Rcom_dir == 10) { // turn right
      LmotorBspeed = 0;
      LmotorFspeed = 125;
      RmotorBspeed = 0;
      RmotorFspeed = -125;
    }
  }

  if (Lcom_dir >= 4 && Lcom_dir <= 6) { // when the left joystick is moving up
    LmotorBspeed = 0;
    LmotorFspeed = 185;
    RmotorBspeed = 0;
    RmotorFspeed = 170;
    if (Rcom_dir == 1 || Rcom_dir == 5 || Rcom_dir == 9) { // turn left
      LmotorBspeed = 0;
      LmotorFspeed -= 20;
      RmotorBspeed = 0;
      RmotorFspeed += 30;
    }
    else if (Rcom_dir == 2 || Rcom_dir == 6 || Rcom_dir == 10) { // turn right
      LmotorBspeed = 0;
      LmotorFspeed += 30;
      RmotorBspeed = 0;
      RmotorFspeed -= 20;
    }
 }
  else if (Lcom_dir >= 8 && Lcom_dir <= 10) { // when the left joystick is moving down
    LmotorBspeed = 185;
    LmotorFspeed = 0;
    RmotorBspeed = 170;
    RmotorFspeed = 0;
    if (Rcom_dir == 1 || Rcom_dir == 5 || Rcom_dir == 9) { // turn left
      LmotorFspeed = 0;
      LmotorBspeed -= 20;
      RmotorFspeed = 0;
      RmotorBspeed += 30;
    }
    else if (Rcom_dir == 2 || Rcom_dir == 6 || Rcom_dir == 8) { // turn right
      LmotorFspeed = 0;
      LmotorBspeed += 30;
      RmotorFspeed = 0;
      RmotorBspeed -= 20;
    }
 }
 
  writeMotorSpeed(LmotorFspeed, LmotorBspeed, RmotorBspeed, RmotorFspeed, Rcom_dir);

  analogWrite(LmotorFpin, LmotorFspeed);
  analogWrite(LmotorBpin, LmotorBspeed);
  analogWrite(RmotorFpin, RmotorFspeed);
  analogWrite(RmotorBpin, RmotorBspeed);
 
  delay(100);
}

void motorStop() {              
  digitalWrite(LmotorBpin, LOW);
  digitalWrite(LmotorFpin, LOW);
  digitalWrite(RmotorBpin, LOW);
  digitalWrite(RmotorFpin, LOW);
  delay(1000);
}



void writeMotorSpeed(int LmotorFspeed, int LmotorBspeed, int RmotorBspeed, int RmotorFspeed, int Rcom_dir) {
  Serial.print(LmotorFspeed);
  Serial.print("  |  ");
  Serial.print(LmotorBspeed);
  Serial.print("  |  ");
  Serial.print(RmotorFspeed);
  Serial.print("  |  ");
  Serial.print(RmotorBspeed);
  Serial.print("  |  ");
  Serial.println(Rcom_dir);
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

