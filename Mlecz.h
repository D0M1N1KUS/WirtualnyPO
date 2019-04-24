#pragma once

#include "Roslina.h"

#define PROBY_ROZPRZESTRZENIENIA 3

namespace mlecz
{
	class Mlecz : public roslina::Roslina
	{
	public:
		Mlecz(int sila, int x, int y, Swiat* swiat);
		int akcja();
		void rysowanie();
	};
}