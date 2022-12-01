#include "force.h"
using namespace std;


Force::Force(Board* next) : Decorator{next} {}

void Force::notify(Board &b) {
	// change board somehow
}

Force::~Force() {}