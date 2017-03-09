#include "io.h"
#include "Map.h"
#include "Hero.h"
#include "NPC.h"

void RenderWorld(Map dMap, Hero dHero, NPC dNPC) {
	Border(58, 17, 33);
	dMap.GetMap();
	dNPC.GetNPCs(dMap);
	dHero.GetHero(dMap);
	dHero.ShowInfo(35, 1);
}

int main() {
	Init(60, 18, "Valden");
	Map VMap(64, 32, 32, 16);
	Hero VHero(VMap);
	NPC VNPC(32, VMap);
	RenderWorld(VMap, VHero, VNPC);
	while (true) {
		switch (ReadKey()) {
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
			RenderWorld(VMap, VHero, VNPC);
			break;
		case 27:
			return 0;
		default:
			break;
		}
	}
	return 0;
}