/*
 * 
 * https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide/installing-windows
 */

#include "Keyboard.h"

#define N_BUTTONS 10

String macros[N_BUTTONS] = {
  // Left column (from 1 to 5)
  "L1",
  "L2",
  "L3",
  "L4",
  "Hello I typed this from my macro keyboard!",
  // Right column (from 1 to 5)
  "R1",
  "R2",
  "R3",
  "R4",
  "R5",
};

int pins[N_BUTTONS] {
  9,
  8,
  7,
  6,
  5,
  10,
  16,
  14,
  15,
  2,
};
int currentState[N_BUTTONS];

void setup() {
  for (int i = 0; i < N_BUTTONS; ++i) {
    pinMode(pins[i], INPUT_PULLUP);
    currentState[i] = digitalRead(pins[i]);
  }
  Keyboard.begin();
  delay(300);
}

int counter = 0;

void loop() {
  for (int i = 0; i < N_BUTTONS; ++i) {
    int buttonState = digitalRead(pins[i]);
    if (buttonState != currentState[i]) {
      currentState[i] = buttonState;
      if (buttonState == 1) {
        if (macros[i] == "INCREMENT") {
          Keyboard.print(String(counter++));
        } else if (macros[i] == "RESET") {
          counter = 0;
        } else {
          Keyboard.print(macros[i]);  
        }
//        Serial.println(macros[i]);
        delay(100);
      }
    }
  }
}
