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
(btw Ethan, i left u another function to make that Ethan prolly needs. Put some notes there for ya)
