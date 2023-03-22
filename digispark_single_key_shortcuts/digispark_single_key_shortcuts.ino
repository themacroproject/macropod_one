/*
 Digispark Single Key Example

 This sketch demonstrates how to perform shortcut operations 
 using a single key with the Digispark ATTiny85.

 Below is a list of predefined keys that you can use:
 https://github.com/themacroproject/arduino_code/Arduino_Keyboard_Macros.pdf

 Circuit:
 * Digispark ATTiny85
 * wire to connect P1 to OUT of key1.

 created 3 March 2023
 by Aniket Katkar
 THE MACRO PROJECT: https://themacroproject.github.io

 This example is in the public domain under MIT Licence
 https://opensource.org/license/mit/

 https://github.com/themacroproject/arduino_code
 https://github.com/themacroproject/circuit_design
 */

#include "DigiKeyboard.h";

// the number of the key pin
const int keyPin1 = 1;  

// declare key variable states for reading the key 1 status
int keyState1 = 0; 

void setup() {
  pinMode(keyPin1, INPUT);
}

void loop() {
  // this is generally not necessary but with some older systems it seems to
  // prevent missing the first character after a delay:
  DigiKeyboard.sendKeyStroke(0);

  // read the state of the pushbutton value:
  keyState1 = digitalRead(keyPin1);

  // Check key got pressed and type corressponding string letter by 
  // letter on the computer (assumes US-style keyboard)
  if (keyState1 == HIGH) {
    // shortcut to show desktop on Windows OS
    DigiKeyboard.sendKeyStroke(KEY_D, MOD_GUI_LEFT);
  }

  // It's better to use DigiKeyboard.delay() over the regular Arduino delay()
  // if doing keyboard stuff because it keeps talking to the computer to make
  // sure the computer knows the keyboard is alive and connected
  DigiKeyboard.delay(500);
}

