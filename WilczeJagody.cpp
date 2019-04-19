#include "WilczeJagody.h"
#include <iostream>

wilczeJagody::WilczeJagody::WilczeJagody(int sila, int x, int y, Swiat * swiat)
	: Roslina(sila, x, y, swiat, IdOrganizmu::WILCZAJAGODA) { }

int wilczeJagody::WilczeJagody::akcja()
{
	return Roslina::akcja();
}

WynikKolizji wilczeJagody::WilczeJagody::kolizja()
{
	return WynikKolizji();
}

void wilczeJagody::WilczeJagody::rysowanie()
{
	std::cout << "&";
}
