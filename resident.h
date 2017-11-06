#ifndef __RESIDENT_H__
#define __RESIDENT_H__

#include "building.h"

class Resident :public Building {
    std::string btype;
public:
    std::string getbtype(); // return the Building type(Academic
    Resident(std::string);
    void paytuition(Player *p); // acutally pay the rent, inherited from Building class
    std::string getblock();
    void notifygame() {}
    std::string* print();
    void improve(int i) {}
    int getlevel() {return 0;}
    void setlevel(int){};
};

#endif
