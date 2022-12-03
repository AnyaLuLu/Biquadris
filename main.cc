#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "board.h"
#include "block.h"
#include "level.h"

using namespace std;

/*
enum Op {LEFT, RIGHT, DOWN, CLOCKWISE, COUNTERCLOCKWISE, DROP, LEVEL_UP, LEVEL_DOWN, NO_RANDOM, RANDOM, BLOCK, RESTART, SEQUENCE};

Op convertOp(string opStr) {
    vector<string> commands = {"left", "right", "down", "clockwise", "counterclockwise", "drop", "levelup", "leveldown", "norandom", "random", "block", "restart", "sequence"};

    for (int i = 0; i < commands.size(); ++i) {
        if (opStr.size() <= commands[i].size() && opStr == commands[i].substr(0, opStr.size())) {
            return Op(i);
        }
    }
} // convertOp
*/

int main (int argc, char *argv[]) {

    size_t player1 = 1, player2 = 2;
	size_t startLevel = 0;
    size_t maxLevel = 4;
	size_t board1counter = 1, board2counter = 1;
	size_t hiscore = 0;
	string p1blocks = "sequence1.txt";
	string p2blocks = "sequence2.txt";

    // create boards, displays, etc. here

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

        if ( cin.eof() ) break;

        Op op = convertOp(command);

        switch( op ) {
            /*
            case LEFT: 

                break;
            case RIGHT:

            	break;
            case DOWN: 

                break;
            case CLOCKWISE: 

                break;				
            case COUNTERCLOCKWISE:

                break;
            case DROP: 

                break;
            */
            case LEVEL_UP: 

                break;
            case LEVEL_DOWN: 

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
    } // for
} // main