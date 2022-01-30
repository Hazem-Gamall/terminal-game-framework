#ifndef TEXTUREMANAGER
#define TEXTUREMANAGER
#include <map>
#include "TextureObject.h"
#include <string>
#include "TerminalHandler.h"

class TextureManager{
public:
    static TextureManager* getInstance(){
        if(instance == 0){
            instance = new TextureManager();
        }
        return instance;
    }
    void addTexture(std::string id, TextureObject* texture);
    void editTexutre(std::string id, TextureObject* texture);
    void deleteTexture(std::string id);

    void drawTexture(std::string id, Vector2D* position);
    TextureObject* getTexture(std::string id);

private:
    TextureManager(){}
    std::map<std::string, TextureObject*> textures;
    static TextureManager* instance;
};

#endif