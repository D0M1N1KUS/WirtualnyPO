#pragma once

#include "Swiat.h"
#include "TworcaSwiata.h"
#include "RysowanieSwiata.h"
//#include "StanZapisu.h"

#define K_GORA 0x48
#define K_DOL 0x50
#define K_LEWO 0x4b
#define K_PRAWO 0x4d
#define K_MOC 0x20
#define K_BRAK 0x0e


namespace gra
{
	class Gra
	{
	private:
		Swiat* swiat;
		tworcaSwiata::TworcaSwiata* tworcaSwiata;
		rysowanieSwiata::RysowanieSwiata* rysownikSwiata;
		//StanZapisu* stanZapisu;

		int nacisnietyPrzycisk = -1;
		Kierunek kierunek = BRAK;

	public:
		Gra(int x, int y);
		~Gra();
		void obslugaSterowania();
		void Rozpocznij();

	private:
		int obslugaKlawiszy();
		void wykonajTure();
		Kierunek konwertujNaKierunek(int k_kier);
	};
}
