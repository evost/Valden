#pragma once

#include "constants.h"
#include "utility.h"

static wstring gameLog[logSize];
static short logPosition = 0;

void AddLog(wstring s);
void NewHero(Hero &dHero);
void NewMap(Map &dMap, Hero &dHero, NPC &dNPC);
void Game(Map &dMap, Hero &dHero, NPC &dNPC, bool &showHints);
int Menu(bool inGame, bool newVersion, wstring versionNum);
void Settings();
