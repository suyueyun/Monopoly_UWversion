#include "building.h"
#include <iostream>
#include "game.h"

using namespace std;

Building::Building(string name,int price): Square(name,"Building"),price(price), ismortaged(false),owner(NULL){
}

void Building::setowner(Player* p){
    p->own.push_back(this);
    owner = p;
}


int Building::getprice(){
    return price;
}
void Building::setprice(int money){
    price = money;
}

void Building::setmortage(bool mortage){
    ismortaged = mortage;
}
bool Building::checkmortage(){
    return ismortaged;
}

Player * Building::getowner(){
    return owner;
}

void Building::move(Player *p){
    notifygame();
    if(owner == NULL){
        if(p->getmoney() - price < 0){
            cout << "You don't have enought money to purchase" << endl;
            auction(p);
        }else{
            cout << "Would you like to buy the building? enter y for yes, otherwise no" << endl;
            char i;
            cin >> i;
            if(i == 'y'){
                p->buy(this);
                owner = p;
                cout<< "Now the Building " << gname() << " is belong to " << p->getname() << endl;
            }else  {
                auction(p);
            }
        }
    }else{
        if(p != owner){
            if (this->checkmortage()) {
                cout << "this property is mortgaged" << endl;
                return;
            }
            p->setcreditor(owner);
            paytuition(p);
        }
    }
}

void Building::auction(Player *p) {
    cout << "it is auction time" << endl;
    int heighest=0;
    int index=0;
    int quit[8]={0,0,0,0,0,0,0,0};
    int i=0;
    int numquit=1;
    quit[p->order]=1;
    while (1) {
        if (quit[i]==1) {
            i++;
            continue;
        }
        cout << "Player " << g->p[i]->getname() << ", do you want to raise(enter raise) or withdraw(enter withdraw)?" << endl;
        string respon;
        cin >> respon;
        while (1) {
            if (respon != "raise" && respon != "withdraw" ) {
                cout << "invalud input, please try again" << endl;
                cin >> respon;
            } else {
                break;
            }
        }
        if (respon == "raise" ){
            cout << "how much do you want to bit" << endl;
            int bit=0;
            cin >> bit;
            while (1) {
                if (cin.fail()) {
                    cout << " you should input a integer" << endl;
                    cin.clear();
                    cin >>bit;
                } else if (bit <= heighest) {
                    cout << " you should bit higher than " << heighest << endl;
                    cin >> bit;
                } else {
                    break;
                }
            }
            cout << "player " << g->p[i]->getname() << " bit "<< bit << endl;
            heighest = bit;
            index=i;
        } else {
            cout << "player " << g->p[i]->getname() <<" withdraw" << endl;
            quit[i]=1;
            numquit++;
        }
        if (numquit==g->getnumplayer()) {
            cout << "no one buy this buliding" << endl;
            return;
        }
        if (numquit==g->getnumplayer()-1) {
            if (quit[i+1]==1) {
                break;
            } else if (i==g->getnumplayer()-1) {
                break;
            } else if (i==index) {
                break;
            }
        }
        if (i==g->getnumplayer()-1) {
            i=0;
            continue;
        } else {
            i++;
            continue;
        }
    }
    g->p[i]->pay(heighest);
    setowner(g->p[i]);
    if(g->p[i]->own.size()!=0){
        if(g->p[i]->checkblock(this->getblock())){
            g->p[i]->ownblocks.push_back(this->getblock());
        }
    }
}
