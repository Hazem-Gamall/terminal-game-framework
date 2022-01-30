#ifndef TERMINALHANDLER
#define TERMINALHANDLER
#include <termios.h>
#include <unistd.h>
#include <vector>
#include <string>
#include <ncurses.h>
#include "TextureObject.h"
#include "../Vector2D.h"


class TerminalHandler{
public:
    ~TerminalHandler();
    static TerminalHandler* getInstance(){
        if(instance == 0){
            instance = new TerminalHandler();
        }
        return instance;
    }
    void init(WINDOW* w);
    void drawToTerminal(TextureObject* texture, Vector2D* position);
    Vector2D* getWindowDimentions();
private:
    static TerminalHandler* instance;
    TerminalHandler(){}
    WINDOW* window;
    std::vector<std::vector<std::string>> textures;
};

#endif