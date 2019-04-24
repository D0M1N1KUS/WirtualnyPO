#pragma once

#include "Zwierze.h"
#include "Swiat.h"

namespace antylopa
{
	class Antylopa : public Zwierze
	{
	public:
		Antylopa(int sila, int inicjatywa, int x, int y, Swiat* swiat);
		int akcja(Kierunek kierunek = BRAK);
		WynikKolizji kolizja(Organizm* organizm);
		void rysowanie();
	};
}
