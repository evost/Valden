#pragma once

#include "constants.h"
#include <map>

using namespace std;

class GameMap {
public:
	int Width, Height, curX, curY;
	map<int, map<int, TTile>> MainMap;
	GameMap(int width, int height);
	void GetMap();
	bool IsFree(int x, int y);
};
