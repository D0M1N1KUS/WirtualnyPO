#include "StanZapisu.h"
#include "Organizm.h"

StanZapisu::StanZapisu(Swiat* swiat)
{
	this->swiat = swiat;
}

Swiat* StanZapisu::Wczytaj(std::string plik)
{
	plikZeStanemZapisu = new Plik(plik);

	x = plikZeStanemZapisu->CzytajINT();
	y = plikZeStanemZapisu->CzytajINT();
	iloscOrganizmow = plikZeStanemZapisu->CzytajINT();

	listaOrganizmow = new std::vector<Organizm*>();

	for(int i = 0; i < iloscOrganizmow; i++)
	{
		//int* daneOrganizmu = plikZeStanemZapisu->CzytajINTy(DLUGOSC_ORGANIZMU);
		//TODO: stworzy� organizmy
	}

	delete plikZeStanemZapisu;
	stanWczytany = true;
	return nullptr; //TODO
}

void StanZapisu::Zapisz(std::string plik)
{
	if (swiat == nullptr)
		throw std::exception("Zapisanie stany jest niemozliwy! Podano pusty wskaznik do swiata.");
	
	plikZeStanemZapisu = new Plik(plik, true);

	plikZeStanemZapisu->ZapiszINT(x);
	plikZeStanemZapisu->ZapiszINT(y);
	//plikZeStanemZapisu->ZapiszINT(swiat->organizmy);	//TODO: doda� do �wiata metod� do pobierania ilo�ci lub uczyni� StanZapisu klas� zaprzyja�nion�

	//TODO: Zapisa� w forze organizmy do pliku

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



