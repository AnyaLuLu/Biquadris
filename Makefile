CXX = g++
CXXFLAGS = -Wall -std=c++14 -MMD -Werror=vla
EXEC = BIQUARDIS
OBJECTS = txtDisplay.o subject.o observer.o main.o gDisplay.o board.o level.o lvl0.o lvl1.o lvl2.o lvl3.o lvl4.o blind.o decorator.o force.o heavy.o block.o cube.o iBlock.o jBlock.o lBlock.o oBlock.o sBlock tBlock.o zBlock.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -lX11 -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
