#include "Level.h"
// #include "../Audio/AudioHandler.h"
#include <ncurses.h>
#include "../Collision/CollisionHandler.h"

Level::~Level(){
    for(auto unit : units){
        delete unit;
    }
}

Level::Level(std::string id){
    levelID = id;
}

void Level::addUnit(Unit* unit){
    units.push_back(unit);
}

// void Level::addAudio(std::string id, AudioObject* audio){
//     AudioHandler::getInstance()->addAudio(id, audio);
// }

void Level::update(){
    if(!units.empty()){
        for(Unit* unit : units){
            unit->update();
        }
    }
}

void Level::draw(){
    if(!units.empty()){
        for(std::list<Unit*>::iterator it = units.begin(); it != units.end(); ++it){
            (*it)->draw();
        }
    }
}

// void Level::playAudio(std::string audioID){
//     AudioHandler::getInstance()->play(audioID);
// }


std::list<Unit*>::iterator Level::deleteUnit(std::list<Unit*>::iterator it){
    auto res = units.erase(it);
    delete *it;
    return res;
}

