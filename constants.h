#pragma once

#include "structs.h"

const int minMapVisY = 31;
const int maxMapVisY = 60;
const int minFontSize = 8;
const int maxFontSize = 64;
extern short mapVisY;
extern short mapVisX;
extern short windowX;
extern short windowY;
extern short borderDelimiter;
extern short fontSize;
const int invSize = 20;
const int startSkill = 5;
const int startSkillRandom = 5;
const int startHp = 10;
const int heroStartVisDistance = 0;
const int raceCount = 3;
const short scrollDist = 8;
const int maxLevel = 10;
const int XP_table[maxLevel] = { 11, 28, 50, 78, 112, 152, 198, 251, 310, 375 };
const int characteristicsNumber = 3;
const int newLevelPoints = characteristicsNumber;
const int logSize = 16;
const int logoSize = 5;
const int historySize = 24;
const int copyrightSize = 2;
const short Black = 0;
const short Blue = 1;
const short Green = 2;
const short Cyan = 3;
const short Red = 4;
const short Magenta = 5;
const short Brown = 6;
const short LightGray = 7;
const short DarkGray = 8;
const short LightBlue = 9;
const short LightGreen = 10;
const short LightCyan = 11;
const short LightRed = 12;
const short LightMagenta = 13;
const short Yellow = 14;
const short White = 15;
const int NPCTypesNum = 10;
const int rat = 0;
const int vepr = 1;
const int wolf = 2;
const int goblin = 3;
const int gnoll = 4;
const int bear = 5;
const int Ork = 6;
const int Troll = 7;
const int Werewolf = 8;
const int Ogr = 9;
const TTile NPC_tiles[NPCTypesNum] = {
	{ 0, DarkGray, '^' },
	{ 1, Brown, 'm' },
	{ 2, White, 'w' },
	{ 3, Yellow, 'g' },
	{ 4, Brown, 'n' },
	{ 5, Brown, 'M' },
	{ 6, Yellow, 'c' },
	{ 7, Yellow, '&' },
	{ 8, LightGray, 'W' },
	{ 9, Yellow, 'G' }
};
const TNPC NPC_types[NPCTypesNum] = {
	{ 0, 4,  2, 2, 5, 4,  1, 3, 0, 0 },
	{ 1, 8,  3, 4, 3, 8,  2, 3, 0, 0 },
	{ 2, 16, 4, 5, 5, 16, 3, 3, 0, 0 },
	{ 3, 20, 5, 7, 5, 20, 4, 4, 0, 0 },
	{ 4, 24, 6, 10, 4, 24, 5, 4, 0, 0 },
	{ 5, 28, 7, 12, 2, 28, 6, 4, 0, 0 },
	{ 6, 32, 8, 15, 6, 32, 7, 5, 0, 0 },
	{ 7, 36, 9, 19, 3, 36, 8, 5, 0, 0 },
	{ 8, 40, 10, 22, 7, 40, 9, 5, 0, 0 },
	{ 9, 44, 11, 26, 2, 44, 10, 6, 0, 0 }
};
const int tilesNum = 19;
const int grassD = 0;
const int grassL = 1;
const int grassB = 2;
const int sandD = 3;
const int sandL = 4;
const int sandB = 5;
const int trapGrassD = 6;
const int trapGrassL = 7;
const int trapGrassB = 8;
const int trapKnown = 9;
const int trapUsed = 10;
const int waterL = 11;
const int treeD = 12;
const int treeL = 13;
const int treeB = 14;
const int rockD = 15;
const int rockL = 16;
const int rockW = 17;
const int waterD = 18;
const int minTrap = trapGrassD;
const double trapHPpc = 0.15;
const double trapDisarmpc = 0.5;
const TTile Tiles[tilesNum] = {
	{ 0, Green, ',' },
	{ 1, LightGreen, ',' },
	{ 2, Brown, ',' },
	{ 3, Green, '.' },
	{ 4, LightGreen, '.' },
	{ 5, Brown, '.' },
	{ 6, Green, ',' },
	{ 7, LightGreen, ',' },
	{ 8, Brown, ',' },
	{ 9, Red, '_' },
	{ 10, Brown, '_' },
	{ 11, LightBlue, '~' },
	{ 12, Green, '!' },
	{ 13, LightGreen, '!' },
	{ 14, Brown, '!' },
	{ 15, DarkGray, 'o' },
	{ 16, LightGray, 'o' },
	{ 17, White, 'o' },
	{ 18, Blue, '~' }
};
const int itemsNum = 20;
const int blank = -1;
const int weapon = 0;
const int armor = 1;
const int poultice = 2;
const TItem Items[itemsNum] = {
	{ 0, 2, 0, 0, 0, 0, 0, 0 }, { 1, 0, 1, 0, 0, 0, 0, 1 },
	{ 0, 4, 0, 0, 0, 0, 0, 2 }, { 1, 0, 2, 0, 0, 0, 0, 3 },
	{ 0, 8, 0, 0, 0, 0, 0, 4 }, { 1, 0, 3, 0, 0, 0, 0, 5 },
	{ 0, 10, 0, 0, 0, 0, 0, 6 }, { 1, 0, 5, 0, 0, 0, 0, 7 },
	{ 0, 12, 0, 0, 0, 0, 0, 8 }, { 1, 0, 7, 0, 0, 0, 0, 9 },
	{ 0, 14, 0, 0, 0, 0, 0, 10 }, { 1, 0, 9, 0, 0, 0, 0, 11 },
	{ 0, 16, 0, 0, 0, 0, 0, 12 }, { 1, 0, 12, 0, 0, 0, 0, 13 },
	{ 0, 18, 0, 0, 0, 0, 0, 14 }, { 1, 0, 15, 0, 0, 0, 0, 15 },
	{ 0, 20, 0, 0, 0, 0, 0, 16 }, { 1, 0, 18, 0, 0, 0, 0, 17 },
	{ 0, 22, 0, 0, 0, 0, 0, 18 }, { 1, 0, 22, 0, 0, 0, 0, 19 }
};
const int poulticeNum = 3;
const TItem poultices[poulticeNum] = {
	{ 2, 0, 0, 0, 0, 0, 15, 20 },
	{ 2, 0, 0, 0, 0, 0, 20, 21 },
	{ 2, 0, 0, 0, 0, 0, 25, 22 }
};
const TItem blankItem = { -1, 0, 0, 0, 0, 0, 0, 0 };
