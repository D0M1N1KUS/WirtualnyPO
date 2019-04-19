#include "Trawa.h"
#include <iostream>

trawa::Trawa::Trawa(int sila, int x, int y, Swiat * swiat)
	: Roslina(sila, x, y, swiat, IdOrganizmu::TRAWA) { }

int trawa::Trawa::akcja()
{
	return Roslina::akcja();
}

WynikKolizji trawa::Trawa::kolizja()
{
	return WynikKolizji();
}

void trawa::Trawa::rysowanie()
{
	std::cout << "#";
}
