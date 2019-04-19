#include"Roslina.h"

#include"Swiat.h"

roslina::Roslina::Roslina(int sila, int x, int y, Swiat * swiat, IdOrganizmu ID)
	:Organizm(sila, 0, x, y, swiat, ID) { }

int roslina::Roslina::akcja()
{
	return 0;
}

WynikKolizji roslina::Roslina::kolizja(int x, int y)
{
	return WynikKolizji();
}

