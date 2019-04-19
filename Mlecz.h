#pragma once

#include "Roslina.h"

namespace mlecz
{
	class Mlecz : public roslina::Roslina
	{
	public:
		Mlecz(int sila, int x, int y, Swiat* swiat);
		int akcja();
		WynikKolizji kolizja();
		void rysowanie();
	};
}