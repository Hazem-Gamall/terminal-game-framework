#include "Level.h"
#include "../Audio/AudioHandler.h"
#include <ncurses.h>

Level::Level(std::string id){
    levelID = id;
    score = 0;
}

Level::~Level(){
    for(Unit* unit : units){
        delete unit;
    }
}

void Level::addUnit(Unit* unit){
    units.push_back(unit);
}

void Level::addAudio(std::string id, AudioObject* audio){
    AudioHandler::getInstance()->addAudio(id, audio);
}

void Level::update(){
    if(!units.empty()){
        for(size_t i = 0; i < units.size(); i++){
            if(deleteUnit(units[i])){
                delete units[i];
                units.erase(units.begin() + i);
                continue;
            }
            units[i]->update();
        }
    }
}

void Level::draw(){
    if(!units.empty()){
        for(Unit* unit : units){
            unit->draw();
        }
    }
}

void Level::playAudio(std::string audioID){
    AudioHandler::getInstance()->play(audioID);
}


bool Level::deleteUnit(Unit* unit){
    Vector2D* unit_position = unit->getPosition();
    if((unit_position->getX()) < 0){
        return true;
    }
    return false;
}

