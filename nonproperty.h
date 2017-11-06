#ifndef __NONPROPERTY_H__
#define __NONPROPERTY_H__

#include <string>
#include "square.h"
#include "player.h"


class NonProperty : public Square {
public:
    NonProperty(std::string);    //constructor
    void trade(Player *object);   //trade this nonproperty with another player
    void notifygame();   //notify the game that state changed
    std::string *print();   //print the nonproperty
    std::string gettype();  //get the type of this buliding
    void move(Player *);   //player move to this bulidng and take action.
    void setowner(Player *);   //set the owner of this bulidng
    void setmortage(bool);   //set the state of the mortgage of this building
    void setlevel(int){};   //set the improvement of this building
    bool checkmortage(){return false;}   //check the state of mortgage of this building
    Player* getowner(){return NULL;}   //get the owner of this building
    int getlevel(){return  0;}   //get the improvement of this building
    int getprice() {return 0;}
};

#endif
