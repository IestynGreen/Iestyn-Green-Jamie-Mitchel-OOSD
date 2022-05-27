#include "gameObject.h"

void gameObject::update() {
	xpos = xpos + xvel;
	ypos = ypos + yvel;
}

