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
	for (int x = 0; x <= Width; x++) {
		MainMap[x] = new TTile[height];
		for (int y = 0; y <= Height; y++) {
			MainMap[x][y].isVisible = false;
			int chance = rand() % 100 + 1;
			if (chance <= 13)
				MainMap[x][y] = Tiles[grassD];
			else if (chance <= 26)
				MainMap[x][y] = Tiles[grassB];
			else if (chance <= 38)
				MainMap[x][y] = Tiles[grassL];
			else if (chance <= 51)
				MainMap[x][y] = Tiles[sandD];
			else if (chance <= 64)
				MainMap[x][y] = Tiles[sandB];
			else if (chance <= 76)
				MainMap[x][y] = Tiles[sandL];
			else if (chance <= 82)
				MainMap[x][y] = Tiles[treeD];
			else if (chance <= 87)
				MainMap[x][y] = Tiles[treeB];
			else if (chance <= 91)
				MainMap[x][y] = Tiles[treeL];
			else if (chance <= 95)
				MainMap[x][y] = Tiles[rockD];
			else if (chance <= 98)
				MainMap[x][y] = Tiles[rockL];
			else
				MainMap[x][y] = Tiles[rockW];
		}
	}
}

void Map::GetMap() {
	for (int x = curX; x < curX + mapVisX; x++)
		for (int y = curY; y < curY + mapVisY; y++)
			if (MainMap[x][y].isVisible)
				SetSymbol((short)(x - curX + 1), (short)(y - curY + 1), MainMap[x][y].cell, Black, MainMap[x][y].color);
}

bool Map::IsFree(int x, int y) {
	if (MainMap[x][y].type > 5)
		return false;
	else
		return true;
}

void Map::SetVisible(int x, int y) {
	MainMap[x][y].isVisible = true;
}
