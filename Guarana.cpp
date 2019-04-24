#include "Guarana.h"
#include <iostream>

guarana::Guarana::Guarana(int sila, int x, int y, Swiat * swiat)
	: Roslina(sila, x, y, swiat, GUARANA) { }

WynikKolizji guarana::Guarana::kolizja(Organizm* organizm)
{
	Roslina::kolizja(organizm);
	swiat->DodajKomunikat(NazwaOrganizmu(organizm->GetID()) + " zwmocnil sie do " + 
		std::to_string(organizm->getSila() + 4) + " w (" + std::to_string(x) + "," + std::to_string(y) + ")");
	return WZMOCNIENIE;
}

void guarana::Guarana::rysowanie()
{
	std::cout << "+";
}
