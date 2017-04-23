#pragma once

#include "Map.h"
#include "Hero.h"

class NPC {
public:
	int NPCk;
	TNPC* NPCs;
	NPC(int k, Map &dMap, int heroLevel);
	void GetNPCs(Map &dMap, Hero &dHero);
	bool NoNPCs(short x, short y);
	void NPCstep(Map &dMap, Hero &dHero);
	int HeroAttack(int x, int y, int damage);
};
