#include "Antylopa.h"
#include <iostream>

#define SILA 4
#define INICJATYWA 4


antylopa::Antylopa::Antylopa(int sila, int inicjatywa, int x, int y, Swiat * swiat)
	: Zwierze(sila, inicjatywa, x, y, swiat, IdOrganizmu::ANTYLOPA)
{
}

int antylopa::Antylopa::akcja()
{
	return 0;
}

WynikKolizji antylopa::Antylopa::kolizja()
{
	return WynikKolizji();
}

void antylopa::Antylopa::rysowanie()
{
	std::cout << "a";
}
