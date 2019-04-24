#include "Czlowiek.h"
#include <iostream>

#define SILA 5
#define INICJATYWA 4

czlowiek::Czlowiek::Czlowiek(int sila, int inicjatywa, int x, int y, Swiat* swiat)
	: Zwierze(sila, inicjatywa, x, y, swiat, CZLOWIEK) { }

int czlowiek::Czlowiek::akcja(Kierunek kierunek)
{
	if (kierunek == MOC)
		return NIE_MOGE;
	else
		return Zwierze::akcja(kierunek);
}


void czlowiek::Czlowiek::rysowanie()
{
	std::cout << "C";
}
