#pragma once


#include"Swiat.h"
#include"Struktury.h"


#define ODSTEP 1
#define SZEROKOSC_KONSOLI 80
#define WYSOKOSC_KONSOLI 25

namespace rysowanieSwiata
{
	class RysowanieSwiata
	{
	private:
		Swiat* swiat;
		Punkt pozycjaPlanszy;
		Punkt pozycjaKomunikatow;
		Rozmiar rozmiarPlanszy;
		Rozmiar rozmiarKomunikatow;

	public:
		RysowanieSwiata(Swiat* swiat);
		void rysujSwiat();
		void wypiszKomunikaty();
	};
}
