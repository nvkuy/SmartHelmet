const int fsrTop = 0;
const int fsrBot = 1;
const int button = 8;
const int enA = 9;
const int in1 = 6;
const int in2 = 7;

int fsrTopVal;
int fsrBotVal;
int isFit;
int isPress;
//int isTakeOff;
unsigned long int steps;
//int isFirst;

void setup() {

  Serial.begin(9600);

  pinMode(button, INPUT);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  steps = 0;
  isFit = 0;
//  isFirst = 1;

}

void loop() {

  isPress = digitalRead(button);
  fsrTopVal = analogRead(fsrTop);
  fsrBotVal = analogRead(fsrBot);
  analogWrite(enA, 255);

    Serial.print("Top: ");
    Serial.println(fsrTopVal);
    Serial.print("Bot: ");
    Serial.println(fsrBotVal);
    Serial.println(isFit);

  if (fsrTopVal > 30) {
    if (isFit == 0) {
      steps++;
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      Serial.println(steps);
    }
  } //else {
  //  isTakeOff = 1;
  //}

  if (fsrBotVal > 100) {
    isFit = 1;
    digitalWrite(in1, HIGH);
    digitalWrite(in2, HIGH);
    Serial.println(isFit);
  }

  if (isPress == HIGH) {
//    if (isFirst = 1) {
//      steps += 50; 
//      isFirst = 0; 
//    }
//    Serial.println(isFit);
//    steps = 100;
    while (steps != 0) {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      steps--;
      Serial.println(steps);
    }
    digitalWrite(in1, HIGH);
    digitalWrite(in2, HIGH);
    isFit = 0;
//    isFirst = 1;
  }
}
