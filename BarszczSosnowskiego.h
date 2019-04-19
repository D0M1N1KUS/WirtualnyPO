#pragma once

#include "Roslina.h"

namespace barszcz
{
	class Barszcz : public roslina::Roslina
	{
	public:
		Barszcz(int sila, int x, int y, Swiat* swiat);
		int akcja();
		WynikKolizji kolizja();
		void rysowanie();
	};
}