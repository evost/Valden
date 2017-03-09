#include <Windows.h>
#include <iostream>
#include <string>
#include <time.h>
#include <conio.h>
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

void Border(short x, short y, short x0) {
	setlocale(LC_ALL, "C");
	for (int i = 1; i < y; i++) {
		SetSymbol(0, i, 186);
		SetSymbol(x0, i, 186);
		SetSymbol(x, i, 186);
	}
	for (int i = 1; i <= x; i++) {
		SetSymbol(i, 0, 205);
		SetSymbol(i, y, 205);
	}
	SetSymbol(0, 0, 201);
	SetSymbol(0, y, 200);
	SetSymbol(x, 0, 187);
	SetSymbol(x, y, 188);
	SetSymbol(x0, 0, 203);
	SetSymbol(x0, y, 202);
	setlocale(LC_ALL, "rus");
}

short ReadKey() {
	return _getch();
}