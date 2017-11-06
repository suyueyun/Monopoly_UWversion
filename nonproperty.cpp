#include "nonproperty.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include "game.h"

using namespace std;
NonProperty::NonProperty(string name) :Square(name, "NonProperty") {}   //constructor

string NonProperty::gettype() {
    return "NonProperty";
}


string* NonProperty::print() {
    if(gname() == "OSAP"){       //print every square that is nonproperty
        pstr[0] = "|COLLECT ";
        pstr[1] = "|OSAP    ";
    }else if(gname()==  "DCTL"){
        pstr[0] = "|DC Tims ";
        pstr[1] = "|Line    ";
    }else if(gname() == "GT"){
        pstr[0] = "|GO TO   ";
        pstr[1] = "|TIMS    ";
    }else if(gname() == "GN"){
        pstr[0] = "|Gosse   ";
        pstr[1] = "|Nesting ";
    }else if(gname() == "TUITION"){
        pstr[0] = "|TUITION ";
        pstr[1] = "|        ";
    }else if(gname() == "COOP"){
        pstr[0] = "|COOP    ";
        pstr[1] = "|FEE     ";
    }else if(gname() == "SLC"){
        pstr[0] = "|SLC     ";
        pstr[1] = "|        ";
    }else if(gname() == "NH"){
        pstr[0] = "|NEEDLES ";
        pstr[1] = "|HALL    ";
    }
    string player = "";
    for(unsigned int i = 0; i < 8 ;++i){
        if(lop[i] != NULL){
            player += lop[i]->getchar();
        }
    }
    player = "|" + player;     //print the player that visit the building
    ostringstream os;
    os << left << setw(9) << player;
    player = os.str();
    pstr[2] = "|        ";
    pstr[3] = player;
    pstr[4] = "|________";
    return pstr;
}

void NonProperty::move(Player * p){
    trade(p);
}
void NonProperty::setowner(Player *p){
    
}

void NonProperty::setmortage(bool b){
    
}

void NonProperty::trade(Player *object) {    //every different square has different action when a player step on it
    if (gname()=="OSAP") {
    } else if (gname()=="DCTL") {
        if (object->getsend()==true) {
            if (object->getcupsnum()==0) {
                object->setstop(true);
            } else {
                cout << "do you want to use a Roll Up the Rim cup?(enter yes or no)" << endl;
                string respon;
                while (1) {
                    cin >> respon;
                    if (respon != "yes" && respon != "no") {
                        cout << " you can only input yes or no, please try again" << endl;
                        cin >> respon;
                    } else {
                        break;
                    }
                }
                if (respon=="yes") {
                    object->addcups(-1);
                    object->setsend(false);
                    object->setstop(false);
                } else {
                    object->setstop(true);
                }
            }
        }
    } else if (gname()=="GT") {
        object->setsend(true);
        object->setstop(true);
        object->setposn(object->getposn()-20);
        popvisitor(object->order); // remove the player from Go to Tims
    } else if (gname()=="GN") {
        return;
    } else if (gname()=="TUITION") {
        cout << "Choose between paying $300 tuition (enter 1) or 10% of your total worth (enter 2)" << endl;
        int choose;
        while(cin >> choose) {
            if (cin.fail()) {
                cout <<"invalid input" << endl;
                continue;
            }
            if (choose==1) {
                object->setcreditor(NULL);
                object->pay(300);
                return;
            } else if (choose==2) {
                object->setcreditor(NULL);
                object->pay(object->getworth() / 10);
                return;
            } else {
                cout << "invalid input" << endl;
                continue;
            }
        }
    } else if (gname()=="coop") {
        object->setcreditor(NULL);
        object->pay(150);
    } else if (gname()=="SLC") {
        int ran;
        int rr;
        srand((unsigned int)time(0));
        rr=(rand() % 100);
        if (rr==1) {
            if (object->totalcups < 4) {
                object->addcups(1);
            }
            return;
        }
        srand((unsigned int)time(0));
        ran=(rand() % 24) +1;
        if (ran<=3 && ran >=1) {
            cout << "moving back 3 units" << endl;
            g->playermove(object->order,-3);
        } else if (ran >=4 && ran <=7) {
            cout << "moving back 2 units" << endl;
            g->playermove(object->order,-2);
        } else if (ran>=8 && ran<=11) {
            cout << "moving back 1 unit" << endl;
            g->playermove(object->order,-1);
        } else if (ran>=12 && ran <=14) {
            cout << "moving forward 1 unit" << endl;
            g->playermove(object->order,1);
        } else if (ran>=15 && ran <=18) {
            cout << "moving forward 2 units" << endl;
            g->playermove(object->order,2);
        } else if (ran >= 19 && ran <=22) {
            cout << "moving forward 3 units" << endl;
            g->playermove(object->order,3);
        } else if (ran == 23) {
            cout << "Moveing to DC Tims Line" << endl;
            g->moveDCTL(object->order);
        } else {
            if (object->getposn()==2) {
                g->playermove(object->order,-2);
            } else if (object->getposn()==17) {
                g->playermove(object->order,-17);
            } else if (object->getposn()==33) {
                g->playermove(object->order,-33);
            }
        }
    } else if (gname()=="NH") {
        int ran;
        int rr;
        srand((unsigned int)time(0));
        rr=(rand() % 100);
        if (rr==1) {
            if (object->totalcups < 4) {
                object->addcups(1);
            }
            return;
        }
        srand((unsigned int) time(0));
        ran=(rand() % 18) +1;
        if (ran==1) {
            object->setcreditor(NULL);
            object->pay(200);
        } else if (ran>1 && ran <=3) {
            object->setcreditor(NULL);
            object->pay(100);
        } else if (ran >=4 && ran <=6) {
            object->setcreditor(NULL);
            object->pay(50);
        } else if (ran >=7 && ran <= 12) {
            object->earn(25);
        } else if (ran >=13 && ran <=15) {
            object->earn(50);
        } else if (ran >=16 && ran <=17) {
            object->earn(100);
        } else if (ran == 18) {
            object->earn(200);
        }
    }
}
