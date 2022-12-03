#include "force.h"
#include "block.h"
#include "iBlock.h"
#include "jBlock.h"
#include "lBlock.h"
#include "oBlock.h"
#include "sBlock.h"
#include "tBlock.h"
#include "zBlock.h"
using namespace std;


Force::Force(Board* next) : Decorator{next} {}

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

void Force::newBlock() {
	char type;

    cout << "Choose a Block type: i/j/l/o/s/t/z" << endl;

	cin >> type;

	Block* b;

	if (type == 'i')
    {
        b = new iBlock(playingBoard, lvl -> lvlNum(), width);
    }
    else if (type == 'j')
    {
        b = new jBlock(playingBoard, lvl -> lvlNum(), width);
    }
    else if (type == 'l')
    {
        b = new lBlock(playingBoard, lvl -> lvlNum(), width);
    }
    else if (type == 'o')
    {
        b = new oBlock(playingBoard, lvl -> lvlNum(), width);
    }
    else if (type == 's')
    {
        b = new sBlock(playingBoard, lvl -> lvlNum(), width);
    }
    else if (type == 'z')
    {
        b = new zBlock(playingBoard, lvl -> lvlNum(), width);
    }
    else if (type == 't')
    {
        b = new tBlock(playingBoard, lvl -> lvlNum(), width);
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

Force::~Force() {}