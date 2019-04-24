#include "Antylopa.h"
#include <iostream>

#define SILA 4
#define INICJATYWA 4


antylopa::Antylopa::Antylopa(int sila, int inicjatywa, int x, int y, Swiat * swiat)
	: Zwierze(sila, inicjatywa, x, y, swiat, IdOrganizmu::ANTYLOPA)
{
}

int antylopa::Antylopa::akcja(Kierunek kierunek)
{
	if(nowyOrganizm)
	{
		nowyOrganizm = false;
		return NIE_MOGE;
	}

	const int zasieg = rand() % 2 + 1;

	int nowyX = x, nowyY = y;

	switch (kierunek == BRAK ? rand() % 4 : kierunek)
	{
	case GORA:
		if (y - zasieg >= 0) nowyY = y - zasieg;
		else return NIE_MOGE;
		break;
	case DOL:
		if (y + zasieg < swiat->getYS()) nowyY = y + zasieg;
		else return NIE_MOGE;
		break;
	case LEWO:
		if (x - zasieg >= 0) nowyX = x - zasieg;
		else return NIE_MOGE;
		break;
	case PRAWO:
		if (x + zasieg < swiat->getXS()) nowyX = x + zasieg;
		else return NIE_MOGE;
	default:
		break;
	}

	return wykonajRuch(nowyX, nowyY);
}

WynikKolizji antylopa::Antylopa::kolizja()
{
	return WynikKolizji();
}

void antylopa::Antylopa::rysowanie()
{
	std::cout << "a";
}
