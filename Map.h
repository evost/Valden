#pragma once

#include <iostream>
#include "structs.h"
#include "constants.h"

class Map {
private:
	TTile **MainMap = NULL;
	TTile Tiles[3] = { { 0, Green, '.' },{ 1, Green, '!'},{ 2, LightGray, 'o' } };
public:
	int Width, Height, curX, curY;
	short visX, visY;
	Map(int width, int height, short visX, short visY);
	void GetMap();
	void GetTile(int x, int y);
	bool IsFree(int x, int y);
};
