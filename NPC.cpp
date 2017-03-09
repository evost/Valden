#include "NPC.h"
#include "io.h"
#include "Map.h"

NPC::NPC(int k, Map dMap) {
	NPCs = (TNPC*)malloc(k*sizeof(TNPC));
	NPCk = k;
	for (int i = 0; i < k; i++) {
		NPCs[i] = NPC_types[rand() % 2];
		do {
			NPCs[i].x = rand() % (dMap.Width - 4) + 2;
			NPCs[i].y = rand() % (dMap.Height - 4) + 2;
		} while (!dMap.IsFree(NPCs[i].x, NPCs[i].y));
	}
}

void NPC::GetNPCs(Map dMap) {
	for (int i = 0; i < NPCk; i++)
		if (NPCs[i].hp > 0 && NPCs[i].x >= dMap.curX && NPCs[i].x <= dMap.curX + dMap.visX - 1 && NPCs[i].y >= dMap.curY && NPCs[i].y <= dMap.curY + dMap.visY - 1) {
			SetColor(Black, NPC_tiles[NPCs[i].type].color);
			SetSymbol((short)(NPCs[i].x + 1 - dMap.curX), (short)(NPCs[i].y + 1 - dMap.curY), NPC_tiles[NPCs[i].type].cell);
		}
}

bool NPC::NoNPCs(short x, short y) {
	for (int i = 0; i < NPCk; i++)
		if (NPCs[i].x == x && NPCs[i].y == y) return false;
	return true;
};

void NPC::NPCstep(Map dMap, Hero &dHero) {
	for (int i = 0; i < NPCk; i++)
		if (sqrt(pow(abs(NPCs[i].x - dHero.x), 2) + pow(abs(NPCs[i].y - dHero.y), 2)) <= NPCs[i].visDist && (abs(NPCs[i].x - dHero.x)+abs(NPCs[i].y - dHero.y) > 1))
			if (NPCs[i].x < dHero.x && dMap.IsFree(NPCs[i].x + 1, NPCs[i].y) && NoNPCs(NPCs[i].x + 1, NPCs[i].y)) {
				dMap.GetTile(NPCs[i].x, NPCs[i].y);
				NPCs[i].x++;
			}
			else if (NPCs[i].x > dHero.x && dMap.IsFree(NPCs[i].x - 1, NPCs[i].y) && NoNPCs(NPCs[i].x - 1, NPCs[i].y)) {
				dMap.GetTile(NPCs[i].x, NPCs[i].y);
				NPCs[i].x--;
			}
			else if (NPCs[i].y < dHero.y && dMap.IsFree(NPCs[i].x, NPCs[i].y + 1) && NoNPCs(NPCs[i].x, NPCs[i].y + 1)) {
				dMap.GetTile(NPCs[i].x, NPCs[i].y);
				NPCs[i].y++;
			}
			else if (NPCs[i].y > dHero.y && dMap.IsFree(NPCs[i].x, NPCs[i].y - 1) && NoNPCs(NPCs[i].x, NPCs[i].y - 1)) {
				dMap.GetTile(NPCs[i].x, NPCs[i].y);
				NPCs[i].y--;
			}
};