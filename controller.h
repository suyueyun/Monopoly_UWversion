#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <iostream>
#include "game.h"

class Controller {
    bool checkWin();   //if the game win or not
public:
    void init();   //initialize the game
    Game *game;   // a game pointer
    Controller();  //the constructor
    ~Controller();  //the destructor
    void play(std::string, std::string);    //to play the game
};

#endif

