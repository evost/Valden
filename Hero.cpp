#include "Hero.h"
#include "game.h"

Hero::Hero() {
	strength = startSkill + rand() % startSkillRandom;
	dexterity = startSkill + rand() % startSkillRandom;
	intelligence = startSkill + rand() % startSkillRandom;
	level = 1;
	killed = 0;
	cpoints = 0;
	maxhp = startHp + strength;
	hp = maxhp;
	xp = 0;
	maxxp = XP_table[level - 1];
	visDistance = heroStartVisDistance + intelligence;
	cweapon = Items[0];
	carmor = Items[1];
	for (int i = 0; i < invSize; i++)
		invertory[i] = blankItem;
	x = 0;
	y = 0;
}

void Hero::GetHero(GameMap &dMap) {
	SetSymbol((short)(x + 1 - dMap.curX), (short)(y + 1 - dMap.curY), 'X', Black, Red);
}

void Hero::SetVisibleCells(GameMap &dMap) {
	for (int mx = x - visDistance; mx <= x + visDistance; mx++)
		for (int my = y - visDistance; my <= y + visDistance; my++)
			if (mx >= 0 && my >= 0 && mx <= dMap.Width && my <= dMap.Height && Distance(mx, my, x, y) <= visDistance) {
				if (dMap.MainMap[mx][my].type >= minTrap && dMap.MainMap[mx][my].type < trapKnown && dMap.MainMap[mx][my].isVisible == false && (rand() % 100 < intelligence)) {
					AddLog(sSeeTrap);
					dMap.MainMap[mx][my] = Tiles[trapKnown];
				}
				dMap.MainMap[mx][my].isVisible = true;
			}
}

void Hero::HeroStep(short dx, short dy, GameMap &dMap) {
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
		if (dMap.MainMap[x][y].type >= minTrap && dMap.MainMap[x][y].type <= trapKnown)
			if (rand() % 100 < (dexterity + intelligence) * trapDisarmpc) {
				AddLog(sDisarmTrap);
				dMap.MainMap[x][y] = Tiles[trapUsed];
			}
			else {
				AddLog(sFallTrap);
				dMap.MainMap[x][y] = Tiles[trapUsed];
				int damage = (int)(hp * trapHPpc);
				if (hp > 1 && damage >= hp)
					damage = hp - 1;
				else if (damage >= hp)
					damage = hp;
				if (damage == 0) damage = 1;
				hp -= damage;
				AddLog(sReceived + to_wstring(damage) + sDamageToHero2);
				if (hp <= 0) {
					hp = 0;
					AddLog(sDeath);
				}
			}
	}
}

int Hero::GetDamage() {
	if (cweapon.type == blank)
		return strength;
	else
		return strength + cweapon.damage;
}

int Hero::GetDefense() {
	if (carmor.type == blank)
		return 0;
	else
		return carmor.defense;
}

void Hero::ExpInc(float dxp) {
	if (dxp > 0) {
		killed++;
		dxp += (dxp*intelligence) / 100;
		xp += dxp;
		AddLog(sReceived + FloatToWstring(dxp) + sIncExp);
		if (xp >= XP_table[level - 1] && level < maxLevel) {
			level++;
			maxxp = XP_table[level - 1];
			AddLog(sNewLevel);
			cpoints += newLevelPoints;
		}
		int chance = rand() % 100;
		if (chance < 34)
			for (int i = 0; i < invSize; i++)
				if (invertory[i].type == blank) {
					if (chance < 11)
						invertory[i] = poultices[chance % poulticeNum];
					else {
						int min = 2 * (level - 2);
						int max = level * 2 + 1;
						if (max > itemsNum) max = itemsNum;
						if (min < 0) min = 0;
						if (min > max) min = max - 1;
						int random = rand() % (max - min + 1) + min;
						invertory[i] = Items[random];
					}
					AddLog(sReceived + sItems[invertory[i].id]);
					break;
				}
				else if (i = invSize - 1)
					AddLog(sNoFreeSpace);
	}
}
