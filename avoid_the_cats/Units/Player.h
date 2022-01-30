#ifndef PLAYER
#define PLAYER

#include "Unit.h"
#include "../Vector2D.h"

class Player : public Unit{
public:
    Player(){}
    Player(TextureObject*, Vector2D* position);
    void update();
    void clean();
    void reset();

private:
    Vector2D orig_position;
    void handleInput();
};

#endif