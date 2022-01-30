#pragma once
#include "Unit.h"

enum Direction{UP, DOWN, LEFT, RIGHT};

class SnakeBlock : public Unit{
public:
    SnakeBlock(std::string texture_id, Vector2D *pos);
    void update();
    void setVelocity(Direction dir, float speed);
    void clean(){}

};
