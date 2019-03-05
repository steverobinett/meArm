#include <Servo.h>
// srr feb 2019 - added prints and delays
#define CLAW_PIN 6
#define LEFT_PIN 9
#define RIGHT_PIN 10
#define MIDDLE_PIN 11

Servo middle, right, left, claw;
void setup() {
  Serial.begin(9600);
  middle.attach(MIDDLE_PIN);
  right.attach(RIGHT_PIN);
  left.attach(LEFT_PIN);
  claw.attach(CLAW_PIN);

}
// start middle - full right, full left and back to middle
void fullSweep() {

  middle.write(90);
  delay(1000);

  //full right
  for (int i = 90; i > 0; i--) {
    middle.write(i);
    delay(50);
  }
  //full left
  for (int i = 0; i < 180; i++) {
    middle.write(i);
    delay(50);
  }

  //return to middle
  for (int i = 180; i > 90; i--) {
    middle.write(i);
    delay(50);
  }

  middle.write(90);
}

void testLeft() {

  int min_ht = 40;
  int max_ht = 120;
  int wait = 50;

  delay(2000);
  left.write(min_ht);

  for (int i = min_ht; i < max_ht; i++) {
    left.write(i);
    delay(wait);
  }

  for (int i = max_ht; i > min_ht; i--) {
    left.write(i);
    delay(wait);
  }

}
void testRight() {

  const int min_fwd = 55;
  const int max_fwd = 165;
  const int wait = 50;

  delay(2000);
  for (int i = min_fwd; i < max_fwd; i = i + 5) {
    right.write(i);
    delay(wait);
  }

  for (int i = max_fwd; i > min_fwd; i = i - 5) {
    right.write(i);
    delay(wait);
  }

}

void testClaw() {
  delay(1000);
  claw.write(60);

  for (int i = 60; i > 0; i--) {
    delay(75);
    claw.write(i);
  }
}

void loop() {

  fullSweep();

  testLeft();
  delay(1000);
  testRight();
  testClaw();
}
