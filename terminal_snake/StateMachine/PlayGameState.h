#include "GameState.h"
#include "../Level/Level.h"
#include "../Rendering/TextureObject.h"
#include "../Units/Snake.h"

class PlayGameState : public GameState{
public:
    PlayGameState();
    ~PlayGameState();
    void update();
    void draw();

    int getTotalScore() const {return totalScore;}
    
private:
    void checkCollision();
    int totalScore;
    Snake *snake;
    Level *level;
};
