#ifndef UNIT
#define UNIT

#include "../Rendering/TextureObject.h"
#include "../Rendering/TextureManager.h"

class Unit{
public:
    virtual ~Unit(){
        delete texture;
        delete position;
        delete velocity;
    }
    virtual TextureObject* getTexture(){return texture;};

    virtual void update() =0;

    virtual void draw(){
        TextureManager::getInstance()->drawTexture(textureID, position);
    }

    virtual void clean() = 0;

    virtual Vector2D* getPosition() const{
        return position;
    }

protected:
    TextureObject* texture;
    std::string textureID;
    Vector2D* position;
    Vector2D* velocity;

    
};

#endif