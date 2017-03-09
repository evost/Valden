#include "Hero.h"
#include "io.h"
#include "strings.h"

Hero::Hero(Map dMap) {
	armor = 0;
	damage = 1;
	defence = 0;
	hp = 10;
	xp = 0;
	weapon = 0;
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
	SetString(x, y + 1, sHP + " : " + to_string(Hero::hp));
}

void Hero::HeroStep(short dx, short dy, Map &dMap) {
	dx += x;
	dy += y;
	if (dx >= 0 && dy >= 0 && dx <= dMap.Width && dy <= dMap.Height && dMap.IsFree(dx, dy)) {
		x = dx;
		y = dy;
		if (((x - dMap.curX) < scrollDist) && (dMap.curX > 0))
			dMap.curX--;
		if (((y - dMap.curY) < scrollDist) && (dMap.curY > 0))
			dMap.curY--;
		if (((dMap.curX + dMap.visX - x) <= scrollDist) && (dMap.curX <= (dMap.Width - dMap.visX)))
			dMap.curX++;
		if (((dMap.curY + dMap.visY - y) <= scrollDist) && (dMap.curY <= (dMap.Height - dMap.visY)))
			dMap.curY++;
	}
}