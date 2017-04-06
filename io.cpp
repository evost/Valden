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

void Randomize() {
	srand((int)time(0));
}

void Init(short x, short y, wstring name) {
	Randomize();
	src = { 0, 0, x, y };
	CONSOLE_FONT_INFOEX fontInfo;
	fontInfo.cbSize = sizeof(fontInfo);
	GetCurrentConsoleFontEx(hStdOut, TRUE, &fontInfo);
	wcscpy_s(fontInfo.FaceName, L"Lucida Console");
	fontInfo.dwFontSize.Y = 20;
	SetCurrentConsoleFontEx(hStdOut, TRUE, &fontInfo);
	SetConsoleWindowInfo(hStdOut, true, &src);
	SetConsoleScreenBufferSize(hStdOut, { x + 1, y + 1 });
	SetConsoleTitleW(name.c_str());
	CONSOLE_CURSOR_INFO cur = { 1, false };
	SetConsoleCursorInfo(hStdOut, &cur);
	buffer = (CHAR_INFO*)malloc((x + 1) * (y + 1) * sizeof(CHAR_INFO));
	Clear();
}

short ReadKey() {
	return _getch();
}

void Render() {
	WriteConsoleOutputW(hStdOut, buffer, { src.Right + 1 , src.Bottom + 1 }, { 0, 0 }, &src);
	Clear();
}
