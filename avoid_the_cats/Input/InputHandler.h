#ifndef INPUTHANDLER
#define INPUTHANDLER
#include <ncurses.h>

class InputHandler{
public:
    static InputHandler* getInstance(){
        if(instance == 0){
            instance = new InputHandler();
        }
        return instance;
    }

    void init(WINDOW *w);
    void update();
    bool isKeyDown(int);

private:
    InputHandler(){}
    static InputHandler* instance;
    int pressed_key;
    WINDOW* w;
};

#endif