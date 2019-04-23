#pragma once

#include<vector>
#include<string>

#include "Organizm.h"
#include "Pliki.h"
#include "Swiat.h"

#define DLUGOSC_PREAMBULY 3
#define DLUGOSC_ORGANIZMU 5

/*
 * Struktura pliku
 * 
 * Preambu�a
 * | Bajt(y)	| Zawarto��					|
 * |------------|---------------------------|
 * | 0 - 3		| x - rozmiar planszy		|
 * | 4 - 7		| y - rozmiar planszy		|
 * | 8 - 11		| ilo�� organizm�w			|
 * | od 12		| organizmy					|
 * |------------|---------------------------|
 * 
 * Organizm
 * | Bajt(y)	| Zawarto��					|
 * |------------|---------------------------|
 * |  0 - 3		| sila						|
 * |  4 - 7		| inicjatywa				|
 * |  8 - 11	| x							|
 * | 12 - 15	| y							|
 * | 16 - 19	| id						|
 * |------------|---------------------------|
 */

class StanZapisu
{
private:
	Plik* plikZeStanemZapisu;

	int x, y;
	std::vector<Organizm*>* listaOrganizmow;
	Swiat* swiat;

	bool stanWczytany = false;

public:
	StanZapisu(Swiat* swiat = nullptr);
	std::vector<Organizm*>* Wczytaj(std::string plik);
	void Zapisz(std::string plik);

	//gettery
	std::vector<Organizm*>* ListaOrganizmow();
	int X();
	int Y();

	//settery
	/*void ustawListeOrganizmow(std::vector<Organizm*> listaOrganizmow);
	void ustawX();
	void ustawY();*/
	void UstawSwiat(Swiat* swiat);
};
