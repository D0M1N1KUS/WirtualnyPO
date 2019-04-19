#include "Wilk.h"
#include <iostream>

#define SILA 9
#define INICJATYWA 5


wilk::Wilk::Wilk(int sila, int inicjatywa, int x, int y, Swiat* swiat)
	: Zwierze(sila, inicjatywa, x, y, swiat, IdOrganizmu::WILK) { }

int wilk::Wilk::akcja()
{
	return Zwierze::akcja();
}

WynikKolizji wilk::Wilk::kolizja()
{
	return WynikKolizji();
}

void wilk::Wilk::rysowanie()
{
	std::cout << "w";
}
