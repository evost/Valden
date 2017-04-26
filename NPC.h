#pragma once

#include "Map.h"
#include "Hero.h"
#include <map>

class NPC {
public:
	int NPCk;
	map <int, TNPC> NPCs;
	NPC(int k, Map &dMap, int heroLevel);
	void GetNPCs(Map &dMap, Hero &dHero);
	bool NoNPCs(short x, short y);
	void NPCstep(Map &dMap, Hero &dHero);
	int HeroAttack(int x, int y, int damage);
};
