#include "PlayGameState.h"
#include "../Audio/AudioHandler.h"
#include "StateMachine.h"
#include "../Collision/CollisionHandler.h"
#include "../Game.h"
#include "../Units/Block.h"
#include "LostGameState.h"
#include "WonGameState.h"
#include <list>

PlayGameState::PlayGameState(){
    totalScore = 0;
    stateID = "PLAY";
    int x = TerminalHandler::getInstance()->getWindowDimentions()->getX();
    int y = TerminalHandler::getInstance()->getWindowDimentions()->getY();

    player = new Player("player",new Vector2D((x/2)-8, y-1));
    ball = new Ball("ball", new Vector2D(50,20));

    Level* level = new Level("Level1");
    for(int i = 0; i < (TerminalHandler::getInstance()->getWindowDimentions()->getX()/5)-1; i++)
        for(int j = 1; j < 5; j++)
            level->addUnit(new Block("block", new Vector2D(5*i,j*3)));

    pushLevel(level);
}

PlayGameState::~PlayGameState(){
    if(!levels.empty()){
        for(Level* level : levels){
            delete level;
        }
    }
    delete player;
    delete ball;
}


void PlayGameState::update(){

    if(ball->isLost()){
        LostGameState* lostState = new LostGameState(new GraphicObject("lost", new TextureObject("Assets/lost.txt"), new Vector2D(25,10)), totalScore);
        StateMachine::getInstance()->pushState(lostState);
    }
    if(levels.back()->getUnits()->empty()){
        WonGameState* wonState = new WonGameState(new GraphicObject("won", new TextureObject("Assets/won.txt"), new Vector2D(25,10)));
        StateMachine::getInstance()->pushState(wonState);
    }
    checkCollision();
    player->update();
    ball->update();

}

void PlayGameState::draw(){

    mvprintw(0, 0, "Score:%d", totalScore);
    mvprintw(0, (TerminalHandler::getInstance()->getWindowDimentions()->getX()/2)-6
    ,"%s",levels.back()->getLevelID().c_str());

    player->draw();
    ball->draw();

    if(!levels.empty()){
        levels.back()->draw();
    }
}

void PlayGameState::pushLevel(Level* level){
    levels.push_back(level);
}

void PlayGameState::changeLevel(Level* level){
    if(level->getLevelID() == levels.back()->getLevelID()){
        //Same level nothing changes
    }else{
        popLevel();
        pushLevel(level);
    }
}

void PlayGameState::popLevel(){
    levels.pop_back();
}


void PlayGameState::checkCollision(){
    if(!levels.empty()){
        std::list<Unit*> *units = levels.back()->getUnits();
        for(std::list<Unit*>::iterator it = units->begin(); it != units->end(); ++it){
            if(CollisionHandler::getInstance()->checkCollision(ball, *it)){
                ball->down();
                ++totalScore;
                it = levels.back()->deleteUnit(it);
                break;
            }
        }
    }
    if(CollisionHandler::getInstance()->checkCollision(player, ball)){
        ball->up();
    }
}