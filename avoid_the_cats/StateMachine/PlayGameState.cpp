#include "PlayGameState.h"
#include "../Audio/AudioHandler.h"
#include "StateMachine.h"
#include "LostGameState.h"
#include "WonGameState.h"
#include "../Game.h"
#include "../Units/Enemy.h"
#include "../Collision/CollisionHandler.h"

PlayGameState::PlayGameState(){ 
    totalScore = 0;
    stateID = "PLAY";

    int x = TerminalHandler::getInstance()->getWindowDimentions()->getX();
    int y = TerminalHandler::getInstance()->getWindowDimentions()->getY();
    player = new Player(new TextureObject("Assets/player.txt"), new Vector2D(0 , (y/2)-5));
    
    levelDone = new GraphicObject("leveldone", new TextureObject("Assets/level_done.txt"), new Vector2D(45,15));

    Level* firstLevel = new Level("Level1");
    firstLevel->addUnit(new Enemy("enemy1", new TextureObject("Assets/enemy.txt"), new Vector2D(90,10)));
    firstLevel->addUnit(new Enemy("enemy2", new TextureObject("Assets/enemy.txt"), new Vector2D(40,0)));
    

    Level* secondLevel = new Level("Level2");
    secondLevel->addUnit(new Enemy("enemy3", new TextureObject("Assets/enemy.txt"),new Vector2D(55,5)));
    secondLevel->addUnit(new Enemy("enemy4", new TextureObject("Assets/enemy.txt"),new Vector2D(130,25)));
    secondLevel->addUnit(new Enemy("enemy5", new TextureObject("Assets/enemy.txt"),new Vector2D(200,30)));


    Level* thirdLevel = new Level("Level3");
    thirdLevel->addUnit(new Enemy("enemy6", new TextureObject("Assets/enemy.txt"), new Vector2D(60,5)));
    thirdLevel->addUnit(new Enemy("enemy7", new TextureObject("Assets/enemy.txt"), new Vector2D(110,15)));
    thirdLevel->addUnit(new Enemy("enemy8", new TextureObject("Assets/enemy.txt"), new Vector2D(155,0)));
    thirdLevel->addUnit(new Enemy("enemy9", new TextureObject("Assets/enemy.txt"), new Vector2D(180,40)));


    pushLevel(thirdLevel);
    pushLevel(secondLevel); 
    pushLevel(firstLevel); 


}

PlayGameState::~PlayGameState(){
    if(!levels.empty()){
        for(Level* level : levels){
            delete level;
        }
    }
}



void PlayGameState::update(){

    if(isDone() && !(levels.empty())){
        erase();
        levelDone->draw();
        popLevel();
        ++totalScore;
        player->reset();
        refresh();
        napms(1000);
    }
    if(levels.empty()){
        StateMachine::getInstance()->changeState(new WonGameState(
            new GraphicObject("won",
            new TextureObject("Assets/won.txt"),
            new Vector2D(35,10))
        ));
    }
    
    player->update();

    if(!levels.empty()){
        levels.back()->update();
        if(checkCollision()){
            StateMachine::getInstance()->changeState(
                new LostGameState(new GraphicObject(
                    "lost",
                    new TextureObject("Assets/lost.txt"),
                    new Vector2D(25,10)
                ), totalScore
                ));
        }
    }
}

void PlayGameState::draw(){
    mvprintw(0, 0, "Score:%d", totalScore);
    mvprintw(0, (TerminalHandler::getInstance()->getWindowDimentions()->getX()/2)-6
    ,"%s",levels.back()->getLevelID().c_str());

    player->draw();

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
    delete levels.back();
    levels.pop_back();
}


bool PlayGameState::isDone(){
    int x = player->getPosition()->getX();
    int width = player->getTexture()->getWidth();
    if(x+ width >= TerminalHandler::getInstance()->getWindowDimentions()->getX()){
        return true;
    }
    return false;
}


bool PlayGameState::checkCollision(){
    if(!levels.empty()){
        for(Unit* unit : *(levels.back()->getUnits())){
            if(CollisionHandler::getInstance()->checkCollision(player, unit)){
                return true;
            }
        }
    }
    return false;
}
