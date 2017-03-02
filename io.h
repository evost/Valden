#pragma once

#include <Windows.h>
#include <string>
#include "structs.h"

using namespace std;

void SetColor(short background, short text);
void SetSymbol(short x, short y, char c);
void SetString(short x, short y, string s);
void Init(short x, short y, string name);