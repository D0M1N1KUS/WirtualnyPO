#pragma once

#include "Zwierze.h"

namespace wilk
{
	class Wilk : public Zwierze
	{
	public:
		Wilk(int sila, int inicjatywa, int x, int y, Swiat* swiat);
		int akcja();
		WynikKolizji kolizja();
		void rysowanie();
	};

}
