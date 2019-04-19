#include "Organizm.h"
#include <cstddef>

int Organizm::getX()
{
	return this->x;
}

int Organizm::getY()
{
	return this->y;
}

int Organizm::getSila()
{
	return this->sila;
}

int Organizm::getInicjatywa()
{
	return this->inicjatywa;
}

IdOrganizmu Organizm::GetID()
{
	return ID;
}

std::string Organizm::NazwaOrganizmu()
{
	return NazwaOrganizmu(ID);
}

std::string Organizm::NazwaOrganizmu(IdOrganizmu id)
{
	switch (id)
	{
	case WILK:
		return "Wilk";
	case OWCA:
		return "Owca";
	case LIS:
		return "Lis";
	case ZOLW:
		return "Zolw";
	case ANTYLOPA:
		return "Antylopa";
	case TRAWA:
		return "Trawa";
	case MLECZ:
		return "Mlecz";
	case GUARANA:
		return "Guarana";
	case WILCZAJAGODA:
		return "Wilcza Jagoda";
	case BARSZ:
		return "Barszcz Sosnowskiego";
	case CZLOWIEK:
		return "Czlowiek";
	default:
		return "Nienzany organizm";
	}
}

Organizm::Organizm(int sila, int inicjatywa, int x, int y, Swiat *swiat, IdOrganizmu Id)
	: sila(sila), inicjatywa(inicjatywa), x(x), y(y), swiat(swiat), ID(Id) {}

void Organizm::setPozycja(int x, int y)
{
	this->x = x;
	this->y = y;
}


