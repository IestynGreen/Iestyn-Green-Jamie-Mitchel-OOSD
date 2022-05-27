#include "enemyClass.h"
#include "playerClass.h"

enemyClass::enemyClass() {
	xpos = 700;
	ypos = 400;
}
void enemyClass :: nearby(int playerx, int playery) {
	if (((playerx - xpos) < 400) && ((playerx - xpos) > -400)) {
		if (playerx > xpos){
			xpos += 2;

		}
		if (playerx < xpos) {
			xpos -= 2;

		}
		if (playery > ypos) {
			ypos += 2;

		}
		if (playery < ypos) {
			ypos -= 2;

		}
	}

}