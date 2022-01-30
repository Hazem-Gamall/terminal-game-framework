#ifndef GAMESTATE
#define GAMESTATE

#include <string>

class GameState{
public: 
    virtual ~GameState(){}
    virtual void update() = 0;
    virtual void draw() = 0;
    std::string getStateID() const {return stateID;}

protected:
    std::string stateID;
};

#endif