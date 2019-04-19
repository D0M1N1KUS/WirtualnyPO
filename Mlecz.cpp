#include "Mlecz.h"
#include <iostream>

mlecz::Mlecz::Mlecz(int sila, int x, int y, Swiat * swiat)
	: Roslina(sila, x, y, swiat, IdOrganizmu::MLECZ) { }

int mlecz::Mlecz::akcja()
{
	return 0;
}

WynikKolizji mlecz::Mlecz::kolizja()
{
	return WynikKolizji();
}

void mlecz::Mlecz::rysowanie()
{
	std::cout << "*";
}
