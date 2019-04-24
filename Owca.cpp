#include "Owca.h"
#include <iostream>

#define SILA 4
#define INICJATYWA 4


owca::Owca::Owca(int sila, int inicjatywa, int x, int y, Swiat * swiat)
	: Zwierze(sila, inicjatywa, x, y, swiat, IdOrganizmu::OWCA) { }

int owca::Owca::akcja()
{
	return Zwierze::akcja();
}

void owca::Owca::rysowanie()
{
	std::cout << "o";
}
