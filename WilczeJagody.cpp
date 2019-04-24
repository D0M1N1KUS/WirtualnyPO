#include "WilczeJagody.h"
#include "Swiat.h"
#include <iostream>

wilczeJagody::WilczeJagody::WilczeJagody(int sila, int x, int y, Swiat * swiat)
	: Roslina(sila, x, y, swiat, IdOrganizmu::WILCZAJAGODA) { }

WynikKolizji wilczeJagody::WilczeJagody::kolizja(Organizm* organizm)
{
	Roslina::kolizja(organizm);
	swiat->usunOrganizmZPlanszy(this);
	swiat->usunOrganizmZPlanszy(organizm);
	swiat->DodajKomunikat(NazwaOrganizmu(organizm->GetID()) + " zatrul sie w (" + 
		std::to_string(x) + "," + std::to_string(y) + ")");
	return ZATRUCIE;
}

void wilczeJagody::WilczeJagody::rysowanie()
{
	std::cout << "&";
}
