#pragma once 

#include "Zwierze.h"

namespace czlowiek
{
	class Czlowiek : protected Zwierze
	{
	public:
		Czlowiek(int sila, int inicjatywa, int x, int y, Swiat* swiat);
		int akcja();
		WynikKolizji kolizja();
		void rysowanie();
	};
}