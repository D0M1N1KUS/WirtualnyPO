#pragma once
#include <vector>
#include "Struktury.h"
#include "Swiat.h"

namespace wolnePola
{
	class WolnePola
	{
	private:
		Punkt punkt;
		Rozmiar rozmiar;
		Swiat* swiat;

		std::vector<Punkt>* punkty;
	public:
		WolnePola(Punkt p, Rozmiar r, Swiat* swiat);
		WolnePola(Punkt a, Punkt b, Swiat* swiat);
		~WolnePola();
		std::vector<Punkt>* ZnajdzWolnePola();
		bool jestesmyW_Planszy(int i, int j);
	};
}
