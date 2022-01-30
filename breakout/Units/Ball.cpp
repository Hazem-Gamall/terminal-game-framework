#include "Ball.h"
#include "../Rendering/TextureManager.h"
#include "../Collision/CollisionHandler.h"

Ball::Ball(std::string texture_id, Vector2D* pos){
    textureID = texture_id;
    position = pos;
    vel_y = vel_x = 0.35;
    velocity = new Vector2D(vel_x, vel_y);
    lost = false;
}

void Ball::update(){
    Vector2D* screen_size = TerminalHandler::getInstance()->getWindowDimentions();
    if(position->getX() >= screen_size->getX()){
        left();
    }
    if(position->getX() <= 0){
        right();
    }
    if(position->getY() >= screen_size->getY()){
        lost = true;
    }
    if(position->getY() <= 0){
        down();
    }

    *position += *velocity; 
}

void Ball::up(){
    velocity->setY(-vel_y);
}

void Ball::down(){
    velocity->setY(vel_y);
}

void Ball::right(){
    velocity->setX(vel_x);
}

void Ball::left(){
    velocity->setX(-vel_x);
}