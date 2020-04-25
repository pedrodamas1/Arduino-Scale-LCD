/*
 * Check if the button has been pressed
 */

 bool buttonPressed() {
  int val = analogRead(0);
  if (val<800) {
    return true;
  }
  else {
    return false;
  }
 }
