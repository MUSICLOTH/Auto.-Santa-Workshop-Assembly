
#define LEFT_MOTOR 5
#define RIGHT_MOTOR 18
#define LINE_LEFT 32
#define LINE_RIGHT 33

void setup() {
  pinMode(LEFT_MOTOR, OUTPUT);
  pinMode(RIGHT_MOTOR, OUTPUT);
  pinMode(LINE_LEFT, INPUT);
  pinMode(LINE_RIGHT, INPUT);
}

void loop() {
  int left = digitalRead(LINE_LEFT);
  int right = digitalRead(LINE_RIGHT);

  if (left == LOW && right == LOW) {
    forward();
  } 
  else if (left == LOW) {
    turnLeft();
  } 
  else if (right == LOW) {
    turnRight();
  } 
  else {
    stopMotors();
  }
}

void forward() {
  digitalWrite(LEFT_MOTOR, HIGH);
  digitalWrite(RIGHT_MOTOR, HIGH);
}

void turnLeft() {
  digitalWrite(LEFT_MOTOR, LOW);
  digitalWrite(RIGHT_MOTOR, HIGH);
}

void turnRight() {
  digitalWrite(LEFT_MOTOR, HIGH);
  digitalWrite(RIGHT_MOTOR, LOW);
}

void stopMotors() {
  digitalWrite(LEFT_MOTOR, LOW);
  digitalWrite(RIGHT_MOTOR, LOW);
}
