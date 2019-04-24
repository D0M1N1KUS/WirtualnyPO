#include"Roslina.h"

#include"Swiat.h"
#include <ctime>
#include"WolnePola.h"

roslina::Roslina::Roslina(int sila, int x, int y, Swiat * swiat, IdOrganizmu ID)
	:Organizm(sila, 0, x, y, swiat, ID)
{
	srand(time(NULL));
}

int roslina::Roslina::akcja(Kierunek kierunek)
{
	if(nowyOrganizm)
	{
		nowyOrganizm = false;
	}
	else if(rand() % 100 < PRAWDOPODOBIENSTWO_ROZRASTANIA_SIE)
	{
		wolnePola::WolnePola wyszukanieWolnychPol(Punkt(x, y), Rozmiar(3, 3), swiat);
		std::vector<Punkt>* wolnePola = wyszukanieWolnychPol.ZnajdzWolnePola();

		if (wolnePola->empty())
			return NIE_MOGE;
		else
		{
			Punkt punkDocelowy = wolnePola->at(rand() % wolnePola->size());
			swiat->dodajNowyOrganizm(ID, punkDocelowy.x, punkDocelowy.y);
			swiat->DodajKomunikat(NazwaOrganizmu() + " rozroslo sie w (" +
				std::to_string(punkDocelowy.x) + "," + std::to_string(punkDocelowy.y) + ")");
			return ROZMNAZANIE;
		}
	}
	return NIE_MOGE;
}

WynikKolizji roslina::Roslina::kolizja(Organizm* organizm)
{
	int x = organizm->getX(), y = organizm->getY();
	IdOrganizmu idSasiada = organizm->GetID();
	if (jestZwierze(idSasiada))
	{
		swiat->DodajKomunikat(NazwaOrganizmu(organizm->GetID()) + " zjadl " + NazwaOrganizmu() +
			" w (" + std::to_string(x) + "," + std::to_string(y) + ")");
		return SMIERC;
	}
	else
		throw std::exception("Roslina nie moze atakowac druga rosline!");
}

