#include "BarszczSosnowskiego.h"
#include <iostream>

barszcz::Barszcz::Barszcz(int sila, int x, int y, Swiat * swiat)
	: Roslina(sila, x, y, swiat, BARSZ) { }


WynikKolizji barszcz::Barszcz::kolizja()
{
	return ZATRUCIE;
}

void barszcz::Barszcz::rysowanie()
{
	std::cout << "!";
}
