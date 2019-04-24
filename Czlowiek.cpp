#include "Czlowiek.h"
#include <iostream>

#define SILA 5
#define INICJATYWA 4

czlowiek::Czlowiek::Czlowiek(int sila, int inicjatywa, int x, int y, Swiat* swiat)
	: Zwierze(sila, inicjatywa, x, y, swiat, CZLOWIEK), cooldownMocy(COOLDOWN_MOCY) { }

int czlowiek::Czlowiek::akcja(Kierunek kierunek)
{
	akcjaMocy();
	if (kierunek == MOC)
	{
		aktywujMoc();
		return NIE_MOGE;
	}
	else
		return Zwierze::akcja(kierunek);
}


void czlowiek::Czlowiek::rysowanie()
{
	std::cout << "C";
}

void czlowiek::Czlowiek::aktywujMoc()
{
	if (cooldownMocy >= COOLDOWN_MOCY) {
		oryginalnaSila = sila;
		sila += 10;
		swiat->DodajKomunikat(std::string("Czlowiek uzyl mocy specjalnej! Jego sila wynosi ") +
			std::to_string(sila) + ".");
		cooldownMocy = 0;
	}
	else
	{
		swiat->DodajKomunikat(std::string("Moc specjalna czlowieka mozna uzyc za ") +
			std::to_string(COOLDOWN_MOCY - cooldownMocy) + " tur.");
	}

}

void czlowiek::Czlowiek::akcjaMocy()
{
	if (sila > oryginalnaSila)
	{
		sila--;
		swiat->DodajKomunikat(std::string("Sila czlowieka wynosi ") +
			std::to_string(sila) + ".");
	}
	else
		cooldownMocy++;
}
