#ifndef BLOCK
#define BLOCK

#include "Unit.h"
#include "../Rendering/TextureObject.h"
#include <string>

class Block : public Unit{
public:
    Block(std::string texture_id, Vector2D* position);
    void update();
    void clean();
};

#endif