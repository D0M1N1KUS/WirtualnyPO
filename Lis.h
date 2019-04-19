#pragma once

#include "Zwierze.h"

namespace lis
{
	class  Lis : public Zwierze
	{
	public:
		Lis(int sila, int inicjatywa, int x, int y, Swiat* swiat);
		int akcja();
		bool polePusteLubSlabyPrzeciwnik(int x, int y);
		WynikKolizji kolizja();
		void rysowanie();
	};
}
