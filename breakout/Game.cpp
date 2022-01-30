#include "Game.h"
#include "Input/InputHandler.h"
#include "Rendering/TerminalHandler.h"
#include "StateMachine/StateMachine.h"
#include "StateMachine/MenuGameState.h"
#include "Units/Block.h"

Game* Game::instance = 0;

void Game::init(){
    running = true;
    TerminalHandler::getInstance()->init(stdscr);
    InputHandler::getInstance()->init(stdscr);
    
    TextureManager::getInstance()->addTexture("player", new TextureObject("Assets/player.txt"));
    TextureManager::getInstance()->addTexture("ball", new TextureObject("Assets/ball.txt"));
    TextureManager::getInstance()->addTexture("block", new TextureObject("Assets/block.txt"));

    MenuGameState* menuState = new MenuGameState();
    menuState->addTexture(new GraphicObject("welcome", new TextureObject("Assets/welcome.txt"), new Vector2D(25,10)));

  


    StateMachine::getInstance()->pushState(menuState);
}

void Game::update(){
    StateMachine::getInstance()->update();
    InputHandler::getInstance()->update();


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
