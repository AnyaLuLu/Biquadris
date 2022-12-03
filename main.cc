#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "board.h"
#include "block.h"
#include "level.h"

using namespace std;

enum Op {LEFT, RIGHT, DOWN, CLOCKWISE, COUNTERCLOCKWISE, DROP, LEVEL_UP, LEVEL_DOWN, NO_RANDOM, RANDOM, BLOCK, RESTART, SEQUENCE};

Op convertOp(string opStr) {
    vector<string> commands = {"left", "right", "down", "clockwise", "counterclockwise", "drop", "levelup", "leveldown", "norandom", "random", "block", "restart", "sequence"};

    for (int i = 0; i < commands.size(); ++i) {
        if (opStr.size() <= commands[i].size() && opStr == commands[i].substr(0, opStr.size())) {
            return Op(i);
        }
    }
} // convertOp

int getNum(string command) {
    stringstream ss;
    ss << command;
    int retNum;

    if (!(ss >> retNum)) {
        return 1;
    } else {
        return retNum;
    }
}

string removeNum(string command) {
    stringstream ss;
    ss << command;

    int tempNum;
    ss >> tempNum;
    string retString;
    ss >> retString;
    return retString;
    
}

int main (int argc, char *argv[]) {

    int player1 = 1, player2 = 2;
	int startLevel = 0;
    int maxLevel = 4;
	int board1counter = 1, board2counter = 1;
	int hiscore = 0;
	string p1blocks = "sequence1.txt";
	string p2blocks = "sequence2.txt";
    int turnCount = 0;
    int curPlayer = 1;

    // create boards, displays, etc. here
    Board *Board1;
    Board *Board2;
    Board *curBoard;

    bool graphicsOn = true;

    for (int i = 1; i < argc; i++) {
        string command = argv[i];
        if (command == "-text") {
		    graphicsOn = false;

        } else {
			if (command != "-seed" && command != "-scriptfile1" && command != "-scriptfile2" && command != "-startlevel") {
				cerr << "Invalid Argument: " << command << endl;
				return 1;
			}

            string extra = argv[i+1];
            i += 1;

            if (command == "-seed") {
                try {
                    srand(stoi(extra));
                } catch (...) {
                    cerr << "Invalid seed: " << extra << endl;
                }

            } else if (command == "-scriptfile1") {
                ifstream testfile(extra);

                if (!testfile.good()) {
                    cerr << "Invalid file: " << extra << endl;
                    return 1;
                }

                p1blocks = extra;

            } else if (command == "-scriptfile2") {
                ifstream testfile(extra);

                if (!testfile.good()) {
                    cerr << "Invalid file: " << extra << endl;
                    return 1;
                }

                p2blocks = extra;

            } else if (command == "-startlevel") {
                try {
                    startLevel = stoi(extra);
                } catch (...) {
                    cerr << "Invalid level (not an integer): " << extra << endl;
                    return 1;
                }

                if (!(0 <= startLevel && startLevel <= maxLevel)) {
                    cerr << "Invalid level (out of bounds): " << extra << endl;
                    return 1;
                }
            } 
        }
    }

    while (true) {
        cerr << "Command: ";
        string command;
        cin >> command;

        int num = getNum(command);
        command = removeNum(command);

        if ( cin.eof() ) break;

        curPlayer = (turnCount % 2) + 1;
        if (curPlayer == 1) {
            curBoard = Board1;
        } else {
            curBoard = Board2;
        }

        Op op = convertOp(command);

        switch( op ) {
            case LEFT: 
                curBoard->left();
                break;
            case RIGHT:
                curBoard->right();
            	break;
            case DOWN: 
                curBoard->down();
                break;
            case CLOCKWISE: 
                curBoard->cw();
                break;				
            case COUNTERCLOCKWISE:
                curBoard->ccw();
                break;
            case DROP: 
                curBoard->drop();
                break;
            case LEVEL_UP: 
                curBoard->levelup();
                break;
            case LEVEL_DOWN: 
                curBoard->leveldown();
                break;
            case NO_RANDOM:
                
                break;
            case RANDOM:

                break;
            case BLOCK:

                break;
            case SEQUENCE:

                break;
            case RESTART:

                break;
            default: 
                cerr << "Invalid command." << endl;
                break;
        } // switch

        curBoard->addBlock();

        turnCount += 1;
    } // infinite while
} // main

