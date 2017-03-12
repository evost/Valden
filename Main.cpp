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
				RenderWorld(VMap, VHero, VNPC);
			}
			break;
	}
	return 0;
}