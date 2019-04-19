#pragma once

#include "Roslina.h"

namespace guarana
{
	class Guarana : public roslina::Roslina
	{
	public:
		Guarana(int sila, int x, int y, Swiat* swiat);
		int akcja();
		WynikKolizji kolizja();
		void rysowanie();
	};
}
