#include "io.h"

using namespace std;

void SetSymbol(short x, short y, wchar_t c, short background, short text) {
	buffer[x + y * (src.Right + 1)].Char.UnicodeChar = c;
	buffer[x + y * (src.Right + 1)].Attributes = (WORD)((background << 4) | text);
}

void Clear() {
	for (int i = 0; i < (src.Right + 1)*(src.Bottom + 1); i++) {
		buffer[i].Char.UnicodeChar = ' ';
		buffer[i].Attributes = (WORD)((0 << 4) | 15);
	}
}

void Init(wstring name) {
	srand((int)time(0));
	CONSOLE_FONT_INFOEX fontInfo;
	fontInfo.cbSize = sizeof(fontInfo);
	GetCurrentConsoleFontEx(hStdOut, TRUE, &fontInfo);
	wcscpy_s(fontInfo.FaceName, L"Lucida Console");
	SetCurrentConsoleFontEx(hStdOut, TRUE, &fontInfo);
	SetConsoleTitleW(name.c_str());
	CONSOLE_CURSOR_INFO cur = { 1, false };
	SetConsoleCursorInfo(hStdOut, &cur);
}

void SetWindow(short x, short y, short fontSize) {
	src.Left = 0;
	src.Top = 0;
	src.Right = x;
	src.Bottom = y;
	CONSOLE_FONT_INFOEX fontInfo;
	fontInfo.cbSize = sizeof(fontInfo);
	GetCurrentConsoleFontEx(hStdOut, TRUE, &fontInfo);
	fontInfo.dwFontSize.Y = fontSize;
	SetCurrentConsoleFontEx(hStdOut, TRUE, &fontInfo);
	COORD xy;
	xy.X = x + 1;
	xy.Y = y + 1;
	SetConsoleScreenBufferSize(hStdOut, xy);
	SetConsoleWindowInfo(hStdOut, true, &src);
	SetConsoleScreenBufferSize(hStdOut, xy);
	SetConsoleWindowInfo(hStdOut, true, &src);
	free(buffer);
	buffer = (CHAR_INFO*)malloc((x + 1) * (y + 1) * sizeof(CHAR_INFO));
	Clear();
}

short ReadKey() {
	return _getch();
}

void Render() {
	COORD xy;
	xy.X = src.Right + 1;
	xy.Y = src.Bottom + 1;
	COORD x0y0;
	x0y0.X = 0;
	x0y0.Y = 0;
	WriteConsoleOutputW(hStdOut, buffer, xy, x0y0, &src);
	Clear();
}

wstring to_wstring(int i) {
	return to_wstring((long double)i);
}
