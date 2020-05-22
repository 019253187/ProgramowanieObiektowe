#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Tablica {
	public:
		int** tablica;
		int rozmiarX;
		int rozmiarY;

		int utworzTablice(int rozmiarX, int rozmiarY) {
			this->rozmiarX = rozmiarX;
			this->rozmiarY = rozmiarY;
			this->tablica = new int*[rozmiarY];
			for(int y=0; y<(this->rozmiarY); y++) {
				this->tablica[y] = new int[rozmiarX];
				for(int x=0; x<(this->rozmiarX); x++) {
					this->tablica[y][x] = 0;
				}
			}
			return 0;
		}

		int zmienKomorke(int xKomorki, int yKomorki, int nowaZawartosc) {
			if(rozmiarX<=0 || rozmiarY<=0) {
				return -1;
			}
			if(xKomorki<0 || yKomorki<0) {
				return -2;
			}
			if(yKomorki>=rozmiarY || xKomorki>=rozmiarX) {
				return -3;
			}

			tablica[yKomorki][xKomorki] = nowaZawartosc;
			return 0;
		}

		int wyswietlTablice(void) {
			if(rozmiarX<=0 || rozmiarY<=0) {			
				return -1;
			}
			cout << "Oto twoja tablica o rozmiarze ";
			cout << rozmiarX << " kolumn na  "; 
			cout << rozmiarY << " wierszy:" << endl;
			for(int y=0; y<rozmiarY; y++) {
				for(int x=0; x<rozmiarX; x++) {
					cout << tablica[y][x] << "\t";
				}
				cout << endl;
			}
			return 0;
		}

		int zmianaRozmiaru(int nowyRozmiarX, int nowyRozmiarY) {
			if(rozmiarX<=0 || rozmiarY<=0) {
				return -1;
			}
			Tablica tabelka;
			this->utworzTablice(nowyRozmiarX, nowyRozmiarY);
			for(int y=0; y<nowyRozmiarY; y++) {
				if(y<rozmiarY) { //Zapobieżenie segfault(odczyt spoza tablicy)
					for(int x=0; x<nowyRozmiarX; x++) {
						if(x<rozmiarX) {
							tabelka.tablica[y][x] = (tablica[y][x]);
						}
					}
				}
			}
			delete [] tablica;
			tablica = tabelka.tablica;
			rozmiarX = nowyRozmiarX;
			rozmiarY = nowyRozmiarY;
			delete [] tabelka.tablica;
			return 0;
		}

		int sumujWiersz(int wiersz) {
			int suma = 0;
			for(int x=0; x<rozmiarX; x++) {
				suma += tablica[wiersz][x];
			}
			return suma;
		}

		int sumujKolumne(int kolumna) {
			int suma = 0;
			for(int y=0; y<rozmiarY; y++) {
				suma += tablica[y][kolumna];
			}
			return suma;
		}

		int minimumWiersza(int wiersz) {
			int minimum = tablica[wiersz][0];
			for(int x=0; x<rozmiarX; x++) {
				if(minimum>tablica[wiersz][x]) {
					minimum = tablica[wiersz][x];
				}
			}
			return minimum;
		}

		int maksimumWiersza(int wiersz) {
			int maksimum = tablica[wiersz][0];
			for(int x=0; x<rozmiarX; x++) {
				if(maksimum<tablica[wiersz][x]) {
					maksimum = tablica[wiersz][x];
				}
			}
			return maksimum;
		}

		int sredniaWiersza(int wiersz) {
			float srednia = (float)sumujWiersz(wiersz);
			srednia /= (float)rozmiarX;
			return srednia;
		}

		int minimumKolumny(int kolumna) {
			int minimum = tablica[0][kolumna];
			for(int y=0; y<rozmiarY; y++) {
				if(minimum>tablica[y][kolumna]) {
					minimum = tablica[y][kolumna];
				}
			}
			return minimum;
		}

		int maksimumKolumny(int kolumna) {
			int maksimum = tablica[0][kolumna];
			for(int y=0; y<rozmiarY; y++) {
				if(maksimum<tablica[y][kolumna]) {
					maksimum = tablica[y][kolumna];
				}
			}
			return maksimum;
		}

		int sredniaKolumny(int kolumna) {
			float srednia = (float)sumujKolumne(kolumna);
			srednia /= (float)rozmiarY;
			return srednia;
		}

		int zapiszTablice(string nazwaPliku) {
			ofstream plik;
			plik.open(nazwaPliku.c_str()); //Konwersja nazwy pliku na c-string - wymaganie	funkcji open()
			plik << rozmiarX << endl << rozmiarY << endl;
			for(int y=0; y<rozmiarY; y++) {
				for(int x=0; x<rozmiarX; x++) {
					plik << tablica[y][x] << "\t";
				}
				plik << endl;
			}
			plik.close();
			return 0;
		}

		int otworzTablice(string nazwaPliku) {
			ifstream dane;
			dane.open(nazwaPliku.c_str());
			int odczytano_wierszy = 0;
			int odczytano_kolumn = 0;
			if(dane.is_open()) {
				cout << "Pomyslnie otworzono plik \"" << nazwaPliku << "\"." << endl;
				dane >> odczytano_wierszy;
				cout << "Odczytano ilosc wierszy: " << odczytano_wierszy << endl;
				dane >> odczytano_wierszy;
				cout << "Odczytano ilosc wierszy: " << odczytano_wierszy << endl;
				if(!(odczytano_wierszy > 0) || (!(odczytano_kolumn > 0))) {
					return -1; //Zakonczenie funkcji zwracajac null
				}
				this->utworzTablice(odczytano_kolumn, odczytano_wierszy);
				for(int y=0; y<rozmiarY; y++) {
					for(int x=0; x<rozmiarX; x++) {
						dane >> tablica[y][x];
					}
				}
				cout << endl;
				dane.close();
				return 0;
			} else {
				cout << "Wystapil blad przy otwieraniu pliku \"" << nazwaPliku << "\"." << endl;
			}
			dane.close();
			return -1;
		}
};