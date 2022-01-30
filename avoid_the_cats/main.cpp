#include "Game.h"
#include <chrono>
#include <thread>
#include <ncurses.h>

void init_ncurses(){
    initscr();
    keypad(stdscr, true);
    cbreak();
    noecho();
    curs_set(0);
    nodelay(stdscr, true);
}

int main(){
    init_ncurses();
    Game *game = Game::getInstance();
    game->init();

    while(game->isRunning()){
        auto start = std::chrono::high_resolution_clock::now();

        game->update();
        game->draw();

         auto stop = std::chrono::high_resolution_clock::now();
        
        std::chrono::duration<double,std::milli> duration = stop-start;
        double sleep = 16.7 - duration.count();
        napms(sleep);
    }

    delete game;
    return 0;
}