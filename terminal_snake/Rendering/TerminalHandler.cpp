#include "TerminalHandler.h"
#include <iostream>

TerminalHandler* TerminalHandler::instance = 0;

void TerminalHandler::init(WINDOW* w){
    window = w;
}


Vector2D* TerminalHandler::getWindowDimentions(){
    int x, y;
    getmaxyx(window, y, x);
    return (new Vector2D(x,y));
}

void TerminalHandler::drawToTerminal(TextureObject* texture, Vector2D* position){
    int x = position->getX();
    int y = position->getY();


    for(std::string str : texture->getTexture()){
        // printf("%s", str.c_str());
        mvwprintw(window, y++, x, str.c_str());
    }
    // printw("done\n");
}

TerminalHandler::~TerminalHandler(){
    endwin();
}
