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
	~Swiat();

	void Ruch(Organizm* org, int Xobecny, int Yobecny);
	Organizm* GetOrganizmXY(int x, int y);
	bool poleJestPuste(int x, int y);

	void inicjalizujSwiat(std::vector<Organizm*>* listaOrganizmow);
	void dodajNowyOrganizm(IdOrganizmu ID, int x, int y);
	void usunOrganizm(Organizm* org);

	std::vector<Organizm*>::iterator poczatekListyOrganizmow();
	std::vector<Organizm*>::iterator koniecListyOrganizmow();
	std::vector<Organizm*>::iterator usunOrganizm(std::vector<Organizm*>::iterator iterator);
	void ustawOrganizmDoUsuniecia(Organizm* organizm);
	std::vector<Organizm*>::iterator usunOrganizmDoUsuniecia(Organizm* danyOrganizm);
	std::vector<Organizm*>::iterator dodajOrganizmDoDodania(Organizm* danyOrganizm);

	

	int getXS();
	int getYS();

	void DodajKomunikat(std::string komunikat);
	void WyczyscKomunikaty();
	std::vector<std::string>* GetKomunikaty();
};
