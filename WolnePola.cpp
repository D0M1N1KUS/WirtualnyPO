#include "WolnePola.h"

wolnePola::WolnePola::WolnePola(Punkt p, Rozmiar r, Swiat* swiat)
	: punkt(Punkt(p.x - 1, p.y - 1)), rozmiar(r), swiat(swiat)
{
	punkty = new std::vector<Punkt>();
}


/*
1:
   0	
    ++ y takie same
2:
   0
	+ x takie same
	+

*/
wolnePola::WolnePola::WolnePola(Punkt a, Punkt b, Swiat* swiat)
	: swiat(swiat)
{
	punkty = new std::vector<Punkt>();
	if (a.y == b.y)
	{
		rozmiar = Rozmiar(4, 3);
		if (a.x < b.x)
			punkt = Punkt(a.x - 1, a.y - 1);
		else
			punkt = Punkt(b.x - 1, b.y - 1);
	}
	else if (a.x == b.x)
	{
		rozmiar = Rozmiar(3, 4);
		if (a.y < b.y)
			punkt = Punkt(a.x - 1, a.y - 1);
		
		else 
			punkt = Punkt(b.x - 1, b.y - 1);
		
	}
	else
		throw new std::exception("Nieprawidlowe dane do obliczenia wplnych pol");
}

wolnePola::WolnePola::~WolnePola()
{
	punkty->clear();
	delete punkty;
}

std::vector<Punkt>* wolnePola::WolnePola::ZnajdzWolnePola()
{
	for (int i = punkt.x; i < punkt.x + rozmiar.a; i++)
	{
		for (int j = punkt.y; j < punkt.y + rozmiar.b; j++)
		{
			if (jestesmyW_Planszy(i, j) && swiat->poleJestPuste(i, j))
				punkty->push_back(Punkt(i, j));
		}
	}
	return punkty;
}

bool wolnePola::WolnePola::jestesmyW_Planszy(int i, int j)
{
	return i >= 0 && i < swiat->getXS() && j >= 0 && j < swiat->getYS();
}
