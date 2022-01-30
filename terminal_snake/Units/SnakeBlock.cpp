#include "SnakeBlock.h"

SnakeBlock::SnakeBlock(std::string texture_id, Vector2D *pos)
{
    textureID = texture_id;
    position = pos;
    velocity = new Vector2D(0, 0);
}

void SnakeBlock::update()
{
    // printf("velocit: (%f, %f)\n" , velocity->getX(), velocity->getY());
    *position += *velocity;
}

void SnakeBlock::setVelocity(Direction dir, float speed)
{
    // printf("direction: %d, speed: %f", dir, speed);
    switch (dir)
    {
    case UP:
        velocity->setY(-speed);
        velocity->setX(0);
        break;
    case DOWN:
        velocity->setY(speed);
        velocity->setX(0);
        break;
    case RIGHT:
        velocity->setY(0);
        velocity->setX(speed);
        break;
    case LEFT:
        velocity->setY(0);
        velocity->setX(-speed);
        break;
    default:
        break;
    }
}