#ifndef TEXTUREOBJECT
#define TEXTUREOBJECT
#include "../Vector2D.h"
#include <vector>
#include <string>

class TextureObject{
public:
    TextureObject(std::string file_path);
    std::vector<std::string> getTexture() const {return texture;}
    int getWidth() const {return width;}
    int getHeight() const {return height;}
private:
    int width, height;
    std::string textureFromFile(std::string);
    std::vector<std::string> toVectorString(std::string texture);
    std::vector<std::string> texture;
};
#endif