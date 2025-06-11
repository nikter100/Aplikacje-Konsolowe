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
		int rzutKostki = (rand() % 6) + 1;
		cout << "Kostka" << i + 1 << ": " << rzutKostki << endl;
		wyrzuconeLiczby.push_back(rzutKostki);
	}
}

int Rzut::policzPunkty() {
	const int N = 7;
	int licznik[N] = { 0 }; // index jest jako liczba a wartosc jako ilosc wystepowania np {1,2,3,1,1} to index 1 bedzie miał warość 3, index 2 bedzie mial 1, index 3 bedzie mial 1
	int suma = 0;

	for (int i = 0; i < wyrzuconeLiczby.size(); i++) {
		for (int j = 1; j < N; j++) {
			if (wyrzuconeLiczby[i] == j) {	//jesli wartosc z wektora wyrzuconeLiczby jest rowna indeksowi licznika 
				licznik[j]++;	// inkrementujemy wartosc danego indesku 
			}
		}
	}
	
	for (size_t i = 0; i < N; i++)
	{
		if (licznik[i] >= 2)	//jesli wartosc jest wieksza niz 2 
		{
			suma +=( i * licznik[i]);	//inkrementujemy o iloczyn indexu i wartosci np. index 1 bedzie miał warość 3 to 1 * 3 TYLKO WARTOSCI KTORYCH JEST 2 LUB WIECEJ czyli index 2 bedzie mial 1 NIE dodajemy 
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
