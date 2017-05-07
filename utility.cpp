#include "utility.h"

using namespace std;

void SetString(short x, short y, wstring s, short background, short text) {
	for (unsigned int i = 0; i < s.length(); i++)
		SetSymbol(x + i, y, s[i], background, text);
}

void Randomize(int sid) {
	srand(sid);
}

void Border(short x, short y, short x0) {
	for (int i = 1; i < y; i++) {
		SetSymbol(0, i, L'║', 0, 15);
		SetSymbol(x0, i, L'║', 0, 15);
		SetSymbol(x, i, L'║', 0, 15);
	}
	for (int i = 1; i < x; i++) {
		SetSymbol(i, 0, L'═', 0, 15);
		SetSymbol(i, y, L'═', 0, 15);
	}
	SetSymbol(x0, 0, L'╦', 0, 15);
	SetSymbol(x0, y, L'╩', 0, 15);
	SetSymbol(0, 0, L'╔', 0, 15);
	SetSymbol(0, y, L'╚', 0, 15);
	SetSymbol(x, 0, L'╗', 0, 15);
	SetSymbol(x, y, L'╝', 0, 15);
}

wstring FloatToWstring(float k) {
	return (to_wstring((int)k) + L"." + to_wstring((int)((k - (float)(int)k) * 100)));
}

wstring Version(wstring url) {
	wstring newVersion = L"";
	if (!URLDownloadToFileW(0, url.c_str(), L"version.md", 0, 0)) {
		wifstream inf(L"version.md", ios::binary | ios::in);
		inf >> newVersion;
		inf.close();
		_wremove(L"version.md");
	}
	return newVersion;
}

bool SaveExist(wstring path) {
	return !_waccess(path.c_str(), 0);
}

void CreateSaveDir(wstring path) {
	CreateDirectoryW(path.c_str(), NULL);
}

void SaveHero(Hero &dHero) {
	ofstream out(sSavePath + sHeroSave, ios::binary | ios::out);
	out << dHero.xp << ' ';
	out << dHero.x << ' ';
	out << dHero.y << ' ';
	out << dHero.killed << ' ';
	out << dHero.hp << ' ';
	out << dHero.strength << ' ';
	out << dHero.dexterity << ' ';
	out << dHero.intelligence << ' ';
	out << dHero.maxhp << ' ';
	out << dHero.maxxp << ' ';
	out << dHero.level << ' ';
	out << dHero.cpoints << ' ';
	out << dHero.race << ' ';
	out << dHero.visDistance << ' ';
	out << dHero.carmor.id << ' ';
	out << dHero.cweapon.id << ' ';
	out << dHero.invertory.size() << ' ';
	for (int i = 0; i < dHero.invertory.size(); i++)
		out << dHero.invertory[i].id << ' ';
	out.close();
}

void LoadHero(Hero &dHero) {
	int k, id;
	ifstream inf(sSavePath + sHeroSave, ios::binary | ios::in);
	inf >> dHero.xp;
	inf >> dHero.x;
	inf >> dHero.y;
	inf >> dHero.killed;
	inf >> dHero.hp;
	inf >> dHero.strength;
	inf >> dHero.dexterity;
	inf >> dHero.intelligence;
	inf >> dHero.maxhp;
	inf >> dHero.maxxp;
	inf >> dHero.level;
	inf >> dHero.cpoints;
	inf >> dHero.race;
	inf >> dHero.visDistance;
	inf >> id;
	if (id != 0)
		dHero.carmor = Items[id - 1];
	else
		dHero.carmor = blankItem;
	inf >> id;
	if (id != 0)
		dHero.cweapon = Items[id - 1];
	else
		dHero.cweapon = blankItem;
	inf >> k;
	dHero.invertory.clear();
	for (int i = 0; i < k; i++) {
		inf >> id;
		if (id <= itemsNum)
			dHero.invertory[i] = Items[id - 1];
		else
			dHero.invertory[i] = poultices[id - itemsNum];
	}
	inf.close();
}

void SaveNPC(NPC &dNPC) {
	ofstream out(sSavePath + sNPCSave, ios::binary | ios::out);
	out << dNPC.NPCk << ' ';
	for (int i = 0; i < dNPC.NPCk; i++) {
		out << dNPC.NPCs[i].type << ' ';
		out << dNPC.NPCs[i].hp << ' ';
		out << dNPC.NPCs[i].x << ' ';
		out << dNPC.NPCs[i].y << ' ';
	}
	out.close();
}

void LoadNPC(NPC &dNPC, GameMap &dMap) {
	ifstream inf(sSavePath + sNPCSave, ios::binary | ios::in);
	int type;
	dNPC.NPCs.clear();
	inf >> dNPC.NPCk;
	for (int i = 0; i < dNPC.NPCk; i++) {
		inf >> type;
		dNPC.NPCs.insert(pair<int, TNPC>(i, NPC_types[type]));
		inf >> dNPC.NPCs[i].hp;
		inf >> dNPC.NPCs[i].x;
		inf >> dNPC.NPCs[i].y;
	}
	inf.close();
}

void SaveMap(GameMap &dMap) {
	ofstream outf(sSavePath + sMapSave, ios::binary | ios::out);
	outf << dMap.Width << ' ';
	outf << dMap.Height << ' ';
	outf << dMap.curX << ' ';
	outf << dMap.curY << ' ';
	for (int x = 0; x < dMap.Width; x++)
		for (int y = 0; y < dMap.Height; y++) {
			outf << dMap.MainMap[x][y].type << ' ';
			outf << dMap.MainMap[x][y].isVisible << ' ';
		}
	outf.close();
}

void LoadMap(GameMap &dMap) {
	ifstream inf(sSavePath + sMapSave, ios::binary | ios::in);
	int type;
	dMap.MainMap.clear();
	inf >> dMap.Width;
	inf >> dMap.Height;
	inf >> dMap.curX;
	inf >> dMap.curY;
	for (int x = 0; x < dMap.Width; x++)
		for (int y = 0; y < dMap.Height; y++) {
			inf >> type;
			dMap.MainMap[x][y] = Tiles[type];
			inf >> dMap.MainMap[x][y].isVisible;
		}
	inf.close();
}

void SaveSettings(short &fontSize, short &mapVisY) {
	ofstream outf(sSavePath + sSettingsSave, ios::binary | ios::out);
	outf << fontSize << ' ';
	outf << mapVisY << ' ';
	outf.close();
}

void LoadSettings(short &fontSize, short &mapVisY) {
	ifstream inf(sSavePath + sSettingsSave, ios::binary | ios::in);
	inf >> fontSize;
	inf >> mapVisY;
	inf.close();
}

float Distance(int x1, int y1, int x2, int y2) {
	return sqrt(pow((float)abs(x1 - x2), 2) + pow((float)abs(y1 - y2), 2));
}
