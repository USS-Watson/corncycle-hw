const int FRONT_LEFT_FWD = 3;
const int FRONT_LEFT_REV = 2;
const int FRONT_RIGHT_FWD = 11;
const int FRONT_RIGHT_REV = 10;
const int BACK_LEFT_FWD = 8;
const int BACK_LEFT_REV = 1;
const int BACK_RIGHT_FWD = 0;
const int BACK_RIGHT_REV = 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(FRONT_LEFT_FWD, OUTPUT);
  pinMode(FRONT_LEFT_REV, OUTPUT);
  pinMode(FRONT_RIGHT_FWD, OUTPUT);
  pinMode(FRONT_RIGHT_REV, OUTPUT);
  pinMode(BACK_LEFT_FWD, OUTPUT);
  pinMode(BACK_LEFT_REV, OUTPUT);
  pinMode(BACK_RIGHT_FWD, OUTPUT);
  pinMode(BACK_RIGHT_REV, OUTPUT);
  analogWrite(FRONT_LEFT_FWD, 0);
  analogWrite(FRONT_LEFT_REV, 0);
  analogWrite(FRONT_RIGHT_FWD, 0);
  analogWrite(FRONT_RIGHT_REV, 0);
  analogWrite(BACK_LEFT_FWD, 0);
  analogWrite(BACK_LEFT_REV, 0);
  analogWrite(BACK_RIGHT_FWD, 0);
  analogWrite(BACK_RIGHT_REV, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(FRONT_LEFT_FWD, 127);
  Serial.println("FRONT_LEFT_FWD");
  delay(1500);
  analogWrite(FRONT_LEFT_FWD, 0);
  analogWrite(FRONT_LEFT_REV, 127);
  Serial.println("FRONT_LEFT_REV");
  delay(1500);
  analogWrite(FRONT_LEFT_REV, 0);
  analogWrite(FRONT_RIGHT_FWD, 127);
  Serial.println("FRONT_RIGHT_FWD");
  delay(1500);
  analogWrite(FRONT_RIGHT_FWD, 0);
  analogWrite(FRONT_RIGHT_REV, 127);
  Serial.println("FRONT_RIGHT_REV");
  delay(1500);
  analogWrite(FRONT_RIGHT_REV, 0);
  analogWrite(BACK_LEFT_FWD, 127);
  Serial.println("BACK_LEFT_FWD");
  delay(1500);
  analogWrite(BACK_LEFT_FWD, 0);
  analogWrite(BACK_LEFT_REV, 127);
  Serial.println("BACK_LEFT_REV");
  delay(1500);
  analogWrite(BACK_LEFT_REV, 0);
  analogWrite(BACK_RIGHT_FWD, 127);
  Serial.println("BACK_RIGHT_FWD");
  delay(1500);
  analogWrite(BACK_RIGHT_FWD, 0);
  analogWrite(BACK_RIGHT_REV, 127);
  Serial.println("BACK_RIGHT_REV");
  delay(1500);
  analogWrite(BACK_RIGHT_REV, 0);
}
