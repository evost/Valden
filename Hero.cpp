#include "Hero.h"
#include "io.h"
#include "strings.h"
#include "constants.h"

Hero::Hero(Map dMap) {
	strength = 5 + rand() % 5;
	dexterity = 5 + rand() % 5;
	intelligence = 5 + rand() % 5;
	level = 1;
	maxhp = 10 + strength;
	hp = maxhp;
	xp = 0;
	maxxp = XP_table[level - 1];
	weapon = 0;
	armor = 0;
	do {
		x = rand() % (dMap.visX - 6) + 3;
		y = rand() % (dMap.visY - 6) + 3;
	} while (!dMap.IsFree(x, y));
}

void Hero::GetHero(Map dMap) {
	SetColor(Black, Red);
	SetSymbol((short)(x + 1 - dMap.curX), (short)(y + 1 - dMap.curY), 'X');
}

void Hero::ShowInfo(short x, short y) {
	SetString(x, y + 0, sCoordinates + " : " + to_string(Hero::x) + ", " + to_string(Hero::y) + "  ");
	SetString(x, y + 1, sHP + " : " + to_string(Hero::hp) + " / " + to_string(Hero::maxhp));
	SetString(x, y + 2, sXP + " : " + to_string(Hero::xp) + " / " + to_string(Hero::maxxp));
	SetString(x, y + 3, sLevel + " : " + to_string(Hero::level));
	SetString(x, y + 4, sStrength + " : " + to_string(Hero::strength));
	SetString(x, y + 5, sDexterity + " : " + to_string(Hero::dexterity));
	SetString(x, y + 6, sIntelligence + " : " + to_string(Hero::intelligence));
}

void Hero::HeroStep(short dx, short dy, Map &dMap) {
	dx += x;
	dy += y;
	if (dx >= 0 && dy >= 0 && dx <= dMap.Width && dy <= dMap.Height && dMap.IsFree(dx, dy)) {
		dMap.GetTile(x, y);
		x = dx;
		y = dy;
		if (((dMap.curX + dMap.visX - x) <= scrollDist) && (dMap.curX <= (dMap.Width - dMap.visX))) {
			dMap.curX++;
			dMap.GetMap();
		}
		else if (((dMap.curY + dMap.visY - y) <= scrollDist) && (dMap.curY <= (dMap.Height - dMap.visY))) {
			dMap.curY++;
			dMap.GetMap();
		}
		else if (((x - dMap.curX) < scrollDist) && (dMap.curX > 0)) {
			dMap.curX--;
			dMap.GetMap();
		}
		else if (((y - dMap.curY) < scrollDist) && (dMap.curY > 0)) {
			dMap.curY--;
			dMap.GetMap();
		}
	}
}