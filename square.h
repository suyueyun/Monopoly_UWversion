#ifndef __SQUARE_H__
#define __SQUARE_H__

#include <string>
#include <vector>

class Game;
class Player;

const int numofline = 5;

class Square{
protected:
    std::string *pstr;
    std::string name;
    std::string type;
    Game *g;
    Player **lop; // records players landing on the square
public:
    Square(std::string,std::string);
    virtual int getprice() = 0;
    virtual bool checkmortage() = 0;
    virtual Player* getowner() = 0;
    virtual void setowner(Player *) = 0;
    virtual void setmortage(bool) = 0;
    virtual void setlevel(int) = 0;
    virtual int getlevel() = 0;
    ~Square();
    void setgame (Game *);
    void pushvisitor(Player *,int); // store the address of value of player who land on the square
    void popvisitor(int); // removee the address of value of player when it leave the square
    void notifygame(); // call game's print board
    virtual std::string* print() = 0; // return arrary of string store the printing data of each square
    virtual void move(Player *) =0; // call the corresponding methods when player lan on different squares
    std::string gettype(); // return the square types(Building or Nonproperty)
    std::string gname(); // return the name of square
};


#endif
