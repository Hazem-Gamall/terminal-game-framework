#include "Snake.h"
#include <fstream>
#include "../Input/InputHandler.h"

Snake::Snake(std::string texture_id, Vector2D *pos)
{
    textureID = texture_id;
    position = pos;
    velocity = new Vector2D(0,-speed);
    // block_counter = 0;
    direction = UP;

    for (int i = 0; i < 10; i++)
    {
        blocks.push_back(new SnakeBlock("snake_block", new Vector2D(15, 15 + (i * speed))));
        // blocks.back()->setVelocity(UP, speed);
    }
}

void Snake::draw()
{
    for (auto block : blocks)
    {
        block->draw();
    }
}

void Snake::update()
{
    auto keyboard = InputHandler::getInstance();

    if (direction != DOWN && (keyboard->isKeyDown('w') || keyboard->isKeyDown(KEY_UP)))
    {
        velocity->setX(0);
        velocity->setY(-speed);
        direction = UP;
    }
    if (direction != UP && (keyboard->isKeyDown('s') || keyboard->isKeyDown(KEY_DOWN)))
    {
        velocity->setX(0);
        velocity->setY(speed);
        direction = DOWN;

    }
    if (direction != RIGHT && (keyboard->isKeyDown('a') || keyboard->isKeyDown(KEY_LEFT)))
    {   
        velocity->setX(-2*speed);
        velocity->setY(0);
        direction = LEFT;
    }
    if (direction != LEFT && (keyboard->isKeyDown('d') || keyboard->isKeyDown(KEY_RIGHT)))
    {
        velocity->setX(2*speed);
        velocity->setY(0);
        direction = RIGHT;
    }

    addBlock();
    delete blocks.back();
    blocks.pop_back();

    // printf("%d\n", block_counter);
    {
        std::ofstream file("log.txt", std::ios::app);
        int i = 0;
        for (auto block : blocks)
        {
            
            block->update();

            file << i++ << " Position: (" << block->getPosition()->getX() << ", " << block->getPosition()->getY() << ")\n";
        }
        file << "************************iteration************************\n";
    }

}

void Snake::addBlock(){
    float head_x = blocks.front()->getPosition()->getX();
    float head_y = blocks.front()->getPosition()->getY();
    
    blocks.insert(
        blocks.begin(),
        new SnakeBlock
            (
                "snake_block", new Vector2D(head_x + velocity->getX(), head_y + velocity->getY())
            )
    );

}

std::list<SnakeBlock*> *Snake::getBlocks(){
    return &blocks;
}