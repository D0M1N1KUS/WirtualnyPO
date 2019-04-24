#pragma once

#include "Swiat.h"


#define LICZBAWILKOW 2
#define LICZBAOWIEC 2
#define LICZBALISOW 2
#define LICZBAZOLWI 2
#define LICZBAANTYLOP 2
#define LICZBATRAWY 2
#define LICZBAMLECZY 2
#define LICZBAGUARANY 2
#define LICZBAWILCZYCHJAGOD 2
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
