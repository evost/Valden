#pragma once

struct Tile {
	short type, color;
	char cell;
};

struct TNPC {
	int type, hp, dxp, strength, dexterity, maxhp, level, visDist, x, y;
};