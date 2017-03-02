#pragma once

#include "Map.h"

class Hero {
private:
	int armor, weapon, hp, xp, defence, damage;
public:
	int x, y;
	Hero(Map dMap);
	void GetHero(Map dMap);
	void ShowInfo(short x, short y);
	void HeroStep(short dx, short dy, Map &dMap);
};