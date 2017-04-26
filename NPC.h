#pragma once

#include "GameMap.h"
#include "Hero.h"

class NPC {
public:
	int NPCk;
	map <int, TNPC> NPCs;
	NPC(int k, GameMap &dMap, int heroLevel);
	void GetNPCs(GameMap &dMap, Hero &dHero);
	bool NoNPCs(short x, short y);
	void NPCstep(GameMap &dMap, Hero &dHero);
	int HeroAttack(int x, int y, int damage);
};
