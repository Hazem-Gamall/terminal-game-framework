#include "StateMachine.h"

StateMachine* StateMachine::instance = 0;

void StateMachine::pushState(GameState* state){
    gameStates.push_back(state);
}

void StateMachine::changeState(GameState* state){
    if(state->getStateID() == gameStates.back()->getStateID()){
        //nothing happens same state
    }else{
        popState();
        pushState(state);
    }
}

void StateMachine::popState(){
    delete gameStates.back();
    gameStates.pop_back();
}

void StateMachine::update(){
    if(!gameStates.empty()){
        gameStates.back()->update();
    }
}

void StateMachine::draw(){
    if(!gameStates.empty()){
        gameStates.back()->draw();
    }
}

void StateMachine::clean(){
    if(!gameStates.empty()){
        for(GameState* state : gameStates){
            delete state;
        }
    }
}