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

bool isBlock(string command) {
    if (command == "I" || command == "J" || command == "L" || command == "O" || command == "S" || command == "T" || command == "Z") {
        return true;
    } else {
        return false;
    }
}

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
	int hiscore = 0;
	string p1blocks = "sequence1.txt";
	string p2blocks = "sequence2.txt";
    int turnCount = 0;
    int curPlayer = 1;
    int width = 11;
    int height = 18;
    vector<string> commandSequence;

    // create boards, displays, etc. here
    vector<vector<char>> p1board = (height, vector<char> (width, ' '));
    vector<vector<char>> p2board = (height, vector<char> (width, ' '));
    Board *Board1{width, height, 0, p1blocks, p1board};
    Board *Board2{width, height, 0, p2blocks, p2board};
    Board *curBoard = Board1;

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

        if (commandSequence.empty()) {
            cin >> command;
        } else {
            command = commandSequence.front();
            commandSequence.erase(commandSequence.begin());
        }
        

        int num = getNum(command);
        command = removeNum(command);

        if ( cin.eof() ) break;

        curPlayer = (turnCount % 2) + 1;
        if (curPlayer == 1) {
            curBoard = Board1;
        } else {
            curBoard = Board2;
        }

        char blockType;
        Op op;

        if (isBlock(command)) {
            blockType = command[0];
            op = BLOCK;
        } else {
            op = convertOp(command);
        }
       

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
                curBoard->addBlock();
                turnCount += 1;
                break;
            case LEVEL_UP: 
                curBoard->levelup();
                break;
            case LEVEL_DOWN: 
                curBoard->leveldown();
                break;
            case NO_RANDOM:
                string file;
                cin >> file;
                curBoard->setFile(file);
                break;
            case RANDOM:
                curBoard->setFile("");
                break;
            case BLOCK:
                curBoard->force_set(blockType);
                break;
            case SEQUENCE:
                string file;
                string fileCommand;
                ifstream f;

                if (commandSequence.empty()) {
                    cin >> file;
                } else {
                    file = commandSequence.front();
                    commandSequence.erase(commandSequence.begin());
                }

                f.open(file);
                if (!f.good()) {
                    cout << "Invalid file: " << file << endl;
                    continue;
                }

                while (f >> fileCommand) {
                    commandSequence.emplace_back(fileCommand);
                }
                break;
            case RESTART:
                int level1 = Board1->getLvl();
                string file1 = Board1->getFile();
                int level2 = Board2->getLvl();
                string file2 = Board1->getFile();
                delete Board1;
                delete Board2;

                vector<vector<char>> newBoard1  = (height, vector<char> (width, ' '));
                vector<vector<char>> newBoard2  = (height, vector<char> (width, ' '));

                Board1 = new Board{width, height, level1, file1, newBoard1};
                Board2 = new Board{width, height, level2, file2, newBoard2};
                break;
            default: 
                cerr << "Invalid command." << endl;
                break;
        } // switch

        if (curBoard->getScore() >= hiscore) {
            hiscore = curBoard->getScore();
        }
    } // infinite while
} // main

