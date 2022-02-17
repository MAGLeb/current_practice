#define BUTTON_PIN 2
#define SOUND_PIN 3
#define FIRST_LED_PIN 4
#define LAST_LED_PIN 13
#define TEMP_SEN_PIN A0
#define LIGHT_SEN_PIN A1

#define THERESHOLD_SOUND 990
#define LED_ON 2

int temp = 0;
int temp_min = 1023;
int temp_max = 0;

int light = 0;
int light_min = 1023;
int light_max = 0;

int number_leds = 0;
boolean prev = true;
boolean state = true;


void setup() {
  // initialize digital pin LED_BUILTIN as an output.

  pinMode(SOUND_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  
  for(int i=FIRST_LED_PIN; i<=LAST_LED_PIN; i++)
    pinMode(i, OUTPUT);

  Serial.begin(9600);
}

// the loop function runs over and over again forever
// digitalWrite(PIN, HIGH/LOW);
// delay(time in seconds);
void loop() {
  temp = analogRead(TEMP_SEN_PIN);
  light = analogRead(LIGHT_SEN_PIN);
  boolean current = digitalRead(BUTTON_PIN);

  if(temp > temp_max) {
    temp_max = temp;
  }
  if(temp < temp_min)
    temp_min = temp;

  if(light > light_max)
    light_max = light;
  if(light < light_min)
    light_min = light;

  if(!current && prev)
    state = !state;
    
  prev = current;

  if(state) {
    number_leds = temp;
    number_leds = map(number_leds, temp_min, temp_max, 4, 13);
  } else {
    number_leds = light;
    number_leds = map(number_leds, light_min, light_max, 4, 13);
  }
  
  for(int i=FIRST_LED_PIN; i<=number_leds; i++) {
    digitalWrite(i, HIGH);
    delay(LED_ON);
    digitalWrite(i, LOW);
  }

  if(light > (light_min + light_max) / 2)
    tone(SOUND_PIN, 3000, 100);
}
