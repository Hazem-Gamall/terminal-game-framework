#ifndef LEVEL
#define LEVEL

#include <list>
#include <string>
#include "../Units/Unit.h"
// #include "../Audio/AudioObject.h"

class Level{
public:
    Level(std::string);
    ~Level();
    void addUnit(Unit*);
    // void addAudio(std::string, AudioObject*);
    void draw();
    void update();
    // void playAudio(std::string);
    std::string getLevelID() const {return levelID;}
    std::list<Unit*>::iterator deleteUnit(std::list<Unit*>::iterator it);
    std::list<Unit*>* getUnits() {return &units;}
private:
    std::string levelID;
    std::list<Unit*> units;
};

#endif