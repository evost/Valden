#pragma once

#include "structs.h"

const int windowX = 58;
const int windowY = 17;
const int borderDelimiter = 33;
const int mapVisX = 32;
const int mapVisY = 16;

const int invSize = 9;
const int startSkill = 5;
const int startSkillRandom = 5;
const int startHp = 10;

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

const int tree = 1;
const int rock = 2;
const int grass = 0;

const int bat = 0;
const int goblin = 1;

const int weapon = 0;
const int armor = 1;

const short scrollDist = 3;
const int maxLevel = 10;
const int XP_table[maxLevel] = { 10, 20, 30, 70, 100, 170, 270, 440, 710, 1000};

const TItem sword1 = { 0, 2, 0, 0, 0, 0, 0 , 1 };
const TItem spear1 = { 0, 4, 0, 0, 0, 0, 0 , 2 };
const TItem sword2 = { 0, 8, 0, 0, 0, 0, 0 , 3 };

const TItem armor1 = { 1, 0, 1, 0, 0, 0, 0 , 4 };
const TItem armor2 = { 1, 0, 2, 0, 0, 0, 0 , 5 };
const TItem armor3 = { 1, 0, 4, 0, 0, 0, 0 , 6 };