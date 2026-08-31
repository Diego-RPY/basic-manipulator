// ======================================================
// 3-Axis Joystick Motor Control
// X-axis  -> Motor A (primary) + Motor A2 (paired, spins opposite)
// Y-axis  -> Motor B
// Z-axis  -> Motor C (rotation)
// ======================================================

// Speed control variables
int Xvalue = 0;
int Yvalue = 0;
int Zvalue = 0;
int Xspeed = 0;
int Yspeed = 0;
int Zspeed = 0;

// Motor A connections (X-axis, primary)
int enA = 11;
int in1 = 13;
int in2 = 12;

// Motor A2 connections (X-axis, paired - always spins opposite to Motor A)
int enA2 = 6;
int in5 = 7;
int in6 = 4;

// Motor B connections (Y-axis)
int enB = 10;
int in3 = 9;
int in4 = 8;

// Motor C connections (Z-axis / rotation)
int enC = 5;
int in7 = 2;
int in8 = 3;

void setup() {
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enA2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(enC, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  pinMode(in7, OUTPUT);
  pinMode(in8, OUTPUT);

  // Turn off all motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(in5, LOW);
  digitalWrite(in6, LOW);
  digitalWrite(in7, LOW);
  digitalWrite(in8, LOW);

  Serial.begin(9600);
}

void loop() {
  // Read joystick values
  Xvalue = analogRead(A1);  // X-axis -> Motor A / Motor A2
  Yvalue = analogRead(A0);  // Y-axis -> Motor B
  Zvalue = analogRead(A2);  // Rotation axis -> Motor C

  // Map joystick values (0-1023) to speed (-255 to 255)
  Xspeed = map(Xvalue, 0, 1023, -255, 255);
  Yspeed = map(Yvalue, 0, 1023, -255, 255);
  Zspeed = map(Zvalue, 0, 1023, -255, 255);

  // ---- Motor A + Motor A2 control (X-axis) ----
  if (Xspeed > 10) {
    // Motor A forward
    analogWrite(enA, Xspeed);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    // Motor A2 runs at the same speed but in reverse
    analogWrite(enA2, Xspeed);
    digitalWrite(in5, LOW);
    digitalWrite(in6, HIGH);
  } else if (Xspeed < -10) {
    // Motor A backward
    analogWrite(enA, -Xspeed);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    // Motor A2 runs at the same speed but in reverse
    analogWrite(enA2, -Xspeed);
    digitalWrite(in5, HIGH);
    digitalWrite(in6, LOW);
  } else {
    // Stop both X-axis motors
    analogWrite(enA, 0);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    analogWrite(enA2, 0);
    digitalWrite(in5, LOW);
    digitalWrite(in6, LOW);
  }

  // ---- Motor B control (Y-axis) ----
  if (Yspeed > 10) {
    // Move motor B forward
    analogWrite(enB, Yspeed);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  } else if (Yspeed < -10) {
    // Move motor B backward
    analogWrite(enB, -Yspeed);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  } else {
    // Stop motor B
    analogWrite(enB, 0);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }

  // ---- Motor C control (Z-axis / rotation) ----
  if (Zspeed > 10) {
    // Rotate motor C forward
    analogWrite(enC, Zspeed);
    digitalWrite(in7, HIGH);
    digitalWrite(in8, LOW);
  } else if (Zspeed < -10) {
    // Rotate motor C backward
    analogWrite(enC, -Zspeed);
    digitalWrite(in7, LOW);
    digitalWrite(in8, HIGH);
  } else {
    // Stop motor C
    analogWrite(enC, 0);
    digitalWrite(in7, LOW);
    digitalWrite(in8, LOW);
  }

  delay(100);  // Small delay for stability
}
