#pragma once

#include <Windows.h>
#include <string>
#include <time.h>
#include <conio.h>

using namespace std;

static HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
static SMALL_RECT src;
static CHAR_INFO* buffer = (CHAR_INFO*)malloc(sizeof(CHAR_INFO));

void SetSymbol(short x, short y, wchar_t c, short background, short text);
void Init(wstring name);
void SetWindow(short x, short y, short fontSize);
short ReadKey();
void Render();
