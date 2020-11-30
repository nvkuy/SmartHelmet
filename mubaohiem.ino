const int fsrTop = 0;
const int fsrBot = 1;
const int motor = 5;
const int button = 2;

int fsrTopVal;
int fsrBotVal;
int isPress;
//bool isRelease, isFit;

void setup() {
  Serial.begin(9600);
  pinMode(motor, OUTPUT);
  pinMode(button, INPUT);
//  isRelease = false;
//  isFit = false;
}

void loop() {
  fsrTopVal = analogRead(fsrTop);
  fsrBotVal = analogRead(fsrBot);
  Serial.print("Top: ");
  Serial.println(fsrTopVal);
  Serial.print("Bot: ");
  Serial.println(fsrBotVal);
//  if ((fsrTopVal > 10) && (isRelease = false) && (isFit = false)) {
//    digitalWrite(motor, HIGH);
//  }
  if (fsrTopVal > 10) {
    digitalWrite(motor, HIGH);
  }
  if (fsrBotVal > 10) {
//    isFit = true;
    digitalWrite(motor, LOW);
  }
//  isPress = digitalRead(button);
//  if (isPress == HIGH) {
//    Serial.println("Release!");
//    isRelease = true;
//    isFit = false;
//  }
//  if (isRelease = true) {
//    analogWrite(motor, 255);
//  }
  isPress = digitalRead(button);
  if (isPress == HIGH) {
    Serial.println("Release!");
    analogWrite(motor, 0);
  }
}
