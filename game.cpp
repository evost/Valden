#include "game.h"

void ShowGameHints(short x, short y) {
	SetString(x, y + 0, "arrows", Black, Green);
	SetString(x + 6, y + 0, ": " + sMotion);
	SetString(x, y + 1, "wsad  ", Black, Green);
	SetString(x + 6, y + 1, ": " + sAttack);
	SetString(x, y + 2, "i     ", Black, Green);
	SetString(x + 6, y + 2, ": " + sInventory);
	SetString(x, y + 3, "Esc   ", Black, Green);
	SetString(x + 6, y + 3, ": " + sMenu);
};

void ShowCharacteristicsHints(short x, short y) {
	SetString(x, y + 0, "Esc", Black, Green);
	SetString(x + 3, y + 0, ": " + sBack);
};

void ShowInventoryHints(short x, short y) {
	SetString(x, y + 0, "arrows", Black, Green);
	SetString(x + 6, y + 0, ": " + sSelect);
	SetString(x, y + 1, "Enter", Black, Green);
	SetString(x + 6, y + 1, ": " + sUse);
	SetString(x, y + 2, "Space", Black, Green);
	SetString(x + 6, y + 2, ": " + sDelete);
	SetString(x, y + 3, "Esc", Black, Green);
	SetString(x + 6, y + 3, ": " + sBack);
};

void RenderWorld(Map dMap, Hero dHero, NPC dNPC, bool hint) {
	dNPC.GetNPCs(dMap);
	dHero.GetHero(dMap);
	Clear(borderDelimiter + 2, 1, windowX - 1, 4);
	Clear(borderDelimiter + 2, windowY - 1, windowX - 1, windowY - 1);
	SetString(borderDelimiter + 2, windowY - 1, "Tab", Black, Green);
	if (hint) {
		ShowGameHints(borderDelimiter + 2, 1);
		SetString(borderDelimiter + 5, windowY - 1, ": " + sInfo);
	} else {
		dHero.ShowInfo(borderDelimiter + 2, 1);
		SetString(borderDelimiter + 5, windowY - 1, ": " + sHints);

	}
}
