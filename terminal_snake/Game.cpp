#include "Game.h"
#include "Input/InputHandler.h"
#include "Rendering/TerminalHandler.h"
#include "StateMachine/StateMachine.h"
#include "Units/Dot.h"
#include "Units/Snake.h"
#include "StateMachine/MenuGameState.h"
#include "StateMachine/WonGameState.h"
#include "Rendering/GraphicObject.h"
#include <fstream>

Game *Game::instance = 0;

void Game::init()
{
    std::ofstream file("log.txt");
    running = true;
    TerminalHandler::getInstance()->init(stdscr);
    InputHandler::getInstance()->init(stdscr);

    TextureManager::getInstance()->addTexture("snake_block", new TextureObject("Assets/snake_block.txt"));
    TextureManager::getInstance()->addTexture("dot", new TextureObject("Assets/dot.txt"));
    MenuGameState *menuState = new MenuGameState();
    menuState->addTexture(new GraphicObject("welcome", new TextureObject("Assets/welcome.txt"), new Vector2D(25, 10)));
    StateMachine::getInstance()->pushState(new WonGameState(new GraphicObject("welcome", new TextureObject("Assets/welcome.txt"), new Vector2D(25, 10))));
    StateMachine::getInstance()->changeState(menuState);
}

void Game::update()
{
    StateMachine::getInstance()->update();
    InputHandler::getInstance()->update();

    if (InputHandler::getInstance()->isKeyDown(' '))
    {
        StateMachine::getInstance()->changeState(new PlayGameState());
    }

    if (InputHandler::getInstance()->isKeyDown('q'))
    {
        quit();
    }
}

void Game::draw()
{
    erase();
    StateMachine::getInstance()->draw();
}

void Game::quit()
{
    running = false;
}
