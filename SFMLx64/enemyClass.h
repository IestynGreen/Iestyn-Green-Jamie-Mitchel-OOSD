#pragma once
#include "gameObject.h"
class enemyClass:public gameObject{
public:
	void nearby(int playerx, int playery);
	enemyClass();
};

