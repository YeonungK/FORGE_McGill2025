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

ezButton button1(SW_PINL);
ezButton button2(SW_PINR);

int xValueL = 0; // To store value of the X axis
int yValueL = 0; // To store value of the Y axis
int bValueL = 0; // To store value of the button

int xValueR = 0; // To store value of the X axis
int yValueR = 0; // To store value of the Y axis
int bValueR = 0; // To store value of the button

void setup() {
  Serial.begin(9600) ;
  button1.setDebounceTime(50); // set debounce time to 50 milliseconds
  button2.setDebounceTime(50); // set debounce time to 50 milliseconds
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

  // if (button1.isPressed()) {
  //   Serial.println("The button is pressed");
  //   // TODO do something here
  // }

  // if (button1.isReleased()) {
  //   Serial.println("The button is released");
  //   // TODO do something here
  // }

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

  delay(100);
}


