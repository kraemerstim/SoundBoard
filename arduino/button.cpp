#include "Button.h"

int Button::buttonCount = 0;
Button Button::activeButtons[20];

Button::Button(int button_id, int pin) {
  this->button_id = button_id;
  this->pin = pin;
}

Button::Button() {

}

int Button::getButtonId() {
  return this->button_id;
}

int Button::getPin() {
    return this->pin;
}

void Button::registerButton(Button button) {
    activeButtons[buttonCount] = button;
    buttonCount++;
}

int Button::getPressedId() {
    for (int i = 0; i < buttonCount; i++) {
        if (digitalRead(activeButtons[i].getPin()) == LOW) {
            return activeButtons[i].getButtonId();
        }
    }
    return -1;
}
