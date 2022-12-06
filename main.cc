#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "board.h"
#include "block.h"
#include "level.h"
#include "txtDisplay.h"
#include "gDisplay.h"

using namespace std;

enum Op
{
    LEFT,
    RIGHT,
    DOWN,
    CLOCKWISE,
    COUNTERCLOCKWISE,
    DROP,
    LEVEL_UP,
    LEVEL_DOWN,
    NO_RANDOM,
    RANDOM,
    BLOCK,
    RESTART,
    SEQUENCE
};

Op convertOp(string opStr)
{
    vector<string> commands = {"left", "right", "down", "clockwise", "counterclockwise", "drop", "levelup", "leveldown", "norandom", "random", "block", "restart", "sequence"};

    for (int i = 0; i < commands.size(); ++i)
    {
        if (opStr.size() <= commands[i].size() && opStr == commands[i].substr(0, opStr.size()))
        {
            return Op(i);
        }
    }
    return Op(0);
} // convertOp

bool isBlock(string command)
{
    if (command == "I" || command == "J" || command == "L" || command == "O" || command == "S" || command == "T" || command == "Z")
    {
        return true;
    }
    else
    {
        return false;
    }
}

int getNum(string command)
{
    stringstream ss;
    ss << command;
    int retNum;

    if (!(ss >> retNum))
    {
        return 1;
    }
    
    return retNum;
}

string removeNum(string command)
{
    stringstream ss;
    ss << command;

    int tempNum;
    string retString;
    if (ss >> tempNum) {
        ss >> retString;
        //cerr << 3 << retString << 3;
        return retString;
    } else {
        return command;
    }
    
    
}

int main(int argc, char *argv[])
{

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
    vector<vector<char>> p1board(height, vector<char>(width, ' '));
    vector<vector<char>> p2board(height, vector<char>(width, ' '));

    Board *Board1;// = new Board{width, height, 0, p1blocks, p1board};
    Board *Board2;// = new Board{width, height, 0, p2blocks, p2board};
    Board *curBoard;

    txtDisplay *tDisplay;

    bool graphicsOn = true;
    for (int i = 1; i < argc; i++)
    {
        string command = argv[i];
        if (command == "-text")
        {
            graphicsOn = false;
        }
        else
        {
            if (command != "-seed" && command != "-scriptfile1" && command != "-scriptfile2" && command != "-startlevel")
            {
                cerr << "Invalid Argument: " << command << endl;
                return 1;
            }

            string extra = argv[i + 1];
            i += 1;

            if (command == "-seed")
            {
                try
                {
                    srand(stoi(extra));
                }
                catch (...)
                {
                    cerr << "Invalid seed: " << extra << endl;
                }
            }
            else if (command == "-scriptfile1")
            {
                ifstream testfile(extra);

                if (!testfile.good())
                {
                    cerr << "Invalid file: " << extra << endl;
                    return 1;
                }

                p1blocks = extra;
            }
            else if (command == "-scriptfile2")
            {
                ifstream testfile(extra);

                if (!testfile.good())
                {
                    cerr << "Invalid file: " << extra << endl;
                    return 1;
                }

                p2blocks = extra;
            }
            else if (command == "-startlevel")
            {
                try
                {
                    startLevel = stoi(extra);
                }
                catch (...)
                {
                    cerr << "Invalid level (not an integer): " << extra << endl;
                    return 1;
                }

                if (!(0 <= startLevel && startLevel <= maxLevel))
                {
                    cerr << "Invalid level (out of bounds): " << extra << endl;
                    return 1;
                }
            }
        }
    }

    int bSize = 15;
    int divider = 2;
    
    Board1 = new Board{width, height, 0, p1blocks, p1board};
    Board2 = new Board{width, height, 0, p2blocks, p2board};
    curBoard = Board1;
    tDisplay = new txtDisplay{Board1, Board2};
    
    if (graphicsOn) {
        Xwindow *x = new Xwindow{32*bSize+20*divider, 26*bSize+17*divider};
        GDisplay *gDisplay = new GDisplay{Board1, Board2, x, bSize, divider};
    }

    curBoard->notifyObservers("text", 0, 0);

    
    while (true)
    {
        bool turnOver = true;

        cout << "Command: ";
        string command;

        if (commandSequence.empty())
        {
            cin >> command;
        } else
        {
            command = commandSequence.front();
            commandSequence.erase(commandSequence.begin());
        }

        int num = getNum(command);
        //cerr << command << endl;
        command = removeNum(command);

        if (cin.eof())
            break;

        curPlayer = (turnCount % 2) + 1;

        if (curPlayer == 1)
        {
            curBoard = Board1;
        }
        else
        {
            curBoard = Board2;
        }

        char blockType;
        Op op;

        if (isBlock(command))
        {
            blockType = command[0];
            op = BLOCK;
        }
        else
        {
            op = convertOp(command);
        }

        if (op == LEFT)
        {
            curBoard->undraw();
            for (int i = 0; i < num; ++i) {
                curBoard->left();
            }
            curBoard->draw();

            if (curBoard->getHeavy()) {
                curBoard->down();
                turnOver = curBoard->down();
            } else if (curBoard->getLvl() >= 3) {
                turnOver = curBoard->down();
            }
        }
        else if (op == RIGHT)
        {
            curBoard->undraw();
            for (int i = 0; i < num; ++i) {
                curBoard->right();
                //std::cerr << i << "is i" << std::endl;
            }
            curBoard->draw();

            if (curBoard->getHeavy()) {
                curBoard->down();
                turnOver = curBoard->down();
            } else if (curBoard->getLvl() >= 3) {
                curBoard->down();
            }
        }
        else if (op == DOWN)
        {
            curBoard->undraw();
            for (int i = 0; i < num; ++i) {
                turnOver = curBoard->down();
            }
        }

        else if (op == CLOCKWISE)
        {
            curBoard->undraw();
            for (int i = 0; i < num; ++i) {
                curBoard->cw();
            }
            curBoard->draw();

            if (curBoard->getLvl() >= 3) {
                turnOver = curBoard->down();
            }
        }
        else if (op == COUNTERCLOCKWISE)
        {
            curBoard->undraw();
            for (int i = 0; i < num; ++i) {
                curBoard->ccw();
            }
            curBoard->draw();

            if (curBoard->getLvl() >= 3) {
                turnOver = curBoard->down();
            }
        }

        else if (op == DROP)
        {
            curBoard->undraw();
            for (int i = 0; i < num; ++i) {
                curBoard->drop();
            }
            curBoard->draw();

            turnOver = false;
        }

        else if (op == LEVEL_UP)
        {
            for (int i = 0; i < num; ++i) {
                curBoard->levelup();
            }

            if (curPlayer == 1) {
                curBoard->notifyObservers("g_level", 1, 0);
            } else {
                curBoard->notifyObservers("g_level", 2, 0);
            }
        }
        else if (op == LEVEL_DOWN)
        {
            for (int i = 0; i < num; ++i) {
                curBoard->leveldown();
            }
            
            if (curPlayer == 1) {
                curBoard->notifyObservers("g_level", 1, 0);
            } else {
                curBoard->notifyObservers("g_level", 2, 0);
            }
        }

        else if (op == NO_RANDOM)
        {
            if(curBoard -> getLvl() < 3){
                cout << "Randomness can only be set for level 3 and 4, you are on level " << curBoard -> getLvl() << endl;
            }
            else{
                string inputfile;
                cin >> inputfile;
                ifstream myfile;
                myfile.open(inputfile);
                if(myfile){
                    curBoard->setFile(inputfile);
                }
                else{
                    cout << "That file does not exist" << endl;
                }
            }
        }
        else if (op == RANDOM)
        {
            if(curBoard -> getLvl() < 3){
                cout << "Randomness can only be restored to level 3 and 4, you are on level " << curBoard -> getLvl() << endl;
            }
            else{
                curBoard->setFile("");
            }
        }
        else if (op == BLOCK)
        {
            curBoard->force_set(blockType);
        }

        else if (op == SEQUENCE)
        {
            string file;
            string fileCommand;
            ifstream f;

            if (commandSequence.empty())
            {
                cin >> file;
            }
            else
            {
                file = commandSequence.front();
                commandSequence.erase(commandSequence.begin());
            }

            f.open(file);
            if (!f.good())
            {
                cout << "Invalid file: " << file << endl;
                continue;
            }

            while (f >> fileCommand)
            {
                commandSequence.emplace_back(fileCommand);
            }
        }
        else if (op == RESTART)
        {
            int level1 = Board1->getLvl();
            string file1 = Board1->getFile();
            int level2 = Board2->getLvl();
            string file2 = Board1->getFile();
            delete Board1;
            delete Board2;

            vector<vector<char>> newBoard1(height, vector<char>(width, ' '));
            vector<vector<char>> newBoard2(height, vector<char>(width, ' '));

            Board1 = new Board{width, height, level1, file1, newBoard1};
            Board2 = new Board{width, height, level2, file2, newBoard2};
        }
        else
        {
            cerr << "Invalid command." << endl;
        }

        if (curBoard->getScore() >= hiscore)
        {
            hiscore = curBoard->getScore();
            curBoard->notifyObservers("g_score", hiscore, 0);
        }

        curBoard -> notifyObservers("text", 0, 0);

        if(!turnOver){
            curBoard -> addBlock();
            curBoard->notifyObservers("g_next", curPlayer, 0);
            turnCount++;

            if (curBoard->getBlind()) {
                curBoard->setBlind(false);
                curBoard->notifyObservers("g_unblind", curPlayer, 0);
            } 

            if (curBoard->getHeavy()) {
                curBoard->setHeavy(false);
            }

            int check = curBoard->clearlines();

            if (check >= 1) {
                curBoard->notifyObservers("g_score", hiscore, 0);
            }

            if (check >= 2) {
                cout << "Pick an effect: blind/heavy/force" << endl;

                string effect;
                cin >> effect;
                Board *otherBoard;

                if (curBoard == Board1) {
                    otherBoard = Board2;
                } else {
                    otherBoard = Board1;
                }

                if (effect == "blind") {
                    otherBoard->setBlind(true);

                    int otherPlayer = curPlayer % 2 + 1;
                    otherBoard->notifyObservers("g_blind", otherPlayer, 0);
                } else if (effect == "heavy") {
                    otherBoard->setHeavy(true);
                } else if (effect == "force") {
                    char block_type;
                    cin >> block_type;
                    otherBoard->force_set(block_type);
                }
            }
        }
    } // infinite while
    

} // main
