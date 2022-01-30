#ifndef WONGAMESTATE
#define WONGAMESTATE

#include "GameState.h"
#include "../Rendering/GraphicObject.h"
#include <vector>
#include <string>

class WonGameState : public GameState{
public:
    WonGameState(GraphicObject*);
    void update();
    void draw();

    void addTexture(GraphicObject*);

private:
    std::vector<GraphicObject*> textures;
};

#endif