#include "Gra.h"
#include <iostream>
#include <conio.h>

int main()
{
	try {
		int x = 5, y = 10;
		std::cout << "Podaj rozmiar planszy (min 5x5):";
		std::cin >> x;
		std::cin >> y;

		gra::Gra rozgrywka{ x,y };
		rozgrywka.Rozpocznij();
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
		system("pause");
	}
	
	return 0;
}
