#include <Servo.h>

Servo myServo;

const int servoPin = 3;
const int buttonPin = 5;
const int initPos = 90;
const int openPos = 0;
const int openDelay = 864000; //Delay for one day (3600 *26 * 10), every 12h ==> 432000

int buttonVal;
int timer = 0;

void setup() {
  //Serial.begin(9600);

  myServo.attach(servoPin);

  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);

  myServo.attach(servoPin);
  myServo.write(initPos);
  delay(1000);
  myServo.detach();
}

void loop() {
  buttonVal = digitalRead(buttonPin);
//
//  Serial.print("Timer = ");
//  Serial.print(timer);
//  Serial.print("\n");

  if (buttonVal == LOW || timer == openDelay) {
    myServo.attach(servoPin);
    myServo.write(openPos);
    delay(575);
    myServo.write(initPos);
    delay(1500);
    myServo.detach();
    delay(5000);
    timer = 0;
  }

  delay(100);
  timer += 1;
}
