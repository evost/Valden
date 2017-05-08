#include "NPC.h"
#include "game.h"

NPC::NPC(int k, GameMap &dMap, int heroLevel) {
	bool isFree;
	NPCs.clear();
	NPCk = k;
	for (int i = 0; i < k; i++) {
		int l1 = heroLevel - 2, l2 = heroLevel - 1, l3 = heroLevel;
		if (l1 < 0) l1 = 0;
		if (l2 > NPCTypesNum - 1) l2 = NPCTypesNum - 1;
		if (l3 > NPCTypesNum - 1) l3 = NPCTypesNum - 1;
		int random = rand() % 100;
		if (random < 50)
			NPCs[i] = NPC_types[l1];
		else if (random < 83)
			NPCs[i] = NPC_types[l2];
		else
			NPCs[i] = NPC_types[l3];
		do {
			NPCs[i].x = rand() % (dMap.Width - 4) + 2;
			NPCs[i].y = rand() % (dMap.Height - 4) + 2;
			isFree = true;
			for (int k = 0; k < i; k++)
				if (NPCs[k].x == NPCs[i].x && NPCs[k].y == NPCs[i].y)
					isFree = false;
		} while (!dMap.IsFree(NPCs[i].x, NPCs[i].y) || !isFree);
	}
}

void NPC::GetNPCs(GameMap &dMap, Hero &dHero) {
	for (int i = 0; i < NPCk; i++)
		if (NPCs[i].hp > 0 && NPCs[i].x >= dMap.curX && NPCs[i].x <= dMap.curX + mapVisX - 1 && NPCs[i].y >= dMap.curY && NPCs[i].y <= dMap.curY + mapVisY - 1 && Distance(NPCs[i].x, NPCs[i].y, dHero.x, dHero.y) <= dHero.visDistance)
			SetSymbol((short)(NPCs[i].x + 1 - dMap.curX), (short)(NPCs[i].y + 1 - dMap.curY), NPC_tiles[NPCs[i].type].cell, Black, NPC_tiles[NPCs[i].type].color);

}

bool NPC::NoNPCs(short x, short y) {
	for (int i = 0; i < NPCk; i++)
		if (NPCs[i].x == x && NPCs[i].y == y && NPCs[i].hp > 0) return false;
	return true;
}

void NPC::NPCstep(GameMap &dMap, Hero &dHero) {
	for (int i = 0; i < NPCk; i++)
		if (NPCs[i].hp > 0 && dHero.hp > 0) {
			if (abs(NPCs[i].x - dHero.x) + abs(NPCs[i].y - dHero.y) == 1) {
				if (rand() % 100 >= dHero.dexterity) {
					if (NPCs[i].strength - dHero.GetDefense() > 0) {
						AddLog(sMonsters[NPCs[i].type] + sDamageToHero1 + to_wstring(NPCs[i].strength - dHero.GetDefense()) + sDamageToHero2);
						dHero.hp -= NPCs[i].strength - dHero.GetDefense();
					}
					else
						AddLog(sMonsters[NPCs[i].type] + sNoDamage);
					if (dHero.hp <= 0) {
						dHero.hp = 0;
						AddLog(sDeath);
					}
				}
				else
					AddLog(sHeroDodged + sMonsters[NPCs[i].type]);
			}
			else
				if (Distance(NPCs[i].x, NPCs[i].y, dHero.x, dHero.y) <= NPCs[i].visDist && (abs(NPCs[i].x - dHero.x) + abs(NPCs[i].y - dHero.y) > 1))
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
			}
			else
				AddLog(sMonsters[NPCs[i].type] + sDodged);
		}
	return 0;
}
