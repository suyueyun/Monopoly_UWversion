#include "resident.h"
#include <sstream>
#include <iomanip>

using namespace std;

Resident::Resident(string name): Building(name,200), btype("Resident"){
}

string Resident::getbtype(){
    return btype;
}

void Resident::paytuition(Player *p) {
    if (p!=owner) {
        int a;
        a=owner->getnumofred();
        if (a==1) {
            owner->earn(25);
            p->pay(25);
        } else if (a==2) {
            owner->earn(50);
            p->pay(50);
        } else if (a==3) {
            owner->earn(100);
            p->pay(100);
        } else {
            owner->earn(200);
            p->pay(200);
        }
    }
}
string Resident::getblock(){
    return "";
}

string* Resident::print(){
    ostringstream os;
    os << left << setw(8) << gname();
    string outname = os.str();
    outname = "|" + outname;
    pstr[0] = outname;
    string player = "";
    for(unsigned int i = 0; i < 8 ;++i){
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
