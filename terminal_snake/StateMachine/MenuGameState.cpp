#include "MenuGameState.h"
#include "../Rendering/TextureManager.h"

MenuGameState::~MenuGameState(){
    if(!textures.empty()){
        for(GraphicObject* texture : textures){
            delete texture;
        }
    }
}

void MenuGameState::update(){}

void MenuGameState::addTexture(GraphicObject* texture){
    textures.push_back(texture);
}

void MenuGameState::draw(){
    if(!textures.empty()){
        for(size_t i = 0; i < textures.size(); i++){
            textures[i]->draw();
        }
    }
}

