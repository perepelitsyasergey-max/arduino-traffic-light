

int RED = 13;
int YELLOW = 12;
int GREEN = 11;
int BUTTON = 2;
int BUZZER = 9;

const int GREEN_TIME = 80;    // Загальний час зеленого
const int FAST_BEEP_START = 50; // Коли починати швидко пищати

void setup() {
 pinMode( RED, OUTPUT);
 pinMode(YELLOW, OUTPUT);
 pinMode(GREEN, OUTPUT);
 pinMode(BUTTON, INPUT_PULLUP);
 pinMode(BUZZER, OUTPUT);

}

void loop() {

  // Зелений сигнал
  digitalWrite(GREEN, HIGH);
  for (int i=0; i<GREEN_TIME; i++) {
    if (digitalRead(BUTTON) == LOW) {
      break;
    }
    int beepInterval = (i < FAST_BEEP_START) ? 10:5;
    if (i%beepInterval == 0) {
      tone(BUZZER, 1000, 50);
    }  
    delay(100);    
  }
  digitalWrite(GREEN, LOW);
  



  // Жовний сингал
  for(int i=0; i<3; i++) {
    digitalWrite (YELLOW, HIGH);
    delay(400);
    digitalWrite(YELLOW,LOW);
    delay(400);    
  }

  // Червоний сигнал
  digitalWrite(RED, HIGH);
  delay(3000);
  digitalWrite(RED, LOW);

  

}
