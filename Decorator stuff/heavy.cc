#include "heavy.h"
using namespace std;


Heavy::Heavy(Board* next) : Decorator{next} {}

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

} // convertOp

void Heavy::newBlock() {
	char type;

    if(file == ""){
        type = lvl -> blockType(true);
    }
    else{
        type = lvl -> blockType(false);
    }

    // notify observers here to change display
    if(!currentBlock -> canCreate()){
        lost = true;
        return;
    }

    cout << "Command: ";
    string command;

    while (cin >> command)
    {
        Op op = convertOp(command);

        switch (op)
        {
        case LEFT:
            currentBlock -> left();
            break;
        case RIGHT:
            currentBlock -> right();
            break;
        case DOWN:
            currentBlock -> down();
            break;
        case CLOCKWISE:
            currentBlock -> clockwise();
            break;
        case COUNTERCLOCKWISE:
            currentBlock -> counterClockwise();
            break;
        case DROP:
            currentBlock -> drop();
            break;
        }
        // notify observers here to change display
        // does block mutate playingBoard as it moves?

		currentBlock -> down();
    }

    playingBlocks.emplace_back(currentBlock);
    currentBlock -> addBlock();

    currentBlock = nextBlock;
    if(file == ""){
        nextBlock = this -> assignBlock(true);
    }
    else{
        nextBlock = this -> assignBlock(false);
    }
}

Heavy::~Heavy() {}