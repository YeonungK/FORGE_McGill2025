int motor1pin1 = 3; //reverse right
int motor1pin2 = 5; //forward right

int motor2pin1 = 6; //reverse left
int motor2pin2 = 9; //forward left

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing motor driver...");
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);

  // pinMode(9, OUTPUT); // ENA
  // pinMode(10, OUTPUT); // ENB
}

void stop() {              //function of stop
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
}

void forward(){
  analogWrite(motor1pin1, 0);
  analogWrite(motor1pin2, 178);
  analogWrite(motor2pin1, 0);
  analogWrite(motor2pin2, 150);
}

void reverse(){
  analogWrite(motor1pin1, 175); 
  analogWrite(motor1pin2, 0);
  analogWrite(motor2pin1, 170);
  analogWrite(motor2pin2, 0);
  
}

void turn_right(){
  analogWrite(motor1pin1, 0);
  analogWrite(motor1pin2, 110);
  analogWrite(motor2pin1, 0);
  analogWrite(motor2pin2, 0);//120);
}

void turn_left(){
  analogWrite(motor1pin1, 0);
  analogWrite(motor1pin2, 0);//110); 
  analogWrite(motor2pin1, 0);
  analogWrite(motor2pin2, 109);
}

void loop() {
  // analogWrite(9, 200);
  // analogWrite(10, 200);
  //forward();
  //reverse();
  turn_left();
  Serial.println("turning left");
  delay(500);
  stop();
  Serial.println("I am stopped");
  delay(1000);
  turn_right();
  Serial.println("turning right");
  delay(500);
  stop();
  Serial.println("I am stopped");
  delay(1000);
  
}

