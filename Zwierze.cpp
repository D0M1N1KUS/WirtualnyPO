#include "Zwierze.h"
#include <stdlib.h>
#include <vector>
#include "WolnePola.h"
#include <ctime>


Zwierze::Zwierze(int sila, int inicjatywa, int x, int y, Swiat* swiat, IdOrganizmu Id)
	: Organizm(sila, inicjatywa, x, y, swiat, Id) 
{ 
	srand(time(NULL));
}

void Zwierze::dodajKomunikatO_WynikuWalki(Organizm* organizm, int x, int y, bool przeciwnikZginal)
{
	if (przeciwnikZginal) {
		swiat->DodajKomunikat(NazwaOrganizmu() + " zabil " + NazwaOrganizmu(organizm->GetID()) +
			" w (" + std::to_string(x) + "," + std::to_string(y) + ")");
	}
	else
	{
		swiat->DodajKomunikat(NazwaOrganizmu(organizm->GetID()) + " zabil " + NazwaOrganizmu() + 
			" w (" + std::to_string(x) + "," + std::to_string(y) + ")");
	}
}

WynikKolizji Zwierze::kolizja(Organizm* organizm)
{
	int x = organizm->getX(), y = organizm->getY();
	IdOrganizmu idSasiada = organizm->GetID();
	int silaSasiada = organizm->getSila();

	if (jestZwierze(idSasiada))
	{
		if (idSasiada == ID)
		{
			if (!organizm->organizmJestNowy() && rozmnazaj(x, y))
			{
				return ROZMNAZANIE;
			}
			else
				return NIE_MOGE;
		}
		else
		{
			if (silaSasiada <= sila)
			{
				swiat->ustawOrganizmDoUsuniecia(organizm);
				dodajKomunikatO_WynikuWalki(organizm, x, y, true);
				swiat->Ruch(this, x, y);
				return ZWYCIESTWO;
			}
			else
			{
				swiat->ustawOrganizmDoUsuniecia(this);
				dodajKomunikatO_WynikuWalki(organizm, x, y, false);
				return SMIERC;
			}
		}
	}
	else
		throw std::exception("Roslina nie moze atakowac!");
}

bool Zwierze::rozmnazaj(int x, int y)
{
	Punkt punktA = Punkt(x, y);
	Punkt punktB = Punkt(this->x, this->y);
	wolnePola::WolnePola wolnePole(punktA, punktB, swiat);
	std::vector<Punkt>* wektor = wolnePole.ZnajdzWolnePola();
	if (!wektor->empty())
	{
		int wylosowanePole = rand() % wektor->size(),
			a = wektor->at(wylosowanePole).x,
			b = wektor->at(wylosowanePole).y;
		swiat->dodajNowyOrganizm(ID, a, b);
		swiat->DodajKomunikat(NazwaOrganizmu(ID) + " rozmnozyl sie w (" +
			std::to_string(x) + "," + std::to_string(y) + ")");
		return true;
	}
	return false;
}

int Zwierze::akcja(Kierunek kierunek)
{
	if(nowyOrganizm)
	{
		nowyOrganizm = false;
		return NIE_MOGE;
	}

	int nowyX = x, nowyY = y;

	switch (kierunek == BRAK ?  rand() % 4 : kierunek)
	{
	case GORA:
		if (y > 0) nowyY = y - 1;
		else return NIE_MOGE;
		break;
	case DOL:
		if (y < swiat->getYS() - 1) nowyY = y + 1;
		else return NIE_MOGE;
		break;
	case LEWO:
		if (x > 0) nowyX = x - 1;
		else return NIE_MOGE;
		break;
	case PRAWO:
		if (x < swiat->getXS() - 1) nowyX = x + 1;
		else return NIE_MOGE;
	default:
		break;
	}

	if (swiat->poleJestPuste(nowyX, nowyY))
	{
		swiat->Ruch(this, nowyX, nowyY);
		return RUCH;
	}
	else
	{
		WynikKolizji wynik = swiat->GetOrganizmXY(nowyX, nowyY)->kolizja(this);
		if (wynik == SMIERC) {
			swiat->Ruch(this, nowyX, nowyY);
			return ZWYCIESTWO;
		}
		if (wynik == ZWYCIESTWO)
			return SMIERC;
		return wynik;
	}	
}

