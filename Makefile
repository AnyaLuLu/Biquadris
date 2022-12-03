CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
OBJECTS = txtDisplay.o subject.o observer.o main.o board.o level.o lvl0.o lvl1.o lvl2.o lvl3.o lvl4.o block.o cube.o iBlock.o jBlock.o lBlock.o oBlock.o sBlock.o tBlock.o zBlock.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = a4q3

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

.PHONY: clean
clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

-include ${DEPENDS}