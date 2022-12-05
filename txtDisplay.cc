#include "txtDisplay.h"

txtDisplay::txtDisplay(Board *Board1, Board *Board2) : Board1{Board1}, Board2{Board2}
{
    Board1->attach(this);
    Board2->attach(this);
}

void txtDisplay::notify()
{
    out << " Level:    " << Board1->getLvl() << "        "
        << "Level:    " << Board2->getLvl() << std::endl;
    out << " Score:    " << Board1->getScore() << "        "
        << "Score:    " << Board2->getScore() << std::endl;

    for (int i = 0; i < Board1->getWidth() + 2; ++i)
    {
        out << '_';
    }
    out << "      ";
    for (int i = 0; i < Board2->getWidth() + 2; ++i)
    {
        out << '_';
    }
    out << std::endl;

    for (int i = 0; i < Board1->getHeight(); ++i)
    {
        out << '|';
        for (int j = 0; j < Board1->getWidth(); ++j)
        {
            out << Board1->getState(i, j);
        }
        out << '|';

        out << "      ";

        out << '|';
        for (int j = 0; j < Board2->getWidth(); ++j)
        {
            out << Board2->getState(i, j);
        }
        out << '|' << std::endl;
    }

    for (int i = 0; i < Board1->getWidth() + 2; ++i)
    {
        out << '_';
    }
    out << "      ";
    for (int i = 0; i < Board2->getWidth() + 2; ++i)
    {
        out << '_';
    }
    out << std::endl;
    out << std::endl;

    // out << Board2->getNextBlockChar()<<endl;

    std::string newblockb1s1;
    std::string newblockb1s2;
    std::string newblockb2s1;
    std::string newblockb2s2;


    if (Board1->getNextBlockChar() == 'I')
    {
        newblockb1s1 = "             ";
        newblockb1s2 = " Next: IIII  ";
    }
    else if (Board1->getNextBlockChar() == 'J')
    {
        newblockb1s1 = "       J     ";
        newblockb1s2 = " Next: JJJ   ";
    }
    else if (Board1->getNextBlockChar() == 'L')
    {
        newblockb1s1 = "         L   ";
        newblockb1s2 = " Next: LLL   ";
    }
    else if (Board1->getNextBlockChar() == 'O')
    {
        newblockb1s1 = "       OO    ";
        newblockb1s2 = " Next: OO    ";
    }
    else if (Board1->getNextBlockChar() == 'S')
    {
        newblockb1s1 = "        SS   ";
        newblockb1s2 = " Next: SS    ";
    }
    /*
    else if (Board1->getNextBlockChar() == 'T'){
        newblockb1s1 = "       TTT   ";
        newblockb1s2 = " Next:  T    ";
    }
    else if (Board1->getNextBlockChar() == 'Z'){
        newblockb1s1 = "       ZZ    ";
        newblockb1s2 = " Next:  ZZ   ";
    }


    if (Board2->getNextBlockChar() == 'I'){
        newblockb2s1 = "             ";
        newblockb2s2 = " Next: IIII  ";
    }
    else if (Board2->getNextBlockChar() == 'J'){
        newblockb2s1 = "       J     ";
        newblockb2s2 = " Next: JJJ   ";
    }
    else if (Board2->getNextBlockChar() == 'L'){
        newblockb2s1 = "         L   ";
        newblockb2s2 = " Next: LLL   ";
    }
    else if (Board2->getNextBlockChar() == 'O'){
        newblockb2s1 = "       OO    ";
        newblockb2s2 = " Next: OO    ";
    }
    else if (Board2->getNextBlockChar() == 'S'){
        newblockb2s1 = "        SS   ";
        newblockb2s2 = " Next: SS    ";
    }
    else if (Board2->getNextBlockChar() == 'T'){
        newblockb2s1 = "       TTT   ";
        newblockb2s2 = " Next:  T    ";
    }
    else if (Board2->getNextBlockChar() == 'Z'){
        newblockb2s1 = "       ZZ    ";
        newblockb2s2 = " Next:  ZZ   ";
    }
    */
    out << newblockb1s1 << "      " << newblockb2s1 << std::endl;
    out << newblockb1s2 << "      " << newblockb2s2 << std::endl;
}
