#include "Gra.h"

#include<string>
#include"Enumy.h"
#include<conio.h>
#include <iostream>
#include "Konsola.h"

#define ZAPIS 's'
#define WCZYTAJ 'l'
#define ZAKONCZ 'q'

#define KLAWISZ_SPECJALNY 224

#define LOKALIZACJA_ZAPISU "zapis.bin"

using namespace std;

gra::Gra::Gra(int x, int y)
{
	tworcaSwiata = new tworcaSwiata::TworcaSwiata(x, y);
	swiat = tworcaSwiata->StworzSwiat();
	
	rysownikSwiata = new rysowanieSwiata::RysowanieSwiata(swiat);
	stanZapisu = new StanZapisu(swiat);
}

gra::Gra::~Gra()
{
	delete swiat;
	delete tworcaSwiata;
	delete stanZapisu;
	delete rysownikSwiata;
}

void gra::Gra::obslugaSterowania()
{
	nacisnietyPrzycisk = obslugaKlawiszy();

	if (nacisnietyPrzycisk == K_GORA || nacisnietyPrzycisk == K_DOL || nacisnietyPrzycisk == K_LEWO ||
		nacisnietyPrzycisk == K_PRAWO || nacisnietyPrzycisk == K_MOC || nacisnietyPrzycisk == K_BRAK)
		wykonajTure();
	else if (nacisnietyPrzycisk == ZAPIS)
	{
		stanZapisu->Zapisz(LOKALIZACJA_ZAPISU);
		swiat->DodajKomunikat("Zapisano!");
	}
	else if (nacisnietyPrzycisk == WCZYTAJ)
	{
		auto nowaListaOrganizmow = stanZapisu->Wczytaj(LOKALIZACJA_ZAPISU);
		swiat->inicjalizujSwiat(nowaListaOrganizmow, stanZapisu->X(), stanZapisu->Y());
		swiat->DodajKomunikat("Wczytano!");
	}
	else if (nacisnietyPrzycisk == ZAKONCZ)
		return;
	else
		swiat->DodajKomunikat("Nieznany klawisz");
}

void gra::Gra::Rozpocznij()
{
	wyczyscEkran();

	swiat->DodajKomunikat("Krotki komunikat");
	swiat->DodajKomunikat("Dlugi komunikat: Uwaga! Autor gry nie poniesie odpowiedzialnosci za wszelkie krzywdy, odniesione podczas grania. Grasz na wlasna odpowiedzialnosc. To jest wersja pre-pre-pre-pre-alpha, wiec szalu nie ma. Milej gry xDDDDDD!");

	do {
		try {
			rysownikSwiata->rysujSwiat();
			rysownikSwiata->wypiszKomunikaty();
			obslugaSterowania();

			wyczyscEkran();
		}
		catch (std::exception e)
		{
			cout << e.what() << endl;
			pause();
		}		
	} while (nacisnietyPrzycisk != 'q');

}

int gra::Gra::obslugaKlawiszy()
{
	int klawisz = _getch();
	if (klawisz == KLAWISZ_SPECJALNY)
		return _getch();
	else
		return klawisz;
}

void gra::Gra::wykonajTure()
{
	for (int i = 0; i < swiat->getIloscOrganizmow(); i++)
	{
		int wynik = swiat->getOrganizm(i)->GetID() == CZLOWIEK
			? swiat->getOrganizm(i)->akcja(konwertujNaKierunek(nacisnietyPrzycisk))
			: swiat->getOrganizm(i)->akcja();
		if (wynik == SMIERC || wynik == ZATRUCIE)
			i = swiat->usunOrganizm(i, i);
		if (wynik == ZWYCIESTWO || wynik == ZATRUCIE)
			i = swiat->usunOrganizmDoUsuniecia(i);
		if (wynik == ROZMNAZANIE)
			i = swiat->dodajOrganizmDoDodania(i);
	}

	pierwszaTura = false;
}

Kierunek gra::Gra::konwertujNaKierunek(int k_kier)
{
	switch (k_kier)
	{
	case K_BRAK:
		return BRAK;
	case K_DOL:
		return DOL;
	case K_GORA:
		return GORA;
	case K_LEWO:
		return LEWO;
	case K_PRAWO:
		return PRAWO;
	case K_MOC:
		return MOC;
	default:
		return BRAK;
	}
}
