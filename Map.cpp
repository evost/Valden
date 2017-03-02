#include "Map.h"
#include "io.h"

Map::Map(int width, int height, short visX, short visY)
{
	curX = 0;
	curY = 0;
	Map::visX = visX;
	Map::visY = visY;
	Width = width - 1;
	Height = height - 1;
	MainMap = (Tile**)malloc(Width);
	for (int x = 0; x <= Width; x++) {
		MainMap[x] = new Tile[Height + 1];
	}
	for (int x = 0; x <= Width; x++) {
		for (int y = 0; y <= Height; y++) {
			int chance = rand() % 100 + 1;
			if (chance > 70) {
				if (chance > 90) {
					MainMap[x][y] = Tiles[rock];
				}
				else {
					MainMap[x][y] = Tiles[tree];
				}
			}
			else {
				MainMap[x][y] = Tiles[grass];
			};
		}
	}
}

void Map::GetMap()
{
	for (int x = curX; x < curX + visX; x++) {
		for (int y = curY; y < curY + visY; y++) {
			SetColor(Black, MainMap[x][y].color);
			SetSymbol({ (short)(x - curX + 1), (short)(y - curY + 1) }, MainMap[x][y].cell);
		}
	}
}

void Map::GetTile(int x, int y)
{
	SetColor(Black, MainMap[x][y].color);
	SetSymbol({ (short)(x - curX + 1), (short)(y - curY + 1) }, MainMap[x][y].cell);
}

bool Map::IsFree(int x, int y)
{
	return !MainMap[x][y].type;
}