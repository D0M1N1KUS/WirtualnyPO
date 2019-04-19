#pragma once


struct Punkt
{
public:
	Punkt() : x(0), y(0) {}
	Punkt(int x, int y) : x(x), y(y) {}
	int x;
	int y;
};

struct Rozmiar
{
	Rozmiar() : a(0), b(0) {}
	Rozmiar(int a, int b) : a(a), b(b) {}
	int a;
	int b;
};