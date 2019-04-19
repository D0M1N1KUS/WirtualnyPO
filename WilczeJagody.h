#pragma once

#include "Roslina.h"

namespace wilczeJagody
{
	class WilczeJagody : public roslina::Roslina
	{
	public:
		WilczeJagody(int sila, int x, int y, Swiat* swiat);
		int akcja();
		WynikKolizji kolizja();
		void rysowanie();
	};
}