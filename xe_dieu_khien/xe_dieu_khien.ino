#include <SoftwareSerial.h>
#include <Servo.h>
const int rx = 2;
const int tx = 4;


const int motorRUp = 10;
const int motorRDown = 11;
const int motorLUp = 12;
const int motorLDown = 13;

const int ena = 8;
const int enb = 9;

int vSpeed = 200;

SoftwareSerial mySerial = SoftwareSerial(rx, tx);

char data ;


#define SV_1 6 //kepj (xanh luc)
#define SV_2 3 //len xuong (mau` vang)
#define SV_3 5 //toi lui (mau den)

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
  //  int state = mySerial.read();

// if (state > 0) {
//     Serial.println((char) state);
//   }
if (mySerial.available()) { 
  data = mySerial.read();


  if (state == 'F') {
    forward();
  } else if (state == 'B') {
    backward();
  } else if (state == 'R') {
    right();
  } else if (state == 'L') {
    left();
  } else if (state == 'S') {
    stop();
  } else if (state == 'G') {
    forwardLeft();
  } else if (state == 'I') {
    forwardRight();
  } else if (state == 'J') {
    backwardRight();
  } else if (state == 'H') {
    backwardLeft();
  } 
  
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
  analogWrite(ena, 50);
  analogWrite(enb, 255);
  digitalWrite(motorRUp, HIGH);
  digitalWrite(motorRDown, 0);
  digitalWrite(motorLUp, HIGH);
  digitalWrite(motorLDown, 0);
}

void left() {
  analogWrite(ena, 255);
  analogWrite(enb, 50);
  digitalWrite(motorRUp, HIGH);
  digitalWrite(motorRDown, 0);
  digitalWrite(motorLUp, HIGH);
  digitalWrite(motorLDown, 0);
}

void forwardLeft() {
  analogWrite(ena, 255);
  analogWrite(enb, 100);
  digitalWrite(motorRUp, HIGH);
  digitalWrite(motorRDown, 0);
  digitalWrite(motorLUp, HIGH);
  digitalWrite(motorLDown, 0);
}

void forwardRight() {
  analogWrite(ena, 100);
  analogWrite(enb, 255);
  digitalWrite(motorRUp, HIGH);
  digitalWrite(motorRDown, 0);
  digitalWrite(motorLUp, HIGH);
  digitalWrite(motorLDown, 0);
}

void backwardRight() {
  analogWrite(ena, 25);
  analogWrite(enb, 255);
  digitalWrite(motorRUp, HIGH);
  digitalWrite(motorRDown, 0);
  digitalWrite(motorLUp, HIGH);
  digitalWrite(motorLDown, 0);

  // analogWrite(ena, 125);
  // analogWrite(enb, 255);
  // digitalWrite(motorRUp, 0);
  // digitalWrite(motorRDown, HIGH);
  // digitalWrite(motorLUp, 0);
  // digitalWrite(motorLDown, HIGH);
}

void backwardLeft() {
  analogWrite(ena, 255);
  analogWrite(enb, 25);
  digitalWrite(motorRUp, HIGH);
  digitalWrite(motorRDown, 0);
  digitalWrite(motorLUp, HIGH);
  digitalWrite(motorLDown, 0);

  // analogWrite(ena, 255);
  // analogWrite(enb, 125);
  // digitalWrite(motorRUp, 0);
  // digitalWrite(motorRDown, HIGH);
  // digitalWrite(motorLUp, 0);
  // digitalWrite(motorLDown, HIGH);
}

void rotateRight() {
  analogWrite(ena, 255);
  analogWrite(enb, 255);
  digitalWrite(motorRUp, 0);
  digitalWrite(motorRDown, HIGH);
  digitalWrite(motorLUp, HIGH);
  digitalWrite(motorLDown, 0);
}

void rotateLeft() {
  analogWrite(ena, 255);
  analogWrite(enb, 255);
  digitalWrite(motorRUp, HIGH);
  digitalWrite(motorRDown, 0);
  digitalWrite(motorLUp, 0);
  digitalWrite(motorLDown, HIGH);
}