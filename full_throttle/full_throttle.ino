const int FRONT_LEFT_FWD = 15;
const int FRONT_LEFT_REV = 16;
const int FRONT_RIGHT_FWD = 17;
const int FRONT_RIGHT_REV = 18;
const int BACK_LEFT_FWD = 19;
const int BACK_LEFT_REV = 21;
const int BACK_RIGHT_FWD = 22;
const int BACK_RIGHT_REV = 23;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  analogWrite(FRONT_LEFT_FWD, 255);
  analogWrite(FRONT_RIGHT_FWD, 255);
  analogWrite(BACK_LEFT_FWD, 255);
  analogWrite(BACK_RIGHT_FWD, 255);
  analogWrite(FRONT_LEFT_REV, 0);
  analogWrite(FRONT_RIGHT_REV, 0);
  analogWrite(BACK_LEFT_REV, 0);
  analogWrite(BACK_RIGHT_REV, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    Serial.println(Serial.readStringUntil('\n'));
  }
}
