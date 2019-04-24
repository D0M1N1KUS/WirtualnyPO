#pragma once

#include "Swiat.h"


#define LICZBAWILKOW 0
#define LICZBAOWIEC 0
#define LICZBALISOW 0
#define LICZBAZOLWI 1
#define LICZBAANTYLOP 0
#define LICZBATRAWY 0
#define LICZBAMLECZY 0
#define LICZBAGUARANY 0
#define LICZBAWILCZYCHJAGOD 0
#define LICZBABARSZY 0
#define DODAJ_CZLOWIEKA true

namespace tworcaSwiata
{
	class TworcaSwiata
	{
	private:
		bool** tablicaSwiata;
		int xs, ys, noweX, noweY;
		Swiat* nowySwiat;

		void zaalokujTablice();
		void losujPozycje();
	public:
		TworcaSwiata(int xs, int ys);
		Swiat* StworzSwiat();
		
	};
}
