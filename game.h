#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include "player.h"
#include "square.h"
#include "academic.h"
#include "nonproperty.h"
#include "resident.h"
#include "gym.h"

class Controller;
class Square;

const int maxplayer = 8;
const int numofsquares = 40;


class Game {
    int numplayer;
    void clearGame();
public:
    Player ** p;
    Square ** sq;
    int orinumplayer;
    Game();
    ~Game();
    void setnumplayer(int); // initialize the number of players
    void trade(int, std::string, std::string, std::string);
    void improve(int, std::string, std::string);
    void mortgage(int, std::string);
    void unmortgage(int, std::string);
    void moveDCTL(int); // get executed when player is sent do DC Tims Line
    void bankrupt(int);
    int getnumplayer();
    void assets(int); // print the property of a player
    bool iswin();
    void init(int,char,std::string);
    void playermove(int index,int move);
    void printboard();
    void transferproperty(int);// transfer all building of a player to its credictor when a player declare bankrupt
};

#endif
