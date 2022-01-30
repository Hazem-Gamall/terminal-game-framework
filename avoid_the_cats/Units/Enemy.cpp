#include "Enemy.h"
#include "../Rendering/TextureManager.h"

Enemy::Enemy(std::string id, TextureObject* tex, Vector2D* pos){
    textureID = id;
    texture = tex;
    position = pos;
    velocity = new Vector2D(-0.15, 0.2);
    TextureManager::getInstance()->addTexture(textureID, texture);
}


void Enemy::update(){
    if(position->getY() < 0)
        velocity->setY(0.2);
    if(position->getY() >= 35)
        velocity->setY(-0.2);
    *position += *velocity;
    // clear();
}

void Enemy::clean(){
    TextureManager::getInstance()->deleteTexture(textureID);
}