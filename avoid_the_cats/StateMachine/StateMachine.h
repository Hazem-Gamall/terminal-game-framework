#ifndef GAMESTATEMACHINE
#define GAMESTATEMACHINE

#include <vector>
#include "GameState.h"


class StateMachine{
public:
    static StateMachine* getInstance(){
        if(instance == 0){
            instance = new StateMachine();
        }
        return instance;
    }

    void pushState(GameState*);
    void popState();
    void changeState(GameState*);

    void update();

    void draw();
    
    void clean();

private:
    std::vector<GameState*> gameStates;
    static StateMachine* instance;
};

#endif