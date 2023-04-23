long sensor[] = { 0, 1, 2, 3, 4 };  //leftmost - 0, rightmost - 4

int rmf = 9;  //motor right fw
int rmb = 6;  // motor right back
int lmf = 10;
int lmb = 11;

const int initial_motor_speed = 100;

int P;
int I;
int D;

int PID_value = 0;
int previous_error = 0;

float Kp = 15;
float Ki = 0;
float Kd = 140;

int error = 0;

void setup() {
  // put your setup code here, to run once:
  //sensors
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);

  //motors
  pinMode(rmf, OUTPUT);
  pinMode(rmb, OUTPUT);
  pinMode(lmf, OUTPUT);
  pinMode(lmb, OUTPUT);

  Serial.begin(9600);
}

void read_sensor_values() {

  // sensor[0]=analogRead(A0) == 1 ? 0 : 1;
  // sensor[1]=analogRead(A1) == 1 ? 0 : 1;
  // sensor[2]=analogRead(A2) == 1 ? 0 : 1;
  // sensor[3]=analogRead(A3) == 1 ? 0 : 1;
  // sensor[4]=analogRead(A4) == 1 ? 0 : 1;

  sensor[0] = analogRead(A0) > 255 ? 0 : 1;
  sensor[1] = analogRead(A1) > 255 ? 0 : 1;
  sensor[2] = analogRead(A2) > 255 ? 0 : 1;
  sensor[3] = analogRead(A3) > 255 ? 0 : 1;
  sensor[4] = analogRead(A4) > 255 ? 0 : 1;

  Serial.print(sensor[0]);
  Serial.print(' ');
  Serial.print(sensor[1]);
  Serial.print(' ');
  Serial.print(sensor[2]);
  Serial.print(' ');
  Serial.print(sensor[3]);
  Serial.print(' ');
  Serial.print(sensor[4]);
  Serial.print(' ');

  if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 1))  // 00001
    error = 4;
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1))  // 00011
    error = 3;
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 0))  // 00010
    error = 2;
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 0))  // 00110
    error = 1;
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[3] == 0) && (sensor[4] == 0))  // 00100
    error = 0;
  else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 0) && (sensor[4] == 0))  // 01100
    error = -1;
  else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 0))  // 01000
    error = -2;
  else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 0))  // 11000
    error = -3;
  else if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 0))  // 10000
    error = -4;
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 0)) {  // 00000
    if (error == -4) error = -5;
    else error = 5;
  }
}

void calculate_pid() {
  P = error;
  I = I + error;
  D = error - previous_error;

  PID_value = (Kp * P) + (Ki * I) + (Kd * D);

  previous_error = error;

  Serial.print("P ");
  Serial.print(P);
  Serial.print(" I ");
  Serial.print(I);
  Serial.print(" D ");
  Serial.print(D);
}

void motor_control() {
  // Calculating the effective motor speed:
  int left_motor_speed = initial_motor_speed - PID_value;
  int right_motor_speed = initial_motor_speed + PID_value;

  // The motor speed should not exceed the max PWM value
  constrain(left_motor_speed, 0, 100);
  constrain(right_motor_speed, 0, 100);

  analogWrite(3, left_motor_speed);   //Left Motor Speed
  analogWrite(5, right_motor_speed);  //Right Motor Speed
  //following lines of code are to make the bot move forward
  /*The pin numbers and high, low values might be different
    depending on your connections */
  digitalWrite(rmf, LOW);
  digitalWrite(rmb, HIGH);
  digitalWrite(lmf, LOW);
  digitalWrite(lmb, HIGH);
}

void loop() {

  read_sensor_values();
  calculate_pid();
  motor_control();
  Serial.println();
}
