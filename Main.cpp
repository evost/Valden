#include "io.h"
#include "Map.h"
#include "Hero.h"
#include "NPC.h"
#include "constants.h"

#include "game.h"

int main() {
	Init(windowX + 1, windowY + 1, "Valden");
	Map VMap(64, 32, mapVisX, mapVisY);
	Hero VHero(VMap);
	NPC VNPC(16, VMap);
	Border(windowX, windowY, borderDelimiter);
	VMap.GetMap();
	bool showHints = false;
	RenderWorld(VMap, VHero, VNPC, showHints);
	short button = 0;
	while (button != 27) {
		button = ReadKey();
		Clear(borderDelimiter + 2, 9, windowX - 1, 11);
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
		case 9:
			showHints = !showHints;
			break;
		default:
			if (button == 73 || button == 105 || button == 152 || button == 232) {
				VHero.ShowInventory(windowX, windowY);
				Border(windowX, windowY, borderDelimiter);
				VMap.GetMap();
			} else if (button == 67 || button == 99 || button == 145 || button == 225) {
				VHero.ShowCharacteristics();
				Border(windowX, windowY, borderDelimiter);
				VMap.GetMap();
			} else {
				if (button == 87 || button == 119 || button == 150 || button == 230) {
					VHero.ExpInc(VNPC.HeroAttack(VHero.x, VHero.y - 1, VHero.GetDamage()));
					VMap.GetTile(VHero.x, VHero.y - 1);
				} else if (button == 68 || button == 100 || button == 130 || button == 162) {
					VHero.ExpInc(VNPC.HeroAttack(VHero.x + 1, VHero.y, VHero.GetDamage()));
					VMap.GetTile(VHero.x + 1, VHero.y);
				} else if (button == 83 || button == 115 || button == 155 || button == 235) {
					VHero.ExpInc(VNPC.HeroAttack(VHero.x, VHero.y + 1, VHero.GetDamage()));
					VMap.GetTile(VHero.x, VHero.y + 1);
				} else if (button == 65 || button == 97 || button == 148 || button == 228) {
					VHero.ExpInc(VNPC.HeroAttack(VHero.x - 1, VHero.y, VHero.GetDamage()));
					VMap.GetTile(VHero.x - 1, VHero.y);
				}
				VNPC.NPCstep(VMap, VHero);
			}
			break;
		}
		RenderWorld(VMap, VHero, VNPC, showHints);
	}
	return 0;
}
