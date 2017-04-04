#include "io.h"
#include "Map.h"
#include "Hero.h"
#include "NPC.h"
#include "constants.h"
#include "game.h"

int main() {
	Init(windowX, windowY, sWindowName);
	Map VMap(128, 64);
	Hero VHero;
	NPC VNPC(64, VMap);
	bool showHints = false;
	bool inGame = false;
	while (true)
		switch (Menu(inGame)) {
		case 2:
			NewHero(VHero);
			for (int i = 0; i < logSize; i++)
				AddLog(sSpace);
		case 1:
			NewMap(VMap, VHero, VNPC);
			inGame = true;
		case 0:
			Game(VMap, VHero, VNPC, showHints);
			if (VHero.hp <= 0) inGame = false;
			break;
		case 3:
			break;
		case 4:
			return 0;
			break;
		default:
			break;
		}
}
