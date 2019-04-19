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

WynikKolizji Zwierze::kolizja(Organizm* organizm)
{
	int x = organizm->getX(), y = organizm->getY();
	IdOrganizmu idSasiada = organizm->GetID();
	int silaSasiada = organizm->getSila();

	if (jestZwierze(idSasiada))
	{
		if (idSasiada == ID)
		{
			if (rozmnazaj(x, y))
			{
				swiat->DodajKomunikat(NazwaOrganizmu(organizm->GetID()) +  " rozmnozyl sie w (" + 
					std::to_string(x) + "," + std::to_string(y) + ")");
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
				swiat->DodajKomunikat(NazwaOrganizmu(organizm->GetID()) + " zabil " + NazwaOrganizmu() + " w (" +
					std::to_string(x) + "," + std::to_string(y) + ")");
				swiat->Ruch(this, x, y);
				return ZWYCIESTWO;
			}
			else
			{
				swiat->DodajKomunikat(NazwaOrganizmu(organizm->GetID()) + " zabil " + NazwaOrganizmu() + " w (" +
					std::to_string(x) + "," + std::to_string(y) + ")");
				return SMIERC;
			}
		}

	}
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
		return true;
	}
	return false;
}

bool Zwierze::jestZwierze(IdOrganizmu id)
{
	return id < 6;
}

int Zwierze::akcja(Kierunek kierunek)
{
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

