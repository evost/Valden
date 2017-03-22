#include "io.h"

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

void SetString(short x, short y, string s, short background, short text) {
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
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
	system("cls");
	SetColor(Black, White);
	setlocale(LC_ALL, "C");
	for (int i = 1; i < y; i++) {
		SetSymbol(0, i, (char)186);
		SetSymbol(x0, i, (char)186);
		SetSymbol(x, i, (char)186);
	}
	for (int i = 1; i < x; i++) {
		SetSymbol(i, 0, (char)205);
		SetSymbol(i, y, (char)205);
	}
	SetSymbol(x0, 0, (char)203);
	SetSymbol(x0, y, (char)202);
	SetSymbol(0, 0, (char)201);
	SetSymbol(0, y, (char)200);
	SetSymbol(x, 0, (char)187);
	SetSymbol(x, y, (char)188);
	setlocale(LC_ALL, "rus");
}

short ReadKey() {
	return _getch();
}

void Clear(short x1, short y1, short x2, short y2) {
	for (int x = x1; x <= x2; x++)
		for (int y = y1; y <= y2; y++)
			SetSymbol(x, y, ' ');

}
