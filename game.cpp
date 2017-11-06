#include "game.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
using namespace std;


Game::Game(){
    numplayer = 0;
    orinumplayer=0;
    p = new Player*[maxplayer];
    for(int i = 0; i < maxplayer; ++i){
        p[i] = NULL;
    }
    sq = new Square*[numofsquares];
    sq[0] = new NonProperty("OSAP");
    sq[1] = new Academic("AL","Arts1",40,50,2,10,30,90,160,250);
    sq[2] = new NonProperty("SLC");
    sq[3] = new Academic("ML","Arts1",60,50,4,20,60,180,320,450);
    sq[4] = new NonProperty("TUITION");
    sq[5] = new Resident("MKV");
    sq[6] = new Academic("ECH","Arts2",100,50,6,30,90,270,400,550);
    sq[7] = new NonProperty("NH");
    sq[8] = new Academic("PAS","Arts2",100,50,6,30,90,270,400,550);
    sq[9] = new Academic("HH","Arts2",120,50,8,40,100,300,450,600);
    sq[10] = new NonProperty("DCTL");
    sq[11] = new Academic("RCH","Eng",140,100,10,50,150,450,625,750);
    sq[12] = new Gym("PAC");
    sq[13] = new Academic("DEW","Eng",140,100,10,50,150,450,625,750);
    sq[14] = new Academic("CPH","Eng",160,100,12,60,180,500,700,900);
    sq[15] = new Resident("UWP");
    sq[16] = new Academic("LHI","Health",180,100,14,70,200,550,750,950);
    sq[17] = new NonProperty("SLC");
    sq[18] = new Academic("BMH","Health",180,100,14,70,200,550,750,950);
    sq[19] = new Academic("OPT","Health",200,100,16,80,220,600,800,1000);
    sq[20] = new NonProperty("GN");
    sq[21] = new Academic("EV1","Env",220,150,18,90,250,700,875,1050);
    sq[22] = new NonProperty("NH");
    sq[23] = new Academic("EV2","Env",220,150,18,90,250,700,875,1050);
    sq[24] = new Academic("EV3","Env",240,150,20,100,300,750,925,1100);
    sq[25] = new Resident("V1");
    sq[26] = new Academic("PHYS","Sci1",260,150,22,110,330,800,975,1150);
    sq[27] = new Academic("B1","Sci1",260,150,22,110,330,800,975,1150);
    sq[28] = new Gym("CIF");
    sq[29] = new Academic("B2","Sci1",280,150,24,120,360,850,1025,1200);
    sq[30] = new NonProperty("GT");
    sq[31] = new Academic("EIT","Sci2",300,200,26,130,390,900,1100,1275);
    sq[32] = new Academic("ESC","Sci2",300,200,26,130,390,900,1100,1275);
    sq[33] = new NonProperty("SLC");
    sq[34] = new Academic("C2","Sci2",320,200,28,150,450,1000,1200,1400);
    sq[35] = new Resident("REV");
    sq[36] = new NonProperty("NH");
    sq[37] = new Academic("MC","Math",350,200,35,175,500,1100,1300,1500);
    sq[38] = new NonProperty("COOP");
    sq[39] = new Academic("DC","Math",400,200,50,200,600,1400,1700,2000);
    for(int i = 0; i < numofsquares; ++i){
        sq[i]->setgame(this);
    }
}

int Game::getnumplayer() {
    return numplayer;
}

void Game::setnumplayer(int n){
    numplayer = n;
}

Game::~Game(){
    for(int i = 0; i < maxplayer; ++i){
        delete p[i];
    }
    delete p;
    for(int j = 0; j < numofsquares; ++j){
        delete sq[j];
    }
    delete sq;
}

void Game::assets(int index){
    cout << p[index]->getname() << " has $ " << p[index]->getmoney()<< " and owns";
    for (unsigned int i=0; i< p[index]->own.size(); i++) {
        cout << " " << p[index]->own[i]->gname();
    }
    cout << ", and total worth is " << p[index]->getworth() << endl;
}

bool Game::iswin(){
    if(numplayer ==1 ){
        return true;
    }else{
        return false;
    }
}

void Game::init(int order,char cter,string name){
    p[order] = new Player(order,cter,name);
    p[order]->setg(this);
    sq[0]->pushvisitor(p[order],order);
}


void Game::playermove(int index,int step){
    sq[p[index]->getposn()]->popvisitor(index);
    int position = p[index]->getposn() + step;
    if(position >= 40){
        cout << "collect OSAP" << endl;
        p[index]->earn(200);
        position -= 40;
    }
    if(position < 0){
        position += 40;
    }
    p[index]->setposn(position);
    sq[position]->pushvisitor(p[index], index);
    printboard();
    sq[position]->move(p[index]);
}

void Game::moveDCTL(int index){
    sq[p[index]->getposn()]->popvisitor(index);
    p[index]->setround(0);
    p[index]->setsend(true);
    int dctl = 10;
    sq[dctl]->move(p[index]);
    sq[dctl]->pushvisitor(p[index], index);
    printboard();
}

void Game::trade(int index,string name,string give,string receive){
    cout << name << ": " << "accept(y) or reject(n)" << endl;
    Player * trader = NULL;
    for(int i = 0; i < numplayer; ++i){
        if(p[i]->getname() == name){
            trader = p[i];
        }
    }
    if (trader==NULL) {
        cout << "invalid name" << endl;
        return;
    }
    char input;
    if(cin >> input){
        if(input == 'y'){
            istringstream isg(give);
            istringstream isr(receive);
            int money;
            if(isg >> money){
                if(p[index]->getmoney() - money < 0){
                    cout << p[index]->getname() << " doesn't have enough money to pay!" << endl;
                    return;
                }
                Building * exchange =NULL;
                int in = 0;
                for(int i = 0; i < trader->own.size(); ++i){
                    if(trader->own[i]->gname() == receive){
                        in = i;
                        exchange = trader->own[i];
                    }
                }
                if(exchange == NULL){
                    cout << "Property does not exist" << endl;
                    return;
                }
                if (exchange->checkmortage()) {
                    cout << "this property is mortgaged" << endl;
                    return;
                }
                for(int i = 0; i<trader->own.size() ; i++) {
                    if (trader->own[i]->getblock()==exchange->getblock()) {
                        if (exchange->getlevel()!=0) {
                            cout << " this building has been improved" << endl;
                            return;
                        }
                    }
                }
                p[index]->pay(money);
                trader->own.erase(trader->own.begin() + in); // pop the building that is sold from player
                trader->setworth(- exchange->getprice());
                trader->earn(money);
                exchange->setowner(p[index]);
                p[index]->setworth(exchange->getprice());
            }else if(isr >> money){
                if(trader->getmoney() - money < 0){
                    cout << trader->getname() << " doesn't have enough money to pay!" << endl;
                    return;
                }
                Building * exchange =NULL;
                int in = 0;
                for(int i = 0; i < p[index]->own.size(); ++i){
                    if(p[index]->own[i]->gname() == give){
                        exchange = p[index]->own[i];
                        in = i;
                    }
                }
                if(exchange == NULL){
                    cout << "Property does not exist" << endl;
                    return;
                }
                if (exchange->checkmortage()) {
                    cout << "this property is mortgaged" << endl;
                    return;
                }
                for(int i = 0; i<p[index]->own.size() ; i++) {
                    if (p[index]->own[i]->getblock()==exchange->getblock()) {
                        if (exchange->getlevel()!=0) {
                            cout << " this building has been improved" << endl;
                            return;
                        }
                    }
                }
                p[index]->own.erase(p[index]->own.begin() + in);// pop the building that is sold from player
                p[index]->setworth(-exchange->getprice());
                p[index]->earn(money);
                trader->pay(money);
                exchange->setowner(trader);
                trader->setworth(exchange->getprice());
            }else{
                int inp = 0;
                int ind = 0;
                Building * exchangep=NULL;
                Building * exchanged=NULL;
                for(int i = 0; i < p[index]->own.size(); ++i){
                    if(p[index]->own[i]->gname() == give){
                        exchangep = p[index]->own[i];
                        inp = i;
                    }
                }
                for(int i = 0; i < trader->own.size(); ++i){
                    if(trader->own[i]->gname() == receive){
                        
                        exchanged = trader->own[i];
                        ind = i;
                    }
                }
                for(int i = 0; i<trader->own.size() ; i++) {
                    if (trader->own[i]->getblock()==exchanged->getblock()) {
                        if (exchanged->getlevel()!=0) {
                            cout << " this building has been improved" << endl;
                            return;
                        }
                    }
                }
                for(int i = 0; i<p[index]->own.size() ; i++) {
                    if (p[index]->own[i]->getblock()==exchangep->getblock()) {
                        if (exchangep->getlevel()!=0) {
                            cout << " this building has been improved" << endl;
                            return;
                        }
                    }
                }
                if(exchanged == NULL){
                    cout << "Property does not exist" << endl;
                    return;
                }
                if (exchanged->checkmortage()) {
                    cout << "this property is mortgaged" << endl;
                    return;
                }
                if(exchangep == NULL){
                    cout << "Property does not exist" << endl;
                    return;
                }
                if (exchangep->checkmortage()) {
                    cout << "this property is mortgaged" << endl;
                    return;
                }
                p[index]->own.erase(p[index]->own.begin() + inp);
                p[index]->setworth(-exchangep->getprice());
                trader->own.erase(trader->own.begin() + ind);
                trader->setworth(- exchanged->getprice());
                exchangep->setowner(trader);
                trader->setworth(exchangep->getprice());
                exchanged->setowner(p[index]);
                p[index]->setworth(exchanged->getprice());
            }
        }
    }
}

void Game::improve(int index, string property, std::string buyorsell) {
    Player * me = p[index];
    Building * exchange = NULL;
    for(int i = 0; i < me->own.size(); ++i){
        if(me->own[i]->gname() == property){
            exchange = me->own[i];
        }
    }
    int check=0;
    for (int i=0; i<p[index]->ownblocks.size(); i++) {
        if (exchange->getblock()==p[index]->ownblocks[i]) {
            check=1;
        }
    }
    if (check==0) {
        cout << "you can not improve this building" << endl;
        return;
    }
    if(exchange == NULL){
        cout << "Property does not exist" << endl;
        return;
    }
    if(buyorsell == "buy"){
        if (exchange->getlevel()!=5) {
            exchange->improve(1);
        } else {
            cout << "you have already upgrade the highest level" << endl;
            return;
        }
    } else {
        if (exchange->getlevel()!=0) {
            exchange->improve(-1);
        } else {
            cout << "you dont have any improvement there" << endl;
            return;
        }
    }
    printboard(); // print the board to show improvement
}

void Game::mortgage(int index, std::string property) {
    Player * me = p[index];
    Building * exchange = NULL;
    for(int i = 0; i < me->own.size(); ++i) {
        if(me->own[i]->gname() == property){
            exchange = me->own[i];
        }
    }
    if(exchange == NULL){
        cout << "Property does not exist" << endl;
        return;
    }
    if (exchange->getlevel()!=0) {
        cout << "Property still have improvement, cannot be mortgaged" << endl;
        return;
    }
    exchange->setmortage(true);
    me->earn(exchange->getprice() /2);
}

void Game::unmortgage(int index, std::string property) {
    Player * me = p[index];
    Building * exchange = NULL;
    for(int i = 0; i < me->own.size(); ++i) {
        if(me->own[i]->gname() == property){
            exchange = me->own[i];
        }
    }
    if(exchange == NULL){
        cout << "Property does not exist" << endl;
        return;
    }
    exchange->setmortage(false);
    me->pay(((exchange->getprice() /2 ) /10) *11);
}


void Game::printboard(){
    cout<<"____________________________________________________________________________________________________" << endl;
    for(int i = 0; i < 5; ++i){
        for(int j = 20; j <= 30; ++j){
            cout << (sq[j]->print())[i];
        }
        cout << "|" << endl;
    }
    for(int i = 1; i <= 8; ++i){
        for(int j = 0; j < 5; ++j){ // print the middle
            if(i == 4 && j == 3){
                cout<< left << setw(90) << (sq[20-i]->print())[j] + "|" + "                   _________________________________________";
                cout<< (sq[30+i]->print())[j];
                cout<< "|" << endl;
            }else if(i == 4 && j == 4){
                cout<< left << setw(90) << (sq[20-i]->print())[j] + "|" + "                   |                                       |";
                cout<< (sq[30+i]->print())[j];
                cout<< "|" << endl;
            }else if(i == 6 && j == 0){
                cout<< left << setw(90) << (sq[20-i]->print())[j] + "|" + "                   |_______________________________________|";
                cout<< (sq[30+i]->print())[j];
                cout<< "|" << endl;
            }else if(i == 6 && j == 1){
                cout<< left << setw(90) << (sq[20-i]->print())[j] + "|" + "                   -----------Created by YS and DO----------";
                cout<< (sq[30+i]->print())[j];
                cout<< "|" << endl;
            }else if(i == 5 && j == 0){
                cout<< left << setw(90) << (sq[20-i]->print())[j] + "|" + "                   |  ###   ###   #####  ###   ###   ###   |";
                cout<< (sq[30+i]->print())[j];
                cout<< "|" << endl;
            }else if(i == 5 && j == 1){
                cout<< left << setw(90) << (sq[20-i]->print())[j] + "|" + "                   |  #  #  #  #     #  #   # #   # #   #  |";
                cout<< (sq[30+i]->print())[j];
                cout<< "|" << endl;
            }else if(i == 5 && j == 2){
                cout<< left << setw(90) << (sq[20-i]->print())[j] + "|" + "                   |  ####  ####    #   #   # #   # #   #  |";
                cout<< (sq[30+i]->print())[j];
                cout<< "|" << endl;
            }else if(i == 5 && j == 3){
                cout<< left << setw(90) << (sq[20-i]->print())[j] + "|" + "                   |  #  #  #  #   #    #   # #   # #   #  |";
                cout<< (sq[30+i]->print())[j];
                cout<< "|" << endl;
            }else if(i == 5 && j == 4){
                cout<< left << setw(90) << (sq[20-i]->print())[j] + "|" + "                   |  ###   ###   #      ###   ###   ###   |";
                cout<< (sq[30+i]->print())[j];
                cout<< "|" << endl;
            }else{
                cout<< left << setw(90) << (sq[20-i]->print())[j] + "|";
                cout<< (sq[30+i]->print())[j];
                cout<< "|" << endl;
            }
        }
        
    }
    for(int j = 0 ; j < 5; ++j){
        if(j == 4){
            cout << (sq[20-9]->print())[j] + "|" << "________________________________________________________________________________" << (sq[20-9]->print())[j] + "|" << endl;
        }else{
            cout<< left << setw(90) << (sq[20-9]->print())[j] + "|";
            cout<< (sq[30+9]->print())[j];
            cout<< "|" << endl;
        }
    }
    for(int i = 0; i < 5; ++i){ // print the last 10 quares on the board
        for(int j = 10; j >= 0; --j){
            cout << (sq[j]->print())[i];
        }
        cout << "|" << endl;
    }
}

void Game::bankrupt(int index) {
    if (p[index]->isbankrupt()) {
        cout << "Player " << p[index]->getname() << " declare bankrupt"<< endl;
        transferproperty(index);
        sq[p[index]->getposn()]->popvisitor(index);
        p[index]->totalcups=p[index]->totalcups-p[index]->getcupsnum();
        p[index]->addcups(-1 * p[index]->getcupsnum());
        delete p[index];
        p[index] = NULL;
    }else {
        cout << "you still have money to pay" << endl;
    }
}

void Game::transferproperty(int index){
    if(p[index]->getcreditor() == NULL){ // if the credictor does not exist, start aution
        cout << "start auction" << endl;
        for(int i = 0; i < p[index]->own.size();++i){
            p[index]->own[i]->auction(p[index]);
        }
    }else{ // if the credictor exist, transfer buildings
        cout << "All properties of " << p[index]->getname() << " is belong to " << p[index]->getcreditor()->getname() << endl;
        for(int i = 0; i < p[index]->own.size();++i){
            p[index]->own[i]->setowner(p[index]->getcreditor());
        }
    }
}
