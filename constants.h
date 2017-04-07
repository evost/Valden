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
const int XP_table[maxLevel] = { 10, 20, 30, 70, 100, 170, 270, 440, 710, 1000 };
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

const int grassD = 0;
const int grassL = 1;
const int grassB = 2;
const int sandD = 3;
const int sandL = 4;
const int sandB = 5;
const int treeD = 6;
const int treeL = 7;
const int treeB = 8;
const int rockD = 9;
const int rockL = 10;
const int rockW = 11;
const int water = 12;

const int bat = 0;
const int goblin = 1;

const int weapon = 0;
const int armor = 1;

const TTile Tiles[13] = {  { 0, Green, ',' }, { 1, LightGreen, ',' }, { 2, Brown, ',' }, { 3, Green, '.' },  { 4, LightGreen, '.' }, { 5, Green, '.' }, { 6, Green, '!' }, { 7, LightGreen, '!' }, { 8, Brown, '!' }, { 9, DarkGray, 'o' }, { 10, LightGray, 'o' }, { 11, White, 'o' } , { 12, Blue, '~' } };
const TTile NPC_tiles[2] = { { 0, Brown, '^' },{ 1, Yellow, 'g' } };
const TNPC NPC_types[2] = { { 0, 3, 2, 1, 5, 3, 1, 3, 0, 0 },{ 1, 5, 3, 3, 7, 5, 2, 4, 0, 0 } };

const TItem sword1 = { 0, 2, 0, 0, 0, 0, 0 , 0 };
const TItem spear1 = { 0, 4, 0, 0, 0, 0, 0 , 1 };
const TItem sword2 = { 0, 8, 0, 0, 0, 0, 0 , 2 };

const TItem armor1 = { 1, 0, 1, 0, 0, 0, 0 , 3 };
const TItem armor2 = { 1, 0, 2, 0, 0, 0, 0 , 4 };
const TItem armor3 = { 1, 0, 4, 0, 0, 0, 0 , 5 };
