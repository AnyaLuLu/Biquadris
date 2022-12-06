# Biquadris
CS 246

Ethan Chan's Update:

What's fixed:
1. clockwise and counterclockwise on all the blocks
2. drop doesnt seg fault anymore
3. right and left work past the 11th row

I still need to:
1. test: testing the guards on block functions (i.e. if there is another block in the way when you try to move it). I will do this later. This shouldnt impact debugging other aspects of the game

For Anya and Ethan Liu to work on:
1. bug: all blocks: if right is the first step, clockwise and counterclockwise dont work on the second step. not sure if this is a problem in block or board. I didn't look too far into it, but if you think the problem is in block you can leave it for me.

2. (FIXED) test: test score
3. (FIXED) bug: line clearing. currently, we are clearing the wrong line LOL
4. (FIXED) add feature: render the board before the first move
5. (FIXED) bug: the next block isnt always showing the correct block. I think its showing 2 blocks in advance? but im not 100pct sure cuz i didnt look too far into it
6. add feature: a cerr message when you try to execute an invalid block move (e.g. when you try to go left on the first move)
7. (FIXED) add feature: make levels print out "new level!" every time we levelup (or leveldown)
8. add feature: graphics observer
9. clean up comments (at the end) and probably other things along the way




Anya's update (Dec 5, 7:30pm):

Whats been fixed / added:
1. clearline() now deletes the right line
2. When clearing a line, all the blockpos need to be moved down too, that's been done
3. Score has been fixed and now displays correct score
4. Fixed displays so next block appears right
5. Levels print out what a level has been changed

To do:
- Ethan Chan's point 1 (see above)
- Graphics display
- Test command line interface stuff (pdf page 5)
- commands random and norandom file segment fault
- test restart
- test blind
- test heavy
- test force
- error message for invalid moves

Update 12/05

Bugs found:
- After moving down, some turns don't work - Ethan Chan
- Score not updating properly in higher levels


