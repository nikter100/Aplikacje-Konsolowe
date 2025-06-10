#include <iostream>
#include "NWD.h";

using namespace std;


int main()
{
	int a, b;

	cout << "Podaj a: ";
	cin >> a;
	cout << "Podaj b: ";
	cin >> b;
	
	NWD funkcja1;

	funkcja1.uzupelnijLiczby(a, b);
	cout << "Najwiekszy wspolny dzielnik: " << funkcja1.szukanieNWD();
}
