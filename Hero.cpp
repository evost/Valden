#include "Hero.h"
#include "io.h"

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
	SetSymbol({ (short)(x + 1 - dMap.curX), (short)(y + 1 - dMap.curX) }, 'X');
}

void Hero::ShowInfo(short x, short y) {
	SetString({ x, y }, "Координаты : " + to_string(Hero::x) + ", " + to_string(Hero::y) + "  ");
}