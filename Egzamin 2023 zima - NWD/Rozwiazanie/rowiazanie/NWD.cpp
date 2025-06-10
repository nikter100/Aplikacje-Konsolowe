#include "NWD.h";

void NWD::uzupelnijLiczby(int liczba1, int liczba2) {
	a = liczba1;
	b = liczba2;
}

int NWD::szukanieNWD() {
	while (a != b)
	{
		if (a > b)
		{
			a = a - b;
		}
		b = b - a;
	}
	return a;
}