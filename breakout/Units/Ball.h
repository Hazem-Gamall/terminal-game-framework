#ifndef BALL
#define BALL

#include "Unit.h"
#include "../Vector2D.h"

class Ball : public Unit{
public:
    Ball(std::string texture_id, Vector2D* pos);
    Vector2D* getVelocity() const {return velocity;}
    void update();
    void clean(){}
    bool isLost() const {return lost;}
    void up();
    void down();
    void right();
    void left();
private:
    float vel_x, vel_y;
    bool lost;
};


#endif