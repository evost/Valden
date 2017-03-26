#include "Map.h"
#include "io.h"

Map::Map(int width, int height) {
	curX = 0;
	curY = 0;
	MainMap = (TTile**)malloc(width * height * sizeof(TTile));
	if (width - 1 < mapVisX)
		Width = mapVisX;
	else
		Width = width - 1;
	if (height - 1 < mapVisY)
		Height = mapVisY;
	else
		Height = height - 1;
	for (int x = 0; x <= Width; x++)
		MainMap[x] = new TTile[Height + 1];
	for (int x = 0; x <= Width; x++)
		for (int y = 0; y <= Height; y++) {
			int chance = rand() % 100 + 1;
			if (chance > 75)
				if (chance > 90)
					MainMap[x][y] = Tiles[rock];
				else
					MainMap[x][y] = Tiles[tree];
			else
				MainMap[x][y] = Tiles[grass];
		}
}

void Map::GetMap() {
	for (int x = curX; x < curX + mapVisX; x++)
		for (int y = curY; y < curY + mapVisY; y++)
			SetSymbol((short)(x - curX + 1), (short)(y - curY + 1), MainMap[x][y].cell, Black, MainMap[x][y].color);
}

bool Map::IsFree(int x, int y) {
	return !MainMap[x][y].type;
}
