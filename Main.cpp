#include "io.h"
#include "Map.h"
#include "Hero.h"

int main()
{
	Init({ 60, 18 }, "Valden");
	Map VMap(64, 32, 16, 16);
	Hero VHero(VMap);
	VMap.GetMap();
	VHero.GetHero(VMap);
	VHero.ShowInfo(34, 1);
	return 0;
}