#include <ESP32Servo.h>


// servo pin
const int servoPin = 18;
Servo servo;
Servo myServo;
int x = 1;

void setup() {
  servo.attach(servoPin);
  Serial.begin(9600);
  servo.write(0);
}

void loop() {
  Serial.print(x);
  if (x == 1) // light the LED
  {
    servo.write(0);
    x = 0;
    delay(15000);
  }
  else {
    servo.write(180);
    x = 1;
    delay(15000);
  }
}
