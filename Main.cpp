#include "io.h"
#include "Map.h"
#include "Hero.h"

void RenderWorld(Map dMap, Hero dHero) {
	dMap.GetMap();
	dHero.GetHero(dMap);
	dHero.ShowInfo(34, 1);
}

int main() {
	Init(60, 18, "Valden");
	Map VMap(64, 32, 16, 16);
	Hero VHero(VMap);
	RenderWorld(VMap, VHero);
	while (true) {
		switch (ReadKey()) {
		case 224:
			switch (ReadKey()) {
			case 72:
				VHero.HeroStep(0, -1, VMap);
				break;
			case 75:
				VHero.HeroStep(-1, 0, VMap);
				break;
			case 77:
				VHero.HeroStep(1, 0, VMap);
				break;
			case 80:
				VHero.HeroStep(0, 1, VMap);
				break;
			default:
				break;
			}
			RenderWorld(VMap, VHero);
			break;
		case 27:
			return 0;
		default:
			break;
		}
	}
	return 0;
}