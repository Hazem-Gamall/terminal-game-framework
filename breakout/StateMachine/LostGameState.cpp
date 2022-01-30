#include "LostGameState.h"
#include <ncurses.h>
#include "../Input/InputHandler.h"
#include "../Game.h"
#include "StateMachine.h"

LostGameState::LostGameState(GraphicObject* texture, int score){
    textures.push_back(texture);
    this->score = score;
}

LostGameState::~LostGameState(){
    for(GraphicObject* texture : textures){
        delete texture;
    }
}

void LostGameState::draw(){
    if(!textures.empty()){
        for(GraphicObject* texture : textures){
            texture->draw();
        }
    }
    mvprintw(20,60, "your score is:%d", score);
}

void LostGameState::update(){
    if(!textures.empty()){
        for(GraphicObject* texture : textures){
            texture->update();
        }
    }

}


void LostGameState::addTexture(GraphicObject* texture){
    textures.push_back(texture);
}