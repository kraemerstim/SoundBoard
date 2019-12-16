#include "Button.h"

const int ButtonDelay = 500;
const int ButtonSize = 6;
Button buttons[ButtonSize] = {
    Button(0, 2),
    Button(1, 3),
    Button(2, 4),
    Button(3, 5),
    Button(4, 6),
    Button(5, 7)
  };

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(30);
  Serial.println('\n');

  for (int i = 0; i < ButtonSize; i++) {
    pinMode(buttons[i].getPin(), INPUT_PULLUP);
    delay(50);
    Button::registerButton(buttons[i]);
  }
}

void sendButtonPressed(int pressedID) {
  Serial.print("Gedrückt: ");
  Serial.println(pressedID);
}

void loop() {
  // put your main code here, to run repeatedly:
  int pressedId = Button::getPressedId();
  if (pressedId > -1) {
    sendButtonPressed(pressedId);
    delay(ButtonDelay);
  }
  delay(10);
}
