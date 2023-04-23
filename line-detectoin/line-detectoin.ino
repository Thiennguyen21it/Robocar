
const int motorLUp = 10;
const int motorLDown = 11;
const int motorRUp = 12;
const int motorRDown = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(motorLUp, OUTPUT);
  pinMode(motorLDown, OUTPUT);
  pinMode(motorRUp, OUTPUT);
  pinMode(motorRDown, OUTPUT);

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // forward();
  // digitalWrite(LED_BUILTIN, HIGH);
  // delay(200);
  // digitalWrite(LED_BUILTIN, LOW);
  // delay(200);
  digitalWrite(motorLUp, HIGH);
}

void forward() {
  // digitalWrite(motorLUp, HIGH);
  // digitalWrite(motorLDown, LOW);
  // digitalWrite(motorRUp, HIGH);
  // digitalWrite(motorRDown, LOW);
}
