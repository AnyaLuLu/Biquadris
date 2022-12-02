#include "txtDisplay.h"

txtDisplay::txtDisplay(Board *myBoard) : myBoard{myBoard}
{
    myBoard->attach(this);
}

void txtDisplay::notify()
{
    for (int i = 0; i < myBoard->getWidth() + 2; ++i){
        out << '_';
    }
    out << std::endl;
    for (int i = 0; i < myBoard->getHeight(); ++i){
        out << '|';
        for (int j = 0; j < myBoard->getWidth(); ++j){
            out << myBoard -> getState(i, j);
        }
        out << '|' << std::endl;
    }
    for (int i = 0; i < myBoard->getWidth() + 2; ++i){
        out << '_';
    }
    out << std::endl;
}
