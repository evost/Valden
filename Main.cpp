#include "io.h"
#include "Map.h"
#include "Hero.h"
#include "NPC.h"
#include "constants.h"
#include "game.h"

int main() {
	Init(windowX, windowY, sWindowName);
	Map VMap(128, 64);
	Hero VHero(VMap);
	NPC VNPC(64, VMap);
	bool showHints = false;
	bool inGame = false;
	while (true)
		switch (Menu(inGame)) {
		case 1:
			NewGame(VMap, VHero, VNPC);
			inGame = true;
			for (int i = 0; i < logSize; i++)
				AddLog(sSpace);
		case 0:
			Game(VMap, VHero, VNPC, showHints);
			break;
		case 2:
			break;
		case 3:
			return 0;
			break;
		default:
			break;
		}
}
