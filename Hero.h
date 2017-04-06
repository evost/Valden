#pragma once

#include "Map.h"
#include "strings.h"

class Hero {
private:
public:
	float xp;
	TItem carmor, cweapon;
	TItem invertory[invSize];
	int x, y;
	int hp, strength, dexterity, intelligence, maxhp, maxxp, level, cpoints, race, visDistance;
	Hero();
	void GetHero(Map &dMap);
	void SetVisibleCells(Map &dMap);
	void HeroStep(short dx, short dy, Map &dMap);
	int GetDamage();
	int GetDefense();
	void ExpInc(float dxp);
};
