#pragma once

#include <string>
#include <fstream>
#include <urlmon.h>
#pragma comment( lib, "urlmon.lib" )
#include "io.h"
#include "Map.h"
#include "NPC.h"

using namespace std;

void SetString(short x, short y, wstring s, short background, short text);
void Randomize(int sid);
void Border(short x, short y, short x0);
wstring FloatToWstring(float k);
wstring Version(wstring url);
bool SaveExist(wstring path);
void CreateSaveDir(wstring path);
template<class T> void Save(T &object, wstring path) {
	ofstream out(path, ios::binary | ios::out);
	out.write((char*)(&object), sizeof object);
	out.close();
}
template<class T> void Load(T &object, wstring path) {
	ifstream inf(path, ios::binary | ios::in);
	inf.read((char*)(&object), sizeof object);
	inf.close();
}
void SaveNPC(NPC &dNPC);
void LoadNPC(NPC &dNPC, Map &dMap);
void SaveMap(Map &dMap);
void LoadMap(Map &dMap);
void SaveSettings(short &fontSize, short &mapVisY);
void LoadSettings(short &fontSize, short &mapVisY);
double Distance(int x1, int y1, int x2, int y2);