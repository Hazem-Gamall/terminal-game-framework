#ifndef PLAYGAMESTATE
#define PLAYGAMESTATE

#include "GameState.h"
#include "../Level/Level.h"
#include "MenuGameState.h"
#include "../Rendering/GraphicObject.h"
#include "../Rendering/TextureObject.h"
#include "../Vector2D.h"
#include "../Units/Player.h"
#include <vector>

class PlayGameState : public GameState{
public:
    PlayGameState();
    ~PlayGameState();
    void update();
    void draw();

    void pushLevel(Level*);
    void popLevel();
    void changeLevel(Level*);
    int getTotalScore() const {return totalScore;}
    bool checkCollision();
    
private:
    int totalScore;
    bool isDone();
    GraphicObject* levelDone;
    std::vector<Level*> levels;
    Player* player;
};

#endif