#include "io.h"
#include "Map.h"
#include "Hero.h"
#include "NPC.h"
#include "constants.h"
#include "game.h"
#include "version.h"

int main() {
	Init(windowX, windowY, sWindowName);
	SetString(mapVisX / 2, mapVisY / 2, sLoading, Black, White);
	Border(windowX, windowY, borderDelimiter);
	Render();
	Map VMap(128, 64);
	Hero VHero;
	NPC VNPC(64, VMap);
	bool showHints = false;
	bool inGame = false;
	wstring versionNum = Version(sNersionURL);
	bool newVersion = false;
	if (versionNum != L"")
		newVersion = versionNum != version;
	while (true)
		switch (Menu(inGame, newVersion, versionNum)) {
		case 4:
			NewHero(VHero);
			for (int i = 0; i < logSize; i++)
				AddLog(sSpace);
		case 2:
			NewMap(VMap, VHero, VNPC);
			inGame = true;
		case 0:
			Game(VMap, VHero, VNPC, showHints);
			if (VHero.hp <= 0) inGame = false;
			break;
		case 1:
			break;
		case 3:
			break;
		case 6:
			return 0;
			break;
		default:
			break;
		}
}
