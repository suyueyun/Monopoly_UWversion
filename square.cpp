#include "square.h"
#include "game.h"
using namespace std;

Square::Square(string name,string type): name(name),type(type){
    pstr = new string[5];
    lop = new Player*[8];
    for(int i = 0; i < 8; ++i){
        lop[i] = NULL;
    }
}

string Square::gettype(){
    return type;
}

string Square::gname(){
    return name;
}

void Square::pushvisitor(Player * p,int index){
    lop[index] =p;
}

void Square::popvisitor(int index){
    lop[index] = NULL;
}

void Square::setgame(Game *game) {
    g=game;
}

void Square::notifygame(){
    g->printboard();
}

Square::~Square(){
    delete [] pstr;
    delete[] lop;
}

