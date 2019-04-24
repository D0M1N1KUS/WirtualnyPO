#include "Zolw.h"
#include<cstdio>
#include <iostream>
#include <ctime>

#define SILA 2
#define INICJATYWA 1


zolw::Zolw::Zolw(int sila, int inicjatywa, int x, int y, Swiat * swiat)
	: Zwierze(sila, inicjatywa, x, y, swiat, IdOrganizmu::ZOLW)
{
	srand(time(NULL));
}

int zolw::Zolw::akcja(Kierunek kierunek)
{
	if (rand() % 4 == 0) {
		return Zwierze::akcja(kierunek);
	}
	else {
		return NIE_MOGE;
	}
}

WynikKolizji zolw::Zolw::kolizja(Organizm* organizm)
{
	if (organizm->GetID() != ZOLW && organizm->getSila() < 5) {
		swiat->DodajKomunikat(NazwaOrganizmu() + " odpycha " + organizm->NazwaOrganizmu() +
			" w (" + std::to_string(x) + "," + std::to_string(y) + ")");
		return ODEPCHNIECIE;
	}
	else
		return Zwierze::kolizja(organizm);
}

void zolw::Zolw::rysowanie()
{
	std::cout << "z";
}
