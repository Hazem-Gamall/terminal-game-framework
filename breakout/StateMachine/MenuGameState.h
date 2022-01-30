#ifndef MENUGAMESTATE
#define MENUGAMESTATE

#include "GameState.h"
#include "../Rendering/GraphicObject.h"
#include <vector>
#include <string>

class MenuGameState : public GameState{
public: 
    ~MenuGameState();
    void update();
    void draw();
    void addTexture(GraphicObject*);
private:
    std::vector<GraphicObject*> textures;
};

#endif