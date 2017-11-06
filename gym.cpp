#include "gym.h"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

Gym::Gym(string name): Building(name,150),btype("Gym"){
}

string Gym::getbtype(){
    return btype;
}

string* Gym::print(){
    ostringstream os;
    os << left << setw(8) << gname();
    string outname = os.str();
    outname = "|" + outname;
    pstr[0] = outname;
    string player = "";
    for(int i = 0; i < 8 ;++i){ // get character of the Players on the square
        if(lop[i] != NULL){
            player += lop[i]->getchar();
        }
    }
    player = "|" + player;
    ostringstream osp;
    osp << left << setw(9) << player;
    player = osp.str();
    pstr[1] = "|        ";
    pstr[2] = "|        ";
    pstr[3] = player;
    pstr[4] = "|________";
    return pstr;
}

void Gym::paytuition(Player *p) {
    int a;
    int b;
    int check=0;
    srand((unsigned int)time(0));
    a= (rand() % 6) +1;
    b= (rand() % 6) +1;
    cout << "you roll two dice, one is " << a << " , one is " << b << endl;
    if (gname()=="PAC") {
        for (unsigned int i=0; i< owner->own.size(); i++) {
            if (owner->own[i]->gname()=="CIF") {
                check=1;
            }
        }
        if (check==1) {
            p->pay(10 * (a + b));
            owner->earn(10 * (a + b));
        } else {
            p->pay(4 * (a + b));
            owner->earn(4 * (a + b));
        }
    } else {
        for (unsigned int i=0; i< owner->own.size(); i++) {
            if (owner->own[i]->gname()=="PAC") {
                check=1;
            }
        }
        if (check==1) {
            p->pay(10 * (a + b));
            owner->earn(10 * (a + b));
        } else {
            p->pay(4 * (a + b));
            owner->earn(4 * (a + b));
        }
    }
}
string Gym::getblock(){
    return "";
}

