# Biquadris
CS 246

2022-12-02 Update (Anya)

Added currentBlock* and nextBlock*
    Added a new function assignBlock (line 110). Calls lvl -> blockType, which returns a string, then returns a Block* based on that string.

    currentBlock* and nextBlock* called in the ctor to initialize them thru blockType in lvl

    currentBlock* added to Board's vectors in newBlock() (see line 304), then both pointers r updated.


2. clean up comments (at the end) and probably other things along the way
3. Test memory
4. Graphics display
5. Test blind
6. Test force
7. Level 4 * block
8. People need to lose

:DDDDDDDDDDDD

(ig we can use currentBlock* to help with the display)

