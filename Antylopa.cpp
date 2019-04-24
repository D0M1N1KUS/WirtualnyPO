#include "Antylopa.h"
#include <iostream>
#include "WolnePola.h"

#define SILA 4
#define INICJATYWA 4


antylopa::Antylopa::Antylopa(int sila, int inicjatywa, int x, int y, Swiat * swiat)
	: Zwierze(sila, inicjatywa, x, y, swiat, IdOrganizmu::ANTYLOPA)
{
}

void antylopa::Antylopa::sprobujUniknacWalce(int& nowyX, int& nowyY)
{
	if(!swiat->poleJestPuste(nowyX, nowyY))
	{
		Organizm* docelowyOrganizm = swiat->GetOrganizmXY(nowyX, nowyY);
		IdOrganizmu idDocelowegoOrganizmu = docelowyOrganizm->GetID();
		if(ID != idDocelowegoOrganizmu && jestZwierze(idDocelowegoOrganizmu))
		{
			if(rand() % 2 == 0)
			{
				wolnePola::WolnePola szukanieWolnychPol(Punkt(nowyX, nowyY), Rozmiar(3, 3), swiat);
				auto wolnePola = szukanieWolnychPol.ZnajdzWolnePola();

				if (!wolnePola->empty())
				{
					auto docelowyPunkt = wolnePola->at(rand() % wolnePola->size());
					nowyX = docelowyPunkt.x;
					nowyY = docelowyPunkt.y;
					swiat->DodajKomunikat(NazwaOrganizmu() + " unikla walki z " + NazwaOrganizmu(idDocelowegoOrganizmu) +
						" w (" + std::to_string(docelowyOrganizm->getX()) + "," + std::to_string(docelowyOrganizm->getY()) + ")");
				}
				//w przeciwnym przypadku ucieczka jest niemo¿liwa i antylopa walczy
			}
		}
	}
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

	sprobujUniknacWalce(nowyX, nowyY);

	return wykonajRuch(nowyX, nowyY);
}

WynikKolizji antylopa::Antylopa::kolizja(Organizm* organizm)
{
	if (organizm->GetID() == ANTYLOPA)
		return Zwierze::kolizja(organizm);

	wolnePola::WolnePola szukanieWolnychPol(Punkt(x, y), Rozmiar(3, 3), swiat);
	auto wolnePola = szukanieWolnychPol.ZnajdzWolnePola();

	if(rand() % 2 == 0 && !wolnePola->empty())
	{
		swiat->DodajKomunikat(NazwaOrganizmu() + " unikla walki z " + NazwaOrganizmu(organizm->GetID()) +
			" w (" + std::to_string(x) + "," + std::to_string(y) + ")");
		auto docelowyPunkt = wolnePola->at(rand() % wolnePola->size());
		swiat->Ruch(this, docelowyPunkt.x, docelowyPunkt.y);
		return RUCH;
	}
	else
		return Zwierze::kolizja(organizm);
}

void antylopa::Antylopa::rysowanie()
{
	std::cout << "a";
}
