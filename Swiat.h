#pragma once

#include <vector>
#include <string>
#include "Organizm.h"
#include "wilk.h"
#include "owca.h"
#include "antylopa.h"
#include "zolw.h"
#include "lis.h"
#include "barszczsosnowskiego.h"
#include "mlecz.h"
#include "guarana.h"
#include "wilczejagody.h"
#include "trawa.h"


#define MIN_X 5
#define MIN_Y 5
#define MINIMALNA_ILOSC_ORGANIZMOW 20


class Swiat
{
private:
	int xs, ys; //wymiary �wiata
	int organizmy;
	Organizm*** plansza;
	std::vector<Organizm*>* listaOrganizmow;
	std::vector<std::string>* listaKomuinikatow;

	Organizm* organizmDoUsuniecia;
	Organizm* organizmDoDodania;

public:
	void zaalokujNowySwiat(unsigned int y, unsigned int x);
	Swiat(int xs, int ys);
	void wyczyscSwiat();
	~Swiat();

	void Ruch(Organizm* org, int Xobecny, int Yobecny);
	Organizm* GetOrganizmXY(int x, int y);
	bool poleJestPuste(int x, int y);

	void inicjalizujSwiat(std::vector<Organizm*>* listaOrganizmow, int x, int y);
	void dodajNowyOrganizm(IdOrganizmu ID, int x, int y);
	Organizm* stworzNowyOrganizm(IdOrganizmu ID, int pozycjaX, int pozycjaY, int sila = 0, int inicjatywa = 0);
	void usunOrganizmZPlanszy(Organizm* org);

	std::vector<Organizm*>::iterator poczatekListyOrganizmow();
	std::vector<Organizm*>::iterator koniecListyOrganizmow();
	void ustawOrganizmDoUsuniecia(Organizm* organizm);

	int usunOrganizm(int i, int daneI);
	int usunOrganizmDoUsuniecia(int daneI);
	int dodajOrganizmDoDodania(int daneI);

	int getXS();
	int getYS();
	int getIloscOrganizmow();
	Organizm* getOrganizm(int i);

	void DodajKomunikat(std::string komunikat);
	void WyczyscKomunikaty();
	std::vector<std::string>* GetKomunikaty();
};
