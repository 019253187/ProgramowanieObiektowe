#include <iostream>
#include <fstream>
#include <string>
#include "tablice.h"

using namespace std;

KomorkaLiczbowa::KomorkaLiczbowa() {
	zawartosc = 0;
}

int KomorkaLiczbowa::ustaw(int wartosc) {
	zawartosc = wartosc;
	return 0;
}

int KomorkaLiczbowa::ustaw(string wartosc) {
	return -1;
}

int KomorkaLiczbowa::zwrocInt() {
	return zawartosc;
}

string KomorkaLiczbowa::zwroc() {
	return to_string(zawartosc);
}

KomorkaTekstowa::KomorkaTekstowa() {
	zawartosc = "0";
}

int KomorkaTekstowa::ustaw(string wartosc) {
	zawartosc = wartosc;
	return 0;
}

int KomorkaTekstowa::ustaw(int wartosc) {
	return -1;
}

int KomorkaTekstowa::zwrocInt() {
	return 0;
}

string KomorkaTekstowa::zwroc() {
	return zawartosc;
}

Tablica::Tablica() {
	tablica = NULL;
	rozmiarX = 0;
	rozmiarY = 0;
	typyKolumn = NULL;
}

int Tablica::utworzTablice(int rozmiarX, int rozmiarY, string* typyKolumn) {
	cout << "Tablica::utworzTablice():"<<endl;
	if(this->tablica != NULL) {
		cout << "!Usuwam stara tablice o adr." << &(this->tablica) << endl;
		for(int x=0; x<this->rozmiarX; x++) {
			delete [] this->tablica[x];
		}

		delete [] this->tablica;
		delete [] this->typyKolumn;
	}
	this->rozmiarX = rozmiarX;
	cout << "Ustawiono rozmiar X" << (this->rozmiarX) << " w " << &(this->rozmiarX) << endl;
	this->rozmiarY = rozmiarY;
	cout << "Ustawiono rozmiar Y" << (this->rozmiarY) << " w " << &(this->rozmiarY) << endl;
	this->typyKolumn = new string[rozmiarX];
	cout << "Stworzono nowa tablice typow kolumn o adr.: " << this->typyKolumn << endl; 
	this->tablica = new Komorka*[rozmiarX];
	cout << "Stworzono nowa tablice kolumn o adr.: " << this->tablica << endl; 
	for(int x=0; x<(this->rozmiarX); x++) {
		this->tablica[x] = NULL;
		this->typyKolumn[x] = typyKolumn[x];
		cout << "Ustawiono typ " << x << ". kolumny na " << this->typyKolumn[x] << endl;
		if(typyKolumn[x] == "int") {
			this->tablica[x] = new KomorkaLiczbowa[rozmiarY];
			cout << "Tworze kolumne liczbowa " << x << ". o adr.:" << &this->tablica[x] << endl;
		} else if(typyKolumn[x] == "string") {
			this->tablica[x] = new KomorkaTekstowa[rozmiarY];
			cout << "Tworze kolumne tekstowa " << x << ". o adr.:" << &this->tablica[x] << endl;
		} else {
			cout << "UWAGA! Podano nieznany typ zmiennej dla kolumny" << x << "!";
		}
		//Poniższe zakomentowałem gdyż w sumie oddzielna inicjalizacja w tej funkcji
		//już nie jest potrzebna - konstruktory komórek je inicjalizują.
		/*for(int y=0; y<(this->rozmiarY); y++) {
			if(this->typyKolumn[x] == "int") {
				this->tablica[x][y].ustaw(0);
			} else if(this->typyKolumn[x] == "string") {
				this->tablica[x][y].ustaw("nic");
			}
		}*/
	}
	return 0;
}

int Tablica::zmienKomorke(int xKomorki, int yKomorki, int nowaZawartosc) {
	if(rozmiarX<=0 || rozmiarY<=0) {
		return -1;
	}
	if(xKomorki<0 || yKomorki<0) {
		return -2;
	}
	if(yKomorki>=rozmiarY || xKomorki>=rozmiarX) {
		return -3;
	}

	tablica[xKomorki][yKomorki].ustaw(nowaZawartosc);
	return 0;
}

int Tablica::zmienKomorke(int xKomorki, int yKomorki, string nowaZawartosc) {
	if(rozmiarX<=0 || rozmiarY<=0) {
		return -1;
	}
	if(xKomorki<0 || yKomorki<0) {
		return -2;
	}
	if(yKomorki>=rozmiarY || xKomorki>=rozmiarX) {
		return -3;
	}

	tablica[xKomorki][yKomorki].ustaw(nowaZawartosc);
	return 0;
}

int Tablica::wyswietlTablice(void) {
	if(rozmiarX<=0 || rozmiarY<=0) {			
		return -1;
	}
	cout << "Oto twoja tablica o rozmiarze ";
	cout << rozmiarX << " kolumn na "; 
	cout << rozmiarY << " wierszy:" << endl;
	cout << "Adres tablicy: " << &tablica << endl;
	for(int x=0; x<rozmiarX; x++) {
		cout << "Adres kolumny "<<x<<". = "<<&tablica[x];
		for(int y=0; y<rozmiarY; y++) {
			cout << &tablica[x][y] << " = ";
			cout << tablica[x][y].zwroc() << "\t";
		}
		cout << endl;
	}

	for(int x = 0; x<rozmiarX; x++) {
		cout << "Adres listy typow kolumn:" << typyKolumn << endl;
		cout << typyKolumn[x] << "\t";
	}
	cout << endl;

	return 0;
}

int Tablica::zmianaRozmiaru(int nowyRozmiarX, int nowyRozmiarY) {
	if(rozmiarX<=0 || rozmiarY<=0) {
		return -1;
	}

	string* noweTypyKolumn = new string[nowyRozmiarX];
	for(int x = 0; x<nowyRozmiarX; x++) {
		if(x<rozmiarX) {
			noweTypyKolumn[x] = typyKolumn[x];
		} else {
			noweTypyKolumn[x] = "int";
		}
	}
	Tablica tabelka;
	tabelka.utworzTablice(nowyRozmiarX, nowyRozmiarY, noweTypyKolumn);
	
	for(int x=0; x<nowyRozmiarX; x++) {
		if(x<rozmiarX) {
			if(typyKolumn[x] == "string") {
				for(int y=0; y<nowyRozmiarY; y++) {
					if(y<rozmiarY) { //Zapobieżenie segfault(odczyt spoza tablicy)
						tabelka.tablica[x][y].ustaw(tablica[x][y].zwroc());
					}
				}
			} else if(typyKolumn[x] == "int") {
				for(int y=0; y<nowyRozmiarY; y++) {
					if(y<rozmiarY) { //Zapobieżenie segfault(odczyt spoza tablicy)
						tabelka.tablica[x][y].ustaw(tablica[x][y].zwrocInt());
					}
				}
			} else {	
				cout << "Nieznany typ komorki tablicy";
				cout << "przy zmianie rozmiaru." << endl;
			}
		}
	}
	//Usuniecie starej tablicy - zapobiezenie memleak
	if(this->tablica != NULL) {
		for(int x=0; x<this->rozmiarX; x++) {
			delete [] this->tablica[x];
		}
		delete [] this->tablica;
	}

	this->rozmiarX = nowyRozmiarX;
	this->rozmiarY = nowyRozmiarY;
	tablica = tabelka.tablica;

	return 0;
}

float Tablica::sumujWiersz(int wiersz) {
	float suma = 0;
	for(int x=0; x<rozmiarX; x++) {
		suma += (float)tablica[x][wiersz].zwrocInt();
	}
	return suma;
}

float Tablica::sumujKolumne(int kolumna) {
	float suma = 0;
	for(int y=0; y<rozmiarY; y++) {
		suma += (float)tablica[kolumna][y].zwrocInt();
	}
	return suma;
}

float Tablica::minimumWiersza(int wiersz) {
	float minimum = (float) tablica[0][wiersz].zwrocInt();
	for(int x=0; x<rozmiarX; x++) {
		if(minimum > (float)tablica[x][wiersz].zwrocInt()) {
			minimum =(float) tablica[x][wiersz].zwrocInt();;
		}
	}
	return minimum;
}

float Tablica::maksimumWiersza(int wiersz) {
	float maksimum =(float) tablica[0][wiersz].zwrocInt();
	for(int x=0; x<rozmiarX; x++) {
		if(maksimum < (float)tablica[x][wiersz].zwrocInt()) {
			maksimum =(float) tablica[x][wiersz].zwrocInt();
		}
	}
	return maksimum;
}

float Tablica::sredniaWiersza(int wiersz) {
	float srednia = sumujWiersz(wiersz);
	srednia /= (float)rozmiarX;
	return srednia;
}

float Tablica::minimumKolumny(int kolumna) {
	float minimum = (float)tablica[kolumna][0].zwrocInt();
	for(int y=0; y<rozmiarY; y++) {
		if(minimum > (float)tablica[kolumna][y].zwrocInt()) {
			minimum = (float)tablica[kolumna][y].zwrocInt();
		}
	}
	return minimum;
}

float Tablica::maksimumKolumny(int kolumna) {
	float maksimum = (float)tablica[kolumna][0].zwrocInt();
	for(int y=0; y<rozmiarY; y++) {
		if(maksimum < (float)tablica[kolumna][y].zwrocInt()) {
			maksimum = (float)tablica[kolumna][y].zwrocInt();
		}
	}
	return maksimum;
}

float Tablica::sredniaKolumny(int kolumna) {
	float srednia = sumujKolumne(kolumna);
	srednia /= (float)rozmiarY;
	return srednia;
}

int Tablica::zapiszTablice(string nazwaPliku) {
	ofstream plik;
	plik.open(nazwaPliku.c_str()); //Konwersja nazwy pliku na c-string - wymaganie	funkcji open()
	plik << rozmiarX << endl << rozmiarY << endl;
	for(int x=0; x<rozmiarX; x++) {
		plik << typyKolumn[x] << "\t";
	}
	plik << endl;

	for(int x=0; x<rozmiarX; x++) {
		for(int y=0; y<rozmiarY; y++) {
			plik << tablica[x][y].zwroc() << "\t";
		}
		plik << endl;
	}
	plik.close();
	return 0;
}

int Tablica::otworzTablice(string nazwaPliku) {
	ifstream dane;
	dane.open(nazwaPliku.c_str());
	int odczytano_wierszy = 0;
	int odczytano_kolumn = 0;
	if(dane.is_open()) {
		cout << "Pomyslnie otworzono plik \"" << nazwaPliku << "\"." << endl;
		dane >> odczytano_wierszy;
		cout << "Odczytano ilosc wierszy: " << odczytano_wierszy << endl;
		dane >> odczytano_kolumn;
		cout << "Odczytano ilosc kolumn: " << odczytano_kolumn << endl;

		if(!(odczytano_wierszy > 0) || (!(odczytano_kolumn > 0))) {
			return -1;
		}

		if(typyKolumn != NULL) delete [] typyKolumn;
		typyKolumn = new string[odczytano_kolumn];
		for(int x=0; x<odczytano_kolumn; x++) {
			dane >> typyKolumn[x];
		}
		this->utworzTablice(odczytano_kolumn, odczytano_wierszy, typyKolumn);
		
		for(int y=0; y<rozmiarY; y++) {
			for(int x=0; x<rozmiarX; x++) {
				if(typyKolumn[x] == "int") {
					int biezacaKomorka;
					dane >> biezacaKomorka;
					tablica[x][y].ustaw(biezacaKomorka);
				}

				if(typyKolumn[x] == "string") {
					string biezacaKomorka;
					dane >> biezacaKomorka;
					tablica[x][y].ustaw(biezacaKomorka);
				}
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

int Tablica::zmienTypKolumny(int kolumna, std::string nowyTyp) {
	if(tablica[kolumna] != NULL) delete [] tablica[kolumna];
	tablica[kolumna] = NULL;
	if(nowyTyp == "int") {
		tablica[kolumna] = new KomorkaLiczbowa[rozmiarY];
	} else if(nowyTyp == "string") {
		tablica[kolumna] = new KomorkaTekstowa[rozmiarY];
	} else {
		return -1;
	}
	typyKolumn[kolumna] = nowyTyp;
	for(int y=0; y<rozmiarY; y++) {
		if(nowyTyp == "int") {
			tablica[kolumna][y].ustaw(0);
		} else if(nowyTyp == "string") {
			tablica[kolumna][y].ustaw("nic");
		}
	}
	return 0;
}

int Tablica::zmienTypTablicy(std::string nowyTyp) {
	for(int x=0; x<rozmiarX; x++) {
		zmienTypKolumny(x, nowyTyp);
	}
	return 0;
}