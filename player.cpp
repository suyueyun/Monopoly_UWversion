#include "player.h"
#include "building.h"
#include <iostream>
#include "game.h"

using namespace std;

const int startmoney = 1500;
const int startposn = 0;

int Player::totalcups = 0; // static field initialization

Player::Player(int o,char ctr,string name):order(o),cter(ctr),name(name),money(startmoney),posn(startposn),numofred(0),numofgym(0),cupsnum(0),bankrupt(false),own(NULL),issend(false),totalworth(startmoney), stop(false){
    creditor = NULL;
}

void Player::setg(Game *game){
    g = game;
}

bool Player::isbankrupt() {
    return bankrupt;
}


char Player::getchar(){
    return cter;
}


int Player::getcupsnum() {
    return cupsnum;
}

int Player::getnumofred() {
    return numofred;
}

void Player::setnumofred(int i) {
    numofred=i;
}

void Player::addcups(int num){
    totalcups += num;
    cupsnum += num;
}

void Player::setstop(bool b) {
    stop=b;
}

bool Player::getstop() {
    return stop;
}

string Player::getname(){
    return name;
}

int Player::getmoney(){
    return money;
}

int Player::getworth(){
    return totalworth;
}

void Player::setworth(int amount){
    totalworth += amount;
}

void Player::setposn(int posn){
    if(posn > 39){
        posn = posn - 40;
        cout << "You have collect OSAP" << endl;
        earn(200);
    }
    this->posn = posn;
}

int Player::getposn(){
    return posn;
}

void Player::pay(int amount){
    int check = money - amount;
        if(check < 0){ // check if the player do not have enough money to pay
            cout << "Not enought money to pay" << endl;
            cout << "would you like to sell, mortgage, or trade your property, otherwise declear bankrupt? "<< endl;
            string input;
            while(cin >> input){ // let player choose command to increase their cash in order to avoid bankrupt
                if(input == "mortgage"){
                    cout << "You choose mortgage, please enter the property you want to mortgage" << endl;
                    string building;
                    cin >> building;
                    g->mortgage(order,building);
                    break;
                }else if(input == "sell"){
                    cout << "You choose sell improvement, please enter the property you want to mortgage" << endl;
                    string building;
                    cin >> building;
                    g->improve(order,building,"sell");
                    break;
                }else if(input == "bankrupt"){
                    bankrupt = true;
                    cout << "enter bankrupt to declear in your turn" << endl;
                    return;
                }else if(input == "trade"){
                    cout << "Enter the name of player you want to trade" << endl;
                    string name;
                    cin >> name;
                    cout << "Enter the property you want to give" << endl;
                    string give;
                    cout << "Enter the money you want to recieve" << endl;
                    string recieve;
                    cin >> recieve;
                    g->trade(order, name, give, recieve);
                }else{
                    cout << "Invalid command, enter sell, mortgage , trade or declear bankrupt " << endl;
                
                }
            }
            pay(amount);
        }else{
            totalworth -= amount;
            money -= amount;
            cout << getname() << " pays " << amount << endl;
        }
    
}
void Player::buy(Building* b){
    totalworth += b->getprice();
    pay(b->getprice());
    b->setowner(this);
    if(b->getbtype() == "Resident"){
        numofred++;
    } else if (b->gettype() == "Gym") {
        numofgym++;
    }
    if(own.size()!=0){
        //if(checkblock(b->getblock())){
        //    ownblocks.push_back(b->getblock());
        //}
        addblock(b->getblock());
    }
}

void Player::earn(int amount){
    totalworth += amount;
    money += amount;
    cout << getname() << " earns " << amount << endl;
}

void Player::addblock(string block){
    int count = 0;
    for(unsigned int i = 0; i < own.size();++i){
        if (block == own[i]->getblock()) {
            count++;
        }
    }
    if (count == 1){
        if(block == "Arts1" or block == "Math"){
            ownblocks.push_back(block);
        }
    }else if(count == 2){
        ownblocks.push_back(block);
    }
}

bool Player::getsend(){
    return issend;
}

void Player::setsend(bool send){
    issend=send;
}

void Player::setcreditor(Player *p){
    creditor = p;
}

Player * Player::getcreditor(){
    return creditor;
}

bool Player::checkblock(string block){
    for(unsigned int i = 0; i < ownblocks.size();++i){
        if (block == ownblocks[i]) {
            return true;
        }
    }
    return false;
}

int Player::getround(){
    return round;
}

void Player::setround(int i){
    round = i;
}

void Player::setmoney(int m){
    money = m;
}
