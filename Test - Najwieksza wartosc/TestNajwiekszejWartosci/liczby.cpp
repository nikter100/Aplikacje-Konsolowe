#include "pch.h"
#include "liczby.h"
#include <iostream>

using namespace std;

void  Liczby::pobierzLiczby() {
		for (int i = 0; i < N; i++)
		{
			cout << "Podaj " << i + 1 << " liczbe:";
			cin >> arr[i];
		}
	}

void Liczby::ustawLiczby(int tab[]) {
	for (int i = 0; i < N; i++) {
		arr[i] = tab[i];
	}
}

void Liczby::wyswietlLiczby() {
		for (int i = 0; i < N; i++)
		{
			cout << arr[i] << endl;
		}
	}

int Liczby::maksLiczba() {

		int maks = arr[0];
		for (int i = 0; i < N; i++)
		{
			if (arr[i] > maks)
			{
				maks = arr[i];
			}
		}
		return maks;
	}
