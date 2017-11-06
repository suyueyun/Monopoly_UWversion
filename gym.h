#ifndef __GYM_H__
#define __GYM_H__


#include "building.h"

class Gym :public Building {
    std::string btype;
public:
    std::string getbtype();
    Gym(std::string);
    void paytuition(Player *); // autually pay the fee according to the sum of dice player rolls
    std::string getblock();
    void notifygame() {}
    std::string* print();
    void improve(int i) {}
    int getlevel() {return 0;}
    void setlevel(int){};
};

#endif
