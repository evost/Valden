#include "io.h"
#include "Map.h"
#include "Hero.h"
#include "NPC.h"
#include "constants.h"
#include "game.h"

int main() {
	Init(windowX, windowY, sWindowName);
	Map VMap(128, 64);
	Hero VHero(VMap);
	NPC VNPC(64, VMap);
	bool showHints = false;
	short button = 0;
	while (button != 27) {
		RenderWorld(VMap, VHero, VNPC, showHints);
		Render();
		button = ReadKey();
		if (VHero.hp > 0)
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
			case 32:
				VNPC.NPCstep(VMap, VHero);
				break;
			default:
				if (button == 73 || button == 105 || button == 152 || button == 232)
					VHero.ShowInventory(windowX, windowY);
				else if (button == 67 || button == 99 || button == 145 || button == 225)
					VHero.ShowCharacteristics();
				else {
					if (button == 87 || button == 119 || button == 150 || button == 230)
						VHero.ExpInc(VNPC.HeroAttack(VHero.x, VHero.y - 1, VHero.GetDamage()));
					else if (button == 68 || button == 100 || button == 130 || button == 162)
						VHero.ExpInc(VNPC.HeroAttack(VHero.x + 1, VHero.y, VHero.GetDamage()));
					else if (button == 83 || button == 115 || button == 155 || button == 235)
						VHero.ExpInc(VNPC.HeroAttack(VHero.x, VHero.y + 1, VHero.GetDamage()));
					else if (button == 65 || button == 97 || button == 148 || button == 228)
						VHero.ExpInc(VNPC.HeroAttack(VHero.x - 1, VHero.y, VHero.GetDamage()));
					VNPC.NPCstep(VMap, VHero);
				}
				break;
			}
	}
	return 0;
}
