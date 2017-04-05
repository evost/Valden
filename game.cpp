#include "game.h"

void AddLog(wstring s) {
	unsigned int k = 0;
	while (k*(windowX - 3 - borderDelimiter) < s.length()) {
		gameLog[logPosition] = s.substr(k*(windowX - 3 - borderDelimiter), windowX - 3 - borderDelimiter);
		logPosition = (logPosition + 1) % logSize;
		k++;
	}
}

void ShowLog() {
	for (int i = 0; i < logSize; i++)
		SetString(borderDelimiter + 2, windowY - 2 - logSize + i, gameLog[(logPosition - 1 - i + logSize) % logSize], Black, White);
}

void ShowGameHints(short x, short y) {
	SetString(x, y + 0, skArrows, Black, Green);
	SetString(x + 6, y + 0, sDelimeter + sMotion, Black, White);
	SetString(x, y + 1, skWASD, Black, Green);
	SetString(x + 6, y + 1, sDelimeter + sAttack, Black, White);
	SetString(x, y + 2, skI, Black, Green);
	SetString(x + 6, y + 2, sDelimeter + sInventory, Black, White);
	SetString(x, y + 3, skC, Black, Green);
	SetString(x + 6, y + 3, sDelimeter + sCharacteristics, Black, White);
	SetString(x, y + 4, skSpace, Black, Green);
	SetString(x + 6, y + 4, sDelimeter + sSkip, Black, White);
	SetString(x, y + 5, skEsc, Black, Green);
	SetString(x + 6, y + 5, sDelimeter + sMenu, Black, White);
}

void ShowCharacteristicsHints(short x, short y) {
	SetString(x, y + 0, skArrows, Black, Green);
	SetString(x + 6, y + 0, sDelimeter + sSelect, Black, White);
	SetString(x, y + 1, skPlus, Black, Green);
	SetString(x + 6, y + 1, sDelimeter + sIncrease, Black, White);
	SetString(x, y + 2, skMinus, Black, Green);
	SetString(x + 6, y + 2, sDelimeter + sDecrease, Black, White);
	SetString(x, y + 3, skEnter, Black, Green);
	SetString(x + 6, y + 3, sDelimeter + sAccept, Black, White);
	SetString(x, y + 4, skSpace, Black, Green);
	SetString(x + 6, y + 4, sDelimeter + sClear, Black, White);
	SetString(x, y + 5, skEsc + sComma + skC, Black, Green);
	SetString(x + 6, y + 5, sDelimeter + sBack, Black, White);
}

void ShowInventoryHints(short x, short y) {
	SetString(x, y + 0, skArrows, Black, Green);
	SetString(x + 6, y + 0, sDelimeter + sSelect, Black, White);
	SetString(x, y + 1, skEnter, Black, Green);
	SetString(x + 6, y + 1, sDelimeter + sUse, Black, White);
	SetString(x, y + 2, skSpace, Black, Green);
	SetString(x + 6, y + 2, sDelimeter + sDelete, Black, White);
	SetString(x, y + 3, skEsc + sComma + skI, Black, Green);
	SetString(x + 6, y + 3, sDelimeter + sBack, Black, White);
}

void ShowMenuHints(short x, short y) {
	SetString(x, y + 0, skArrows, Black, Green);
	SetString(x + 6, y + 0, sDelimeter + sSelect, Black, White);
	SetString(x, y + 1, skEnter, Black, Green);
	SetString(x + 6, y + 1, sDelimeter + sUse, Black, White);
}

void RenderWorld(Map &dMap, Hero &dHero, NPC &dNPC, bool hint) {
	dMap.GetMap();
	dNPC.GetNPCs(dMap, dHero);
	dHero.GetHero(dMap);
	ShowLog();
	Border(windowX, windowY, borderDelimiter);
	SetString(borderDelimiter + 2, windowY - 1, skTab, Black, Green);
	if (hint) {
		ShowGameHints(borderDelimiter + 2, 1);
		SetString(borderDelimiter + 5, windowY - 1, sDelimeter + sInfo, Black, White);
	} else {
		dHero.ShowInfo(borderDelimiter + 2, 1);
		SetString(borderDelimiter + 5, windowY - 1, sDelimeter + sHints, Black, White);
	}
}

void NewHero(Hero &dHero) {
	Hero nHero;
	dHero = nHero;
	dHero.CreateHero();
	for (int i = 0; i < historySize; i++)
		SetString(2, 1 + i, sHistory[i], Black, White);
	Border(windowX, windowY, borderDelimiter);
	Render();
	ReadKey();
}

void NewMap(Map &dMap, Hero &dHero, NPC &dNPC) {
	Map nMap(dMap.Width + 1, dMap.Height + 1);
	NPC nNPC(dNPC.NPCk, nMap);
	dMap = nMap;
	dNPC = nNPC;
	do {
		dHero.x = rand() % (dMap.Width - 6) + 3;
		dHero.y = rand() % (dMap.Height - 6) + 3;
	} while (!dMap.IsFree(dHero.x, dHero.y));
	dMap.curX = dHero.x - mapVisX / 2;
	if (dMap.curX < 0) dMap.curX = 0;
	if (dMap.curX > (dMap.Width - mapVisX)) dMap.curX = dMap.Width - mapVisX + 1;
	dMap.curY = dHero.y - mapVisY / 2;
	if (dMap.curY < 0) dMap.curY = 0;
	if (dMap.curY > (dMap.Height - mapVisY)) dMap.curY = dMap.Height - mapVisY + 1;
	dHero.SetVisibleCells(dMap);
}

void Game(Map &dMap, Hero &dHero, NPC &dNPC, bool &dShowHints) {
	short button = 0;
	while (button != 27) {
		RenderWorld(dMap, dHero, dNPC, dShowHints);
		Render();
		button = ReadKey();
		if (dHero.hp > 0)
			switch (button) {
			case 224:
				switch (ReadKey()) {
				case 72:
					if (dNPC.NoNPCs(dHero.x, dHero.y - 1)) dHero.HeroStep(0, -1, dMap);
					break;
				case 75:
					if (dNPC.NoNPCs(dHero.x - 1, dHero.y)) dHero.HeroStep(-1, 0, dMap);
					break;
				case 77:
					if (dNPC.NoNPCs(dHero.x + 1, dHero.y)) dHero.HeroStep(1, 0, dMap);
					break;
				case 80:
					if (dNPC.NoNPCs(dHero.x, dHero.y + 1)) dHero.HeroStep(0, 1, dMap);
					break;
				default:
					break;
				}
				dNPC.NPCstep(dMap, dHero);
				break;
			case 9:
				dShowHints = !dShowHints;
				break;
			case 32:
				dNPC.NPCstep(dMap, dHero);
				break;
			case 73:
			case 105:
			case 152:
			case 232:
				dHero.ShowInventory(windowX, windowY);
				break;
			case 67:
			case 99:
			case 145:
			case 225:
				dHero.ShowCharacteristics();
				break;
			case 87:
			case 119:
			case 150:
			case 230:
				dHero.ExpInc((float)dNPC.HeroAttack(dHero.x, dHero.y - 1, dHero.GetDamage()));
				dNPC.NPCstep(dMap, dHero);
				break;
			case 68:
			case 100:
			case 130:
			case 162:
				dHero.ExpInc((float)dNPC.HeroAttack(dHero.x + 1, dHero.y, dHero.GetDamage()));
				dNPC.NPCstep(dMap, dHero);
				break;
			case 83:
			case 115:
			case 155:
			case 235:
				dHero.ExpInc((float)dNPC.HeroAttack(dHero.x, dHero.y + 1, dHero.GetDamage()));
				dNPC.NPCstep(dMap, dHero);
				break;
			case 65:
			case 97:
			case 148:
			case 228:
				dHero.ExpInc((float)dNPC.HeroAttack(dHero.x - 1, dHero.y, dHero.GetDamage()));
				dNPC.NPCstep(dMap, dHero);
				break;
			default:
				break;
			}
	}
}

void InGameMenu(int y) {
	SetString(2, y + 0, sRadio + sContinue, Black, White);
	SetString(2, y + 1, sRadio + sSave, Black, White);
	SetString(2, y + 2, sRadio + sNewMap, Black, White);
}

void IsSaveMenu(int y) {
	SetString(2, y + 0, sRadio + sLoad, Black, White);
}

void DefMenu(int y) {
	SetString(2, y + 0, sRadio + sNewGame, Black, White);
	SetString(2, y + 1, sRadio + sSettings, Black, White);
	SetString(2, y + 2, sRadio + sExit, Black, White);
}

int Menu(bool inGame, bool newVersion, wstring versionNum) {
	int inGameInt = inGame * 3;
	int isSaveExistInt = SaveExist(sSavePath + sMapSave) || SaveExist(sSavePath + sHeroSave) || SaveExist(sSavePath + sNPCSave) * 1;
	int k = 0, n = 3 + inGameInt + isSaveExistInt;
	short button = 0;
	while (button != 13) {
		Border(windowX, windowY, borderDelimiter);
		ShowMenuHints(borderDelimiter + 2, 1);
		for (int i = 0; i < logoSize; i++)
			SetString(2, 1 + i, sLogo[i], Black, Red);
		if (inGameInt) {
			InGameMenu(logoSize + 2);
		}
		if (isSaveExistInt) {
			IsSaveMenu(logoSize + 2 + inGameInt);
		}
		DefMenu(logoSize + 2 + inGameInt + isSaveExistInt);
		SetString(3, 7 + k, sAsterisk, Black, White);
		for (int i = 0; i < copyrightSize; i++)
			SetString(3, windowY - copyrightSize - 1 + i, sCopyright[i], Black, White);
		if (newVersion)
			SetString(3, windowY - copyrightSize - 2, sVersion[newVersion] + versionNum, Black, White);
		else
			SetString(3, windowY - copyrightSize - 2, sVersion[newVersion], Black, White);
		Render();
		button = ReadKey();
		switch (button) {
		case 224:
			switch (ReadKey()) {
			case 72:
				k = (k - 1 + n) % n;
				break;
			case 80:
				k = (k + 1 + n) % n;
				break;
			default:
				break;
			}
			break;
		case 27:
			if (inGame)
				return 0;
			break;
		default:
			break;
		}
	}
	if (k <= 3 && inGameInt)
		return k;
	else
		return k + (1 - isSaveExistInt) + (3 - inGameInt);
}

double Distance(int x1, int y1, int x2, int y2) {
	return sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
}
