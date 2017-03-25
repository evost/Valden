#include "NPC.h"
#include "io.h"
#include "Map.h"
#include "strings.h"
#include "game.h"

NPC::NPC(int k, Map dMap) {
	NPCs = (TNPC*)malloc(k * sizeof(TNPC));
	NPCk = k;
	for (int i = 0; i < k; i++) {
		if (rand() % 100 < 70)
			NPCs[i] = NPC_types[bat];
		else
			NPCs[i] = NPC_types[goblin];
		do {
			NPCs[i].x = rand() % (dMap.Width - 4) + 2;
			NPCs[i].y = rand() % (dMap.Height - 4) + 2;
		} while (!dMap.IsFree(NPCs[i].x, NPCs[i].y));
	}
}

void NPC::GetNPCs(Map dMap) {
	for (int i = 0; i < NPCk; i++)
		if (NPCs[i].hp > 0 && NPCs[i].x >= dMap.curX && NPCs[i].x <= dMap.curX + mapVisX - 1 && NPCs[i].y >= dMap.curY && NPCs[i].y <= dMap.curY + mapVisY - 1) {
			SetSymbol((short)(NPCs[i].x + 1 - dMap.curX), (short)(NPCs[i].y + 1 - dMap.curY), NPC_tiles[NPCs[i].type].cell, Black, NPC_tiles[NPCs[i].type].color);
		}
}

bool NPC::NoNPCs(short x, short y) {
	for (int i = 0; i < NPCk; i++)
		if (NPCs[i].x == x && NPCs[i].y == y && NPCs[i].hp > 0) return false;
	return true;
}

void NPC::NPCstep(Map dMap, Hero &dHero) {
	for (int i = 0; i < NPCk; i++)
		if (NPCs[i].hp > 0) {
			if (abs(NPCs[i].x - dHero.x) + abs(NPCs[i].y - dHero.y) == 1) {
				if (rand() % 100 >= dHero.dexterity) {
					if (NPCs[i].strength - dHero.GetDefense() > 0) {
						AddLog(sMonsters[NPCs[i].type] + sDamageToHero1 + to_wstring(NPCs[i].strength - dHero.GetDefense()) + sDamageToHero2);
						dHero.hp -= NPCs[i].strength - dHero.GetDefense();
					} else 
						AddLog(sMonsters[NPCs[i].type] + sNoDamage);
					if (dHero.hp <= 0) dHero.Death();
				} else
					AddLog(sHeroDodged + sMonsters[NPCs[i].type]);
			} else
				if (sqrt(pow(abs(NPCs[i].x - dHero.x), 2) + pow(abs(NPCs[i].y - dHero.y), 2)) <= NPCs[i].visDist && (abs(NPCs[i].x - dHero.x) + abs(NPCs[i].y - dHero.y) > 1))
					if (NPCs[i].x < dHero.x && dMap.IsFree(NPCs[i].x + 1, NPCs[i].y) && NoNPCs(NPCs[i].x + 1, NPCs[i].y))
						NPCs[i].x++;
					else if (NPCs[i].x > dHero.x && dMap.IsFree(NPCs[i].x - 1, NPCs[i].y) && NoNPCs(NPCs[i].x - 1, NPCs[i].y))
						NPCs[i].x--;
					else if (NPCs[i].y < dHero.y && dMap.IsFree(NPCs[i].x, NPCs[i].y + 1) && NoNPCs(NPCs[i].x, NPCs[i].y + 1))
						NPCs[i].y++;
					else if (NPCs[i].y > dHero.y && dMap.IsFree(NPCs[i].x, NPCs[i].y - 1) && NoNPCs(NPCs[i].x, NPCs[i].y - 1))
						NPCs[i].y--;
		}
}

int NPC::HeroAttack(int x, int y, int damage) {
	for (int i = 0; i < NPCk; i++)
		if (NPCs[i].x == x && NPCs[i].y == y && NPCs[i].hp > 0) {
			if (rand() % 100 >= NPCs[i].dexterity) {
				NPCs[i].hp -= damage;
				if (NPCs[i].hp > 0)
					AddLog(sDamageToEnemy + to_wstring(damage));
				else {
					AddLog(sMonsters[NPCs[i].type] + sKilling);
					return NPCs[i].dxp;
				}
			} else
				AddLog(sMonsters[NPCs[i].type] + sDodged);
		}
	return 0;
}
