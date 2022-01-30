#include "Block.h"
#include "../Rendering/TextureManager.h"

Block::Block(std::string texture_id, Vector2D* pos){
    textureID = texture_id;
    position = pos;
}

void Block::update(){}

void Block::clean(){}