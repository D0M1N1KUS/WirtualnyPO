#pragma once

#include "Zwierze.h"
#include "Swiat.h"

namespace zolw
{
	class Zolw : public Zwierze
	{
	public:
		Zolw(int sila, int inicjatywa, int x, int y, Swiat* swiat);
		int akcja(Kierunek kierunek = BRAK);
		WynikKolizji kolizja(Organizm* organizm);
		void rysowanie();
	};
}
