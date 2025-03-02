const int FRONT_LEFT_FWD = 3;
const int FRONT_LEFT_REV = 2;
const int FRONT_RIGHT_FWD = 11;
const int FRONT_RIGHT_REV = 10;
const int BACK_LEFT_FWD = 8;
const int BACK_LEFT_REV = 1;
const int BACK_RIGHT_FWD = 0;
const int BACK_RIGHT_REV = 7;
// const int BACK_RIGHT_FWD = 18;
// const int BACK_RIGHT_REV = 19;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(BACK_LEFT_FWD, OUTPUT);
  pinMode(BACK_LEFT_REV, OUTPUT);
  pinMode(BACK_RIGHT_FWD, OUTPUT);
  pinMode(BACK_RIGHT_REV, OUTPUT);
  pinMode(FRONT_LEFT_FWD, OUTPUT);
  pinMode(FRONT_LEFT_REV, OUTPUT);
  pinMode(FRONT_RIGHT_FWD, OUTPUT);
  pinMode(FRONT_RIGHT_REV, OUTPUT);
  digitalWrite(BACK_LEFT_FWD, LOW);
  digitalWrite(BACK_LEFT_REV, LOW);
  digitalWrite(BACK_RIGHT_FWD, LOW);
  digitalWrite(BACK_RIGHT_REV, LOW);
  digitalWrite(FRONT_LEFT_FWD, LOW);
  digitalWrite(FRONT_LEFT_REV, LOW);
  digitalWrite(FRONT_RIGHT_FWD, LOW);
  digitalWrite(FRONT_RIGHT_REV, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(FRONT_LEFT_FWD, HIGH);
  Serial.println("FRONT_LEFT_FWD");
  delay(1500);
  digitalWrite(FRONT_LEFT_FWD, LOW);
  digitalWrite(FRONT_LEFT_REV, HIGH);
  Serial.println("FRONT_LEFT_REV");
  delay(1500);
  digitalWrite(FRONT_LEFT_REV, LOW);
  digitalWrite(FRONT_RIGHT_FWD, HIGH);
  Serial.println("FRONT_RIGHT_FWD");
  delay(1500);
  digitalWrite(FRONT_RIGHT_FWD, LOW);
  digitalWrite(FRONT_RIGHT_REV, HIGH);
  Serial.println("FRONT_RIGHT_REV");
  delay(1500);
  digitalWrite(FRONT_RIGHT_REV, LOW);
  digitalWrite(BACK_LEFT_FWD, HIGH);
  Serial.println("BACK_LEFT_FWD");
  delay(1500);
  digitalWrite(BACK_LEFT_FWD, LOW);
  digitalWrite(BACK_LEFT_REV, HIGH);
  Serial.println("BACK_LEFT_REV");
  delay(1500);
  digitalWrite(BACK_LEFT_REV, LOW);
  digitalWrite(BACK_RIGHT_FWD, HIGH);
  Serial.println("BACK_RIGHT_FWD");
  delay(1500);
  digitalWrite(BACK_RIGHT_FWD, LOW);
  digitalWrite(BACK_RIGHT_REV, HIGH);
  Serial.println("BACK_RIGHT_REV");
  delay(1500);
  digitalWrite(BACK_RIGHT_REV, LOW);
}
