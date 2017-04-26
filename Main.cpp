#include "game.h"
#include "version.h"

int main() {
	Init(sWindowName);
	if (SaveExist(sSavePath + sSettingsSave)) {
		LoadSettings(fontSize, mapVisY);
		mapVisX = mapVisY * 2;
		windowX = mapVisX + 32;
		windowY = mapVisY + 1;
		borderDelimiter = mapVisX + 1;
	}
	SetWindow(windowX, windowY, fontSize);
	SetString(mapVisX / 2, mapVisY / 2, sLoading, Black, White);
	Border(windowX, windowY, borderDelimiter);
	Render();
	GameMap VMap(0, 0);
	Hero VHero;
	NPC VNPC(0, VMap, 1);
	bool showHints = false;
	bool inGame = false;
	wstring versionNum = Version(sVersionURL);
	bool newVersion = false;
	if (versionNum != L"")
		newVersion = versionNum != version;
	while (true)
		switch (Menu(inGame, newVersion, versionNum)) {
		case 4:
			NewHero(VHero);
		case 2:
			NewMap(VMap, 128, 64, VHero, VNPC, 64);
			inGame = true;
		case 0:
			Game(VMap, VHero, VNPC, showHints);
			if (VHero.hp <= 0) inGame = false;
			break;
		case 1:
			CreateSaveDir(sSavePath);
			Save(VHero, sSavePath + sHeroSave);
			SaveMap(VMap);
			SaveNPC(VNPC);
			break;
		case 3:
			if (SaveExist(sSavePath + sHeroSave))
				Load(VHero, sSavePath + sHeroSave);
			else {
				NewHero(VHero);
			}
			if (SaveExist(sSavePath + sMapSave) && SaveExist(sSavePath + sNPCSave)) {
				LoadMap(VMap);
				LoadNPC(VNPC, VMap);
			}
			else
				NewMap(VMap, 128, 64, VHero, VNPC, 64);
			inGame = true;
			break;
		case 5:
			Settings();
			break;
		case 6:
			return 0;
			break;
		default:
			break;
		}
}
