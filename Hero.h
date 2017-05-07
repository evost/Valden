#pragma once

#include "GameMap.h"
#include "strings.h"

class Hero {
public:
	float xp;
	int x, y;
	int killed;
	int hp, strength, dexterity, intelligence, maxhp, maxxp, level, cpoints, race, visDistance;
	TItem carmor, cweapon;
	map<int, TItem> invertory;
	Hero();
	void GetHero(GameMap &dMap);
	void SetVisibleCells(GameMap &dMap);
	void HeroStep(short dx, short dy, GameMap &dMap);
	int GetDamage();
	int GetDefense();
	void ExpInc(float dxp);
};
