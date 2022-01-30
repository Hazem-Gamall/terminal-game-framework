#pragma once
#include <list>
#include "Unit.h"
#include "SnakeBlock.h"


class Snake : public Unit{
public:
    Snake(std::string texture_id, Vector2D* pos);
    void update();
    void draw();
    void clean(){}
    void addBlock();
    std::list<SnakeBlock*> *getBlocks();
    

private:
    const float speed = 1;
    Direction direction;
    std::list<SnakeBlock*> blocks;
};