#ifndef __A5__player__
#define __A5__player__

#include <stdio.h>
#include <stdio.h>
#include <vector>
#include <string>
#include "building.h"

class Building;
class Game;

class Player {
    Game * g;
    const char cter;
    const std::string name;
    int money;
    int posn;
    int numofred;
    int cupsnum;
    int numofgym;
    bool bankrupt;
    bool issend;
    bool stop;
    int totalworth;
    Player * creditor;
    int round;
public:
    static int totalcups; // trace the total number of cups
    std::vector<std::string> ownblocks;
    std::vector<Building*> own;
    const int order; // the order of initilizing the player
    void setstop(bool); // set the state of stop
    bool getstop(); // return the state of stop
    Player(int,char,std::string);
    char getchar(); // return the character of player
    void addblock(std::string); // adding block if the player has all the buildings in the block
    int getnumofred();
    bool isbankrupt(); // return if the player is bankcrupt
    void setnumofred(int);
    int getcupsnum();
    void setworth(int);
    int getworth();
    bool getsend();
    void setsend(bool); // set the state of if the player is sent to DC Tims Line
    std::string getname(); // return the string of name
    int getmoney();
    void setposn(int);
    int getposn();
    void pay(int);
    void buy(Building*);
    void earn(int);
    void addcups(int);
    bool checkblock(std::string);
    void setcreditor(Player *); 
    Player * getcreditor();
    void setg(Game *);
    int getround();
    void setround(int);
    void setmoney(int);
};

#endif
