#pragma once

#include "Zwierze.h"

namespace zolw
{
	class Zolw : public Zwierze
	{
	public:
		Zolw(int sila, int inicjatywa, int x, int y, Swiat* swiat);
		int akcja();
		WynikKolizji kolizja(Organizm* organizm);
		void rysowanie();
	};
}
