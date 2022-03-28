#define MOTOR_PIN 9
#define BUTTON_START_PIN 5
#define BUTTON_NUMBER 3

#define STEP_SPEED (255 / (BUTTON_NUMBER - 1))

void setup() {
  int i = BUTTON_START_PIN;

  while(i < BUTTON_START_PIN + BUTTON_NUMBER) {
    pinMode(i++, INPUT_PULLUP);
  }

  pinMode(MOTOR_PIN, OUTPUT);  
}

void loop() {
  for(int i = 0; i < BUTTON_NUMBER; i++) {
    if(!digitalRead(BUTTON_START_PIN + i)) {
      int speed = STEP_SPEED * i;
      analogWrite(MOTOR_PIN, speed);
    }
  }
}