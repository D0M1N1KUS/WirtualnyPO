#pragma once

#include<iostream>
#include<fstream>
#include<string>

class Plik
{
private:
	std::ios::openmode trybOtwarciaZapisuPliku = std::ios::binary | std::ios::ate;
	std::ios::openmode trybOtwarciaOdczytuPliku = std::ios::binary;
	std::string nazwaPliku;
	std::ofstream outputFileStream;
	std::ifstream inputFileStream;

	long pozycja;

public:
	Plik(std::string& plik, bool stworzNowyPlik = false);
	void ZapiszINT(int i);
	void ZapiszINTy(int* i_tab, long rozmiar);

	int CzytajINT();
	int CzytajINT(long pozycjaW_Pliku);
	int* CzytajINTy(long pozycjaW_Pliku, long ilosc);

	void CzytajOdPocz¹tku();

	static bool PlikIstnieje(std::string& plik);

private:
	static int intTabToCharTab(const int* tab, int size, unsigned char* charTab = nullptr);
	static int charTabToInt(const unsigned char* tab);
};
