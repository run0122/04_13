const int button1 = 7;
const int button2 = 8;
const int photo = A1;

bool test = false;

unsigned long previousMillis = 0;
const long interval = 1000;

int max = 0;
int min = 1000;

void setup() {
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(photo, INPUT);
  Serial.begin(9600);
}

void loop() {
  int reading1 = digitalRead(button1);
  int reading2 = digitalRead(button2);

  unsigned long currentMillis = millis();

  if (reading1 == HIGH) {
    Serial.println("테스트 시작");
    test = true;
    delay(200);
  }
  if (test == true) {
    if ((currentMillis - previousMillis) >= interval) {
      int photoValue = analogRead(A1);

      Serial.println("조도 센서 값 받는 중");
      Serial.println((String) "값 : " + photoValue);

      if (min > photoValue) {
        min = photoValue;
      }
      if (max < photoValue) {
        max = photoValue;
      }

      previousMillis = currentMillis;
    }
  }
  if (reading2 == HIGH) {
    test = false;
    Serial.println("테스트 종료");
    Serial.println((String) "최댓값 : " + max);
    Serial.println((String) "최솟값 : " + min);
    delay(200);
  }
}
