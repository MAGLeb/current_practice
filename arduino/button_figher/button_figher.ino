#define PREPARE_LED_PIN 3
#define FIRST_LED_PIN 4
#define SECOND_LED_PIN 5

#define SOUND_PIN 6

#define FIRST_BUTTON_PIN 10
#define SECOND_BUTTON_PIN 9

#define NUMBER_TO_WIN 10

int counterFirst = 0;
int counterSecond = 0;
int prevValueFirst = 1;
int prevValueSecond = 1;


void setup() {
  Serial.begin(9600);
  pinMode(PREPARE_LED_PIN, OUTPUT);
  pinMode(FIRST_LED_PIN, OUTPUT);
  pinMode(SECOND_LED_PIN, OUTPUT);

  pinMode(SOUND_PIN, OUTPUT);

  pinMode(FIRST_BUTTON_PIN, INPUT_PULLUP);
  pinMode(SECOND_BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  int firstButton = digitalRead(FIRST_BUTTON_PIN);
  int secondButton = digitalRead(SECOND_BUTTON_PIN);
  
  if (firstButton == 0 && prevValueFirst == 1) {
    counterFirst += 1;
  }
  if (secondButton == 0 && prevValueSecond == 1) {
    counterSecond += 1;
  }
  prevValueSecond = secondButton;
  prevValueFirst = firstButton;

  if (counterFirst == NUMBER_TO_WIN || counterSecond == NUMBER_TO_WIN) {
    tone(SOUND_PIN, 4000, 3000);

    if (counterFirst > counterSecond) {
      digitalWrite(FIRST_LED_PIN, HIGH);
    } else {
      digitalWrite(SECOND_LED_PIN, HIGH);
    }
    counterFirst = 0;
    counterSecond = 0;
    prevValueSecond = 1;
    prevValueFirst = 1;

    delay(3000);
    digitalWrite(FIRST_LED_PIN, LOW);
    digitalWrite(SECOND_LED_PIN, LOW);

    for (int i = 0; i < random(2, 7); i++) {
      digitalWrite(PREPARE_LED_PIN, HIGH);
      tone(SOUND_PIN, 500, 500);
      delay(500);
      digitalWrite(PREPARE_LED_PIN, LOW);
      delay(500);
    }
  }
  Serial.println(counterSecond);
}
