#pragma once

#include <fstream>
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
#include "io.h"
#include "GameMap.h"
#include "NPC.h"

using namespace std;

void SetString(short x, short y, wstring s, short background, short text);
void Randomize(int sid);
void Border(short x, short y, short x0);
wstring FloatToWstring(float k);
wstring Version(wstring url);
bool SaveExist(wstring path);
void CreateSaveDir(wstring path);
void SaveHero(Hero &dHero);
void LoadHero(Hero &dHero);
void SaveNPC(NPC &dNPC);
void LoadNPC(NPC &dNPC, GameMap &dMap);
void SaveMap(GameMap &dMap);
void LoadMap(GameMap &dMap);
void SaveSettings(short &fontSize, short &mapVisY);
void LoadSettings(short &fontSize, short &mapVisY);
float Distance(int x1, int y1, int x2, int y2);
