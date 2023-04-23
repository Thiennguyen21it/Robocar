#include <SoftwareSerial.h>

const int rx = 3;
const int tx = 2;

const int motorRUp = 13;
const int motorRDown = 12;
const int motorLUp = 11;
const int motorLDown = 10;

const int ena = 5;
const int enb = 6;

int vSpeed = 200;

SoftwareSerial mySerial = SoftwareSerial(rx, tx);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(rx, INPUT);
  pinMode(tx, OUTPUT);

  pinMode(motorRUp, OUTPUT);
  pinMode(motorRDown, OUTPUT);
  pinMode(motorLUp, OUTPUT);
  pinMode(motorLDown, OUTPUT);

  pinMode(enb, OUTPUT);
  pinMode(ena, OUTPUT);

  Serial.begin(9600);
  mySerial.begin(9600);

  Serial.println("Begin");
}

void loop() {
  // if (!mySerial.available()){
  //   Serial.println("Can not connect Device!!");    
  // }
  int state = mySerial.read();

  if (state > 0) {
    Serial.println((char) state);
  }

  if (state == 'F') {
    forward();
  } else if (state == 'G') {
    backward();
  } else if (state == 'R') {
    right();
  } else if (state == 'L') {
    left();
  } else if (state == 'S') {
    stop();
  } else if (state == 'Q') {
    forwardLeft();
  } else if (state == 'E') {
    forwardRight();
  } else if (state == 'C') {
    backwardRight();
  } else if (state == 'Z') {
    backwardLeft();
  }
}

void stop() {
  analogWrite(ena, 0);
  analogWrite(enb, 0);
  digitalWrite(motorRUp, 0);
  digitalWrite(motorRDown, 0);
  digitalWrite(motorLUp, 0);
  digitalWrite(motorLDown, 0);
}

void forward() {
  analogWrite(ena, 255);
  analogWrite(enb, 255);
  digitalWrite(motorRUp, HIGH);
  digitalWrite(motorRDown, 0);
  digitalWrite(motorLUp, HIGH);
  digitalWrite(motorLDown, 0);
}

void backward() {
  analogWrite(ena, 255);
  analogWrite(enb, 255);
  digitalWrite(motorRUp, 0);
  digitalWrite(motorRDown, HIGH);
  digitalWrite(motorLUp, 0);
  digitalWrite(motorLDown, HIGH);
}

void right() {
  analogWrite(ena, 75);
  analogWrite(enb, 255);
  digitalWrite(motorRUp, HIGH);
  digitalWrite(motorRDown, 0);
  digitalWrite(motorLUp, HIGH);
  digitalWrite(motorLDown, 0);
}

void left() {
  analogWrite(ena, 255);
  analogWrite(enb, 75);
  digitalWrite(motorRUp, HIGH);
  digitalWrite(motorRDown, 0);
  digitalWrite(motorLUp, HIGH);
  digitalWrite(motorLDown, 0);
}

void forwardLeft() {
  analogWrite(ena, 255);
  analogWrite(enb, 125);
  digitalWrite(motorRUp, HIGH);
  digitalWrite(motorRDown, 0);
  digitalWrite(motorLUp, HIGH);
  digitalWrite(motorLDown, 0);
}

void forwardRight() {
  analogWrite(ena, 125);
  analogWrite(enb, 255);
  digitalWrite(motorRUp, HIGH);
  digitalWrite(motorRDown, 0);
  digitalWrite(motorLUp, HIGH);
  digitalWrite(motorLDown, 0);
}

void backwardRight() {
  analogWrite(ena, 125);
  analogWrite(enb, 255);
  digitalWrite(motorRUp, 0);
  digitalWrite(motorRDown, HIGH);
  digitalWrite(motorLUp, 0);
  digitalWrite(motorLDown, HIGH);
}

void backwardLeft() {
  analogWrite(ena, 255);
  analogWrite(enb, 125);
  digitalWrite(motorRUp, 0);
  digitalWrite(motorRDown, HIGH);
  digitalWrite(motorLUp, 0);
  digitalWrite(motorLDown, HIGH);
}

