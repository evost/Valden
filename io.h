#pragma once

#include <Windows.h>
#include <string>
#include "structs.h"

using namespace std;

void SetColor(short background, short text);
void SetSymbol(crd xy, char c);
void SetString(crd xy, string s);
void Init(crd size, string name);