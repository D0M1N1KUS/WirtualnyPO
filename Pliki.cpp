#include <sys/stat.h>
#include <cstdio>
#include "Pliki.h"

Plik::Plik(std::string& plik, bool stworzNowyPlik)
{
	nazwaPliku = plik;

	const bool plikIstnieje = PlikIstnieje(nazwaPliku);
	if (!plikIstnieje && !stworzNowyPlik)
		throw std::exception((std::string{ "Plik \"" } + plik + std::string{ "\" nie istnieje!" }).c_str());
	if(stworzNowyPlik)
		std::ofstream(nazwaPliku, std::ios::trunc).close();

	pozycja = 0;
}

void Plik::ZapiszINT(int i)
{
	outputFileStream.open(nazwaPliku, trybOtwarciaZapisuPliku);

	unsigned char* bufor = new unsigned char[sizeof(int) / sizeof(char)];
	intTabToCharTab(&i, 1, bufor);

	outputFileStream.write(reinterpret_cast<char*>(bufor), sizeof(int));
	outputFileStream.flush();
	outputFileStream.close();
	delete[] bufor;
}

void Plik::ZapiszINTy(int* i_tab, long rozmiar)
{
	outputFileStream.open(nazwaPliku, trybOtwarciaZapisuPliku);

	char* bufor = new char[rozmiar * sizeof(int) / sizeof(char)];
	long dlugoscTablicyZnakow = intTabToCharTab(i_tab, rozmiar, reinterpret_cast<unsigned char*>(bufor));

	outputFileStream.write(bufor, dlugoscTablicyZnakow);
	outputFileStream.flush();
	outputFileStream.close();
	delete[] bufor;
}

int Plik::CzytajINT()
{
	return CzytajINT(pozycja++);
}

int Plik::CzytajINT(long pozycjaW_Pliku)
{
	inputFileStream.open(nazwaPliku, trybOtwarciaOdczytuPliku);
	inputFileStream.ignore(pozycjaW_Pliku * sizeof(int));

	char bufor[sizeof(int)];
	inputFileStream.read(bufor, sizeof(int));
	inputFileStream.close();

	return charTabToInt(reinterpret_cast<unsigned char*>(bufor));
}

int* Plik::CzytajINTy(long pozycjaW_Pliku, long ilosc)
{
	inputFileStream.open(nazwaPliku, trybOtwarciaOdczytuPliku);
	inputFileStream.ignore(pozycjaW_Pliku * sizeof(int));

	const int iloscBajtow = ilosc * sizeof(int);

	char* bufor = new char[iloscBajtow];
	inputFileStream.read(bufor, iloscBajtow);

	int* wczytaneInty = new int[ilosc];
	for (int i = 0; i < ilosc; i++)
		wczytaneInty[i] = charTabToInt(reinterpret_cast<unsigned char*>(bufor + i * sizeof(int)));

	inputFileStream.close();
	delete[] bufor;

	return wczytaneInty;
}

void Plik::CzytajOdPocz¹tku()
{
	pozycja = 0;
}

bool Plik::PlikIstnieje(std::string& plik)
{
	struct stat buf;
	return stat(plik.c_str(), &buf) != -1;
}

int Plik::intTabToCharTab(const int* tab, const int size, unsigned char* charTab)
{
	const int dlugoscTablicy = size * sizeof(int) / sizeof(char);
	if (charTab == nullptr)
		charTab = new unsigned char[dlugoscTablicy];
	
	for(int i = 0; i < dlugoscTablicy; i++)
	{
		//n = 3, 2, 1, 0, 7, 6, 5, 4, 11, 10, 9, 8, ...
		charTab[i] = 
			tab[i / sizeof(int)] >> ((i % 4) * 8);
	}

	return dlugoscTablicy;
}

int Plik::charTabToInt(const unsigned char* tab)
{
	int returnInt = 0;
	for(int i = sizeof(int) - 1; i >= 0; i--)
	{
		returnInt = returnInt << 8*sizeof(char);
		returnInt = returnInt | static_cast<int>(tab[i]);
	}

	return returnInt;
}
