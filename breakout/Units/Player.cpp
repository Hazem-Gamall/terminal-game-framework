#include "Player.h"
#include "../Input/InputHandler.h"
#include "../Rendering/TextureManager.h"

Player::Player(std::string texture_id, Vector2D* pos){
    textureID = texture_id;
    position = pos;
    orig_position = *position;
    velocity = new Vector2D(0,0);
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
    TextureObject* texture = getTexture();
    if(inputHandler->isKeyDown('d') || InputHandler::getInstance()->isKeyDown(KEY_RIGHT)){

        if((position->getX()+texture->getWidth()) 
        > window_size->getX()){
            return;
        }    
        velocity->setX(2.2);

    }if(inputHandler->isKeyDown('a')|| InputHandler::getInstance()->isKeyDown(KEY_LEFT)){

        if(position->getX() <= 0){
            return;
        }
        velocity->setX(-2.2);

    }
}

void Player::clean(){
    TextureManager::getInstance()->deleteTexture(textureID);
}


bool Player::checkCollision(Unit* unit){
    TextureObject* texture = getTexture();

    TextureObject* unit_texture = unit->getTexture();
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = position->getX();
    rightA = position->getX() + texture->getWidth();
    topA = position->getY();
    bottomA = position->getY() + texture->getHeight();

    leftB = unit->getPosition()->getX();
    rightB = unit->getPosition()->getX() + unit_texture->getWidth();
    topB = unit->getPosition()->getY();
    bottomB = unit->getPosition()->getY() + unit_texture->getHeight();

    if(leftA >= rightB){
        // erase();
        // printw("leftA:%d and rightB:%d\n", leftA, rightB);
        return false;}
    if(rightA <= leftB){
        // printw("rightA:%d and leftB:%d\n", rightA, leftB);
        return false;}
    if(bottomA <= topB){
        // printw("bottomA:%d and topB:%d\n", bottomA, topB);
        return false;}
    if(topA >= bottomB){
        // printw("topA:%d and bottomB:%d\n", topA, bottomB);
        return false;}

    return true;
}

void Player::reset(){
    position->setX(orig_position.getX());
    position->setY(orig_position.getY());
}