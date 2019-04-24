#pragma once

#include "Zwierze.h"

namespace owca
{
	class Owca : public Zwierze
	{
	public:
		Owca(int sila, int inicjatywa, int x, int y, Swiat* swiat);
		int akcja();
		void rysowanie();
	};
}
