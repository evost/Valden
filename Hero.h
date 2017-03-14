#pragma once

#include "Map.h"
#include "structs.h"
#include "constants.h"

class Hero {
private:
	int hp, xp, strength, dexterity, intelligence, maxhp, maxxp, level;
	TItem carmor, cweapon;
	TItem invertory[invSize];
public:
	int x, y;
	Hero(Map dMap);
	void GetHero(Map dMap);
	void ShowInfo(short x, short y);
	void HeroStep(short dx, short dy, Map &dMap);
	void ShowInventory(short x, short y);
	int GetDamage();
	void ExpInc(int dxp);
};