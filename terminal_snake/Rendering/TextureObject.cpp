#include "TextureObject.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <ncurses.h>


TextureObject::TextureObject(std::string file_path){
    width = 0;
    height = 0;
    if(textureFromFile(file_path) != "")
        texture = toVectorString(textureFromFile(file_path));
}

std::vector<std::string> TextureObject::toVectorString(std::string texture){
    std::istringstream stream(texture);
    std::string str;
    std::vector<std::string> result;
    while(getline(stream, str, '\n')){
        width = width > str.length()? width:str.length();
        result.push_back(str);
        height++;
    }

    return result;
}


std::string TextureObject::textureFromFile(std::string file_path){
    std::ifstream file(file_path);
    
    if(file){
        std::string result((std::istreambuf_iterator<char>(file)),
        (std::istreambuf_iterator<char>()));

        return result;
        
    }else{
        printf("Error loading file!\n");
        return "";
    }
    return "";
}