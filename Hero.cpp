#include "Hero.h"
#include "game.h"

Hero::Hero() {
	strength = startSkill + rand() % startSkillRandom;
	dexterity = startSkill + rand() % startSkillRandom;
	intelligence = startSkill + rand() % startSkillRandom;
	level = 1;
	cpoints = newLevelPoints;
	maxhp = startHp + strength;
	hp = maxhp;
	xp = 0;
	maxxp = XP_table[level - 1];
	visDistance = heroStartVisDistance + intelligence;
	carmor = armor1;
	cweapon = sword1;
	for (int i = 0; i < invSize; i++)
		invertory[i].type = -1;
	invertory[0] = spear1;
	invertory[1] = armor2;
	x = 0;
	y = 0;
}

void Hero::GetHero(Map &dMap) {
	SetSymbol((short)(x + 1 - dMap.curX), (short)(y + 1 - dMap.curY), 'X', Black, Red);
}

void Hero::ShowInfo(short x, short y) {
	SetString(x, y + 0, sCoordinates + sDelimeter + to_wstring(Hero::x) + sComma + to_wstring(Hero::y), Black, White);
	SetString(x, y + 1, sHP + sDelimeter + to_wstring(hp) + sSlash + to_wstring(maxhp), Black, White);
	if (level < maxLevel)
		SetString(x, y + 2, sXP + sDelimeter + FloatToWstring(xp) + sSlash + to_wstring(maxxp), Black, White);
	else
		SetString(x, y + 2, sXP + sDelimeter + FloatToWstring(xp), Black, White);
	SetString(x, y + 3, sLevel + sDelimeter + to_wstring(level), Black, White);
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

void Hero::ShowInventory(short x, short y) {
	int k = 0;
	short button = 0;
	TItem item;
	while (button != 27 && button != 73 && button != 105 && button != 152 && button != 232) {
		Border(windowX, windowY, borderDelimiter);
		if (cweapon.type == -1)
			SetString(2, 1, sCWeapon + sLack, Black, White);
		else
			SetString(2, 1, sCWeapon + sItems[cweapon.id], Black, White);
		if (cweapon.type == -1)
			SetString(2, 2, sCArmor + sLack, Black, White);
		else
			SetString(2, 2, sCArmor + sItems[carmor.id], Black, White);
		for (int i = 0; i < invSize; i++)
			if (invertory[i].type == -1)
				SetString(2, 4 + i, sRadio + sLack, Black, White);
			else
				SetString(2, 4 + i, sRadio + sItems[invertory[i].id], Black, White);
		ShowInventoryHints(borderDelimiter + 2, 1);
		SetString(3, 4 + k, sAsterisk, Black, White);
		Render();
		button = ReadKey();
		switch (button) {
		case 224:
			SetString(3, 4 + k, sSpace, Black, White);
			switch (ReadKey()) {
			case 72:
				k = (k - 1 + invSize) % invSize;
				break;
			case 80:
				k = (k + 1 + invSize) % invSize;
				break;
			default:
				break;
			}
			break;
		case 13:
			switch (invertory[k].type) {
			case 0:
				item = cweapon;
				cweapon = invertory[k];
				invertory[k] = item;
				break;
			case 1:
				item = carmor;
				carmor = invertory[k];
				invertory[k] = item;
				break;
			default:
				break;
			}
			break;
		case 32:
			invertory[k].type = -1;
			break;
		default:
			break;
		}
	}
}

void Hero::ShowCharacteristics() {
	int dstrength = 0, ddexterity = 0, dintelligence = 0;
	int k = 0;
	short button = 0;
	while (button != 27 && button != 67 && button != 99 && button != 145 && button != 225) {
		Border(windowX, windowY, borderDelimiter);
		SetString(2, 1, sRace + sDelimeter + sRaces[race], Black, White);
		SetString(2, 2, sRadio + sStrength + sDelimeter + to_wstring(strength + dstrength), Black, White);
		SetString(2, 3, sRadio + sDexterity + sDelimeter + to_wstring(dexterity + ddexterity), Black, White);
		SetString(2, 4, sRadio + sIntelligence + sDelimeter + to_wstring(intelligence + dintelligence), Black, White);
		SetString(2, 5, sMaxHP + sDelimeter + to_wstring(maxhp + dstrength), Black, White);
		SetString(2, 6, sMulExp + sDelimeter + to_wstring(100 + intelligence + dintelligence) + sPercent, Black, White);
		SetString(2, 7, sDodgeÑhance + sDelimeter + to_wstring(dexterity + ddexterity) + sPercent, Black, White);
		SetString(2, 8, sVisDistance + sDelimeter + to_wstring(visDistance), Black, White);
		SetString(2, 9, sDamage + sDelimeter + to_wstring(GetDamage() + dstrength), Black, White);
		SetString(2, 10, sDefense + sDelimeter + to_wstring(GetDefense()), Black, White);
		SetString(2, 11, sPoints + sDelimeter + to_wstring(cpoints), Black, White);
		SetString(3, 2 + k, sAsterisk, Black, White);
		ShowCharacteristicsHints(borderDelimiter + 2, 1);
		Render();
		button = ReadKey();
		switch (button) {
		case 224:
			switch (ReadKey()) {
			case 72:
				k = (k - 1 + characteristicsNumber) % characteristicsNumber;
				break;
			case 80:
				k = (k + 1 + characteristicsNumber) % characteristicsNumber;
				break;
			default:
				break;
			}
			break;
		case 61:
		case 43:
			if (cpoints > 0) {
				switch (k) {
				case 0:
					dstrength++;
					break;
				case 1:
					ddexterity++;
					break;
				case 2:
					dintelligence++;
					visDistance++;
					break;
				default:
					break;
				}
				cpoints--;
			}
			break;
		case 45:
			switch (k) {
			case 0:
				if (dstrength > 0) {
					dstrength--;
					cpoints++;
				}
				break;
			case 1:
				if (ddexterity > 0) {
					ddexterity--;
					cpoints++;
				}
				break;
			case 2:
				if (dintelligence > 0) {
					dintelligence--;
					visDistance--;
					cpoints++;
				}
				break;
			default:
				break;
			}
			break;
		case 13:
			strength += dstrength;
			maxhp += dstrength;
			hp += dstrength;
			dexterity += ddexterity;
			intelligence += dintelligence;
			dstrength = 0;
			ddexterity = 0;
			dintelligence = 0;
			break;
		case 32:
			cpoints += dstrength;
			cpoints += ddexterity;
			cpoints += dintelligence;
			visDistance -= dintelligence;
			dstrength = 0;
			ddexterity = 0;
			dintelligence = 0;
			break;
		default:
			break;
		}
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
		if (rand() % 100 < 10)
			for (int i = 0; i < invSize; i++)
				if (invertory[i].type == -1) {
					int random = rand() % 100;
					if (random < 50)
						invertory[i] = spear1;
					else if (random < 75)
						invertory[i] = armor2;
					else if (random < 90)
						invertory[i] = sword2;
					else
						invertory[i] = armor3;
					AddLog(sReceived + sItems[invertory[i].id]);
					break;
				}
	}
}

void Hero::Death() {
	hp = 0;
	AddLog(sDeath);
}

void Hero::CreateHero() {
	int k = 0;
	short button = 0;
	while (button != 13) {
		Border(windowX, windowY, borderDelimiter);
		SetString(2, 1, sSelectRace, Black, White);
		SetString(2, 3, sRadio + sRaceHuman, Black, White);
		SetString(2, 4, sRadio + sRaceDwarf, Black, White);
		SetString(2, 5, sRadio + sRaceElf, Black, White);
		SetString(3, 3 + k, sAsterisk, Black, White);
		Render();
		button = ReadKey();
		switch (button) {
		case 224:
			switch (ReadKey()) {
			case 72:
				k = (k - 1 + raceCount) % raceCount;
				break;
			case 80:
				k = (k + 1 + raceCount) % raceCount;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
	race = k;
	switch (race) {
	case 0:
		dexterity++;
		intelligence++;
		break;
	case 1:
		strength++;
		intelligence++;
		break;
	case 2:
		strength++;
		dexterity++;
		break;
	default:
		break;
	}
}
