#pragma once

#include "Map.h"
#include "structs.h"
#include "constants.h"
#include "io.h"
#include "strings.h"

class Hero {
private:
	float xp;
	TItem carmor, cweapon;
	TItem invertory[invSize];
public:
	int x, y;
	int hp, strength, dexterity, intelligence, maxhp, maxxp, level, cpoints;
	Hero(Map &dMap);
	void GetHero(Map dMap);
	void ShowInfo(short x, short y);
	void HeroStep(short dx, short dy, Map &dMap);
	void ShowInventory(short x, short y);
	void ShowCharacteristics();
	int GetDamage();
	int GetDefense();
	void ExpInc(float dxp);
	void Death();
};
