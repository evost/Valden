#include "Hero.h"
#include "io.h"
#include "strings.h"
#include "constants.h"
#include "game.h"

Hero::Hero(Map &dMap) {
	strength = startSkill + rand() % startSkillRandom;
	dexterity = startSkill + rand() % startSkillRandom;
	intelligence = startSkill + rand() % startSkillRandom;
	level = 1;
	cpoints = newLevelPoints;
	maxhp = startHp + strength;
	hp = maxhp;
	xp = 0;
	maxxp = XP_table[level - 1];
	carmor = armor1;
	cweapon = sword1;
	for (int i = 0; i < invSize; i++)
		invertory[i].type = -1;
	do {
		x = rand() % (dMap.Width - 6) + 3;
		y = rand() % (dMap.Height - 6) + 3;
	} while (!dMap.IsFree(x, y));
	dMap.curX = x - dMap.visX / 2;
	if (dMap.curX < 0) dMap.curX = 0;
	if (dMap.curX > (dMap.Width - dMap.visX)) dMap.curX = dMap.Width - dMap.visX + 1;
	dMap.curY = y - dMap.visY / 2;
	if (dMap.curY < 0) dMap.curY = 0;
	if (dMap.curY > (dMap.Height - dMap.visY)) dMap.curY = dMap.Height - dMap.visY + 1;
}

void Hero::GetHero(Map dMap) {
	SetColor(Black, Red);
	SetSymbol((short)(x + 1 - dMap.curX), (short)(y + 1 - dMap.curY), 'X');
}

void Hero::ShowInfo(short x, short y) {
	SetString(x, y + 0, sCoordinates + ": " + to_string(Hero::x) + ", " + to_string(Hero::y));
	SetString(x, y + 1, sHP + ": " + to_string(hp) + " / " + to_string(maxhp));
	SetString(x, y + 2, sXP + ": " + to_string(xp) + " / " + to_string(maxxp));
	SetString(x, y + 3, sLevel + ": " + to_string(level));
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
		} else if (((dMap.curY + dMap.visY - y) <= scrollDist) && (dMap.curY <= (dMap.Height - dMap.visY))) {
			dMap.curY++;
			dMap.GetMap();
		} else if (((x - dMap.curX) < scrollDist) && (dMap.curX > 0)) {
			dMap.curX--;
			dMap.GetMap();
		} else if (((y - dMap.curY) < scrollDist) && (dMap.curY > 0)) {
			dMap.curY--;
			dMap.GetMap();
		}
	}
}

void Hero::ShowInventory(short x, short y) {
	Border(windowX, windowY, borderDelimiter);
	if (cweapon.type == -1)
		SetString(2, 1, sCWeapon + "---");
	else
		SetString(2, 1, sCWeapon + sItems[cweapon.id]);
	if (cweapon.type == -1)
		SetString(2, 2, sCArmor + "---");
	else
		SetString(2, 2, sCArmor + sItems[carmor.id]);
	for (int i = 0; i < invSize; i++)
		if (invertory[i].type == -1)
			SetString(2, 4 + i, "( ) ---");
		else
			SetString(2, 4 + i, "( ) " + sItems[invertory[i].id]);
	ShowInventoryHints(borderDelimiter + 2, 1);
	int k = 0;
	short button = 0;
	TItem item;
	while (button != 27) {
		SetString(3, 4 + k, "*");
		button = ReadKey();
		switch (button) {
		case 224:
			SetString(3, 4 + k, " ");
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
		case 13:
			switch (invertory[k].type) {
			case 0:
				item = cweapon;
				cweapon = invertory[k];
				invertory[k] = item;
				SetString(2, 1, sCWeapon + sItems[cweapon.id]);
				SetString(2, 4 + k, "( ) " + sItems[invertory[k].id]);
				break;
			case 1:
				item = carmor;
				carmor = invertory[k];
				invertory[k] = item;
				SetString(2, 2, sCArmor + sItems[carmor.id]);
				SetString(2, 4 + k, "( ) " + sItems[invertory[k].id]);
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
	Border(windowX, windowY, borderDelimiter);
	int dstrength = 0, ddexterity = 0, dintelligence = 0;
	SetString(2, 1, "( ) " + sStrength + ": " + to_string(strength + dstrength));
	SetString(2, 2, "( ) " + sDexterity + ": " + to_string(dexterity + ddexterity));
	SetString(2, 3, "( ) " + sIntelligence + ": " + to_string(intelligence + dintelligence));
	SetString(2, 4, sMaxHP + ": " + to_string(maxhp + dstrength));
	SetString(2, 5, sDamage + ": " + to_string(GetDamage() + dstrength));
	SetString(2, 6, sDefense + ": " + to_string(GetDefense()));
	SetString(2, 8, sPoints + ": " + to_string(cpoints));
	ShowCharacteristicsHints(borderDelimiter + 2, 1);
	int k = 0;
	short button = 0;
	while (button != 27) {
		SetString(3, 1 + k, "*");
		button = ReadKey();
		switch (button) {
		case 224:
			SetString(3, 1 + k, " ");
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
			if (cpoints > 0) {
				switch (k) {
				case 0:
					dstrength++;
					SetString(2, 1, "( ) " + sStrength + ": " + to_string(strength + dstrength));
					SetString(2, 4, sMaxHP + ": " + to_string(maxhp + dstrength));
					SetString(2, 5, sDamage + ": " + to_string(GetDamage() + dstrength));
					break;
				case 1:
					ddexterity++;
					SetString(2, 2, "( ) " + sDexterity + ": " + to_string(dexterity + ddexterity));
					break;
				case 2:
					dintelligence++;
					SetString(2, 3, "( ) " + sIntelligence + ": " + to_string(intelligence + dintelligence));
					break;
				default:
					break;
				}
				cpoints--;
				Clear(2, 8, borderDelimiter - 1, 8);
				SetString(2, 8, sPoints + ": " + to_string(cpoints));
			}
			break;
		case 45:
			switch (k) {
			case 0:
				if (dstrength > 0) {
					dstrength--;
					Clear(2, 1, borderDelimiter - 1, 1);
					SetString(2, 1, "( ) " + sStrength + ": " + to_string(strength + dstrength));
					Clear(2, 4, borderDelimiter - 1, 5);
					SetString(2, 4, sMaxHP + ": " + to_string(maxhp + dstrength));
					SetString(2, 5, sDamage + ": " + to_string(GetDamage() + dstrength));
					cpoints++;
					SetString(2, 8, sPoints + ": " + to_string(cpoints));
				}
				break;
			case 1:
				if (ddexterity > 0) {
					ddexterity--;
					Clear(2, 2, borderDelimiter - 1, 2);
					SetString(2, 2, "( ) " + sDexterity + ": " + to_string(dexterity + ddexterity));
					cpoints++;
					SetString(2, 8, sPoints + ": " + to_string(cpoints));
				}
				break;
			case 2:
				if (dintelligence > 0) {
					dintelligence--;
					Clear(2, 3, borderDelimiter - 1, 3);
					SetString(2, 3, "( ) " + sIntelligence + ": " + to_string(intelligence + dintelligence));
					cpoints++;
					SetString(2, 8, sPoints + ": " + to_string(cpoints));
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
			dstrength = 0;
			ddexterity = 0;
			dintelligence = 0;
			Clear(2, 1, borderDelimiter - 1, 5);
			SetString(2, 1, "( ) " + sStrength + ": " + to_string(strength));
			SetString(2, 2, "( ) " + sDexterity + ": " + to_string(dexterity));
			SetString(2, 3, "( ) " + sIntelligence + ": " + to_string(intelligence));
			SetString(2, 4, sMaxHP + ": " + to_string(maxhp + dstrength));
			SetString(2, 5, sDamage + ": " + to_string(GetDamage() + dstrength));
			SetString(2, 8, sPoints + ": " + to_string(cpoints));
			break;
		default:
			break;
		}
	}
};

int Hero::GetDamage() {
	if (cweapon.type == -1)
		return strength;
	else
		return strength + cweapon.damage;
};

int Hero::GetDefense() {
	if (carmor.type == -1)
		return 0;
	else
		return carmor.defense;
};

void Hero::ExpInc(int dxp) {
	if (dxp > 0) {
		xp += dxp;
		SetString(borderDelimiter + 2, 7, sIncExp1 + to_string(dxp) + sIncExp2);
		if (xp >= XP_table[level - 1] && level < maxLevel) {
			level++;
			maxxp = XP_table[level - 1];
			SetString(borderDelimiter + 2, 8, sNewLevel);
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
					SetString(borderDelimiter + 2, 9, sReceived + sItems[invertory[i].id]);
					break;
				}
	}
}
