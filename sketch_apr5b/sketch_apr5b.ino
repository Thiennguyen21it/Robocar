void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // forward();
  digitalWrite(LED_BUILTIN, HIGH);
  delay(200);
  digitalWrite(LED_BUILTIN, LOW);
  delay(200);
}

void forward() {
  // digitalWrite(motorLUp, HIGH);
  // digitalWrite(motorLDown, LOW);
  // digitalWrite(motorRUp, HIGH);
  // digitalWrite(motorRDown, LOW);
}
