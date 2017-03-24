#pragma once

#include <Windows.h>
#include <iostream>
#include <string>
#include <time.h>
#include <conio.h>

using namespace std;

static HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
static SMALL_RECT src;

void SetSymbol(short x, short y, char c, short background, short text);
void SetString(short x, short y, string s, short background, short text);
void Init(short x, short y, string name);
void Border(short x, short y, short x0);
void Clear(short x1, short y1, short x2, short y2);
short ReadKey();
