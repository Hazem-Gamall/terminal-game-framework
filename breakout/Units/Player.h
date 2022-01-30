#ifndef PLAYER
#define PLAYER

#include "Unit.h"
#include "../Vector2D.h"

class Player : public Unit{
public:
    Player(std::string texture_id, Vector2D* position);
    void update();
    void clean();
    bool checkCollision(Unit*);
    void reset();
    
private:
    Vector2D orig_position;
    void handleInput();
};

#endif