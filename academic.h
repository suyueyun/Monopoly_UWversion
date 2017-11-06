#ifndef __ACADEMIC_H__
#define __ACADEMIC_H__

#include <iostream>
#include <stdio.h>
#include "building.h"


class Player;

const int toplevel = 6;

class Academic : public Building {
    int level;
    int impcost;
    std::string btype;
    std::string block;
    int tuition[toplevel]; // record the tutuion for 6 diferent level
public:
    std::string getblock();
    int getlevel();
    Academic(std::string name,std::string block,int price,int impcost,int,int,int,int,int,int);
    void improve(int); // upgrade the level
    void paytuition(Player *); 
    void notifygame();
    std::string* print();
    std::string getbtype();
    void setlevel(int);
};

#endif
