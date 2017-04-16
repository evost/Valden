#pragma once

#include <iostream>
#include "constants.h"

class Map {
private:
public:
	TTile **MainMap;
	int Width, Height, curX, curY;
	Map(int width, int height);
	void GetMap();
	bool IsFree(int x, int y);
};
