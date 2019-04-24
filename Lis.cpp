#include "Lis.h"
#include <stdlib.h>
#include <vector>
#include <iostream>
#include "Swiat.h"

#define SILA 3
#define INICJATYWA 7


lis::Lis::Lis(int sila, int inicjatywa, int x, int y, Swiat * swiat)
	: Zwierze(sila, inicjatywa, x, y, swiat, IdOrganizmu::LIS)
{
}

int lis::Lis::akcja()
{
	std::vector<Kierunek>* bezpiecznePola = new std::vector<Kierunek>();
	if (y > 0 && polePusteLubSlabyPrzeciwnik(x, y - 1))
		bezpiecznePola->push_back(GORA);
	if (y < swiat->getYS() - 1 && polePusteLubSlabyPrzeciwnik(x, y + 1))
		bezpiecznePola->push_back(DOL);
	if (x > 0 && polePusteLubSlabyPrzeciwnik(x - 1, y))
		bezpiecznePola->push_back(LEWO);
	if (x < swiat->getXS() - 1 && polePusteLubSlabyPrzeciwnik(x + 1, y))
		bezpiecznePola->push_back(PRAWO);

	int wylosowanyKierunek = rand() % bezpiecznePola->size();
	
	return Zwierze::akcja(bezpiecznePola->at(wylosowanyKierunek));
}

bool lis::Lis::polePusteLubSlabyPrzeciwnik(int x, int y)
{
	return swiat->poleJestPuste(x, y) || this->getSila() > swiat->GetOrganizmXY(x, y)->getSila();
}

void lis::Lis::rysowanie()
{
	std::cout << "l";
}
