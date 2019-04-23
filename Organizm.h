#pragma once
#include "Enumy.h"
#include <string>
//#include "conio2.h"

class Swiat;

class Organizm
{
protected:
	int sila, inicjatywa, x, y;
	IdOrganizmu ID;
	Swiat* swiat;
	bool ruchZrobiony = true;

	bool jestZwierze(IdOrganizmu id);

public:
	virtual ~Organizm() = default;
	Organizm(int sila, int inicjatywa, int x, int y, Swiat* swiat, IdOrganizmu Id);
	
	virtual int akcja(Kierunek kierunek = BRAK) = 0;
	virtual WynikKolizji kolizja(Organizm* organizm) = 0;
	virtual void rysowanie() = 0;

	void setPozycja(int x, int y);
	int getX();
	int getY();
	int getSila();
	int getInicjatywa();
	IdOrganizmu GetID();

	std::string NazwaOrganizmu();
	static std::string NazwaOrganizmu(IdOrganizmu id);

};

