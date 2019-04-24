#include "Mlecz.h"
#include <iostream>

mlecz::Mlecz::Mlecz(int sila, int x, int y, Swiat * swiat)
	: Roslina(sila, x, y, swiat, IdOrganizmu::MLECZ) { }

int mlecz::Mlecz::akcja()
{
	if(nowyOrganizm)
	{
		nowyOrganizm = false;
		return NIE_MOGE;
	}
	for (int i = 0; i < PROBY_ROZPRZESTRZENIENIA; i++)
		roslina::Roslina::akcja();
	return RUCH;
}

void mlecz::Mlecz::rysowanie()
{
	std::cout << "*";
}
