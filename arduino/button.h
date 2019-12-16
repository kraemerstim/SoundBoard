#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button {
    private:
        static Button activeButtons[20];
        static int buttonCount;

    public:
        static int getPressedId();

        static void registerButton(Button button);

    private:
        int button_id;
        int pin;
 

    public:
        Button(int button_id, int pin);
        Button();

        int getButtonId();
        int getPin();
};

#endif 
