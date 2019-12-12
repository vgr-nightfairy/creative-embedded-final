#include <ESP32Servo.h>


// servo 
const int servoPinS = 18;
const int servoPinFL = 13;
const int servomouthFL = 32;
Servo servoSnape;
Servo servoFatLady;
Servo servoMouthFL;
int x = 1;

// ultrasonics
const int trigPinFL = 12;
const int echoPinFL = 14;
const int pingPinS = 15;
long durationFL;
long distanceFL;
long durationS;
long distanceS;

void setup() {
  Serial.begin(9600);
  
  // servo 
  servoSnape.attach(servoPinS);
  servoFatLady.attach(servoPinFL);
  servoMouthFL.attach(servomouthFL);
  servoSnape.write(0);
  servoFatLady.write(180);
  servoMouthFL.write(0);

  // ultrasonics
  pinMode(trigPinFL, OUTPUT);
  pinMode(echoPinFL, INPUT);
}

void loop() {
  // ultrasonics
  // FL
  digitalWrite(trigPinFL, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinFL, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPinFL, LOW);

  // FL
  durationFL = pulseIn(echoPinFL, HIGH);
  distanceFL = (durationFL) / 148;
  Serial.printf("fl: %i\n", distanceFL);
  delay(200);
//
//  // Snape
  pinMode(pingPinS, OUTPUT);
  digitalWrite(pingPinS, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPinS, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPinS, LOW);
  pinMode(pingPinS, INPUT);

  //  // Snape
  durationS = pulseIn(pingPinS, HIGH);
  distanceS = durationS / 74 / 2;
  Serial.printf("s: %i\n", distanceS);

  if (distanceFL<=30){
    servoFatLady.write(0);
    servoSnape.write(0);
    if (x == 1){
      servoMouthFL.write(0);
      x = 0;
      }
    else {
      servoMouthFL.write(180);
      x = 1;
      }
  }
  else if (distanceS<=30){
    servoFatLady.write(180);
    servoSnape.write(180);
  }
  else{
    servoFatLady.write(180);
    servoSnape.write(0);
  }
//
  delay(100);
}
