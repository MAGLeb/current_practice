#include <LiquidCrystal.h>

#define DIODE_DROP 0.7

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

void setup() {
  lcd.begin(16, 2);
  lcd.print("VOLTAGE METRE");
}

void loop() {
  float voltage = analogRead(A0) / 1024.0 * 10.0;

  if(voltage > 0.1) {
    voltage += DIODE_DROP;
  }

  lcd.setCursor(0, 1);
  lcd.print(voltage);
  lcd.print(" Volts");
}