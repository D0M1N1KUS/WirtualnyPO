#include "StanZapisu.h"
#include "Organizm.h"

StanZapisu::StanZapisu(Swiat* swiat)
{
	this->swiat = swiat;
}

std::vector<Organizm*>* StanZapisu::Wczytaj(std::string plik)
{
	plikZeStanemZapisu = new Plik(plik);

	//Wczytanie informacji o świecie
	x = plikZeStanemZapisu->CzytajINT();
	y = plikZeStanemZapisu->CzytajINT();
	int iloscOrganizmow = plikZeStanemZapisu->CzytajINT();

	if (listaOrganizmow == nullptr)
		listaOrganizmow = new std::vector<Organizm*>();
	else
		listaOrganizmow->clear();

	//Wczytanie organizmów
	for(int i = 0; i < iloscOrganizmow; i++)
	{
		int* daneOrganizmu = plikZeStanemZapisu->CzytajINTy(DLUGOSC_PREAMBULY + DLUGOSC_ORGANIZMU*i, 
			DLUGOSC_ORGANIZMU);
		listaOrganizmow->push_back(swiat->stworzNowyOrganizm(static_cast<IdOrganizmu>(daneOrganizmu[4]),
			daneOrganizmu[2], daneOrganizmu[3], daneOrganizmu[0], daneOrganizmu[1]));
	}

	delete plikZeStanemZapisu;
	stanWczytany = true;
	return listaOrganizmow;
}

void StanZapisu::Zapisz(std::string plik)
{
	if (swiat == nullptr)
		throw std::exception("Zapisanie stany jest niemozliwy! Podano pusty wskaznik do swiata.");
	
	plikZeStanemZapisu = new Plik(plik, true);

	//Zapisanie informacji o świecie
	plikZeStanemZapisu->ZapiszINT(swiat->getXS());	//TODO: doda� do �wiata metod� do pobierania ilo�ci lub uczyni� StanZapisu klas� zaprzyja�nion�
	plikZeStanemZapisu->ZapiszINT(swiat->getYS());
	plikZeStanemZapisu->ZapiszINT(swiat->getIloscOrganizmow());

	//Zapisanie organizmów
	for(auto it = swiat->poczatekListyOrganizmow(); it != swiat->koniecListyOrganizmow(); ++it)
	{
		int organizm[] = { (*it)->getSila(), (*it)->getInicjatywa(), (*it)->getX(), (*it)->getY(), (*it)->GetID() };
		plikZeStanemZapisu->ZapiszINTy(organizm, 5);
	}

	delete plikZeStanemZapisu;
}

std::vector<Organizm*>* StanZapisu::ListaOrganizmow()
{
	return  listaOrganizmow;
}

int StanZapisu::X()
{
	return x;
}

int StanZapisu::Y()
{
	return y;
}

void StanZapisu::UstawSwiat(Swiat* swiat)
{
	this->swiat = swiat;
	x = swiat->getXS();
	y = swiat->getYS();
	//iloscOrganizmow = swiat.getIloscOrganizmow(); //TODO
}



