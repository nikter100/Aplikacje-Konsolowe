#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Album
{
    string wykonawca;
    string nazwaAlbumu;
    int liczbaPiosenek;
    int rokEdycji;
    int liczbaPobran;
};

void wczytajPlik(vector<Album>& albumy) {
    fstream plik;
    plik.open("Data.txt", ios::in);

    if (plik.is_open())
    {
        Album album;
        string linia;
        int nrLini = 1;

        while (getline(plik, linia)) {
            switch (nrLini)
            {
                case 1: album.wykonawca = linia; break;
                case 2: album.nazwaAlbumu = linia; break;
                case 3: album.liczbaPiosenek = stoi(linia); break;
                case 4: album.rokEdycji = stoi(linia); break;
                case 5: 
                    album.liczbaPobran = stoi(linia); 
                    albumy.push_back(album);
                    break;
            }
            nrLini++;
            if (nrLini > 6) nrLini = 1;
        };

        plik.close();
    }
}


void wyswietl(vector<Album>& albumy) {
    for (size_t i = 0; i < albumy.size(); i++)
    {
        Album album = albumy[i];
        cout << album.wykonawca << endl;
        cout << album.nazwaAlbumu << endl;
        cout << album.liczbaPiosenek << endl;
        cout << album.rokEdycji << endl;
        cout << album.liczbaPobran << endl << endl;
    }

}

int main()
{
    vector<Album> albumy;
    wczytajPlik(albumy);
    wyswietl(albumy);
}
