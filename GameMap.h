#pragma once

#include "constants.h"
#include <map>

using namespace std;

class GameMap {
public:
	map<int, map<int, TTile>> MainMap;
	int Width, Height, curX, curY;
	GameMap(int width, int height);
	void GetMap();
	bool IsFree(int x, int y);
};
