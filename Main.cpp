#include "io.h"
#include "Map.h"
#include "Hero.h"
#include "NPC.h"

void RenderWorld(Map dMap, Hero dHero, NPC dNPC) {
	dNPC.GetNPCs(dMap);
	dHero.GetHero(dMap);
	dHero.ShowInfo(35, 1);
}

int main() {
	Init(60, 18, "Valden");
	Map VMap(64, 32, 32, 16);
	Hero VHero(VMap);
	NPC VNPC(16, VMap);
	Border(58, 17, 33);
	VMap.GetMap();
	RenderWorld(VMap, VHero, VNPC);
	short button;
	while (true) {
		button = ReadKey();
		Clear(35, 9, 57, 11);
		switch (button) {
		case 224:
			switch (ReadKey()) {
			case 72:
				if (VNPC.NoNPCs(VHero.x, VHero.y - 1)) VHero.HeroStep(0, -1, VMap);
				break;
			case 75:
				if (VNPC.NoNPCs(VHero.x - 1, VHero.y)) VHero.HeroStep(-1, 0, VMap);
				break;
			case 77:
				if (VNPC.NoNPCs(VHero.x + 1, VHero.y)) VHero.HeroStep(1, 0, VMap);
				break;
			case 80:
				if (VNPC.NoNPCs(VHero.x, VHero.y + 1)) VHero.HeroStep(0, 1, VMap);
				break;
			default:
				break;
			}
			VNPC.NPCstep(VMap, VHero);
			break;
		case 27:
			return 0;
		default:
			if (button == 73 || button == 105 || button == 152 || button == 232) {
				VHero.ShowInventory(58, 17);
				Border(58, 17, 33);
				VMap.GetMap();
			}
			else {
				if (button == 87 || button == 119 || button == 150 || button == 130) {
					VHero.ExpInc(VNPC.HeroAttack(VHero.x, VHero.y - 1, VHero.GetDamage()));
					VMap.GetTile(VHero.x, VHero.y - 1);
				}
				else if (button == 68 || button == 100 || button == 130 || button == 162) {
					VHero.ExpInc(VNPC.HeroAttack(VHero.x + 1, VHero.y, VHero.GetDamage()));
					VMap.GetTile(VHero.x + 1, VHero.y);
				}
				else if (button == 83 || button == 115 || button == 155 || button == 235) {
					VHero.ExpInc(VNPC.HeroAttack(VHero.x, VHero.y + 1, VHero.GetDamage()));
					VMap.GetTile(VHero.x, VHero.y + 1);
				}
				else if (button == 65 || button == 97 || button == 148 || button == 228) {
					VHero.ExpInc(VNPC.HeroAttack(VHero.x - 1, VHero.y, VHero.GetDamage()));
					VMap.GetTile(VHero.x - 1, VHero.y);
				}
				VNPC.NPCstep(VMap, VHero);
			}
			break;
		}
		RenderWorld(VMap, VHero, VNPC);
	}
	return 0;
}