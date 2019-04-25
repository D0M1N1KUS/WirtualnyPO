#include "Swiat.h"
#include "Czlowiek.h"

void Swiat::zaalokujNowySwiat(int x, int y)
{
	plansza = new Organizm**[x];
	for (int i = 0; i < x; i++)
	{
		plansza[i] = new Organizm*[y];
		for (int j = 0; j < y; j++)
		{
			plansza[i][j] = nullptr;
		}
	}
}

Swiat::Swiat(int xs, int ys)
	: xs(xs), ys(ys), listaKomuinikatow(new std::vector<std::string>())
{
	if (xs < MIN_X || ys < MIN_Y || xs > 80 || ys > 80)
		throw std::exception("Podano nieprawidlowy rozmiar planszy!");
	//zaalokujNowySwiat(ys, xs);
}

void Swiat::wyczyscSwiat()
{
	if (plansza != nullptr) {
		for (int i = 0; i < xs; i++)
		{
			for (int j = 0; j < ys; j++)
				if(plansza[i][j] != nullptr)
					delete plansza[i][j];
			delete[] plansza[i];
		}
		delete[] plansza;
	}

	/*if (listaOrganizmow != nullptr) {
		listaOrganizmow->clear();
		delete listaOrganizmow;
	}*/
}

Swiat::~Swiat()
{
	wyczyscSwiat();
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

void Swiat::inicjalizujSwiat(std::vector<Organizm*>* listaOrganizmow, int x, int y)
{
	wyczyscSwiat();
	xs = x;
	ys = y;
	zaalokujNowySwiat(x, y);
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
		break;
	case TRAWA:
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
		break;
	case CZLOWIEK:
		nowyOrganizm = new czlowiek::Czlowiek(5, 4, x, y, this);
		break;
	default:
		throw std::exception("nieznane ID organizmu");
	}

	if (!poleJestPuste(x, y))
		throw std::exception("tu juz jest organizm");
	
	plansza[x][y] = nowyOrganizm;
	organizmDoDodania = nowyOrganizm;
}

Organizm* Swiat::stworzNowyOrganizm(IdOrganizmu ID, int pozycjaX, int pozycjaY, int sila, int inicjatywa)
{
	Organizm* nowyOrganizm = nullptr;
	switch (ID)
	{
	case WILK:
		nowyOrganizm = new wilk::Wilk(sila, inicjatywa, pozycjaX, pozycjaY, this);
		break;
	case OWCA:
		nowyOrganizm = new owca::Owca(sila, inicjatywa, pozycjaX, pozycjaY, this);
		break;
	case LIS:
		nowyOrganizm = new lis::Lis(sila, inicjatywa, pozycjaX, pozycjaY, this);
		break;
	case ZOLW:
		nowyOrganizm = new zolw::Zolw(sila, inicjatywa, pozycjaX, pozycjaY, this);
		break;
	case ANTYLOPA:
		nowyOrganizm = new antylopa::Antylopa(sila, inicjatywa, pozycjaX, pozycjaY, this);
		break;
	case TRAWA:
		nowyOrganizm = new trawa::Trawa(sila, pozycjaX, pozycjaY, this);
		break;
	case MLECZ:
		nowyOrganizm = new mlecz::Mlecz(sila, pozycjaX, pozycjaY, this);
		break;
	case GUARANA:
		nowyOrganizm = new guarana::Guarana(sila, pozycjaX, pozycjaY, this);
		break;
	case WILCZAJAGODA:
		nowyOrganizm = new wilczeJagody::WilczeJagody(sila, pozycjaX, pozycjaY, this);
		break;
	case BARSZ:
		nowyOrganizm = new barszcz::Barszcz(sila, pozycjaX, pozycjaY, this);
		break;
	case CZLOWIEK:
		nowyOrganizm = new czlowiek::Czlowiek(sila, inicjatywa, pozycjaX, pozycjaY, this);
		break;
	default:
		throw std::exception("nieznane ID organizmu");
	}

	return nowyOrganizm;
}

void Swiat::usunOrganizmZPlanszy(Organizm * org)
{
	int x = org->getX(), y = org->getY();
	if (plansza[x][y] == NULL)
		throw std::exception((std::string("Proba usniecia organizmu z pustego pola (") +
			std::to_string(x) + "," + std::to_string(y) + ")").c_str());
	plansza[x][y] = NULL;
}

std::vector<Organizm*>::iterator Swiat::poczatekListyOrganizmow()
{
	return listaOrganizmow->begin();
}

std::vector<Organizm*>::iterator Swiat::koniecListyOrganizmow()
{
	return listaOrganizmow->end();
}

void Swiat::ustawOrganizmDoUsuniecia(Organizm* organizm)
{
	organizmDoUsuniecia = organizm;
}

int Swiat::usunOrganizm(int i, int daneI)
{
	listaOrganizmow->erase(listaOrganizmow->begin() + i);
	return i <= daneI ? daneI - 1 : daneI;
}

int Swiat::usunOrganizmDoUsuniecia(int daneI)
{
	auto doUsuniecia = std::find(listaOrganizmow->begin(), listaOrganizmow->end(), organizmDoUsuniecia);
	int i = std::distance(listaOrganizmow->begin(), doUsuniecia);
	listaOrganizmow->erase(doUsuniecia);
	return i <= daneI ? daneI - 1 : daneI;
}

int Swiat::dodajOrganizmDoDodania(int daneI)
{
	int i = -1;
	for (std::vector<Organizm*>::iterator itA = listaOrganizmow->begin(); itA != listaOrganizmow->end(); ++itA)
	{
		if (organizmDoDodania->GetID() == (*itA)->GetID())
		{
			for (auto itB = itA; itB != listaOrganizmow->end(); ++itB)
			{
				if (organizmDoDodania->GetID() != (*itB)->GetID() || itB == listaOrganizmow->end() - 1)
				{
					i = std::distance(listaOrganizmow->begin(), listaOrganizmow->insert(itB, organizmDoDodania));
					break;
				}
			}
			break;
		}
	}

	return  i <= daneI ? daneI + 1 : daneI;
}

int Swiat::getXS()
{
	return this->xs;
}

int Swiat::getYS()
{
	return this->ys;
}

int Swiat::getIloscOrganizmow()
{
	return listaOrganizmow->size();
}

Organizm* Swiat::getOrganizm(int i)
{
	return listaOrganizmow->at(i);
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


