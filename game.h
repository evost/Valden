#pragma once

#include "constants.h"
#include "utility.h"

extern wstring gameLog[logSize];
extern short logPosition;

void AddLog(wstring s);
void NewHero(Hero &dHero);
void NewMap(Map &dMap, Hero &dHero, NPC &dNPC);
void Game(Map &dMap, Hero &dHero, NPC &dNPC, bool &showHints);
int Menu(bool inGame, bool newVersion, wstring versionNum);
void Settings();
