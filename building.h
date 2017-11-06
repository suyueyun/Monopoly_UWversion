#ifndef __BUILDING_H__
#define __BUILDING_H__

#include <stdio.h>
#include "square.h"
#include "player.h"
#include <string>

class Player;

class Building : public Square {
protected:
    Player *owner;
    bool ismortaged;
    int price;
public:
    Player* getowner();
    void setowner(Player *);
    void setvisitor(Player *);
    Building(std::string name,int price);
    int getprice();
    void setprice(int);
    void setmortage(bool); // set the state of whether the building is mortgaged
    bool checkmortage(); // return the state of whether the building is mortgaged
    void move(Player *); // call the pay mothod if player is trying to purchase this property and call the aution if player does not want to buy
    void auction(Player *);
    virtual std::string getbtype() = 0;
    virtual void paytuition(Player *p) = 0;
    virtual std::string getblock() =0;
    virtual void notifygame() = 0;
    virtual std::string* print() = 0;
    virtual void improve(int) = 0;
    virtual int getlevel() =0;
    virtual void setlevel(int) = 0;
};

#endif
