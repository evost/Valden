#pragma once

#include "constants.h"
#include "utility.h"

extern wstring gameLog[logSize];
extern short logPosition;
void AddLog(wstring s);
void NewHero(Hero &dHero);
void NewMap(GameMap &dMap, int width, int height, Hero &dHero, NPC &dNPC, int NPCk);
void Game(GameMap &dMap, Hero &dHero, NPC &dNPC, bool &showHints);
int Menu(bool inGame, bool newVersion, wstring versionNum);
void Settings();
