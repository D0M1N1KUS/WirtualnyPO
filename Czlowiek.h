#pragma once 

#include "Zwierze.h"

namespace czlowiek
{
	class Czlowiek : public Zwierze
	{
	public:
		Czlowiek(int sila, int inicjatywa, int x, int y, Swiat* swiat);
		int akcja(Kierunek kierunek = BRAK);
		void rysowanie();
	};
}