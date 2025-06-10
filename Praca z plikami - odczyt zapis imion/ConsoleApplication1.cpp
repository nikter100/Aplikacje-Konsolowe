#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string imie, nazwisko;
    int nr_tel;

    string imiona[10]{};
    string nazwiska[10]{};
    int numery[10]{};

    /*
    cout << "Podaj imie: ";
    cin >> imie;
    cout << "Podaj nazwisko: ";
    cin >> nazwisko;
    cout << "Podaj nr teledonu: ";
    cin >> nr_tel;
    */
    fstream plik("dane.txt", std::ios::in | std::ios::out | std::ios::app);

    /*
    plik << imie<< endl;
    plik << nazwisko <<endl;
    plik << nr_tel <<endl<<endl;
    */
    
    if (!plik.is_open()) {
        cout << "Nie otwarto pliku";
        exit(0);
    }

    string linia;
    int nrLini = 1, index = 0, n = 0;

    while (getline(plik, linia))
    {
        switch (nrLini)
        {
        case 1: imiona[index] = linia; break;
        case 2: nazwiska[index] = linia; break;
        case 3: numery[index] = atoi(linia.c_str()); break;
        }
        
        if (nrLini == 4)
        {
            nrLini = 1;
            index++;
        }
        else
        {
            nrLini++;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        cout <<"imie: " << imiona[i] << endl;
        cout <<"nazwisko: " << nazwiska[i] << endl;
        cout <<"numer tel: " << numery[i] << endl;
    }

}
