#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <unordered_map>

using namespace std;

class Rzut
{
public:
	void wprowadzDane(int);

	void inicjujLosowa();
	
	void losowyRzut();

	int policzPunkty();

private:
	int iloscRzutow;
	vector <int> wyrzuconeLiczby;
};

void Rzut::wprowadzDane(int ilosc) {
	iloscRzutow = ilosc;
}

void Rzut::inicjujLosowa() {
	srand(time(NULL));
}

void Rzut::losowyRzut() {
	for (int i = 0; i < iloscRzutow; i++)
	{
		int rzutKostki = (rand() % 5) + 1;
		cout << "Kostka" << i + 1 << ": " << rzutKostki << endl;
		wyrzuconeLiczby.push_back(rzutKostki);
	}
}

int Rzut::policzPunkty() {
	unordered_map<int, int> licznik;

	// Zliczanie wystąpień za pomocą inkrementacji i indeksów
	for (size_t i = 0; i < wyrzuconeLiczby.size(); i++) {
		int wartosc = wyrzuconeLiczby[i];
		licznik[wartosc]++;
	}

	int suma = 0;
	// Sumowanie tylko tych, które wystąpiły co najmniej 2 razy, też z inkrementacją
	for (auto it = licznik.begin(); it != licznik.end(); ++it) {
		if (it->second >= 2) {
			suma += it->first * it->second;
		}
	}

	return suma;
}

int main()
{
	int rzuty = 0;
	string ponownaGra = "t";

	while (ponownaGra == "t")
	{
		do
		{
			cout << "Ile kostek chcesz rzucic?(3-10)";
			cin >> rzuty;
		} while (rzuty < 3 || rzuty > 10);

		Rzut R1;

		R1.wprowadzDane(rzuty);

		R1.inicjujLosowa();
		R1.losowyRzut();
		cout << "Liczba uzyskanych punktow: " << R1.policzPunkty() << endl;

		cout << "Jeszcze raz ? (t / n)";
		cin >> ponownaGra;
	}

}
