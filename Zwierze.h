#pragma once
#include "Enumy.h"
#include "Organizm.h"


class Zwierze : public Organizm
{
public:
	Zwierze(int sila, int inicjatywa, int x, int y, Swiat* swiat, IdOrganizmu Id);
	int akcja(Kierunek kierunek = BRAK);
	void rysowanie() override = 0;

protected:
	WynikKolizji kolizja(Organizm* organizm);
	bool rozmnazaj(int x, int y);

private:
	void dodajKomunikatO_WynikuWalki(Organizm* organizm, int x, int y, bool przeciwnikZginal);
};

