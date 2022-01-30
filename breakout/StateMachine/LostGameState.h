#pragma once

#include "GameState.h"
#include <string>
#include <vector>
#include "../Rendering/GraphicObject.h"

class LostGameState : public GameState{
public:
    LostGameState(GraphicObject* texture, int score);
    ~LostGameState();
    void update();
    void draw();
    void onExit();
    void addTexture(GraphicObject* texture);
private:
    int score;
    std::vector<GraphicObject*> textures;
};