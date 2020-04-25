 /*
 * Initialize the LCD and the HX711 modules
 */
 
void initialize() {
   // LCD stuff:
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Boa bricolage!");
  lcd.setCursor(0,1);
  lcd.print("Peso:");

  // HX711 stuff:
  scale.set_scale(LOADCELL_DIVIDER);
  scale.set_offset(LOADCELL_OFFSET);

  // Give the scale some time to settle before taring
  delay(1000);
  scale.tare();
}
