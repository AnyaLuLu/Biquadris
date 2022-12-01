#include "heavy.h"
using namespace std;


Heavy::Heavy(Board* next) : Decorator{next} {}

void Heavy::notify(Board &b) {
	// change board somehow
}

Heavy::~Heavy() {}