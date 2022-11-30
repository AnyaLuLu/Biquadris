CXX = g++
CXXFLAGS = -Wall -std=c++14 -MMD -Werror=vla
EXEC = BIQUARDIS
OBJECTS = 
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -lX11 -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
