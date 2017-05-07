#include "constants.h"

int minMapVisY = 31;
int maxMapVisY = 60;
int minFontSize = 8;
int maxFontSize = 36;
short mapVisY = minMapVisY;
short mapVisX = mapVisY * 2;
short windowX = mapVisX + 32;
short windowY = mapVisY + 1;
short borderDelimiter = mapVisX + 1;
short fontSize = 16;
int invSize = 16;
int startSkill = 5;
int startSkillRandom = 5;
int startHp = 10;
int heroStartVisDistance = 0;
int raceCount = 3;
short scrollDist = 8;
int XP_table[maxLevel] = { 11, 28, 50, 78, 112, 152, 198, 251, 310, 375 };
int characteristicsNumber = 3;
int newLevelPoints = characteristicsNumber;
int copyrightSize = 2;
int keyLength = 6;
short Black = 0;
short Blue = 1;
short Green = 2;
short Cyan = 3;
short Red = 4;
short Magenta = 5;
short Brown = 6;
short LightGray = 7;
short DarkGray = 8;
short LightBlue = 9;
short LightGreen = 10;
short LightCyan = 11;
short LightRed = 12;
short LightMagenta = 13;
short Yellow = 14;
short White = 15;
int rat = 0;
int vepr = 1;
int wolf = 2;
int goblin = 3;
int gnoll = 4;
int bear = 5;
int Ork = 6;
int Troll = 7;
int Werewolf = 8;
int Ogr = 9;
TTile NPC_tiles[NPCTypesNum] = {
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
TNPC NPC_types[NPCTypesNum] = {
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
int grassD = 0;
int grassL = 1;
int grassB = 2;
int sandD = 3;
int sandL = 4;
int sandB = 5;
int trapGrassD = 6;
int trapGrassL = 7;
int trapGrassB = 8;
int trapKnown = 9;
int trapUsed = 10;
int waterL = 11;
int treeD = 12;
int treeL = 13;
int treeB = 14;
int rockD = 15;
int rockL = 16;
int rockW = 17;
int waterD = 18;
int minTrap = trapGrassD;
float trapHPpc = 0.15f;
float trapDisarmpc = 0.5f;
TTile Tiles[tilesNum] = {
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
TItem Items[itemsNum] = {
	{ 0, 2, 0, 0, 0, 0, 0, 1, 1 }, { 1, 0, 1, 0, 0, 0, 0, 1, 2 },
	{ 0, 4, 0, 0, 0, 0, 0, 2, 3 }, { 1, 0, 2, 0, 0, 0, 0, 2, 4 },
	{ 0, 8, 0, 0, 0, 0, 0, 3, 5 }, { 1, 0, 3, 0, 0, 0, 0, 3, 6 },
	{ 0, 10, 0, 0, 0, 0, 0, 4, 7 }, { 1, 0, 5, 0, 0, 0, 0, 4, 8 },
	{ 0, 12, 0, 0, 0, 0, 0, 5, 9 }, { 1, 0, 7, 0, 0, 0, 0, 5, 10 },
	{ 0, 14, 0, 0, 0, 0, 0, 6, 11 }, { 1, 0, 9, 0, 0, 0, 0, 6, 12 },
	{ 0, 16, 0, 0, 0, 0, 0, 7, 13 }, { 1, 0, 12, 0, 0, 0, 0, 7, 14 },
	{ 0, 18, 0, 0, 0, 0, 0, 8, 15 }, { 1, 0, 15, 0, 0, 0, 0, 8, 16 },
	{ 0, 20, 0, 0, 0, 0, 0, 9, 17 }, { 1, 0, 18, 0, 0, 0, 0, 9, 18 },
	{ 0, 22, 0, 0, 0, 0, 0, 10, 19 }, { 1, 0, 22, 0, 0, 0, 0, 10, 20 }
};
TItem poultices[poulticeNum] = {
	{ 2, 0, 0, 0, 0, 0, 15, 1, 21 },
	{ 2, 0, 0, 0, 0, 0, 20, 1, 22 },
	{ 2, 0, 0, 0, 0, 0, 25, 1, 23 }
};
TItem blankItem = { -1, 0, 0, 0, 0, 0, 0, 0 };
int spawnArea = 3;
