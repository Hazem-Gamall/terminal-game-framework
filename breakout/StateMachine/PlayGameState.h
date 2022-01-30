#ifndef PLAYGAMESTATE
#define PLAYGAMESTATE

#include "GameState.h"
#include "../Level/Level.h"
#include "../Rendering/TextureObject.h"
#include "../Units/Ball.h"
#include "../Units/Player.h"

#include <vector>

class PlayGameState : public GameState{
public:
    PlayGameState();
    ~PlayGameState();
    void update();
    void draw();
    void onExit();

    void pushLevel(Level*);
    void popLevel();
    void changeLevel(Level*);
    int getTotalScore() const {return totalScore;}
    
private:
    void checkCollision();
    int totalScore;
    std::vector<Level*> levels;
    Player* player;
    Ball* ball;
};

#endif