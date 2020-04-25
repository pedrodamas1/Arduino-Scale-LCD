/*
 * Author: Pedro Damas
 * Date: 22/04/2020
 * Last edited: 25/04/2020
 */

#include <LiquidCrystal.h>
#include "HX711.h"

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;

// Adjustment settings
const long LOADCELL_OFFSET = 200004;
const long LOADCELL_DIVIDER = 1870.f;

// LCD pins order: RS EN D4 D5 D6 D7 BL
LiquidCrystal lcd(8,  9,  4,  5,  6,  10);
HX711 scale(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);

void setup() {
  initialize();
}

void loop() {
  lcd.setCursor(7,1);
  lcd.print( scale.get_units(10) );

  if (buttonPressed()) {
    scale.tare();
  }
  
  delay(100);
}
