#include "controller.h"
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include "player.h"
#include <vector>

using namespace std;

Controller::Controller() {    //constructor
    game= new Game;
}

bool Controller::checkWin() {    //check if the game is over
    return game->iswin();
}

Controller::~Controller() {   //destructor
    delete game;
}


void Controller::init() {    //initialize the game, let players choose their characters
    cout << "how many players do you have? " << endl;
    int num=0;
    int number;
    while (1) {
        cin >> number;    //read in the number of players
        if (cin.fail()) {   //check invalid input
            cout << "you should enter a number, please try again." << endl;
            cin.clear();
            continue;
        } else if (number > 8) {
            cout << "too many players, please try again." << endl;
            continue;
        } else if (number < 2) {
            cout << "not enough players, please try again." << endl;
        } else {
            game->setnumplayer(number);    //set the number of players
            game->orinumplayer=number;
            break;
        }
    }
    int choosen[8]={0,0,0,0,0,0,0,0};
    cout << "choose your character among Goose(enter G), GRT Bus(enter B), Tim Hortons Doughnut(enter D), Professor(enter P), Student(enter S), Money(enter $), Laptop(enter L), Pink tie(enter T)" << endl;
    while (1) {
        char c;
        string name;
        cin >> c;   //read the character that a player want to pick
        if (cin.fail()) {    //check invalid input
            cout << "Please enter a letter" << endl;
            cout << "choose your character" << endl;
            continue;
        }
        if (c!='G' && c!='B' && c!='D' && c!='P' && c!='S' && c!='$' && c!= 'L' && c!='T') { //check invalid input
            cout << "invalid input" << endl;
            cout << "choose your character" << endl;
            continue;
        }
        if (c=='G') {
            if (choosen[0]==1) {   //check if this character was chosen
                cout << "this character has been choosen, please choose another" << endl;
                continue;
            } else {
                choosen[0]=1;   //set this character is chosen
                cout << "Enter a name" << endl;
                cin >> name;   //connect the player name with the character that just choose
                game->init(num,c,name);
                num++;    //count the number of players that have chosen the characters
                cout << "player"<<num <<" choose a Goose" << endl;
                if (num>=number) {   //all players have chosen their own character
                    cout << "done" << endl;
                    return;
                }
                cout << "let another player to choose a character" << endl;
                continue;
            }
        }
        else if (c=='B') {
            if (choosen[1]==1) {
                cout << "this character has been choosen, please choose another" << endl;
                continue;
            } else {
                choosen[1]=1;
                cout << "Enter a name" << endl;
                cin >> name;
                game->init(num,c,name);
                num++;
                cout << "player"<<num <<" choose a GRT Bus" << endl;
                if (num>=number) {
                    cout << "done" << endl;
                    return;
                }
                cout << "let anot2her player to choose a character" << endl;
                continue;
            }
        }
        else if (c=='D') {
            if (choosen[2]==1) {
                cout << "this character has been choosen, please choose another" << endl;
                continue;
            } else {
                choosen[2]=1;
                cout << "Enter a name" << endl;
                cin >> name;
                game->init(num,c,name);
                num++;
                cout << "player"<<num <<" choose a Tim Hortons Doughnut" << endl;
                if (num>=number) {
                    cout << "done" << endl;
                    return;
                }
                cout << "let another player to choose a character" << endl;
                continue;
            }
        }
        else if (c=='P') {
            if (choosen[3]==1) {
                cout << "this character has been choosen, please choose another" << endl;
                continue;
            } else {
                choosen[3]=1;
                cout << "Enter a name" << endl;
                cin >> name;
                game->init(num,c,name);
                num++;
                cout << "player"<<num <<" choose a Professor" << endl;
                if (num>=number) {
                    cout << "done" << endl;
                    return;
                }
                cout << "let another player to choose a character" << endl;
                continue;
            }
        }
        else if (c=='S') {
            if (choosen[4]==1) {
                cout << "this character has been choosen, please choose another" << endl;
                continue;
            } else {
                choosen[4]=1;
                cout << "Enter a name" << endl;
                cin >> name;
                game->init(num,c,name);
                num++;
                cout << "player"<<num <<" choose a Student" << endl;
                if (num>=number) {
                    cout << "done" << endl;
                    return;
                }
                cout << "let another player to choose a character" << endl;
                continue;
            }
        }
        else if (c=='$') {
            if (choosen[5]==1) {
                cout << "this character has been choosen, please choose another" << endl;
                continue;
            } else {
                choosen[5]=1;
                cout << "Enter a name" << endl;
                cin >> name;
                game->init(num,c,name);
                num++;
                cout << "player"<<num <<" choose a Money" << endl;
                if (num>=number) {
                    cout << "done" << endl;
                    return;
                }
                cout << "let another player to choose a character" << endl;
                continue;
            }
        }
        else if (c=='L') {
            if (choosen[6]==1) {
                cout << "this character has been choosen, please choose another" << endl;
                continue;
            } else {
                choosen[6]=1;
                cout << "Enter a name" << endl;
                cin >> name;
                game->init(num,c,name);
                num++;
                cout << "player"<<num <<" choose a Laptop" << endl;
                if (num>=number) {
                    cout << "done" << endl;
                    return;
                }
                cout << "let another player to choose a character" << endl;
                continue;
            }
        }
        else if (c=='T') {
            if (choosen[7]==1) {
                cout << "this character has been choosen, please choose another" << endl;
                continue;
            } else {
                choosen[7]=1;
                cout << "Enter a name" << endl;
                cin >> name;
                game->init(num,c,name);
                num++;
                cout << "player"<<num <<" choose a Pink Tie" << endl;
                if (num>=number) {
                    cout << "done" << endl;
                    return;
                }
                cout << "let another player to choose a character" << endl;
                continue;
            }
        }
    }
}

void Controller::play(string s, string file) {    //play the game
    if (s=="New Game" || s=="testing") {   //if the game is in normal mode or testing mode
        game->printboard();   //print the borad
        srand((unsigned int)time(NULL));   //set the random
        string cmd;
        bool rolled=false;
        int index=0;
        cout <<" game begin" << endl;
        cout << " please enter a command" << endl;
        while (cin >> cmd) {    //readin the command
            if (cmd == "roll") {      //the command is to roll dies
                if (s=="New Game") {   //if in the normal mode
                if (rolled==true) {    //check that if the player has rolled
                    cout << "you have rolled" << endl;
                    cout << "please enter another command" << endl;
                    continue;
                } else {    //the player has not rolled
                    rolled=true;    //then set the player has rolled
                    int first=(rand() %6 ) +1;  //random get two numbers
                    int second=(rand() % 6) +1;
                    cout << "player"<< index+1 << " roll a "<< first << " and a " << second << endl;
                    int sum=first+second;   //get the dies sum
                    cout << "player" << index+1 << " roll, sum is " << sum << endl;
                    if (game->p[index]->getstop() == true) {    //check if the player is in the DCTL
                        //cout << " hello" << endl;    //delete
                        if (first!=second) {   //if the player does not get the double
                            if (game->p[index]->getcupsnum()>0) {
                                cout << "would you like to use the Tims cups? enter yes or no" << endl;
                                string tims;
                                cin >> tims;
                                if (tims == "yes") {
                                    game->p[index]->addcups(-1);
                                    game->p[index]->totalcups--;
                                    game->p[index]->setround(0);
                                    game->p[index]->setstop(false);
                                    game->p[index]->setsend(false);
                                    game->playermove(index, sum);
                                    if (game->p[index]->isbankrupt()==true) {
                                        cmd="bankrupt";
                                    } else {
                                        if (first==second) {
                                            cout << "enter anything to roll another time because you rolled a double last time" << endl;
                                            string s1;
                                            cin >> s1;
                                            first=(rand() % 6) +1;
                                            second=(rand() % 6) +1;
                                            cout << "player "<< game->p[index]->getchar() << " roll a "<< first << " and a " << second << endl;
                                            sum=first+second;
                                            cout << "player " << game->p[index]->getchar() << " roll, sum is " << sum << endl;
                                            game->playermove(index, sum);
                                            if (game->p[index]->isbankrupt()==true) {
                                                cmd="bankrupt";
                                            } else {
                                                if (first==second) {
                                                    cout << "enter anything to roll another time because you rolled a double last time" << endl;
                                                    string s1;
                                                    cin >> s1;
                                                    first=(rand() % 6) +1;
                                                    second=(rand() % 6) +1;
                                                    cout << "player "<< game->p[index]->getchar() << " roll a "<< first << " and a " << second << endl;
                                                    sum=first+second;
                                                    cout << "player " << game->p[index]->getchar() << " roll, sum is " << sum << endl;
                                                    game->playermove(index, sum);
                                                    if (game->p[index]->isbankrupt()==true) {
                                                        cmd="bankrupt";
                                                    } else {
                                                        if (first==second) {
                                                            game->moveDCTL(index);    //the player go to DCTL
                                                            cout << "player " << game->p[index]->getchar() << " go to DCTL" << endl;
                                                        } else {
                                                            cout << "please enter a command" << endl;
                                                            continue;
                                                        }
                                                    }
                                                } else {
                                                    cout << "please enter a command" << endl;
                                                    continue;
                                                }
                                            }
                                        } else {
                                            cout << "please enter a command" << endl;
                                            continue;
                                        }
                                    }
                                }
                             else {
                            game->p[index]->setround(game->p[index]->getround()+1);  //the round that the player stay in DCTL increase by 1
                            cout << " you cant get out of the DCTL" << endl;
                            cout << "do you want to pay $50? (enter yes or no)" << endl;
                            string res;
                            cin >> res;   //read in that the player want to pay 50 to get out of DCTO or not
                            while (1) {
                                if (res!="yes" && res!="no") {   //check invalid input
                                    cout << " you can only type in yes or no, please try again" << endl;
                                    cin >> res;
                                } else {
                                    break;
                                }
                            }
                            if (res=="yes") {    //player chooses to pay 50 to get out of DCTl
                                game->p[index]->pay(50);    //player pay 50
                                game->p[index]->setstop(false);   //player get out of DCTL
                                game->p[index]->setsend(false);
                                game->playermove(index, sum);   //the player move
                                if (game->p[index]->isbankrupt()==true) {   //if the player bankrupt after the moving
                                    cmd="bankrupt";     //the player bankrupt
                                } else {
                                if (first==second) {   //if the player roll a double
                                    cout << "enter anything to roll another time because you rolled a double last time" << endl;
                                    string s1;
                                    cin >> s1;     //roll again
                                    first=(rand() % 6) +1;
                                    second=(rand() % 6) +1;
                                    cout << "player "<< game->p[index]->getchar() << " roll a "<< first << " and a " << second << endl;
                                    sum=first+second;
                                    cout << "player " << game->p[index]->getchar() << " roll, sum is " << sum << endl;
                                    game->playermove(index, sum);
                                    if (game->p[index]->isbankrupt()==true) {
                                        cmd="bankrupt";
                                    } else {
                                    if (first==second) {    //if the player roll a double again
                                        cout << "enter anything to roll another time because you rolled a double last time" << endl;
                                        string s1;
                                        cin >> s1;
                                        first=(rand() % 6) +1;
                                        second=(rand() % 6) +1;
                                        cout << "player "<< game->p[index]->getchar() << " roll a "<< first << " and a " << second << endl;
                                        sum=first+second;
                                        cout << "player " << game->p[index]->getchar() << " roll, sum is " << sum << endl;
                                        game->playermove(index, sum);
                                        if (game->p[index]->isbankrupt()==true) {
                                            cmd="bankrupt";
                                        } else {
                                        if (first==second) {   //if the player roll a double three times
                                            game->moveDCTL(index);    //the player go to DCTL
                                            cout << "player " << game->p[index]->getchar() << " go to DCTL" << endl;
                                        }
                                        }
                                    }
                                    }
                                }
                                }
                            } else {
                                if (game->p[index]->getround()<3) {   //check if the player stay in DCTL 3 rounds
                                cout << " you can do nothing" << endl;
                                } else {   //if the player stay in DCTL in 3 rounds, he/she has to pay 50 to get out
                                    cout << "you have to pay 50 to get out" << endl;
                                    game->p[index]->pay(50);
                                    game->p[index]->setstop(false);
                                    game->p[index]->setsend(false);
                                    game->p[index]->setround(0);
                                    game->playermove(index, sum);
                                    if (game->p[index]->isbankrupt()==true) {
                                        cmd="bankrupt";
                                    } else {
                                    if (first==second) {
                                        cout << "enter anything to roll another time because you rolled a double last time" << endl;
                                        string s1;
                                        cin >> s1;
                                        first=(rand() % 6) +1;
                                        second=(rand() % 6) +1;
                                        cout << "player "<< game->p[index]->getchar() << " roll a "<< first << " and a " << second << endl;
                                        sum=first+second;
                                        cout << "player " << game->p[index]->getchar() << " roll, sum is " << sum << endl;
                                        game->playermove(index, sum);
                                        if (game->p[index]->isbankrupt()==true) {
                                            cmd="bankrupt";
                                        } else {
                                        if (first==second) {
                                            cout << "enter anything to roll another time because you rolled a double last time" << endl;
                                            string s1;
                                            cin >> s1;
                                            first=(rand() % 6) +1;
                                            second=(rand() % 6) +1;
                                            cout << "player "<< game->p[index]->getchar() << " roll a "<< first << " and a " << second << endl;
                                            sum=first+second;
                                            cout << "player " << game->p[index]->getchar() << " roll, sum is " << sum << endl;
                                            game->playermove(index, sum);
                                            if (game->p[index]->isbankrupt()==true) {
                                                cmd="bankrupt";
                                            } else {
                                            if (first==second) {
                                                game->moveDCTL(index);
                                                cout << "player " << game->p[index]->getchar() << " go to DCTL" << endl;
                                            }
                                            }
                                        }
                                        }
                                    }
                                    }
                               
                                }}
                            }
                            }
                        } else {    //the player roll a double to get out of DCTL
                            game->p[index]->setround(0);
                            game->p[index]->setstop(false);
                            game->p[index]->setsend(false);
                            game->playermove(index, sum);
                            if (game->p[index]->isbankrupt()==true) {
                                cmd="bankrupt";
                            } else {
                            if (first==second) {
                                cout << "enter anything to roll another time because you rolled a double last time" << endl;
                                string s1;
                                cin >> s1;
                                first=(rand() % 6) +1;
                                second=(rand() % 6) +1;
                                cout << "player "<< game->p[index]->getchar() << " roll a "<< first << " and a " << second << endl;
                                sum=first+second;
                                cout << "player " << game->p[index]->getchar() << " roll, sum is " << sum << endl;
                                game->playermove(index, sum);
                                if (game->p[index]->isbankrupt()==true) {
                                    cmd="bankrupt";
                                } else {
                                if (first==second) {
                                    cout << "enter anything to roll another time because you rolled a double last time" << endl;
                                    string s1;
                                    cin >> s1;
                                    first=(rand() % 6) +1;
                                    second=(rand() % 6) +1;
                                    cout << "player "<< game->p[index]->getchar() << " roll a "<< first << " and a " << second << endl;
                                    sum=first+second;
                                    cout << "player " << game->p[index]->getchar() << " roll, sum is " << sum << endl;
                                    game->playermove(index, sum);
                                    if (game->p[index]->isbankrupt()==true) {
                                        cmd="bankrupt";
                                    } else {
                                    if (first==second) {
                                        game->moveDCTL(index);    //the player go to DCTL
                                        cout << "player " << game->p[index]->getchar() << " go to DCTL" << endl;
                                    }
                                    }
                                }
                                }
                            }
                            }
                        }
                    } else {    //the player not in the DCTL
                        game->playermove(index, sum);   //the player move what he/she rolled
                        if (game->p[index]->isbankrupt()==true) {
                            cmd="bankrupt";
                        } else {
                        if (first==second) {
                            cout << "enter anything to roll another time because you rolled a double last time" << endl;
                            string s1;
                            cin >> s1;
                            first=(rand() % 6) +1;
                            second=(rand() % 6) +1;
                            cout << "player "<< game->p[index]->getchar() << " roll a "<< first << " and a " << second << endl;
                            sum=first+second;
                            cout << "player " << game->p[index]->getchar() << " roll, sum is " << sum << endl;
                            game->playermove(index, sum);
                            if (game->p[index]->isbankrupt()==true) {
                                cmd="bankrupt";
                            } else {
                            if (first==second) {
                                cout << "enter anything to roll another time because you rolled a double last time" << endl;
                                string s1;
                                cin >> s1;
                                first=(rand() % 6) +1;
                                second=(rand() % 6) +1;
                                cout << "player "<< game->p[index]->getchar() << " roll a "<< first << " and a " << second << endl;
                                sum=first+second;
                                cout << "player " << game->p[index]->getchar() << " roll, sum is " << sum << endl;
                                game->playermove(index, sum);
                                if (game->p[index]->isbankrupt()==true) {
                                    cmd="bankrupt";
                                } else {
                                if (first==second) {
                                    game->moveDCTL(index);
                                    cout << "player " << game->p[index]->getchar() << " go to DCTL" << endl;
                                }
                                }
                            }
                            }
                        }
                        }
                    }
                    cout << " please enter a command" << endl;
                }
                } else {    //the game is in the testing mode
                    if (rolled==true) {    //if the player has rolled, then he/she cannot roll again
                        cout << "you have rolled" << endl;
                        cout << "please enter another command" << endl;
                        continue;
                    } else {
                        rolled=true;
                        cout << "enter the first die number" << endl;   //set the first die number
                        int first;
                        cin >> first;
                        int second;
                        cout << "enter the second die number" << endl;   //set the second die number
                        cin >> second;
                        cout << "player"<< index+1 << " roll a "<< first << " and a " << second << endl;
                        int sum=first+second;
                        cout << "player" << index+1 << " roll, sum is " << sum << endl;
                        if (game->p[index]->getstop() == true) {
                            if (first!=second) {
                                if (game->p[index]->getcupsnum()>0) {
                                    cout << "would you like to use the Times cups? enter yes or no" << endl;
                                    string tims;
                                    cin >> tims;
                                    if (tims=="yes") {
                                        game->p[index]->addcups(-1);
                                        game->p[index]->totalcups--;
                                        game->p[index]->setstop(false);
                                        game->p[index]->setsend(false);
                                        game->playermove(index, sum);
                                    } else {
                                    
                                game->p[index]->setround(game->p[index]->getround()+1);
                                cout << " you cant get out of the DCTL" << endl;
                                cout << "do you want to pay $50? (enter yes or no)" << endl;
                                string res;
                                cin >> res;
                                while (1) {
                                    if (res!="yes" && res!="no") {
                                        cout << " you can only type in yes or no, please try again" << endl;
                                        cin >> res;
                                    } else {
                                        break;
                                    }
                                }
                                if (res=="yes") {
                                    game->p[index]->pay(50);
                                    game->p[index]->setstop(false);
                                    game->p[index]->setsend(false);
                                    game->playermove(index, sum);
                                    if (game->p[index]->isbankrupt()==true) {
                                        cmd="bankrupt";
                                    } else {
                                    if (first==second) {
                                        cout << "enter anything to roll another time because you rolled a double last time" << endl;
                                        string s1;
                                        cin >> s1;
                                        cout << "enter the first die number" << endl;
                                        int first;
                                        cin >> first;
                                        int second;
                                        cout << "enter the second die number" << endl;
                                        cin >> second;
                                        cout << "player "<< game->p[index]->getchar() << " roll a "<< first << " and a " << second << endl;
                                        sum=first+second;
                                        cout << "player " << game->p[index]->getchar() << " roll, sum is " << sum << endl;
                                        game->playermove(index, sum);
                                        if (game->p[index]->isbankrupt()==true) {
                                            cmd="bankrupt";
                                        } else {
                                        if (first==second) {
                                            cout << "enter anything to roll another time because you rolled a double last time" << endl;
                                            string s1;
                                            cin >> s1;
                                            cout << "enter the first die number" << endl;
                                            int first;
                                            cin >> first;
                                            int second;
                                            cout << "enter the second die number" << endl;
                                            cin >> second;
                                            cout << "player "<< game->p[index]->getchar() << " roll a "<< first << " and a " << second << endl;
                                            sum=first+second;
                                            cout << "player " << game->p[index]->getchar() << " roll, sum is " << sum << endl;
                                            game->playermove(index, sum);
                                            if (game->p[index]->isbankrupt()==true) {
                                                cmd="bankrupt";
                                            } else {
                                            if (first==second) {
                                                game->moveDCTL(index);
                                                cout << "player " << game->p[index]->getchar() << " go to DCTL" << endl;
                                            }
                                            }
                                        }
                                        }
                                    }
                                    }
                                } else {
                                    if (game->p[index]->getround()<3) {
                                        cout << " you can do nothing" << endl;
                                    } else {
                                        cout << "you have to pay 50 to get out" << endl;
                                        game->p[index]->pay(50);
                                        game->p[index]->setstop(false);
                                        game->p[index]->setsend(false);
                                        game->p[index]->setround(0);
                                        game->playermove(index, sum);
                                        if (game->p[index]->isbankrupt()==true) {
                                            cmd="bankrupt";
                                        } else {
                                        if (first==second) {
                                            cout << "enter anything to roll another time because you rolled a double last time" << endl;
                                            string s1;
                                            cin >> s1;
                                            cout << "enter the first die number" << endl;
                                            int first;
                                            cin >> first;
                                            int second;
                                            cout << "enter the second die number" << endl;
                                            cin >> second;
                                            cout << "player "<< game->p[index]->getchar() << " roll a "<< first << " and a " << second << endl;
                                            sum=first+second;
                                            cout << "player " << game->p[index]->getchar() << " roll, sum is " << sum << endl;
                                            game->playermove(index, sum);
                                            if (game->p[index]->isbankrupt()==true) {
                                                cmd="bankrupt";
                                            } else {
                                            if (first==second) {
                                                cout << "enter anything to roll another time because you rolled a double last time" << endl;
                                                string s1;
                                                cin >> s1;
                                                cout << "enter the first die number" << endl;
                                                int first;
                                                cin >> first;
                                                int second;
                                                cout << "enter the second die number" << endl;
                                                cin >> second;
                                                cout << "player "<< game->p[index]->getchar() << " roll a "<< first << " and a " << second << endl;
                                                sum=first+second;
                                                cout << "player " << game->p[index]->getchar() << " roll, sum is " << sum << endl;
                                                game->playermove(index, sum);
                                                if (game->p[index]->isbankrupt()==true) {
                                                    cmd="bankrupt";
                                                } else {
                                                if (first==second) {
                                                    game->moveDCTL(index);
                                                    cout << "player " << game->p[index]->getchar() << " go to DCTL" << endl;
                                                }
                                                }
                                            }
                                            }
                                        }
                                        }
                                    }
                                }
                                    }
                            }
                        }else {
                                game->p[index]->setround(0);
                                game->p[index]->setstop(false);
                                game->p[index]->setsend(false);
                                game->playermove(index, sum);
                                if (game->p[index]->isbankrupt()==true) {
                                    cmd="bankrupt";
                                } else {
                                if (first==second) {
                                    cout << "enter anything to roll another time because you rolled a double last time" << endl;
                                    string s1;
                                    cin >> s1;
                                    cout << "enter the first die number" << endl;
                                    int first;
                                    cin >> first;
                                    int second;
                                    cout << "enter the second die number" << endl;
                                    cin >> second;
                                    cout << "player "<< game->p[index]->getchar() << " roll a "<< first << " and a " << second << endl;
                                    sum=first+second;
                                    cout << "player " << game->p[index]->getchar() << " roll, sum is " << sum << endl;
                                    game->playermove(index, sum);
                                    if (game->p[index]->isbankrupt()==true) {
                                        cmd="bankrupt";
                                    } else {
                                    if (first==second) {
                                        cout << "enter anything to roll another time because you rolled a double last time" << endl;
                                        string s1;
                                        cin >> s1;
                                        cout << "enter the first die number" << endl;
                                        int first;
                                        cin >> first;
                                        int second;
                                        cout << "enter the second die number" << endl;
                                        cin >> second;
                                        cout << "player "<< game->p[index]->getchar() << " roll a "<< first << " and a " << second << endl;
                                        sum=first+second;
                                        cout << "player " << game->p[index]->getchar() << " roll, sum is " << sum << endl;
                                        game->playermove(index, sum);
                                        if (game->p[index]->isbankrupt()==true) {
                                            cmd="bankrupt";
                                        } else {
                                        if (first==second) {
                                            game->moveDCTL(index);
                                            cout << "player " << game->p[index]->getchar() << " go to DCTL" << endl;
                                        }
                                        }
                                    }
                                    }
                                }
                                }
                            }
                        } else {
                            game->playermove(index, sum);
                            if (game->p[index]->isbankrupt()==true) {
                                cmd="bankrupt";
                            } else {
                            if (first==second) {
                                cout << "enter anything to roll another time because you rolled a double last time" << endl;
                                string s1;
                                cin >> s1;
                                cout << "enter the first die number" << endl;
                                int first;
                                cin >> first;
                                int second;
                                cout << "enter the second die number" << endl;
                                cin >> second;
                                cout << "player "<< game->p[index]->getchar() << " roll a "<< first << " and a " << second << endl;
                                sum=first+second;
                                cout << "player " << game->p[index]->getchar() << " roll, sum is " << sum << endl;
                                game->playermove(index, sum);
                                if (game->p[index]->isbankrupt()==true) {
                                    cmd="bankrupt";
                                } else {
                                if (first==second) {
                                    cout << "enter anything to roll another time because you rolled a double last time" << endl;
                                    string s1;
                                    cin >> s1;
                                    cout << "enter the first die number" << endl;
                                    int first;
                                    cin >> first;
                                    int second;
                                    cout << "enter the second die number" << endl;
                                    cin >> second;
                                    cout << "player "<< game->p[index]->getchar() << " roll a "<< first << " and a " << second << endl;
                                    sum=first+second;
                                    cout << "player " << game->p[index]->getchar() << " roll, sum is " << sum << endl;
                                    game->playermove(index, sum);
                                    if (game->p[index]->isbankrupt()==true) {
                                        cmd="bankrupt";
                                    } else {
                                    if (first==second) {
                                        game->moveDCTL(index);
                                        cout << "player " << game->p[index]->getchar() << " go to DCTL" << endl;
                                    }
                                    }
                                }
                                }
                            }
                            }
                        }
                        cout << " please enter a command" << endl;
                    }
                }
        }
            else if (cmd=="exit") {
                return;
            }
            else if (cmd=="next") {    //if the command is next
                if (rolled==false) {  //if a player has not rolled, then he/she has to roll
                    cout << " you need to roll first" << endl;
                    continue;
                } else {   // the player has rolled
                    rolled=false;   //the next player has not rolled, so set it up
                    if (index!=(game->orinumplayer-1)) {   //if this is not the last player in the list, then add 1 to index to get the next player
                        index++;
                    } else {  //if this is the last player in the list, then the next round is the first player in the list
                        index=0;
                    }
                    if(game->p[index] == NULL){   //if the next player in the list is out
                        cout << "player " << index+1 << " is out" << endl;
                        index++;
                    }
                    cout << "now is player " << game->p[index]->getchar() << " round" << endl;
                    cout << "please enter a command" << endl;
                }
            }
            else if (cmd=="assets") {   //if the command is assets
                game->assets(index);
                cout << " please enter a command" << endl;
            }
            else if (cmd=="trade") {   //if the command is trade
                string name;
                string give;
                string receive;
                cout << "please enter a name you want to trade with" << endl;
                cin >> name;   //read in the object that the player want to trade with
                cout << "please enter what you want to give" << endl;
                cin >> give;   //read in the thing that the player want to give to
                cout << "please enter what you want to receive" << endl;
                cin >> receive;   //read in the thing that the player want to receive
                game->trade(index, name, give, receive);   //make the trade
                cout << " please enter a command" << endl;
            }
            else if (cmd =="improve") {   //if the command is improve
                string property;
                string buyorsell;
                cout << "enter your property name" << endl;
                cin >> property;   //read in the name of the property that player want to improve
                cout << "you want to buy(enter buy) or sell(enter sell)" << endl;
                cin >> buyorsell;   //read in the player want to buy or sell
                game->improve(index, property, buyorsell);
                cout << " please enter a command" << endl;
            } else if (cmd=="mortgage") {   // if the command is mortgage
                string property;
                cout << "please enter the property name you want to mortgage" << endl;
                cin >> property;
                game->mortgage(index, property);
                cout << " please enter a command" << endl;
            } else if (cmd=="unmortgage") {  //if the command is unmortgage
                string property;
                cout << "please enter the property name you want to unmortgage" << endl;
                cin >> property;
                game->unmortgage(index, property);
                cout << " please enter a command" << endl;
            } if (cmd=="bankrupt") {   //if the command is bankrupt
                game->bankrupt(index);
                if (game->p[index] ==NULL) {
                    rolled=false;
                    if (index!=(game->getnumplayer() -1)) {
                        index++;
                    } else {
                        index=0;
                    }
                    game->setnumplayer(game->getnumplayer()-1);
                    if (game->iswin()) {    //check if the game is over so far
                        for (int i=0; i<game->getnumplayer(); i++) {
                            if(game->p[i] != NULL){
                                cout << "Winner is " << game->p[i]->getname() << endl;
                                cout << "Game Over" << endl;
                                return;
                            }
                        }
                    }
                    cout << "now is player: " << game->p[index]->getchar() << " round" << endl;
                    cout << " please enter a command" << endl;
                } else {
                    cout << " please enter a command" << endl;
                }
            } if (cmd=="save") {   // if the command is save the game
                ostream *file = &cout;
                string filename;
                cout << "please enter the file name you want to save to" << endl;
                cin >>filename;   //read in the file name of the out put file
                file = new ofstream(filename.c_str());
                *file << game->getnumplayer() << endl;
                for(int i = 0; i < game->getnumplayer(); ++i){
                    Player * p = game->p[i];
                    *file << p->getname() << " " << p->getchar() << " " << p->getcupsnum() << " " << p->getmoney() << " " << p->getposn();
                    if(p->getposn() == 10){
                        if(p->getstop() == false){
                            *file << " 0";
                        }else{
                            *file << " 1";
                            *file << " " << p->getround();
                        }
                    }
                    *file << endl;
                }
                for(int i = 0; i < numofsquares; ++i){
                    if(game->sq[i]->gettype() == "Building"){
                        *file << game->sq[i]->gname();
                        if(game->sq[i]->getowner() == NULL){
                            *file << " BANK ";
                        }else{
                            *file << " "<< game->sq[i]->getowner()->getname() << " ";
                        }
                        if(game->sq[i]->checkmortage()){
                            *file << "-1" << endl;
                        }else{
                            *file << game->sq[i]->getlevel() << endl;
                        }
                    }
                }
                if ( file != &cout ) delete file;
                cout << " please enter a command" << endl;
            }
        }
    }
    else if (s=="-load") {   //the game is in the load mode
        istream *infile = &cin;
        infile = new ifstream(file.c_str());
        string numplayer;
        getline(*infile, numplayer);
        istringstream ss(numplayer);
        int num;
        ss>>num;
        game->setnumplayer(num);   //set the number of player
        game->orinumplayer=num;
        for (int i=0; i<num; i++) {   //set all the player information
            string inputplayer;
            getline(*infile, inputplayer);
            istringstream sp(inputplayer);
            string name;
            int jail=-1;
            int round=-1;
            sp>>name;
            char symbol;
            sp>>symbol;
            int numroll;
            sp>>numroll;
            int money;
            sp>>money;
            int position;
            sp>>position;
            if (position == 10) {
                sp >>jail;
                if (jail==1) {
                    sp >> round;
                }
            }
            game->init(i, symbol, name);
            game->sq[0]->popvisitor(i);
            game->sq[position]->pushvisitor(game->p[i], i);
            game->p[i]->setmoney(money);
            game->p[i]->setworth(money-1500);
            game->p[i]->setposn(position);
            game->p[i]->addcups(numroll);
            if (jail==1) {
                game->p[i]->setsend(true);
                game->p[i]->setstop(true);
                game->p[i]->setround(round);
            } else {
                game->p[i]->setsend(false);
                game->p[i]->setstop(false);
            }
        }
        for (int i=0; i<28; i++) {   //set all the square information
            string inputbuliding;
            string name;
            string owner;
            int improvement;
            getline(*infile, inputbuliding);
            istringstream sb(inputbuliding);
            sb>>name;
            sb>>owner;
            sb>>improvement;
            for (int j=0; j<40; j++) {
                Player * p = NULL;
                if (game->sq[j]->gname()==name) {
                    if (owner=="BANK") {
                        
                    } else {
                        for(int i =0; i< game->getnumplayer();++i){
                            if(game->p[i]->getname() == owner){
                                p = game->p[i];
                                break;
                            }
                        }
                        game->sq[j]->setowner(p);
                        p->setworth(game->sq[j]->getprice());
                    
                    if (improvement==-1) {
                        game->sq[j]->setmortage(true);
                    } else {
                        game->sq[j]->setlevel(improvement);
                        if (name=="AL" || name=="ML" || name=="ECH" || name=="PAS" || name=="HH" ) {
                            p->setworth(50 * improvement);
                        } else if (name=="RCH" || name== "DWE" || name== "CPH" || name== "LHI" || name=="BMH" || name=="OPT" ) {
                            p->setworth(100 * improvement);
                        } else if (name=="EV1" || name=="EV2" || name=="EV3" || name=="PHYS" || name=="B1" || name== "B2") {
                            p->setworth(150 * improvement);
                        } else {
                            p->setworth(200 * improvement);
                        }
                    }
                    }
                }
            }
        }
        if ( infile != &cin ) delete infile;
    }
    play("New Game", "");
}
