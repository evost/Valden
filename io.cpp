#include <Windows.h>
#include <iostream>
#include <string>
#include <time.h>
#include "constants.h"
#include "structs.h"

using namespace std;

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void SetColor(short background, short text) {
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void SetSymbol(short x, short y, char c) {
	SetConsoleCursorPosition(hStdOut, { x, y });
	cout << c;
}

void SetString(short x, short y, string s) {
	SetColor(Black, White);
	SetConsoleCursorPosition(hStdOut, { x, y });
	cout << s;
}

void Init(short x, short y, string name) {
	srand((int)time(0));
	setlocale(LC_ALL, "rus");
	SMALL_RECT src = { 0, 0, x - 1, y - 1 };
	SetConsoleWindowInfo(hStdOut, true, &src);
	SetConsoleScreenBufferSize(hStdOut, { x, y });
	SetConsoleTitleA(name.c_str());
	CONSOLE_CURSOR_INFO cur = { 1, false };
	SetConsoleCursorInfo(hStdOut, &cur);
}