#include "academic.h"
#include <sstream>
#include <iomanip>

using namespace::std;

int level0 = 0;
int level1 = 1;
int level2 = 2;
int level3 = 3;
int level4 = 4;
int level5 = 5;

Academic::Academic(string name,string block,int price,int impcost,int
                   tuition0,int tuition1,int tuition2,int
                   tuition3,int tuition4,int tuition5):Building(name,price),block(block),impcost(impcost),level(0),btype("Academic"){
    tuition[level0] = tuition0;
    tuition[level1] = tuition1;
    tuition[level2] = tuition2;
    tuition[level3] = tuition3;
    tuition[level4] = tuition4;
    tuition[level5] = tuition5;
}


void Academic::notifygame(){
    
}

string Academic::getbtype() {return "";}

void Academic::improve(int in){
    level += in;
    if(in == 1){
        owner->pay(impcost);
    }else{
        owner->earn(impcost/2);
    }
}

string Academic::getblock(){
    return block;
}

int Academic::getlevel() {
    return level;
}

void Academic::paytuition(Player *visitor){
    int charge = tuition[level];
    visitor->pay(charge);
    if(visitor->getmoney() - charge >= 0){
        owner->earn(charge);
        cout << visitor->getname() << " pay tuition " << "$"
        << charge << " to " << visitor->getname() << endl;
    }

}

string* Academic::print(){
    ostringstream os;
    string l = "|";
    if(level == 0){
        l += "";
    }else if(level == 1) {
        l += "I";
    }else if(level == 2){
        l += "II";
    }else if(level == 3){
        l += "III";
    }else if(level == 4){
        l += "IIII";
    }else if(level == 5){
        l += "IIIII";
    }
    os << left << setw(9) << l;
    string out = os.str();
    pstr[0] = out;
    pstr[1] = "|--------";
    string outname =  "|" + gname();
    unsigned long len = outname.length();
    for(unsigned long i = len; i < 9; ++i){
        outname += " ";
    }
    pstr[2] = outname;
    string player = "";
    for(unsigned int i = 0; i < 8 ;++i){
        if(lop[i] != NULL){ // get the chararcter of owner
            player += lop[i]->getchar();
        }
    }
    player = "|" + player;
    ostringstream osp;
    osp << left << setw(9) << player;
    player = osp.str();
    pstr[3] = player;
    pstr[4] = "|________";
    return pstr;
}
void Academic::setlevel(int l){
    level = l;
}

