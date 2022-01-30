#ifndef GRAPHICOBJECT
#define GRAPHICOBJECT

#include "TextureObject.h"
#include "../Vector2D.h"
#include <string>

class GraphicObject{
public:
    GraphicObject(std::string id, TextureObject* texture, Vector2D* position);
    void draw();
    void update();
private:
    std::string textureID;
    Vector2D* position;
};

#endif