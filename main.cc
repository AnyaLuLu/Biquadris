#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "board.h"
#include "Blocks/block.h"
#include "Levels/level.h"

using namespace std;

enum Op {LEFT, RIGHT, DOWN, CLOCKWISE, COUNTERCLOCKWISE, DROP, LEVEL_UP, LEVEL_DOWN, NO_RANDOM, RANDOM, BLOCK, RESTART, SEQUENCE};

Op convertOp(string opStr) {
    vector<string> commands = {left, right, down, clockwise, counterclockwise, drop, levelup, leveldown, norandom, random, block, restart, sequence};

    for (int i = 0; i < commands.size(); ++i) {
        if (opStr == commands[i].substr(0, opStr.size())) {
            return i;
        }
    }
} // convertOp

int main (int argc, char *argv[]) {

    size_t player1 = 1, player2 = 2;
	size_t startingLevel = 0;
	size_t board1counter = 1, board2counter = 1;
	size_t hiscore = 0;
	string p1LevelZero = "sequence1.txt";
	string p2LevelZero = "sequence2.txt";
    bool graphicsOn = true;

    for (int i = 1; i < argc; i++) {
        string cmd = argv[i];
        if (cmd == "-text") {
		    graphicsOn = false;
        } else {
			if (cmd != "-seed" && cmd != "-scriptfile1" && cmd != "-scriptfile2" && cmd != "-startlevel") {
				cerr << "Error: Unknown Argument: " << cmd << endl;
				return 1;
			}
        }
    }

    for (;;) {
        cerr << "Command: ";
        string command;
        cin >> command;

      if ( cin.eof() ) break;

        Op op = convertOp(command);

        switch( op ) {
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