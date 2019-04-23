#pragma once

#include "Organizm.h"

#define PRAWDOPODOBIENSTWO_ROZRASTANIA_SIE 33

namespace roslina
{
	class Roslina : public Organizm
	{
	public:
		Roslina(int sila, int x, int y, Swiat* swiat, IdOrganizmu ID);
		int akcja();
		WynikKolizji kolizja(Organizm* organizm);
		virtual void rysowanie() = 0;
	};
}