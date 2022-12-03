# Biquadris
CS 246

2022-12-02 Update (Anya)

Added currentBlock* and nextBlock*
    Added a new function assignBlock (line 110). Calls lvl -> blockType, which returns a string, then returns a Block* based on that string.

    currentBlock* and nextBlock* called in the ctor to initialize them thru blockType in lvl

    currentBlock* added to Board's vectors in newBlock() (see line 304), then both pointers r updated.

Fixed scoring
    in clearlines() (see line 334) score i added based on lvl
    Then playingBlocks is looped thru and all approporiate Block*'s are deleted and score is updated

:DDDDDDDDDDDD

(ig we can use currentBlock* to help with the display)







2022-12-02 Update (Ethan)
1. i had to change the board ctor to take in the width of the board in order to check for seg faults. but dw i updated this everywhere that needed to be updated, including in board

2. implemented worth and deletepos functions in block. Anya, u initially put these as virtual functions but i didnt really see a point of doing that so i defined it in block.cc

3. implemented getPos. it just makes a copy of the blockPos vector and returns that copy. I wasnt really sure thats what you guys wanted it to do, so i will clarify tmrw