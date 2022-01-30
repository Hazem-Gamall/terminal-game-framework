#ifndef ENEMY
#define ENEMY

#include "Unit.h"
#include "../Rendering/TextureObject.h"
#include "../Vector2D.h"

class Enemy : public Unit{
public:
    Enemy(std::string id, TextureObject* texture, Vector2D* position);
    // ~Enemy();
    void update();
    void clean();
};

#endif