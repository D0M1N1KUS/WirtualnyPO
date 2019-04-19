#pragma once

#include "Organizm.h"

namespace roslina
{
	class Roslina : public Organizm
	{
	public:
		Roslina(int sila, int x, int y, Swiat* swiat, IdOrganizmu ID);
		int akcja();
		WynikKolizji kolizja(int x, int y);
		virtual void rysowanie() = 0;
	};
}