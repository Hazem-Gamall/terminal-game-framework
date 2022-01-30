#include <cstdlib>
#include <ctime>
#include "PlayGameState.h"
#include "../Rendering/TerminalHandler.h"
#include "../StateMachine/StateMachine.h"
#include "../StateMachine/LostGameState.h"
#include "../Units/Dot.h"
#include "../Collision/CollisionHandler.h"

PlayGameState::~PlayGameState()
{
    delete level;
    delete snake;
}

PlayGameState::PlayGameState()
{
    totalScore = 0;
    stateID = "PLAY";
    int x = TerminalHandler::getInstance()->getWindowDimentions()->getX();
    int y = TerminalHandler::getInstance()->getWindowDimentions()->getY();
    level = new Level("level1");
    snake = new Snake("snake", new Vector2D(x / 2, y / 2));
    srand(time(0));
    level->addUnit(new Dot("dot", new Vector2D(rand() % x, rand() % y)));
}

void PlayGameState::update()
{
    int x = TerminalHandler::getInstance()->getWindowDimentions()->getX();
    int y = TerminalHandler::getInstance()->getWindowDimentions()->getY();
    snake->update();
    float head_x = (*snake->getBlocks()->begin())->getPosition()->getX();
    float head_y = (*snake->getBlocks()->begin())->getPosition()->getY();
    if (head_x > x || head_x < 0 || head_y > y || head_y < 0)
    {
        LostGameState *lostState = new LostGameState(new GraphicObject("lost", new TextureObject("Assets/lost.txt"), new Vector2D(25, 10)), totalScore);
        StateMachine::getInstance()->pushState(lostState);
    }
    checkCollision();
}

void PlayGameState::draw()
{
    mvprintw(0,0, "Score: %d", totalScore);
    level->draw();
    snake->draw();
}

void PlayGameState::checkCollision()
{
    for (auto unit : *level->getUnits())
    {
        for (auto block : *snake->getBlocks())
        {
            auto head = *snake->getBlocks()->begin();
            if (head != block && CollisionHandler::getInstance()->checkCollision(head, block))
            {
                LostGameState *lostState = new LostGameState(new GraphicObject("lost", new TextureObject("Assets/lost.txt"), new Vector2D(25, 10)), totalScore);
                StateMachine::getInstance()->pushState(lostState);
            }
            if (CollisionHandler::getInstance()->checkCollision(unit, block))
            {
                totalScore++;
                snake->addBlock();
                delete unit;
                int x = TerminalHandler::getInstance()->getWindowDimentions()->getX();
                int y = TerminalHandler::getInstance()->getWindowDimentions()->getY();
                unit = new Dot("dot", new Vector2D(2 + rand() % (x-2), 2+rand() % (y-2)));
                return;
            }
        }
    }
}