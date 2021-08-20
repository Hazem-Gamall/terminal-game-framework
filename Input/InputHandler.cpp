#include "InputHandler.h"
#include <cctype>

InputHandler* InputHandler::instance = 0;


void InputHandler::init(WINDOW *w){
    pressed_key = -1;
    this->w = w;
}

void InputHandler::update(){
    pressed_key = tolower(wgetch(w));
}

bool InputHandler::isKeyDown(int key){
    return (pressed_key == key);
}