#include "Player.h"
#include "../Input/InputHandler.h"
#include "../Rendering/TextureManager.h"

Player::Player(TextureObject* tex, Vector2D* pos){
    textureID = "PLAYER";
    position = pos;
    orig_position = *position;
    texture = tex;
    velocity = new Vector2D(0,0);
    TextureManager::getInstance()->addTexture(textureID, texture);
}



void Player::update(){
    velocity->setX(0);
    velocity->setY(0);
    handleInput();
    *position += *velocity;
    
}

void Player::handleInput(){
    Vector2D* window_size = TerminalHandler::getInstance()->getWindowDimentions();
    InputHandler* inputHandler = InputHandler::getInstance();

    if(inputHandler->isKeyDown('d')){

        if((position->getX()+texture->getWidth()) 
        > window_size->getX()){
            return;
        }    
        velocity->setX(1.5);

    }if(inputHandler->isKeyDown('a')){

        if(position->getX() <= 0){
            return;
        }
        velocity->setX(-1.5);

    }if(inputHandler->isKeyDown('w')){

        if(position->getY() <= 0){
            return;
        }
        velocity->setY(-1.5);

    }if(inputHandler->isKeyDown('s')){

        if((position->getY()+texture->getHeight())
        >= window_size->getY()){
            return;
        }
        velocity->setY(1.5);
    }
}

void Player::clean(){
    TextureManager::getInstance()->deleteTexture(textureID);
}


void Player::reset(){
    position->setX(orig_position.getX());
    position->setY(orig_position.getY());
}