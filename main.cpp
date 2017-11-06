#include <iostream>
#include "game.h"
#include "controller.h"
#include <cstring>

using namespace std;

int main(int argc, const char * argv[]) {
    if (argc==1) {    //normal mode
        Controller c;
        c.init();
        c.play("New Game", "");
    } else {
        if (strcmp(argv[1],"-load") == 0) {   //load mode
        Controller c;
        std::string file;
        cout << "enter the file name you want to load" << endl;
        cin >> file;
        c.play(argv[1], file);
        } else {    //testing mode
            Controller c;
            c.init();
            c.play("testing", "");
        }
    }
}
