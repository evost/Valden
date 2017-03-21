#pragma once

#include <Windows.h>
#include <string>
#include "structs.h"

using namespace std;

void SetColor(short background, short text);
void SetSymbol(short x, short y, char c);
void SetString(short x, short y, string s); 
void SetString(short x, short y, string s, short background, short text);
void Init(short x, short y, string name);
void Border(short x, short y, short x0);
void Clear(short x1, short y1, short x2, short y2);
short ReadKey();