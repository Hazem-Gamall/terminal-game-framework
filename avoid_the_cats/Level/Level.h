#ifndef LEVEL
#define LEVEL

#include <vector>
#include <string>
#include "../Units/Unit.h"
#include "../Units/Player.h"
#include "../Audio/AudioObject.h"

class Level{
public:
    Level(std::string);
    ~Level();
    void addUnit(Unit*);
    void addAudio(std::string, AudioObject*);
    void draw();
    void update();
    void playAudio(std::string);
    std::string getLevelID() const {return levelID;}
    std::vector<Unit*>* getUnits() {return &units;}

private:
    int score;
    bool deleteUnit(Unit*);
    std::string levelID;
    std::vector<Unit*> units;
};

#endif