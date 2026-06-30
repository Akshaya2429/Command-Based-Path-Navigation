Design challenge1
// ===== L298N Pins =====
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

// ===== Calibration Values (Adjust After Testing) =====
int turnTime = 900;      // Time for 90° turn (milliseconds)
int oneFootTime = 1400;  // Time to travel 1 foot (milliseconds)

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {

  moveForward(5);
  turnLeft();

  moveForward(4);
  turnRight();

  moveForward(4);
  turnRight();

  moveForward(6);
  turnRight();

  moveForward(3);
  turnRight();

  moveForward(6);
  

  while (1);   // Stop forever after finishing
}

// ================= FUNCTIONS =================

void moveForward(float feet) {
  int moveTime = feet * oneFootTime;

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  delay(moveTime);
  stopRobot();
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  delay(turnTime);
  stopRobot();
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  delay(turnTime);
  stopRobot();
}

void stopRobot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(500);
}
