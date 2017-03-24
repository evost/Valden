#pragma once

#include <Windows.h>
#include <iostream>
#include <string>
#include <time.h>
#include <conio.h>

using namespace std;

static HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
static SMALL_RECT src;
static CHAR_INFO* buffer = NULL;

void SetSymbol(short x, short y, wchar_t c, short background, short text);
void SetString(short x, short y, wstring s, short background, short text);
void Init(short x, short y, wstring name);
void Border(short x, short y, short x0);
short ReadKey();
void Render();
