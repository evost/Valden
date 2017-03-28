#pragma once

#include "Map.h"
#include "Hero.h"

class NPC {
private:
	TNPC NPC_types[2] = { { 0, 3, 2, 1, 5, 3, 1, 3, 0, 0 }, { 1, 5, 3, 3, 7, 5, 2, 4, 0, 0 } };
	TTile NPC_tiles[2] = { { 0, Brown, '^' }, { 1, Yellow, 'g' } };
public:
	int NPCk;
	TNPC* NPCs = NULL;
	NPC(int k, Map dMap);
	void GetNPCs(Map dMap, Hero dHero);
	bool NoNPCs(short x, short y);
	void NPCstep(Map dMap, Hero &dHero);
	int HeroAttack(int x, int y, int damage);
};
