#include "Arduino.h"

int working = 8;
int pulse = 7;
int weft = 6;
int warp = 5; 
int manualStop = 4;

long randNumber;
long speed = 100;

int speedMax = 100;
int speedMin = 75;

int repairMax = 10000;
int repairMin = 5000;

int failureRate = 1000;

int pulseWaitHighOnFail = 1000;

void setup() {
  pinMode(working, OUTPUT); 
  pinMode(pulse, OUTPUT);  
  pinMode(warp, OUTPUT);  
  pinMode(weft, OUTPUT); 
  pinMode(manualStop, OUTPUT);  

  digitalWrite(warp, LOW);
  digitalWrite(weft, LOW); 
  digitalWrite(manualStop, LOW);
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
    delay(pulseWaitHighOnFail);
    digitalWrite(pulse, HIGH);
    delay(random(repairMin, repairMax));
    digitalWrite(warp, LOW);
    digitalWrite(working, HIGH);
    speed = random(speedMin, speedMax);
  } else if (randNumber == 11 ) {
    digitalWrite(weft, HIGH);
    digitalWrite(working, LOW);
    delay(pulseWaitHighOnFail);
    digitalWrite(pulse, HIGH);
    delay(random(repairMin, repairMax));
    digitalWrite(weft, LOW);
    digitalWrite(working, HIGH);
    speed = random(speedMin, speedMax);
  } else if (randNumber == 12 ) {
    digitalWrite(manualStop, HIGH);
    digitalWrite(working, LOW);
    delay(pulseWaitHighOnFail);
    digitalWrite(pulse, HIGH);
    delay(random(repairMin, repairMax));
    digitalWrite(manualStop, LOW);
    digitalWrite(working, HIGH);
    speed = random(speedMin, speedMax);
  }  
}
