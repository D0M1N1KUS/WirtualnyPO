#pragma once

#include "Roslina.h"

namespace trawa
{
	class Trawa : public roslina::Roslina
	{
	public:
		Trawa(int sila, int x, int y, Swiat* swiat);
		void rysowanie();
	};
}