#include "Map.h"
#include "Game.h"

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
			int chance = rand() % 100;
			if (chance < 12)
				MainMap[x][y] = Tiles[grassD];
			else if (chance < 13)
				MainMap[x][y] = Tiles[trapGrassD];
			else if (chance < 25)
				MainMap[x][y] = Tiles[grassB];
			else if (chance < 26)
				MainMap[x][y] = Tiles[trapGrassB];
			else if (chance < 37)
				MainMap[x][y] = Tiles[grassL];
			else if (chance < 38)
				MainMap[x][y] = Tiles[trapGrassL];
			else if (chance < 51)
				MainMap[x][y] = Tiles[sandD];
			else if (chance < 64)
				MainMap[x][y] = Tiles[sandB];
			else if (chance < 76)
				MainMap[x][y] = Tiles[sandL];
			else if (chance < 82)
				MainMap[x][y] = Tiles[treeD];
			else if (chance < 87)
				MainMap[x][y] = Tiles[treeB];
			else if (chance < 91)
				MainMap[x][y] = Tiles[treeL];
			else if (chance < 95)
				MainMap[x][y] = Tiles[rockD];
			else if (chance < 98)
				MainMap[x][y] = Tiles[rockL];
			else
				MainMap[x][y] = Tiles[rockW];
		}
	}
	for (int i = 0; i < width * height / 1000; i++) {
		int x = rand() % width;
		int y = rand() % height;
		int r = rand() % 5 + 3;
		for (int mx = x - r; mx <= x + r; mx++)
			for (int my = y - r; my <= y + r; my++)
				if (mx >= 0 && my >= 0 && mx <= Width && my <= Height && Distance(mx, my, x, y) <= r)
					if (Distance(mx, my, x, y) >= r - 2)
						MainMap[mx][my] = Tiles[waterL];
					else
						MainMap[mx][my] = Tiles[waterD];
		int x0 = x + rand() % (2 * r) - r;
		int y0 = y + rand() % (2 * r) - r;
		for (int mx = x0 - r; mx <= x0 + r; mx++)
			for (int my = y0 - r; my <= y0 + r; my++)
				if (mx >= 0 && my >= 0 && mx <= Width && my <= Height && Distance(mx, my, x0, y0) <= r)
					if (Distance(mx, my, x0, y0) >= r - 2 && Distance(mx, my, x, y) >= r - 1)
						MainMap[mx][my] = Tiles[waterL];
					else
						MainMap[mx][my] = Tiles[waterD];
	}
}

void Map::GetMap() {
	for (int x = curX; x < curX + mapVisX; x++)
		for (int y = curY; y < curY + mapVisY; y++)
			if (MainMap[x][y].isVisible)
				SetSymbol((short)(x - curX + 1), (short)(y - curY + 1), MainMap[x][y].cell, Black, MainMap[x][y].color);
}

bool Map::IsFree(int x, int y) {
	if (MainMap[x][y].type > waterL)
		return false;
	else
		return true;
}
