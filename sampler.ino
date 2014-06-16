#include "Arduino.h"

int working = 8;
int pulse = 7;
int warp = 6;
int weft = 5;
int rope = 4;
int unknown = 3;

long randNumber;
long speed = 100;

int speedMax = 100;
int speedMin = 75;

int repairMax = 10000;
int repairMin = 5000;

int failureRate = 1000;

void setup() {
  pinMode(working, OUTPUT); // sets the pin as output
  pinMode(pulse, OUTPUT); // sets the pin as output
  pinMode(warp, OUTPUT); // sets the pin as output
  pinMode(weft, OUTPUT); // sets the pin as output
  pinMode(rope, OUTPUT); // sets the pin as output
  pinMode(unknown, OUTPUT); // sets the pin as output

  digitalWrite(warp, LOW);
  digitalWrite(weft, LOW);
  digitalWrite(rope, LOW);
  digitalWrite(unknown, LOW);
  digitalWrite(working, HIGH);
  Serial.begin(9600);
}
void loop() {
  delay(speed);
  digitalWrite(pulse, HIGH);
  delay(speed);
  digitalWrite(pulse, LOW);
  randomFailure();
}

void randomFailure() {
  randNumber = random(failureRate);
  if (randNumber == 10) {
    digitalWrite(warp, HIGH);
    digitalWrite(working, LOW);
    delay(random(repairMin, repairMax));
    digitalWrite(warp, LOW);
    digitalWrite(working, HIGH);
    speed = random(speedMin, speedMax);
  } else if (randNumber == 11 ) {
    digitalWrite(weft, HIGH);
    digitalWrite(working, LOW);
    delay(random(repairMin, repairMax));
    digitalWrite(weft, LOW);
    digitalWrite(working, HIGH);
    speed = random(speedMin, speedMax);
  } else if (randNumber == 12 ) {
    digitalWrite(rope, HIGH);
    digitalWrite(working, LOW);
    delay(random(repairMin, repairMax));
    digitalWrite(rope, LOW);
    digitalWrite(working, HIGH);
    speed = random(speedMin, speedMax);
  } else if (randNumber == 13 ) {
    digitalWrite(unknown, HIGH);
    digitalWrite(working, LOW);
    delay(random(repairMin, repairMax));
    digitalWrite(unknown, LOW);
    digitalWrite(working, HIGH);
    speed = random(speedMin, speedMax);
  }
}
