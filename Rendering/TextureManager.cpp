#include "TextureManager.h"
#include "TerminalHandler.h"
#include <iostream>

TextureManager* TextureManager::instance = 0;

void TextureManager::addTexture(std::string id, TextureObject* texture){
    auto it = textures.find(id);
    if(it == textures.end()){
        textures[id] = texture;
    }
}

void TextureManager::editTexutre(std::string id, TextureObject* texture){
    textures[id] = texture;
}

void TextureManager::deleteTexture(std::string id){
    textures.erase(id);
}

void TextureManager::drawTexture(std::string id, Vector2D* position){
    auto it = textures.find(id);
    if(it != textures.end()){//found
        TerminalHandler::getInstance()->drawToTerminal(textures[id], position);
    }
}