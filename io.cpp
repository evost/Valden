#include "io.h"
using namespace std;

void SetSymbol(short x, short y, wchar_t c, short background, short text) {
	buffer[x + y * (src.Right + 1)].Char.UnicodeChar = c;
	buffer[x + y * (src.Right + 1)].Attributes = (WORD)((background << 4) | text);
}

void SetString(short x, short y, wstring s, short background, short text) {
	for (unsigned int i = 0; i < s.length(); i++)
		SetSymbol(x + i, y, s[i], background, text);
}

void Clear() {
	for (int i = 0; i < (src.Right + 1)*(src.Bottom + 1); i++) {
		buffer[i].Char.UnicodeChar = ' ';
		buffer[i].Attributes = (WORD)((0 << 4) | 15);
	}
}

void Init(short x, short y, wstring name) {
	srand((int)time(0));
	src = { 0, 0, x, y };

	CONSOLE_FONT_INFOEX fontInfo;

	// эта строка нужна
	fontInfo.cbSize = sizeof(fontInfo);

	GetCurrentConsoleFontEx(hStdOut, TRUE, &fontInfo);

	// это неправильное использование функции
	//wcsncpy(L"Lucida Console", fontInfo.FaceName, LF_FACESIZE);

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

void Border(short x, short y, short x0) {
	for (int i = 1; i < y; i++) {
		SetSymbol(0, i, L'║', 0, 15);
		SetSymbol(x0, i, L'║', 0, 15);
		SetSymbol(x, i, L'║', 0, 15);
	}
	for (int i = 1; i < x; i++) {
		SetSymbol(i, 0, L'═', 0, 15);
		SetSymbol(i, y, L'═', 0, 15);
	}
	SetSymbol(x0, 0, L'╦', 0, 15);
	SetSymbol(x0, y, L'╩', 0, 15);
	SetSymbol(0, 0, L'╔', 0, 15);
	SetSymbol(0, y, L'╚', 0, 15);
	SetSymbol(x, 0, L'╗', 0, 15);
	SetSymbol(x, y, L'╝', 0, 15);
}

short ReadKey() {
	return _getch();
}

void Render() {
	WriteConsoleOutputW(hStdOut, buffer, { src.Right + 1 , src.Bottom + 1 }, { 0, 0 }, &src);
	Clear();
}

wstring FloatToWstring(float k) {
	return (to_wstring((int)k) + L"." + to_wstring((int)((k - (float)(int)k) * 100)));
}
