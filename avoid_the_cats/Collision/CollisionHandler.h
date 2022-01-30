#ifndef COLLISIONHANDLER
#define COLLISIONHANDLER

#include "../Units/Unit.h"

class CollisionHandler{
public:
    static CollisionHandler* getInstance(){
        if(instance == 0){
            instance = new CollisionHandler();
        }
        return instance;
    }

    bool checkCollision(Unit*, Unit*);


private:
    CollisionHandler(){}
    static CollisionHandler* instance;
};

#endif