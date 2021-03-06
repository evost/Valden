#include "game.h"

wstring gameLog[logSize];
short logPosition = 0;

void AddLog(wstring s) {
	unsigned int k = 0;
	while (k*(windowX - 3 - borderDelimiter) < s.length()) {
		gameLog[logPosition] = s.substr(k*(windowX - 3 - borderDelimiter), windowX - 3 - borderDelimiter);
		logPosition = (logPosition + 1) % logSize;
		k++;
	}
}

void ShowLog() {
	for (int i = 0; i < logSize; i++)
		SetString(borderDelimiter + 2, windowY - 2 - logSize + i, gameLog[(logPosition - 1 - i + logSize) % logSize], Black, White);
}

void ShowGameHints(short x, short y) {
	SetString(x, y + 0, skArrows, Black, Green);
	SetString(x + keyLength, y + 0, sDelimeter + sMotion, Black, White);
	SetString(x, y + 1, skWASD, Black, Green);
	SetString(x + keyLength, y + 1, sDelimeter + sAttack, Black, White);
	SetString(x, y + 2, skI, Black, Green);
	SetString(x + keyLength, y + 2, sDelimeter + sInventory, Black, White);
	SetString(x, y + 3, skC, Black, Green);
	SetString(x + keyLength, y + 3, sDelimeter + sCharacteristics, Black, White);
	SetString(x, y + 4, skSpace, Black, Green);
	SetString(x + keyLength, y + 4, sDelimeter + sSkip, Black, White);
	SetString(x, y + 5, skEsc, Black, Green);
	SetString(x + keyLength, y + 5, sDelimeter + sMenu, Black, White);
}

void ShowCharacteristicsHints(short x, short y) {
	SetString(x, y + 0, skArrows, Black, Green);
	SetString(x + keyLength, y + 0, sDelimeter + sSelect, Black, White);
	SetString(x, y + 1, skPlus, Black, Green);
	SetString(x + keyLength, y + 1, sDelimeter + sIncrease, Black, White);
	SetString(x, y + 2, skMinus, Black, Green);
	SetString(x + keyLength, y + 2, sDelimeter + sDecrease, Black, White);
	SetString(x, y + 3, skEnter, Black, Green);
	SetString(x + keyLength, y + 3, sDelimeter + sAccept, Black, White);
	SetString(x, y + 4, skSpace, Black, Green);
	SetString(x + keyLength, y + 4, sDelimeter + sClear, Black, White);
	SetString(x, y + 5, skEsc + sComma + skC, Black, Green);
	SetString(x + keyLength, y + 5, sDelimeter + sBack, Black, White);
}

void ShowInventoryHints(short x, short y) {
	SetString(x, y + 0, skArrows, Black, Green);
	SetString(x + keyLength, y + 0, sDelimeter + sSelect, Black, White);
	SetString(x, y + 1, skEnter, Black, Green);
	SetString(x + keyLength, y + 1, sDelimeter + sUse, Black, White);
	SetString(x, y + 2, skBckspc, Black, Green);
	SetString(x + keyLength, y + 2, sDelimeter + sDelete, Black, White);
	SetString(x, y + 3, skEsc + sComma + skI, Black, Green);
	SetString(x + keyLength, y + 3, sDelimeter + sBack, Black, White);
}

void ShowMenuHints(short x, short y) {
	SetString(x, y + 0, skArrows, Black, Green);
	SetString(x + keyLength, y + 0, sDelimeter + sSelect, Black, White);
	SetString(x, y + 1, skEnter, Black, Green);
	SetString(x + keyLength, y + 1, sDelimeter + sUse, Black, White);
}

void ShowSettingsHints(short x, short y) {
	SetString(x, y + 0, skArrows, Black, Green);
	SetString(x + keyLength, y + 0, sDelimeter + sSelect, Black, White);
	SetString(x, y + 1, skEnter, Black, Green);
	SetString(x + keyLength, y + 1, sDelimeter + sUse, Black, White);
	SetString(x, y + 2, skSpace, Black, Green);
	SetString(x + keyLength, y + 2, sDelimeter + sClear, Black, White);
	SetString(x, y + 3, skEsc, Black, Green);
	SetString(x + keyLength, y + 3, sDelimeter + sBack, Black, White);
}

void ShowHeroInfo(Hero &dHero, short x, short y) {
	SetString(x, y + 0, sCoordinates + sDelimeter + to_wstring(dHero.x) + sComma + to_wstring(dHero.y), Black, White);
	SetString(x, y + 1, sLevel + sDelimeter + to_wstring(dHero.level), Black, White);
	SetString(x, y + 2, sHP + sDelimeter + to_wstring(dHero.hp) + sSlash + to_wstring(dHero.maxhp), Black, White);
	for (int i = 0; i < (float)dHero.hp / (float)dHero.maxhp*(windowX - borderDelimiter - 3); i++)
		SetString(x + i, y + 3, sSpace, Red, White);
	if (dHero.level <= maxLevel) {
		SetString(x, y + 4, sXP + sDelimeter + FloatToWstring(dHero.xp) + sSlash + to_wstring(dHero.maxxp), Black, White);
		for (int i = 0; i < (float)dHero.xp / (float)dHero.maxxp *(windowX - borderDelimiter - 3); i++)
			SetString(x + i, y + 5, sSpace, Brown, White);
	}
	else
		SetString(x, y + 4, sXP + sDelimeter + FloatToWstring(dHero.xp), Black, White);
}

void RenderWorld(GameMap &dMap, Hero &dHero, NPC &dNPC, bool hint) {
	dMap.GetMap();
	dNPC.GetNPCs(dMap, dHero);
	dHero.GetHero(dMap);
	ShowLog();
	Border(windowX, windowY, borderDelimiter);
	SetString(borderDelimiter + 2, windowY - 1, skTab, Black, Green);
	if (hint) {
		ShowGameHints(borderDelimiter + 2, 1);
		SetString(borderDelimiter + keyLength, windowY - 1, sDelimeter + sInfo, Black, White);
	}
	else {
		ShowHeroInfo(dHero, borderDelimiter + 2, 1);
		SetString(borderDelimiter + keyLength, windowY - 1, sDelimeter + sHints, Black, White);
	}
}

void NewHero(Hero &dHero) {
	for (int i = 0; i < logSize; i++)
		AddLog(sSpace);
	Hero nHero;
	dHero = nHero;
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
	dHero.race = k;
	switch (dHero.race) {
	case human:
		dHero.dexterity++;
		dHero.intelligence++;
		break;
	case dwarf:
		dHero.strength++;
		dHero.intelligence++;
		break;
	case elf:
		dHero.strength++;
		dHero.dexterity++;
		break;
	default:
		break;
	}
	for (int i = 0; i < historySize; i++)
		SetString(2, 1 + i, sHistory[i], Black, White);
	Border(windowX, windowY, borderDelimiter);
	Render();
	ReadKey();
}

void NewMap(GameMap &dMap, int width, int height, Hero &dHero, NPC &dNPC, int NPCk) {
	GameMap nMap(width, height);
	NPC nNPC(NPCk, nMap, dHero.level);
	dMap = nMap;
	dNPC = nNPC;
	do {
		dHero.x = rand() % (dMap.Width - spawnArea * 2) + spawnArea;
		dHero.y = rand() % (dMap.Height - spawnArea * 2) + spawnArea;
	} while (!dMap.IsFree(dHero.x, dHero.y) || !dNPC.NoNPCs(dHero.x, dHero.y));
	dMap.curX = dHero.x - mapVisX / 2;
	if (dMap.curX < 0) dMap.curX = 0;
	if (dMap.curX > (dMap.Width - mapVisX)) dMap.curX = dMap.Width - mapVisX + 1;
	dMap.curY = dHero.y - mapVisY / 2;
	if (dMap.curY < 0) dMap.curY = 0;
	if (dMap.curY > (dMap.Height - mapVisY)) dMap.curY = dMap.Height - mapVisY + 1;
	dHero.SetVisibleCells(dMap);
}

void ShowItemInfo(TItem item) {
	SetString(2, windowY - 8, sDamage + sPlus + to_wstring(item.damage), Black, White);
	SetString(2, windowY - 7, sDefense + sPlus + to_wstring(item.defense), Black, White);
	SetString(2, windowY - 6, sStrength + sPlus + to_wstring(item.dstrength), Black, White);
	SetString(2, windowY - 5, sDexterity + sPlus + to_wstring(item.ddexterity), Black, White);
	SetString(2, windowY - 4, sIntelligence + sPlus + to_wstring(item.dintelligence), Black, White);
	SetString(2, windowY - 3, sHP + sPlus + to_wstring(item.dmaxhp), Black, White);
	SetString(2, windowY - 2, sLevel + sDelimeter + to_wstring(item.level), Black, White);
}

void ShowInventory(Hero &dHero) {
	int k = 0;
	short button = 0;
	while (button != 27 && button != 73 && button != 105 && button != 152 && button != 232) {
		Border(windowX, windowY, borderDelimiter);
		SetString(2, 1, sRadio + sCWeapon + sItems[dHero.cweapon.id], Black, White);
		SetString(2, 2, sRadio + sCArmor + sItems[dHero.carmor.id], Black, White);
		if (k < 2)
			switch (k) {
			case weapon:
				if (dHero.cweapon.type != blank)
					ShowItemInfo(dHero.cweapon);
				break;
			case armor:
				if (dHero.carmor.type != blank)
					ShowItemInfo(dHero.carmor);
				break;
			default:
				break;
			}
		else
			ShowItemInfo(dHero.invertory[k - 2]);
		if (k - 2 <= invSize) {
			for (int i = 0; i <= invSize && i < dHero.invertory.size(); i++)
				if (dHero.invertory[i].level <= dHero.level)
					SetString(2, 4 + i, sRadio + sItems[dHero.invertory[i].id], Black, White);
				else
					SetString(2, 4 + i, sRadio + sItems[dHero.invertory[i].id], Black, Brown);
			if (k < 2)
				SetString(3, 1 + k, sAsterisk, Black, White);
			else
				SetString(3, 4 + k - 2, sAsterisk, Black, White);
		}
		else {
			SetString(2, 4, L"...", Black, White);
			for (int i = ((k - 2 - 1) / invSize)*invSize + 1; i <= ((k - 2 - 1) / invSize + 1)*invSize && i < dHero.invertory.size(); i++)
				if (dHero.invertory[i].level <= dHero.level)
					SetString(2, 5 + i %(((i - 1)/invSize)*invSize + 1), sRadio + sItems[dHero.invertory[i].id], Black, White);
				else
					SetString(2, 5 + i %(((i - 1)/invSize)*invSize + 1), sRadio + sItems[dHero.invertory[i].id], Black, Brown);
			SetString(3, 5 + (k - 2)%(((k - 2 - 1)/invSize)*invSize + 1), sAsterisk, Black, White);
		}
		if (((k - 2 - 1) / invSize + 1)*invSize + 1 < dHero.invertory.size())
			SetString(2, 4 + invSize + 1, L"...", Black, White);
		ShowInventoryHints(borderDelimiter + 2, 1);
		Render();
		button = ReadKey();
		switch (button) {
		case 224:
			switch (ReadKey()) {
			case 72:
				if (k > 0)
					k--;
				break;
			case 80:
				if (k < dHero.invertory.size() + 1)
					k++;
				break;
			default:
				break;
			}
			break;
		case 13:
			if (k < 2)
				switch (k) {
				case weapon:
					dHero.invertory[dHero.invertory.size()] = dHero.cweapon;
					dHero.cweapon = blankItem;
					break;
				case armor:
					dHero.invertory[dHero.invertory.size()] = dHero.carmor;
					dHero.carmor = blankItem;
					break;
				default:
					break;
				}
			else
				if (dHero.invertory[k - 2].level <= dHero.level)
					switch (dHero.invertory[k - 2].type) {
					case weapon:
						swap(dHero.cweapon, dHero.invertory[k - 2]);
						if (dHero.invertory[k - 2].type == blank) {
							for (unsigned int z = k - 2; z < dHero.invertory.size() - 1; z++)
								dHero.invertory[z] = dHero.invertory[z + 1];
							dHero.invertory.erase(dHero.invertory.size() - 1);
							k--;
						}
						break;
					case armor:
						swap(dHero.carmor, dHero.invertory[k - 2]);
						if (dHero.invertory[k - 2].type == blank) {
							for (unsigned int z = k - 2; z < dHero.invertory.size() - 1; z++)
								dHero.invertory[z] = dHero.invertory[z + 1];
							dHero.invertory.erase(dHero.invertory.size() - 1);
							k--;
						}
						break;
					case poultice:
						dHero.hp += dHero.invertory[k - 2].dmaxhp;
						if (dHero.hp > dHero.maxhp)
							dHero.hp = dHero.maxhp;
						for (unsigned int z = k - 2; z < dHero.invertory.size() - 1; z++)
							dHero.invertory[z] = dHero.invertory[z + 1];
						dHero.invertory.erase(dHero.invertory.size() - 1);
						k--;
						break;
					default:
						break;
					}
			break;
		case 8:
			if (k < 2)
				switch (k) {
				case weapon:
					dHero.cweapon = blankItem;
					break;
				case armor:
					dHero.carmor = blankItem;
					break;
				default:
					break;
				}
			else {
				for (unsigned int z = k - 2; z < dHero.invertory.size() - 1; z++)
					dHero.invertory[z] = dHero.invertory[z + 1];
				dHero.invertory.erase(dHero.invertory.size() - 1);
				k--;
			}
			break;
		default:
			break;
		}
	}
}

void ShowCharacteristics(Hero &dHero) {
	int dstrength = 0, ddexterity = 0, dintelligence = 0;
	int k = 0;
	short button = 0;
	while (button != 27 && button != 67 && button != 99 && button != 145 && button != 225) {
		Border(windowX, windowY, borderDelimiter);
		SetString(2, 1, sRace + sDelimeter + sRaces[dHero.race], Black, White);
		SetString(2, 2, sRadio + sStrength + sDelimeter + to_wstring(dHero.strength + dstrength), Black, White);
		SetString(2, 3, sRadio + sDexterity + sDelimeter + to_wstring(dHero.dexterity + ddexterity), Black, White);
		SetString(2, 4, sRadio + sIntelligence + sDelimeter + to_wstring(dHero.intelligence + dintelligence), Black, White);
		SetString(2, 5, sMaxHP + sDelimeter + to_wstring(dHero.maxhp + dstrength), Black, White);
		SetString(2, 6, sMulExp + sDelimeter + to_wstring(100 + dHero.intelligence + dintelligence) + sPercent, Black, White);
		SetString(2, 7, sDodge�hance + sDelimeter + to_wstring(dHero.dexterity + ddexterity) + sPercent, Black, White);
		SetString(2, 8, sSeeTrapChance + sDelimeter + to_wstring(dHero.intelligence + dintelligence) + sPercent, Black, White);
		SetString(2, 9, sDisarmTrapChance + sDelimeter + to_wstring((int)((dHero.dexterity + ddexterity + dHero.intelligence + dintelligence) * trapDisarmpc)) + sPercent, Black, White);
		SetString(2, 10, sVisDistance + sDelimeter + to_wstring(dHero.visDistance), Black, White);
		SetString(2, 11, sDamage + sDelimeter + to_wstring(dHero.GetDamage() + dstrength), Black, White);
		SetString(2, 12, sDefense + sDelimeter + to_wstring(dHero.GetDefense()), Black, White);
		SetString(2, 13, sPoints + sDelimeter + to_wstring(dHero.cpoints), Black, White);
		SetString(2, 14, sKilled + sDelimeter + to_wstring(dHero.killed), Black, White);
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
			if (dHero.cpoints > 0) {
				switch (k) {
				case strength:
					dstrength++;
					break;
				case dexterity:
					ddexterity++;
					break;
				case intelligence:
					dintelligence++;
					dHero.visDistance++;
					break;
				default:
					break;
				}
				dHero.cpoints--;
			}
			break;
		case 45:
			switch (k) {
			case strength:
				if (dstrength > 0) {
					dstrength--;
					dHero.cpoints++;
				}
				break;
			case dexterity:
				if (ddexterity > 0) {
					ddexterity--;
					dHero.cpoints++;
				}
				break;
			case intelligence:
				if (dintelligence > 0) {
					dintelligence--;
					dHero.visDistance--;
					dHero.cpoints++;
				}
				break;
			default:
				break;
			}
			break;
		case 13:
			dHero.strength += dstrength;
			dHero.maxhp += dstrength;
			dHero.hp += dstrength;
			dHero.dexterity += ddexterity;
			dHero.intelligence += dintelligence;
			dstrength = 0;
			ddexterity = 0;
			dintelligence = 0;
			break;
		case 27:
		case 67:
		case 99:
		case 145:
		case 225:
		case 32:
			dHero.cpoints += dstrength;
			dHero.cpoints += ddexterity;
			dHero.cpoints += dintelligence;
			dHero.visDistance -= dintelligence;
			dstrength = 0;
			ddexterity = 0;
			dintelligence = 0;
			break;
		default:
			break;
		}
	}
}

void Game(GameMap &dMap, Hero &dHero, NPC &dNPC, bool &dShowHints) {
	short button = 0;
	while (button != 27) {
		RenderWorld(dMap, dHero, dNPC, dShowHints);
		Render();
		button = ReadKey();
		if (dHero.hp > 0)
			switch (button) {
			case 224:
				switch (ReadKey()) {
				case 72:
					if (dNPC.NoNPCs(dHero.x, dHero.y - 1)) dHero.HeroStep(0, -1, dMap);
					break;
				case 75:
					if (dNPC.NoNPCs(dHero.x - 1, dHero.y)) dHero.HeroStep(-1, 0, dMap);
					break;
				case 77:
					if (dNPC.NoNPCs(dHero.x + 1, dHero.y)) dHero.HeroStep(1, 0, dMap);
					break;
				case 80:
					if (dNPC.NoNPCs(dHero.x, dHero.y + 1)) dHero.HeroStep(0, 1, dMap);
					break;
				default:
					break;
				}
				dNPC.NPCstep(dMap, dHero);
				break;
			case 9:
				dShowHints = !dShowHints;
				break;
			case 32:
				dNPC.NPCstep(dMap, dHero);
				break;
			case 73:
			case 105:
			case 152:
			case 232:
				ShowInventory(dHero);
				break;
			case 67:
			case 99:
			case 145:
			case 225:
				ShowCharacteristics(dHero);
				break;
			case 87:
			case 119:
			case 150:
			case 230:
				dHero.ExpInc((float)dNPC.HeroAttack(dHero.x, dHero.y - 1, dHero.GetDamage()));
				dNPC.NPCstep(dMap, dHero);
				break;
			case 68:
			case 100:
			case 130:
			case 162:
				dHero.ExpInc((float)dNPC.HeroAttack(dHero.x + 1, dHero.y, dHero.GetDamage()));
				dNPC.NPCstep(dMap, dHero);
				break;
			case 83:
			case 115:
			case 155:
			case 235:
				dHero.ExpInc((float)dNPC.HeroAttack(dHero.x, dHero.y + 1, dHero.GetDamage()));
				dNPC.NPCstep(dMap, dHero);
				break;
			case 65:
			case 97:
			case 148:
			case 228:
				dHero.ExpInc((float)dNPC.HeroAttack(dHero.x - 1, dHero.y, dHero.GetDamage()));
				dNPC.NPCstep(dMap, dHero);
				break;
			default:
				break;
			}
	}
}

void InGameMenu(int y) {
	SetString(2, y + 0, sRadio + sContinue, Black, White);
	SetString(2, y + 1, sRadio + sSave, Black, White);
	SetString(2, y + 2, sRadio + sNewMap, Black, White);
}

void IsSaveMenu(int y) {
	SetString(2, y + 0, sRadio + sLoad, Black, White);
}

void DefMenu(int y) {
	SetString(2, y + 0, sRadio + sNewGame, Black, White);
	SetString(2, y + 1, sRadio + sSettings, Black, White);
	SetString(2, y + 2, sRadio + sExit, Black, White);
}

int Menu(bool inGame, bool newVersion, wstring versionNum) {
	int inGameInt = inGame * 3;
	int isSaveExistInt = SaveExist(sSavePath + sMapSave) || SaveExist(sSavePath + sHeroSave) || SaveExist(sSavePath + sNPCSave) * 1;
	int k = 0, n = 3 + inGameInt + isSaveExistInt;
	short button = 0;
	while (button != 13) {
		Border(windowX, windowY, borderDelimiter);
		ShowMenuHints(borderDelimiter + 2, 1);
		for (short i = 0; i < logoSize; i++)
			SetString((short)(mapVisX - sLogo[i].length() + 1) / 2, 1 + i, sLogo[i], Black, Red);
		if (inGameInt) {
			InGameMenu(logoSize + 2);
		}
		if (isSaveExistInt) {
			IsSaveMenu(logoSize + 2 + inGameInt);
		}
		DefMenu(logoSize + 2 + inGameInt + isSaveExistInt);
		SetString(3, logoSize + 2 + k, sAsterisk, Black, White);
		for (int i = 0; i < copyrightSize; i++)
			SetString(2, windowY - copyrightSize - 1 + i, sCopyright[i], Black, White);
		if (newVersion)
			SetString(2, windowY - copyrightSize - 2, sVersion[newVersion] + versionNum, Black, White);
		else
			SetString(2, windowY - copyrightSize - 2, sVersion[newVersion], Black, White);
		Render();
		button = ReadKey();
		switch (button) {
		case 224:
			switch (ReadKey()) {
			case 72:
				k = (k - 1 + n) % n;
				break;
			case 80:
				k = (k + 1 + n) % n;
				break;
			default:
				break;
			}
			break;
		case 27:
			if (inGame)
				return 0;
			break;
		default:
			break;
		}
	}
	if (k <= 3 && inGameInt)
		return k;
	else
		return k + (1 - isSaveExistInt) + (3 - inGameInt);
}

void Settings() {
	short button = 0;
	short k = 0;
	short n = 2;
	short dfontSize = 0;
	short dmapVisY = 0;
	while (button != 27) {
		SetString(2, 2, sRadio + sTileSize + sDelimeter + to_wstring(fontSize + dfontSize), Black, White);
		SetString(2, 3, sRadio + sTileNum + sDelimeter + to_wstring((mapVisY + dmapVisY) * 2 + 32) + sX + to_wstring((mapVisY + dmapVisY) + 1), Black, White);
		SetString(2, 4, sResolution + sDelimeter + to_wstring(2 + ((mapVisY + dmapVisY) * 2 + 32 + 1) * 3 * (fontSize + dfontSize) / 5) + sX + to_wstring(32 + ((mapVisY + dmapVisY) + 1 + 1)*(fontSize + dfontSize)), Black, White);
		SetString(3, 2 + k, sAsterisk, Black, White);
		Border(windowX, windowY, borderDelimiter);
		ShowSettingsHints(borderDelimiter + 2, 1);
		Render();
		button = ReadKey();
		switch (button) {
		case 224:
			switch (ReadKey()) {
			case 72:
				k = (k - 1 + n) % n;
				break;
			case 75:
				switch (k) {
				case 0:
					if (fontSize + dfontSize > minFontSize) dfontSize--;
					break;
				case 1:
					if (mapVisY + dmapVisY > minMapVisY) dmapVisY--;
					break;
				default:
					break;
				}
				break;
			case 77:
				switch (k) {
				case 0:
					if (fontSize + dfontSize < maxFontSize) dfontSize++;
					break;
				case 1:
					if (mapVisY + dmapVisY < maxMapVisY) dmapVisY++;
					break;
				default:
					break;
				}
				break;
			case 80:
				k = (k + 1 + n) % n;
				break;
			default:
				break;
			}
			break;
		case 13:
			fontSize += dfontSize;
			mapVisY += dmapVisY;
			mapVisX = mapVisY * 2;
			windowX = mapVisX + 32;
			windowY = mapVisY + 1;
			borderDelimiter = mapVisX + 1;
			SetWindow(windowX, windowY, fontSize);
			dfontSize = 0;
			dmapVisY = 0;
			CreateSaveDir(sSavePath);
			SaveSettings(fontSize, mapVisY);
			break;
		case 32:
			dfontSize = 0;
			dmapVisY = 0;
			break;
		default:
			break;
		}
	}
};
