#pragma once

#include <string>
#include <time.h>

using namespace std;

void SetSymbol(short x, short y, wchar_t c, short background, short text);
void Init(wstring name);
void SetWindow(short x, short y, short fontSize);
short ReadKey();
void Render();
wstring to_wstring(int i);
