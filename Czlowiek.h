#pragma once 

#include "Zwierze.h"
#include "Swiat.h"

#define COOLDOWN_MOCY 5

namespace czlowiek
{
	class Czlowiek : public Zwierze
	{
	public:
		Czlowiek(int sila, int inicjatywa, int x, int y, Swiat* swiat);
		int akcja(Kierunek kierunek = BRAK);
		void rysowanie();
	private:

		
		int cooldownMocy;

		void aktywujMoc();
		void akcjaMocy();
	};
}