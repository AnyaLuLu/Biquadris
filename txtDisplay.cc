#include "txtDisplay.h"

txtDisplay::txtDisplay(Board *myBoard) : myBoard{myBoard}
{
    myBoard->attach(this);
}

void txtDisplay::notify()
{
    // implement this
}
