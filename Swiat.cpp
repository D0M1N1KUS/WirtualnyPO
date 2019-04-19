#include "Swiat.h"

void Swiat::zaalokujNowySwiat(unsigned int y, unsigned int x)
{
	plansza = new Organizm**[y];
	for (int i = 0; i < y; i++)
	{
		plansza[i] = new Organizm*[x];
		for (int j = 0; j < x; j++)
		{
			plansza[i][j] = NULL;
		}
	}
}

Swiat::Swiat(int xs, int ys)
	: xs(xs), ys(ys), listaKomuinikatow(new std::vector<std::string>())
{
	if (xs < MIN_X || ys < MIN_Y || xs > 80 || ys > 80)
		throw std::exception("Podano nieprawidlowy rozmiar planszy!");
	zaalokujNowySwiat(ys, xs);
}

Swiat::~Swiat()
{
	for (int i = 0; i < xs; i++)
	{
		for (int j = 0; j < ys; j++)
			delete plansza[i][j];
		delete[] plansza[i];
	}
	delete[] plansza;
	listaOrganizmow->clear();
	delete[] listaOrganizmow;
}

void Swiat::Ruch(Organizm* organizm, int Xobecny, int Yobecny)
{
	int x = organizm->getX();
	int y = organizm->getY();

	this->plansza[x][y] = NULL;
	this->plansza[Xobecny][Yobecny] = organizm;
	organizm->setPozycja(Xobecny, Yobecny);
}

Organizm* Swiat::GetOrganizmXY(int x, int y)
{
	if (x < 0 || x >= xs || y < 0 || y >= ys)
		throw std::exception("Wykroczono poza obszar");
	return plansza[x][y];
}

bool Swiat::poleJestPuste(int x, int y)
{
	return GetOrganizmXY(x,y) == NULL;
}

void Swiat::inicjalizujSwiat(std::vector<Organizm*>* listaOrganizmow)
{
	zaalokujNowySwiat(xs, ys);
	this->listaOrganizmow = listaOrganizmow;
	for (int i = 0; i < listaOrganizmow->size(); i++)
	{
		Organizm* organizmTmp = listaOrganizmow->at(i);
		plansza[organizmTmp->getX()][organizmTmp->getY()] = organizmTmp;
	}
}

void Swiat::dodajNowyOrganizm(IdOrganizmu ID, int x, int y)
{
	Organizm* nowyOrganizm = nullptr;
	switch (ID)
	{
	case WILK: 
		nowyOrganizm = new wilk::Wilk(9, 5, x, y, this);
		break;
	case OWCA:
		nowyOrganizm = new owca::Owca(4, 4, x, y, this);
		break;
	case LIS:
		nowyOrganizm = new lis::Lis(3, 7, x, y, this);
		break;
	case ZOLW:
		nowyOrganizm = new zolw::Zolw(2, 1, x, y, this);
		break;
	case ANTYLOPA:
		nowyOrganizm = new antylopa::Antylopa(4, 4, x, y, this);
	/*case TRAWA:
		nowyOrganizm = new trawa::Trawa(0, x, y, this);
		break;
	case MLECZ:
		nowyOrganizm = new mlecz::Mlecz(0, x, y, this);
		break;
	case GUARANA:
		nowyOrganizm = new guarana::Guarana(0, x, y, this);
		break;
	case WILCZAJAGODA:
		nowyOrganizm = new wilczeJagody::WilczeJagody(99, x, y, this);
		break;
	case BARSZ:
		nowyOrganizm = new barszcz::Barszcz(10, x, y, this);
		break;*/
	default:
		throw std::exception("nieznane ID organizmu");
	}

	if (!poleJestPuste(x, y))
		throw std::exception("tu juz jest organizm");
	
	plansza[x][y] = nowyOrganizm;
	organizmDoDodania = nowyOrganizm;
}

void Swiat::usunOrganizm(Organizm * org)
{
	plansza[org->getX()][org->getY()] = NULL;
	std::vector<Organizm*>::iterator iterator = 
		std::find(listaOrganizmow->begin(), listaOrganizmow->end(), org);
	if (iterator != listaOrganizmow->end())
		listaOrganizmow->erase(iterator);
	delete org;
}

std::vector<Organizm*>::iterator Swiat::poczatekListyOrganizmow()
{
	return listaOrganizmow->begin();
}

std::vector<Organizm*>::iterator Swiat::koniecListyOrganizmow()
{
	return listaOrganizmow->end();
}

std::vector<Organizm*>::iterator Swiat::usunOrganizm(std::vector<Organizm*>::iterator iterator)
{
	return listaOrganizmow->erase(iterator);
}

void Swiat::ustawOrganizmDoUsuniecia(Organizm* organizm)
{
	organizmDoUsuniecia = organizm;
}

std::vector<Organizm*>::iterator Swiat::usunOrganizmDoUsuniecia(Organizm* danyOrganizm)
{
	listaOrganizmow->erase(std::find(listaOrganizmow->begin(), listaOrganizmow->end(), danyOrganizm));
	return std::find(listaOrganizmow->begin(), listaOrganizmow->end(), danyOrganizm);
}

std::vector<Organizm*>::iterator Swiat::dodajOrganizmDoDodania(Organizm* danyOrganizm)
{
	for (std::vector<Organizm*>::iterator itA = listaOrganizmow->begin(); itA != listaOrganizmow->end(); ++itA)
	{
		if (organizmDoDodania->GetID() == (*itA)->GetID())
		{
			for (auto itB = itA; itB != listaOrganizmow->end(); ++itB)
			{
				if (organizmDoDodania->GetID() != (*itB)->GetID() || itB == listaOrganizmow->end() - 1)
				{
					listaOrganizmow->insert(itB, organizmDoDodania);
					break;
				}
			}
			break;
		}
	}
	return std::find(listaOrganizmow->begin(), listaOrganizmow->end(), danyOrganizm);
}

int Swiat::getXS()
{
	return this->xs;
}

int Swiat::getYS()
{
	return this->ys;
}

void Swiat::DodajKomunikat(std::string komunikat)
{
	listaKomuinikatow->push_back(komunikat);
}

void Swiat::WyczyscKomunikaty()
{
	listaKomuinikatow->clear();
}

std::vector<std::string>* Swiat::GetKomunikaty()
{
	return listaKomuinikatow;
}


