#include "Guarana.h"
#include <iostream>

guarana::Guarana::Guarana(int sila, int x, int y, Swiat * swiat)
	: Roslina(sila, x, y, swiat, GUARANA) { }

int guarana::Guarana::akcja()
{
	return Roslina::akcja();
}

WynikKolizji guarana::Guarana::kolizja()
{
	return WynikKolizji();
}

void guarana::Guarana::rysowanie()
{
	std::cout << "+";
}
