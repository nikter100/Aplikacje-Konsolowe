#include <iostream>

using namespace std;

class Notatka
{
public:
    Notatka(string, string);

    void wyswietl();
    void wypiszWszystko();
 
protected:
    string tytul, tresc;

private:
    static int licznik;
    int index;
};

int Notatka::licznik = 0;

Notatka::Notatka(string tytulNot, string trescNot)
{
    tytul = tytulNot;
    tresc = trescNot;
    licznik++;
    index = licznik;
}

void Notatka::wyswietl(){
    cout << "Tytul: " << tytul << endl;
    cout << "Tresc: " << tresc << endl;
}

void Notatka::wypiszWszystko() {
    cout << tytul << "; " << tresc << "; " << licznik << "; " << index<<endl;
}


int main()
{
    Notatka n1("Zakupy", "Mleko, Jajka, Maslo");
    n1.wyswietl();
    n1.wypiszWszystko();
    Notatka n2("Do zrobienia", "Nauczyc sie c++");
    n2.wyswietl();
    n2.wypiszWszystko();
}