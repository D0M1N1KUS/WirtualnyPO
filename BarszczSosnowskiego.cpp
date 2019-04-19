#include "BarszczSosnowskiego.h"
#include <iostream>

barszcz::Barszcz::Barszcz(int sila, int x, int y, Swiat * swiat)
	: Roslina(sila, x, y, swiat, BARSZ) { }

int barszcz::Barszcz::akcja()
{
	return 0;
}

WynikKolizji barszcz::Barszcz::kolizja()
{
	return WynikKolizji();
}

void barszcz::Barszcz::rysowanie()
{
	std::cout << "!";
}
