#pragma once

#include <Windows.h>
#include <string>
#include <time.h>
#include <conio.h>

using namespace std;

static HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
static SMALL_RECT src;
static CHAR_INFO* buffer = NULL;

void SetSymbol(short x, short y, wchar_t c, short background, short text);
void Randomize();
void Init(short x, short y, wstring name);
short ReadKey();
void Render();
