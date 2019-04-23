#include "TworcaSwiata.h"
#include <cstdio>
#include "Organizm.h"
#include <ctime>

void tworcaSwiata::TworcaSwiata::zaalokujTablice()
{
	tablicaSwiata = new bool*[xs];
	for (int i = 0; i < xs; i++)
		tablicaSwiata[i] = new bool[ys];

	for (int i = 0; i < xs; i++)
	{
		for (int j = 0; j < ys; j++)
		{
			tablicaSwiata[i][j] = false;
		}
	}
}

void tworcaSwiata::TworcaSwiata::losujPozycje()
{
	do {
		noweX = rand() % xs;
		noweY = rand() % ys;
	} while (tablicaSwiata[noweX][noweY]);
}

tworcaSwiata::TworcaSwiata::TworcaSwiata(int xs, int ys)
	: xs(xs), ys(ys)
{
	srand(time(NULL));
	nowySwiat = new Swiat(xs, ys);
}

Swiat* tworcaSwiata::TworcaSwiata::StworzSwiat()
{
	auto listaOrganizmow = new std::vector<Organizm*>();
	zaalokujTablice();

	int x, y;

	for (int i = 0; i < LICZBAWILKOW; i++)
	{
		losujPozycje();
		listaOrganizmow->push_back(new wilk::Wilk(9, 5, noweX, noweY, nowySwiat));
		tablicaSwiata[noweX][noweY] = true;
	}

	/*for (int i = 0; i < LICZBAOWIEC; i++)
	{
		losujPozycje();
		listaOrganizmow->push_back(new owca::Owca(4, 6, noweX, noweY, nowySwiat));
	}

	for (int i = 0; i < LICZBALISOW; i++)
	{
		losujPozycje();
		listaOrganizmow->push_back(new lis::Lis(3, 7, noweX, noweY, nowySwiat));
	}

	for (int i = 0; i < LICZBAZOLWI; i++)
	{
		losujPozycje();
		listaOrganizmow->push_back(new zolw::Zolw(2, 1, noweX, noweY, nowySwiat));
	}

	for (int i = 0; i < LICZBAANTYLOP; i++)
	{
		losujPozycje();
		listaOrganizmow->push_back(new antylopa::Antylopa(4, 4, noweX, noweY, nowySwiat));
	}

	for (int i = 0; i < LICZBATRAWY; i++)
	{
		losujPozycje();
		listaOrganizmow->push_back(new trawa::Trawa(0, noweX, noweY, nowySwiat));
	}

	for (int i = 0; i < LICZBAMLECZY; i++)
	{
		losujPozycje();
		listaOrganizmow->push_back(new mlecz::Mlecz(0, noweX, noweY, nowySwiat));
	}

	for (int i = 0; i < LICZBAGUARANY; i++)
	{
		losujPozycje();
		listaOrganizmow->push_back(new guarana::Guarana(0, noweX, noweY, nowySwiat));
	}

	for (int i = 0; i < LICZBAWILCZYCHJAGOD; i++)
	{
		losujPozycje();
		listaOrganizmow->push_back(new wilczeJagody::WilczeJagody(0, noweX, noweY, nowySwiat));
	}

	for (int i = 0; i < LICZBABARSZY; i++)
	{
		losujPozycje();
		listaOrganizmow->push_back(new barszcz::Barszcz(0, noweX, noweY, nowySwiat));
	}
*/
	nowySwiat->inicjalizujSwiat(listaOrganizmow, xs, ys);
	return nowySwiat;
}
