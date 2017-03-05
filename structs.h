#pragma once

struct Tile {
	short type, color;
	char cell;
};

struct TNPC {
	int type, hp, xp, defence, damage, visDist, x, y;
};