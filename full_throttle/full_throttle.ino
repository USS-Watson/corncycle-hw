const int LEFT_FWD = 3;
const int LEFT_REV = 2;
const int RIGHT_FWD = 11;
const int RIGHT_REV = 10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LEFT_FWD, OUTPUT);
  pinMode(LEFT_REV, OUTPUT);
  pinMode(RIGHT_FWD, OUTPUT);
  pinMode(RIGHT_REV, OUTPUT);
}

void loop() {
  analogWrite(LEFT_FWD, 127);
  analogWrite(LEFT_REV, 0);
  analogWrite(RIGHT_FWD, 127);
  analogWrite(RIGHT_REV, 0);
  delay(2500);
  analogWrite(LEFT_FWD, 127);
  analogWrite(LEFT_REV, 0);
  analogWrite(RIGHT_FWD, 0);
  analogWrite(RIGHT_REV, 127);
  delay(2500);
  analogWrite(LEFT_FWD, 0);
  analogWrite(LEFT_REV, 127);
  analogWrite(RIGHT_FWD, 0);
  analogWrite(RIGHT_REV, 127);
  delay(2500);
  analogWrite(LEFT_FWD, 0);
  analogWrite(LEFT_REV, 127);
  analogWrite(RIGHT_FWD, 127);
  analogWrite(RIGHT_REV, 0);
  delay(2500);
}
