#pragma once

#include "Organizm.h"

#define PRAWDOPODOBIENSTWO_ROZRASTANIA_SIE 15

namespace roslina
{
	class Roslina : public Organizm
	{
	public:
		Roslina(int sila, int x, int y, Swiat* swiat, IdOrganizmu ID);
		int akcja(Kierunek kierunek = BRAK);
		WynikKolizji kolizja(Organizm* organizm);
		virtual void rysowanie() = 0;
	};
}