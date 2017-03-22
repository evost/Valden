#pragma once

#include "io.h"
#include "strings.h"
#include "constants.h"
#include "Map.h"
#include "Hero.h"
#include "NPC.h"

void ShowGameHints(short x, short y);
void ShowInventoryHints(short x, short y);
void ShowCharacteristicsHints(short x, short y);
void RenderWorld(Map dMap, Hero dHero, NPC dNPC, bool hint);