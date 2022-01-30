#pragma once
#include "Unit.h"

class Dot : public Unit{
public:

    Dot(std::string texture_id, Vector2D* pos);

    void update(){}
    void clean(){}

};