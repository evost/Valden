#pragma once

struct TTile {
	short type, color;
	char cell;
	bool isVisible;
};

struct TNPC {
	int type, hp, dxp, strength, dexterity, maxhp, level, visDist, x, y;
};

struct TItem {
	int type, damage, defense, dstrength, ddexterity, dintelligence, dmaxhp, level, id;
};

struct TStorage {
	int type, x, y;
};