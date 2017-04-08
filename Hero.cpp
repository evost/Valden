#include "Hero.h"
#include "game.h"

Hero::Hero() {
	strength = startSkill + rand() % startSkillRandom;
	dexterity = startSkill + rand() % startSkillRandom;
	intelligence = startSkill + rand() % startSkillRandom;
	level = 1;
	cpoints = 0;
	maxhp = startHp + strength;
	hp = maxhp;
	xp = 0;
	maxxp = XP_table[level - 1];
	visDistance = heroStartVisDistance + intelligence;
	cweapon = Items[0];
	carmor = Items[1];
	for (int i = 0; i < invSize; i++)
		invertory[i].type = -1;
	x = 0;
	y = 0;
}

void Hero::GetHero(Map &dMap) {
	SetSymbol((short)(x + 1 - dMap.curX), (short)(y + 1 - dMap.curY), 'X', Black, Red);
}

void Hero::SetVisibleCells(Map &dMap) {
	for (int mx = x - visDistance; mx <= x + visDistance; mx++)
		for (int my = y - visDistance; my <= y + visDistance; my++)
			if (mx >= 0 && my >= 0 && mx <= dMap.Width && my <= dMap.Height && Distance(mx, my, x, y) <= visDistance)
				dMap.SetVisible(mx, my);
}

void Hero::HeroStep(short dx, short dy, Map &dMap) {
	dx += x;
	dy += y;
	if (dx >= 0 && dy >= 0 && dx <= dMap.Width && dy <= dMap.Height && dMap.IsFree(dx, dy)) {
		x = dx;
		y = dy;
		if (((dMap.curX + mapVisX - x) <= scrollDist) && (dMap.curX <= (dMap.Width - mapVisX)))
			dMap.curX++;
		else if (((dMap.curY + mapVisY - y) <= scrollDist) && (dMap.curY <= (dMap.Height - mapVisY)))
			dMap.curY++;
		else if (((x - dMap.curX) < scrollDist) && (dMap.curX > 0))
			dMap.curX--;
		else if (((y - dMap.curY) < scrollDist) && (dMap.curY > 0))
			dMap.curY--;
		SetVisibleCells(dMap);
	}
}

int Hero::GetDamage() {
	if (cweapon.type == -1)
		return strength;
	else
		return strength + cweapon.damage;
}

int Hero::GetDefense() {
	if (carmor.type == -1)
		return 0;
	else
		return carmor.defense;
}

void Hero::ExpInc(float dxp) {
	if (dxp > 0) {
		dxp += (dxp*intelligence) / 100;
		xp += dxp;
		AddLog(sIncExp1 + FloatToWstring(dxp) + sIncExp2);
		if (xp >= XP_table[level - 1] && level < maxLevel) {
			level++;
			maxxp = XP_table[level - 1];
			hp = maxhp;
			AddLog(sNewLevel);
			cpoints += newLevelPoints;
		}
		if (rand() % 100 < 30)
			for (int i = 0; i < invSize; i++)
				if (invertory[i].type == -1) {
					int min = 2 * (level - 2);
					int max = level * 2 + 1;
					if (max > itemsNum) max = itemsNum;
					if (min < 0) min = 0;
					if (min > max) min = max - 1;
					int random = rand() % (max - min + 1) + min;
					invertory[i] = Items[random];
					AddLog(sReceived + sItems[invertory[i].id]);
					break;
				}
	}
}
