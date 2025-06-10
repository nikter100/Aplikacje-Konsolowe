#pragma once
#include "pch.h"

class Liczby
{
public:
	void pobierzLiczby();

	void ustawLiczby(int tab[]);

	void wyswietlLiczby();

	int maksLiczba();

private:
	static const int N = 3;
	int arr[N]{};
};