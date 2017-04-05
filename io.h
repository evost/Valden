#pragma once

#include <Windows.h>
#include <string>
#include <time.h>
#include <conio.h>
#include <fstream>
#include <urlmon.h>
#pragma comment( lib, "urlmon.lib" )

using namespace std;

static HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
static SMALL_RECT src;
static CHAR_INFO* buffer = NULL;

void SetSymbol(short x, short y, wchar_t c, short background, short text);
void SetString(short x, short y, wstring s, short background, short text);
void Randomize();
void Randomize(int sid);
void Init(short x, short y, wstring name);
void Border(short x, short y, short x0);
short ReadKey();
void Render();
wstring FloatToWstring(float k);
wstring Version(wstring url);
template<typename T> void Save(T &object, wstring path);
template<typename T> void Load(T &object, wstring path);
bool SaveExist(wstring path);
void CreateSaveDir(wstring path);
