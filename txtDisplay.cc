#include "txtDisplay.h"

txtDisplay::txtDisplay(Board *Board1, Board *Board2) : Board1{Board1}, Board2{Board2}
{
    Board1->attach(this);
    Board2->attach(this);
}

void txtDisplay::notify()
{
    out << " Level:    " << Board1->getLvl() << "        " << "Level:    " << Board2->getLvl() << std::endl;
    out << " Score:    " << Board1->getScore() << "        " << "Score:    " << Board2->getScore() << std::endl;
    

    for (int i = 0; i < Board1->getWidth() + 2; ++i){
        out << '_';
    }
    out << "      ";
    for (int i = 0; i < Board2->getWidth() + 2; ++i){
        out << '_';
    }
    out << std::endl;

    for (int i = 0; i < Board1->getHeight(); ++i){
        out << '|';
        for (int j = 0; j < Board1->getWidth(); ++j){
            out << Board1 -> getState(i, j);
        }
        out << '|' << std::endl;

        out << "      ";

        out << '|';
        for (int j = 0; j < Board2->getWidth(); ++j){
            out << Board2 -> getState(i, j);
        }
        out << '|' << std::endl;
    }


    for (int i = 0; i < Board1->getWidth() + 2; ++i){
        out << '_';
    }
    out << "      ";
    for (int i = 0; i < Board2->getWidth() + 2; ++i){
        out << '_';
    }
    out << std::endl;
}
