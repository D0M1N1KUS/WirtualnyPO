#pragma once

#include "Zwierze.h"

namespace antylopa
{
	class Antylopa : public Zwierze
	{
	public:
		Antylopa(int sila, int inicjatywa, int x, int y, Swiat* swiat);
		int akcja();
		WynikKolizji kolizja();
		void rysowanie();
	};
}
