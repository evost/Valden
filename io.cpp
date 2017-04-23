#include "io.h"
#include <Windows.h>
#include <conio.h>

using namespace std;

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
SMALL_RECT src;
CHAR_INFO* buffer = (CHAR_INFO*)malloc(sizeof(CHAR_INFO));
CONSOLE_FONT_INFOEX fontInfo;
COORD xy;
COORD x0y0;

void SetSymbol(short x, short y, wchar_t c, short background, short text) {
	buffer[x + y * xy.X].Char.UnicodeChar = c;
	buffer[x + y * xy.X].Attributes = (WORD)((background << 4) | text);
}

void Clear() {
	for (int i = 0; i < xy.X * xy.Y; i++) {
		buffer[i].Char.UnicodeChar = ' ';
		buffer[i].Attributes = (WORD)0;
	}
}

void Init(wstring name) {
	srand((int)time(0));
	fontInfo.cbSize = sizeof(fontInfo);
	fontInfo.FontFamily = FF_DONTCARE;
	fontInfo.FontWeight = 400;
	wcscpy_s(fontInfo.FaceName, L"Lucida Console");
	SetCurrentConsoleFontEx(hStdOut, FALSE, &fontInfo);
	SetConsoleTitleW(name.c_str());
	CONSOLE_CURSOR_INFO cur = { 1, false };
	SetConsoleCursorInfo(hStdOut, &cur);
	src.Left = 0;
	src.Top = 0;
	x0y0.X = 0;
	x0y0.Y = 0;
}

void SetWindow(short x, short y, short fontSize) {
	fontInfo.dwFontSize.Y = fontSize;
	SetCurrentConsoleFontEx(hStdOut, FALSE, &fontInfo);
	src.Right = x;
	src.Bottom = y;
	xy.X = src.Right + 1;
	xy.Y = src.Bottom + 1;
	SetConsoleScreenBufferSize(hStdOut, xy);
	SetConsoleWindowInfo(hStdOut, true, &src);
	SetConsoleScreenBufferSize(hStdOut, xy);
	SetConsoleWindowInfo(hStdOut, true, &src);
	free(buffer);
	buffer = (CHAR_INFO*)malloc(xy.X * xy.Y * sizeof(CHAR_INFO));
	Clear();
}

short ReadKey() {
	return _getch();
}

void Render() {
	WriteConsoleOutputW(hStdOut, buffer, xy, x0y0, &src);
	Clear();
}

wstring to_wstring(int i) {
	return to_wstring((long double)i);
}
