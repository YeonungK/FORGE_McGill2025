int motor1pin1 = 3;
int motor1pin2 = 5;

int motor2pin1 = 6;
int motor2pin2 = 9;

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

void loop() {
  // analogWrite(9, 200);
  // analogWrite(10, 200);

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
}

void Stop() {              //function of stop
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
  delay(1000);
}