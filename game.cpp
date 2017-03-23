#include "game.h"

void ShowGameHints(short x, short y) {
	SetString(x, y + 0, skArrows, Black, Green);
	SetString(x + 6, y + 0, sDelimeter + sMotion);
	SetString(x, y + 1, skWASD, Black, Green);
	SetString(x + 6, y + 1, sDelimeter + sAttack);
	SetString(x, y + 2, skI, Black, Green);
	SetString(x + 6, y + 2, sDelimeter + sInventory);
	SetString(x, y + 3, skC, Black, Green);
	SetString(x + 6, y + 3, sDelimeter + sInventory);
	SetString(x, y + 4, skEsc, Black, Green);
	SetString(x + 6, y + 4, sDelimeter + sMenu);
}

void ShowCharacteristicsHints(short x, short y) {
	SetString(x, y + 0, skArrows, Black, Green);
	SetString(x + 6, y + 0, sDelimeter + sSelect);
	SetString(x, y + 1, skPlus, Black, Green);
	SetString(x + 6, y + 1, sDelimeter + sIncrease);
	SetString(x, y + 2, skMinus, Black, Green);
	SetString(x + 6, y + 2, sDelimeter + sDecrease);
	SetString(x, y + 3, skEnter, Black, Green);
	SetString(x + 6, y + 3, sDelimeter + sAccept);
	SetString(x, y + 4, skSpace, Black, Green);
	SetString(x + 6, y + 4, sDelimeter + sClear);
	SetString(x, y + 5, skEsc, Black, Green);
	SetString(x + 6, y + 5, sDelimeter + sBack);
}

void ShowInventoryHints(short x, short y) {
	SetString(x, y + 0, skArrows, Black, Green);
	SetString(x + 6, y + 0, sDelimeter + sSelect);
	SetString(x, y + 1, skEnter, Black, Green);
	SetString(x + 6, y + 1, sDelimeter + sUse);
	SetString(x, y + 2, skSpace, Black, Green);
	SetString(x + 6, y + 2, sDelimeter + sDelete);
	SetString(x, y + 3, skEsc, Black, Green);
	SetString(x + 6, y + 3, sDelimeter + sBack);
}

void RenderWorld(Map dMap, Hero dHero, NPC dNPC, bool hint) {
	dNPC.GetNPCs(dMap);
	dHero.GetHero(dMap);
	Clear(borderDelimiter + 2, 1, windowX - 1, 4);
	Clear(borderDelimiter + 2, windowY - 1, windowX - 1, windowY - 1);
	SetString(borderDelimiter + 2, windowY - 1, skTab, Black, Green);
	if (hint) {
		ShowGameHints(borderDelimiter + 2, 1);
		SetString(borderDelimiter + 5, windowY - 1, sDelimeter + sInfo);
	} else {
		dHero.ShowInfo(borderDelimiter + 2, 1);
		SetString(borderDelimiter + 5, windowY - 1, sDelimeter + sHints);
	}
}
