#include "Hero.h"
#include "io.h"
#include "strings.h"
#include "constants.h"

Hero::Hero(Map &dMap) {
	strength = startSkill + rand() % startSkillRandom;
	dexterity = startSkill + rand() % startSkillRandom;
	intelligence = startSkill + rand() % startSkillRandom;
	level = 1;
	maxhp = startHp + strength;
	hp = maxhp;
	xp = 0;
	maxxp = XP_table[level - 1];
	carmor = armor1;
	cweapon = sword1;
	do {
		x = rand() % (dMap.Width - 6) + 3;
		y = rand() % (dMap.Height - 6) + 3;
	} while (!dMap.IsFree(x, y));
	dMap.curX = x - dMap.visX / 2;
	if (dMap.curX < 0) dMap.curX = 0;
	if (dMap.curX > (dMap.Width - dMap.visX)) dMap.curX = dMap.Width - dMap.visX + 1;
	dMap.curY = y - dMap.visY / 2;
	if (dMap.curY < 0) dMap.curY = 0;
	if (dMap.curY >(dMap.Height - dMap.visY)) dMap.curY = dMap.Height - dMap.visY + 1;
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
void Hero::ShowInventory(short x, short y) {
	Border(windowX, windowY, 0);
	if (cweapon.type == -1)
		SetString(2, 1, sCWeapon + "---");
	else
		SetString(2, 1, sCWeapon + cweapon.name);
	if (cweapon.type == -1)
		SetString(2, 2, sCArmor + "---");
	else
		SetString(2, 2, sCArmor + carmor.name);
	for (int i = 0; i < invSize; i++)
		if (invertory[i].type == -1)
			SetString(2, 4 + i, to_string(i + 1) + ") ---");
		else
			SetString(2, 4 + i, to_string(i + 1) + ") " + invertory[i].name);
	while (ReadKey() != 27) {};
}

int Hero::GetDamage() {
	if (cweapon.type != -1)
		return strength;
	else
		return strength + cweapon.damage;
};

void Hero::ExpInc(int dxp) {
	if (dxp > 0) {
		xp += dxp;
		SetString(borderDelimiter + 2, 10, sIncExp1 + to_string(dxp) + sIncExp2);
		if (xp >= XP_table[level - 1] && level < maxLevel) {
			level++;
			maxxp = XP_table[level - 1];
			SetString(borderDelimiter + 2, 11, sNewLevel);
		}
	}
}