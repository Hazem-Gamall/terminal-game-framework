#pragma once

#include "Units/Ball.h"
#include "Units/Player.h"
#include "StateMachine/PlayGameState.h"

class Game{
public:
    static Game* getInstance(){
        if(instance == 0){
            instance = new Game();
        }
        return instance;
    }
    void init();
    void update();
    void draw();
    void quit();
    bool isRunning() const {return running;}

private:
    Game(){}
    static Game* instance;
    bool running;
};