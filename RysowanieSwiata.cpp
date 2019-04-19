#include "RysowanieSwiata.h"
#include <iostream>
#include<string>
#include <cmath>
#include "Konsola.h"

rysowanieSwiata::RysowanieSwiata::RysowanieSwiata(Swiat * swiat)
{
	this->swiat = swiat;

	rozmiarPlanszy = Rozmiar(swiat->getXS() + 2, swiat->getYS() + 2);
	rozmiarKomunikatow = Rozmiar(SZEROKOSC_KONSOLI - (rozmiarPlanszy.a + ODSTEP), 
		WYSOKOSC_KONSOLI);

	pozycjaPlanszy = Punkt(0, 0);
	pozycjaKomunikatow = Punkt(pozycjaPlanszy.x + rozmiarPlanszy.a + ODSTEP, 0);
}

void rysowanieSwiata::RysowanieSwiata::rysujSwiat()
{
	for (int y = 0; y < swiat->getYS() + 2; y++)
	{
		for (int x = 0; x < swiat->getXS() + 2; x++)
		{
			if (x > 0 && y > 0 && x < swiat->getXS() + 1 && y < swiat->getYS() + 1)
			{
				auto organizm = swiat->GetOrganizmXY(x - 1, y - 1);
				if (organizm == NULL) std::cout << " ";
				else organizm->rysowanie();
			}
			else
				std::cout << "+";
		}
		std::cout << std::endl;
	}
}

void rysowanieSwiata::RysowanieSwiata::wypiszKomunikaty()
{
	auto listaKomunikatow = swiat->GetKomunikaty();
	auto liniaKomunikatu = 0;
	char* bufor = new char[SZEROKOSC_KONSOLI];

	for (const auto& komunikat : *listaKomunikatow)
	{
		for (int j = 0; j <= komunikat.length() / rozmiarKomunikatow.a; j++) {
			gotoxy(pozycjaKomunikatow.x, pozycjaKomunikatow.y + liniaKomunikatu++);

			int dlugoscKomunikatu = rozmiarKomunikatow.a <= komunikat.length() ? rozmiarKomunikatow.a : komunikat.length();
			komunikat.copy(bufor, dlugoscKomunikatu, j * rozmiarKomunikatow.a);
			bufor[dlugoscKomunikatu] = NULL;

			std::cout << bufor;
		}
	}
	swiat->WyczyscKomunikaty();
	liniaKomunikatu = 0;
	delete[] bufor;
}
