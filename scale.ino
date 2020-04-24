
#include <LiquidCrystal.h>
#include "HX711.h"

//LCD pin to Arduino
const int pin_RS = 8; 
const int pin_EN = 9; 
const int pin_d4 = 4; 
const int pin_d5 = 5; 
const int pin_d6 = 6; 
const int pin_d7 = 7; 
const int pin_BL = 10;

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;

// Adjustment settings
const long LOADCELL_OFFSET = 200004;
const long LOADCELL_DIVIDER = 1870.f;

LiquidCrystal lcd( pin_RS,  pin_EN,  pin_d4,  pin_d5,  pin_d6,  pin_d7);
HX711 scale;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Boa bricolage!");
  lcd.setCursor(0,1);
  lcd.print("Peso:");

  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(LOADCELL_DIVIDER);
  scale.set_offset(LOADCELL_OFFSET);
  delay(1000);
  scale.tare();
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(7,1);

  if (analogRead(0)<800) {
    scale.tare();
  }
  
  lcd.print( scale.get_units(10) );
  delay(100);
}
