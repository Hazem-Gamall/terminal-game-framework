#include "GraphicObject.h"
#include "TextureManager.h"

GraphicObject::GraphicObject(std::string id, TextureObject* tex, Vector2D* pos){
    textureID = id;
    position = pos;
    TextureManager::getInstance()->addTexture(textureID, tex);
}

void GraphicObject::draw(){
    TextureManager::getInstance()->drawTexture(textureID, position);
}

void GraphicObject::update(){}