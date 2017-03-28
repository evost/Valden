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
	SetString(x, y + 5, skEsc + sComma + skI, Black, Green);
	SetString(x + 6, y + 5, sDelimeter + sBack, Black, White);
}

void ShowInventoryHints(short x, short y) {
	SetString(x, y + 0, skArrows, Black, Green);
	SetString(x + 6, y + 0, sDelimeter + sSelect, Black, White);
	SetString(x, y + 1, skEnter, Black, Green);
	SetString(x + 6, y + 1, sDelimeter + sUse, Black, White);
	SetString(x, y + 2, skSpace, Black, Green);
	SetString(x + 6, y + 2, sDelimeter + sDelete, Black, White);
	SetString(x, y + 3, skEsc + sComma + skC, Black, Green);
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

void NewGame(Map &dMap, Hero &dHero, NPC &dNPC) {
	Map nMap(dMap.Width, dMap.Height);
	Hero nHero(nMap);
	NPC nNPC(dNPC.NPCk, nMap);
	dMap = nMap;
	dHero = nHero;
	dNPC = nNPC;
	dHero.CreateHero();
	Border(windowX, windowY, borderDelimiter);
	for (int i = 0; i < historySize; i++)
		SetString(2, 1 + i, sHistory[i], Black, White);
	Render();
	ReadKey();
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

int Menu(bool inGame) {
	int k = 0, n;
	if (inGame)
		n = 4;
	else
		n = 3;
	short button = 0;
	while (button != 13) {
		Border(windowX, windowY, borderDelimiter);
		ShowMenuHints(borderDelimiter + 2, 1);
		for (int i = 0; i < logoSize; i++)
			SetString(2, 1 + i, sLogo[i], Black, Red);
		if (inGame) {
			SetString(2, logoSize + 2, sRadio + sContinue, Black, White);
			SetString(2, logoSize + 3, sRadio + sNewGame, Black, White);
			SetString(2, logoSize + 4, sRadio + sSettings, Black, White);
			SetString(2, logoSize + 5, sRadio + sExit, Black, White);
		} else {
			SetString(2, logoSize + 2, sRadio + sNewGame, Black, White);
			SetString(2, logoSize + 3, sRadio + sSettings, Black, White);
			SetString(2, logoSize + 4, sRadio + sExit, Black, White);
		}
		SetString(3, 7 + k, sAsterisk, Black, White);
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
	if (inGame)
		return k;
	else
		return k + 1;
}

double Distance(int x1, int y1, int x2, int y2) {
	return sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
}
