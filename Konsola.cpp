#include "Konsola.h"
#include <Windows.h>
#include <strsafe.h>
#include <string>

#define CTITLE "Dominikus Noah Preugszas 160752"

void gotoxy(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}



void ustawKolor(int kolor, int tlo)
{
	const WORD setcolors = ((tlo & 0x0F) << 4) + (kolor & 0x0F);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), setcolors);
}


void ustawTytul(const char* tytul)
{
	TCHAR newtitle[MAX_PATH];
	StringCchPrintf(newtitle, MAX_PATH, TEXT(tytul));
	SetConsoleTitle(newtitle);
}

void ustawRozmiarKonsoli(int szerokosc, int wysokosc)
{ 
	COORD size;
	size.X = szerokosc + 3;
	size.Y = wysokosc + 3;

	szerokosc += 50;

	if (wysokosc <= 25)
		wysokosc = 26;

	SMALL_RECT rect;
	rect.Bottom = wysokosc + 1;
	rect.Right = szerokosc + 1;
	rect.Left = 0;
	rect.Top = 0;

	const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(hConsole, size);
	SetConsoleWindowInfo(hConsole, TRUE, &rect);
}

void wyczyscEkran()
{
	system("cls");
}

void pause()
{
	system("pause");
}
