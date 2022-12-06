CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
<<<<<<< Updated upstream
OBJECTS = xWindow.o gDisplay.o txtDisplay.o subject.o observer.o main.o board.o level.o lvl0.o lvl1.o lvl2.o lvl3.o lvl4.o block.o cube.o iBlock.o jBlock.o lBlock.o oBlock.o sBlock.o tBlock.o zBlock.o
=======
OBJECTS = gDisplay.o xWindow.o txtDisplay.o subject.o observer.o main.o board.o level.o lvl0.o lvl1.o lvl2.o lvl3.o lvl4.o block.o cube.o iBlock.o jBlock.o lBlock.o oBlock.o sBlock.o tBlock.o zBlock.o
>>>>>>> Stashed changes
DEPENDS = ${OBJECTS:.o=.d}
EXEC = BIQUADRIS

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -lX11 -o ${EXEC}

.PHONY: clean
clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

-include ${DEPENDS}