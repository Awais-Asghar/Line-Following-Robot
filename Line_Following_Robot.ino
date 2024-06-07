#define IR_LEFT_PIN A1
#define IR_RIGHT_PIN A0

#define ENA_PIN 5
#define ENB_PIN 3

#define MOTOR_LEFT_PIN1 11
#define MOTOR_LEFT_PIN2 10
#define MOTOR_RIGHT_PIN1 9
#define MOTOR_RIGHT_PIN2 8

int Forward_Speed = 75;
int Turn_Speed = 70;

void setup() {
  // Set motor control pins as output/input
  pinMode(MOTOR_LEFT_PIN1, OUTPUT);
  pinMode(MOTOR_LEFT_PIN2, OUTPUT);
  pinMode(MOTOR_RIGHT_PIN1, OUTPUT);
  pinMode(MOTOR_RIGHT_PIN2, OUTPUT);

  pinMode(ENA_PIN, OUTPUT);
  pinMode(ENB_PIN, OUTPUT);
  
  pinMode(IR_LEFT_PIN, INPUT);
  pinMode(IR_RIGHT_PIN, INPUT);

  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Read IR sensor values
  int irLeftValue = digitalRead(IR_LEFT_PIN);
  int irRightValue = digitalRead(IR_RIGHT_PIN);

  // Debugging - print sensor values
  Serial.print("IR Left: ");
  Serial.print(irLeftValue);
  Serial.print(" IR Right: ");
  Serial.println(irRightValue);

  // Decide motor actions based on sensor readings
  if (irLeftValue ==LOW && irRightValue ==LOW) {
    // Both sensors see white line - move forward
    moveForward();
    Serial.println("Move Forward");
  } else if (irLeftValue ==LOW && irRightValue == HIGH) {
    // Left sensor sees white line - turn left
    turnLeft();
    Serial.println("Turn Left");
  } else if (irLeftValue == HIGH && irRightValue ==LOW) {
    // Right sensor sees white line - turn right
    turnRight();
    Serial.println("Turn Right");
  } else {
    // Lost track of the line - stop
    stopMotors();
    Serial.println("Stop Motors");
  }
}

void moveForward() {
  
  // Set motor directions for forward motion
  digitalWrite(MOTOR_LEFT_PIN1, HIGH);
  digitalWrite(MOTOR_LEFT_PIN2, LOW);
  digitalWrite(MOTOR_RIGHT_PIN1, HIGH);
  digitalWrite(MOTOR_RIGHT_PIN2, LOW);

  analogWrite(ENA_PIN, Forward_Speed); // Set speed for left motor
  analogWrite(ENB_PIN, Forward_Speed); // Set speed for right motor
}


void turnLeft() {

  // Set motor directions for left turn
  digitalWrite(MOTOR_LEFT_PIN1, HIGH);
  digitalWrite(MOTOR_LEFT_PIN2, LOW);
  digitalWrite(MOTOR_RIGHT_PIN1, LOW);
  digitalWrite(MOTOR_RIGHT_PIN2, HIGH);
  // Set motor speeds
  analogWrite(ENA_PIN, Turn_Speed); // Set speed for left motor
  analogWrite(ENB_PIN, Turn_Speed); // Set speed for right motor
}

void turnRight() {

  // Set motor directions for right turn
  digitalWrite(MOTOR_LEFT_PIN1, LOW);
  digitalWrite(MOTOR_LEFT_PIN2, HIGH);
  digitalWrite(MOTOR_RIGHT_PIN1, HIGH);
  digitalWrite(MOTOR_RIGHT_PIN2, LOW);
  // Set motor speeds
  analogWrite(ENA_PIN, Turn_Speed); // Set speed for left motor
  analogWrite(ENB_PIN, Turn_Speed); // Set speed for right motor
}

void stopMotors() {
  // Stop motor drivers
  analogWrite(ENA_PIN, 0);
  analogWrite(ENB_PIN, 0);
}
