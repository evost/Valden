#pragma once

#include "io.h"
#include "strings.h"
#include "constants.h"
#include "Map.h"
#include "Hero.h"
#include "NPC.h"

static wstring gameLog[logSize];
static short logPosition = 0;

void AddLog(wstring s);
void ShowGameHints(short x, short y);
void ShowInventoryHints(short x, short y);
void ShowCharacteristicsHints(short x, short y);
void RenderWorld(Map dMap, Hero dHero, NPC dNPC, bool hint);
void NewGame(Map &dMap, Hero &dHero, NPC dNPC);
void Game(Map &dMap, Hero dHero, NPC dNPC, bool &showHints);
int Menu(bool inGame);
