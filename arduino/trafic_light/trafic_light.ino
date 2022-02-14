#define RED_PIN 12
#define YELLOW_PIN 10
#define GREEN_PIN 8

int red_on = 3000;
int yellow_on = 1200;
int green_on = 3000;
int color_blink = 500;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(RED_PIN, HIGH);
  delay(red_on);
  digitalWrite(YELLOW_PIN, HIGH);
  delay(yellow_on);
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);

  // GREEN ON
  digitalWrite(GREEN_PIN, HIGH);
  delay(green_on);

  for(int i = 0; i < 3; i++) {
    digitalWrite(GREEN_PIN, LOW);
    delay(color_blink);   
    digitalWrite(GREEN_PIN, HIGH);
    delay(color_blink);      
  }
     
  // GREEN TO RED
  digitalWrite(YELLOW_PIN, HIGH);
  delay(yellow_on);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
}
