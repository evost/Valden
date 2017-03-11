#pragma once

#include <string>

struct Tile {
	short type, color;
	char cell;
};

struct TNPC {
	int type, hp, dxp, strength, dexterity, maxhp, level, visDist, x, y;
};

struct TItem {
	int type, damage, defence, dstrength, ddexterity, dintelligence, dmaxhp;
	std::string name;
};