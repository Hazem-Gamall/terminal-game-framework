#include "CollisionHandler.h"

CollisionHandler* CollisionHandler::instance = 0;

bool CollisionHandler::checkCollision(Unit* unitA, Unit* unitB){
    TextureObject* unitA_texture = unitA->getTexture();
    TextureObject* unitB_texture = unitB->getTexture();
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = unitA->getPosition()->getX();
    rightA = unitA->getPosition()->getX() + unitA_texture->getWidth();
    topA = unitA->getPosition()->getY();
    bottomA = unitA->getPosition()->getY() + unitA_texture->getHeight();

    leftB = unitB->getPosition()->getX();
    rightB = unitB->getPosition()->getX() + unitB_texture->getWidth();
    topB = unitB->getPosition()->getY();
    bottomB = unitB->getPosition()->getY() + unitB_texture->getHeight();

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