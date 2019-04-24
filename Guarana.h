#pragma once

#include "Roslina.h"
#include "Swiat.h"

namespace guarana
{
	class Guarana : public roslina::Roslina
	{
	public:
		Guarana(int sila, int x, int y, Swiat* swiat);
		WynikKolizji kolizja(Organizm* organizm);
		void rysowanie();
	};
}
