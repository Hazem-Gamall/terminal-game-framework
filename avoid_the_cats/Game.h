#ifndef GAME
#define GAME

#include "Units/Player.h"
#include "StateMachine/PlayGameState.h"

class Game{
public:
    ~Game();
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
    bool isRunning();

private:
    Game(){}
    static Game* instance;

    bool running;
};

#endif