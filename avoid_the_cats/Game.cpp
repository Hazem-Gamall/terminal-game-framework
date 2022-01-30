#include "Game.h"
#include "Rendering/TextureObject.h"
#include "Level/Level.h"
#include "StateMachine/StateMachine.h"
#include "Rendering/TerminalHandler.h"
#include "StateMachine/MenuGameState.h"
#include "Audio/AudioHandler.h"
#include "Audio/AudioObject.h"
#include "Input/InputHandler.h"
#include "Units/Enemy.h"
#include "Rendering/GraphicObject.h"
#include <ncurses.h>

Game* Game::instance = 0;

void Game::init(){
    TerminalHandler::getInstance()->init(stdscr);
    InputHandler::getInstance()->init(stdscr);

    running = true;

   
    MenuGameState* menuState = new MenuGameState();
    menuState->addTexture(new GraphicObject("welcome",new TextureObject("Assets/welcome.txt"), new Vector2D(25,10)));

    
    StateMachine::getInstance()->pushState(menuState);
}

void Game::update(){
    InputHandler::getInstance()->update();
    StateMachine::getInstance()->update();
    if(InputHandler::getInstance()->isKeyDown(' ')){
        StateMachine::getInstance()->changeState(new PlayGameState());
    }
    if(InputHandler::getInstance()->isKeyDown('q')){
        quit();
    }
}

void Game::draw(){
    erase();
    StateMachine::getInstance()->draw();
}

void Game::quit(){
    running = false;
}

bool Game::isRunning(){
    return running;
}

Game::~Game(){
    delete TerminalHandler::getInstance();
}

