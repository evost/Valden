#include "io.h"
#include "Map.h"

int main()
{
	Init({ 60, 18 }, "Valden");
	Map VMap(64, 32, 16, 16);
	VMap.GetMap();
	return 0;
}