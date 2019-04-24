#include "Trawa.h"
#include <iostream>

trawa::Trawa::Trawa(int sila, int x, int y, Swiat * swiat)
	: Roslina(sila, x, y, swiat, IdOrganizmu::TRAWA) { }

void trawa::Trawa::rysowanie()
{
	std::cout << "#";
}
