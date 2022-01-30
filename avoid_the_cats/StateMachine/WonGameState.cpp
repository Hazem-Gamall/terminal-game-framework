#include "WonGameState.h"
#include "../Rendering/TextureManager.h"

WonGameState::WonGameState(GraphicObject* texture){
    stateID = "WON";
    textures.push_back(texture);
}

void WonGameState::addTexture(GraphicObject* texture){
    textures.push_back(texture);
}

void WonGameState::draw(){
    for(GraphicObject* texture : textures){
        texture->draw();
    }
}

void WonGameState::update(){
    for(GraphicObject* texture : textures){
        texture->update();
    }
}