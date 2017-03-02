#include <Windows.h>
#include <iostream>
#include <string>
#include <time.h>
#include "constants.h"
#include "structs.h"

using namespace std;

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void SetColor(short background, short text)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void SetSymbol(crd xy, char c)
{
	SetConsoleCursorPosition(hStdOut, { xy.X, xy.Y });
	cout << c;
}

void SetString(crd xy, string s)
{
	SetColor(Black, White);
	SetConsoleCursorPosition(hStdOut, { xy.X, xy.Y });
	cout << s;
}

void Init(crd size, string name)
{
	srand((int)time(0));
	setlocale(LC_ALL, "rus");
	SMALL_RECT src = { 0, 0, size.X - 1, size.Y - 1 };
	SetConsoleWindowInfo(hStdOut, true, &src);
	SetConsoleScreenBufferSize(hStdOut, { size.X, size.Y });
	SetConsoleTitleA(name.c_str());
	CONSOLE_CURSOR_INFO cur = { 1, false };
	SetConsoleCursorInfo(hStdOut, &cur);
}