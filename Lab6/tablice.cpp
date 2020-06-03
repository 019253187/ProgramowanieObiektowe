#include <iostream>
#include <fstream>
#include <string>
#include "tablice.h"

using namespace std;

KomorkaLiczbowa::KomorkaLiczbowa() {
	typ = "int";
	zawartosc = 0;
}

int KomorkaLiczbowa::ustaw(int wartosc) {
	zawartosc = wartosc;
	return 0;
}

int KomorkaLiczbowa::zwroc() {
	return zawartosc;
}

KomorkaTekstowa::KomorkaTekstowa() {
	typ = "string";
	zawartosc = 0;
}

int KomorkaTekstowa::ustaw(string wartosc) {
	zawartosc = wartosc;
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

int Tablica::utworzTablice(int rozmiarX, int rozmiarY, string[] typyKolumn) {
	//cout << "Tablica::utworzTablice():"<<endl;
	if(this->tablica != NULL) {
		//cout << "utworzTablice(): tablica nie jest NULL"<<endl;
		for(int x=0; x<this->rozmiarX; x++) {
			//cout << "Usuwam " << y << ". wiersz tablicy o adr.:" << this->tablica[y] << endl;
			delete [] this->tablica[x];
		}
		//cout << "Usuwam cala tablice o adr.:" << this->tablica << endl;
		delete [] this->tablica;
	}

	this->rozmiarX = rozmiarX;
	this->rozmiarY = rozmiarY;
	this->tablica = new Komorka*[rozmiarX];
	for(int x=0; x<(this->rozmiarX); x++) {
		this->tablica[x] = NULL;
		if(typyKolumn[x] == "int") {
			this->tablica[x] = new KomorkaLiczbowa[rozmiarY];
		} else if(typyKolumn[x] == "string") {
			this->tablica[x] = new KomorkaTekstowa[rozmiarY];
		}
		for(int y=0; y<(this->rozmiarY); y++) {
			if(typyKolumn[x] == "int") {
				this->tablica[x][y].ustaw(0);
			} else if(typyKolumn[x] == "string") {
				this->tablica[x][y].ustaw("nic");
			}
		}
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

	tablica[yKomorki][xKomorki].ustaw(nowaZawartosc);
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

	tablica[yKomorki][xKomorki].ustaw(nowaZawartosc);
	return 0;
}

int Tablica::wyswietlTablice(void) {
	if(rozmiarX<=0 || rozmiarY<=0) {			
		return -1;
	}
	cout << "Oto twoja tablica o rozmiarze ";
	cout << rozmiarX << " kolumn na "; 
	cout << rozmiarY << " wierszy:" << endl;
	for(int x=0; x<rozmiarX; x++) {
		for(int y=0; y<rozmiarY; y++) {
			cout << tablica[x][y].zwroc() << "\t";
		}
		cout << endl;
	}
	return 0;
}

int Tablica::zmianaRozmiaru(int nowyRozmiarX, int nowyRozmiarY) {
	if(rozmiarX<=0 || rozmiarY<=0) {
		return -1;
	}
	//cout << "Tablica::zmianaRozmiaru():"<<endl;
	Tablica tabelka;
	tabelka.utworzTablice(nowyRozmiarX, nowyRozmiarY);
	for(int y=0; y<nowyRozmiarY; y++) {
		if(y<rozmiarY) { //Zapobieżenie segfault(odczyt spoza tablicy)
			//cout<<"tabelka: wiersz "<<y<<" o adresie " << tabelka.tablica[y] << endl;
			for(int x=0; x<nowyRozmiarX; x++) {
				//cout<<"tabelka: komorka "<<x;
				if(x<rozmiarX) {
					//cout<<" o adresie "<<&tabelka.tablica[y][x];
					//cout<<" bedzie "<<tablica[y][x]<<" z adr. "<<&tablica[y][x]<<endl;
					if(tablica[y][x].typ == "int") {
						tabelka.tablica[y][x].ustaw(tablica[y][x].zwrocInt());
					} else if(tablica[y][x].typ == "float") {
						tabelka.tablica[y][x].(float)ustaw(tablica[y][x].zwroc());
					} else if(tablica[y][x].typ == "string") {
						tabelka.tablica[y][x].ustaw(tablica[y][x].zwrocString());
					} else {
						cout << "Nieznany typ komorki tablicy";
						cout << "przy zmianie rozmiaru." << endl;
					}
				}
			}
		}
	}
	//Usuniecie starej tablicy - zapobiezenie memleak
	if(this->tablica != NULL) {
		//cout << "utworzTablice(): tablica nie jest NULL"<<endl;
		for(int y=0; y<this->rozmiarY; y++) {
			//cout << "Usuwam " << y << ". wiersz tablicy o adr.:" << this->tablica[y] << endl;
			delete [] this->tablica[y];
		}
		//cout << "Usuwam cala tablice o adr.:" << this->tablica << endl;
		delete [] this->tablica;
	}

	this->rozmiarX = nowyRozmiarX;
	this->rozmiarY = nowyRozmiarY;
	tablica = tabelka.tablica;
/* //OK! odkryłem segf. - w ponizszej petli sa usuwane wiersze potem uzywane jako tablica!
	for(int y=0; y<nowyRozmiarY; y++) {
		cout<<"Usuwam "<<y<<" wiersz tabelki o adr.: "<<tabelka.tablica[y]<<endl;
		delete [] tabelka.tablica[y];
	}*/
	return 0;
}

float Tablica::sumujWiersz(int wiersz) {
	float suma = 0;
	for(int x=0; x<rozmiarX; x++) {
		suma += (float)tablica[wiersz][x].zwroc();
	}
	return suma;
}

float Tablica::sumujKolumne(int kolumna) {
	float suma = 0;
	for(int y=0; y<rozmiarY; y++) {
		suma += (float)tablica[y][kolumna].zwroc();
	}
	return suma;
}

float Tablica::minimumWiersza(int wiersz) {
	float minimum =(float) tablica[wiersz][0].zwroc();
	for(int x=0; x<rozmiarX; x++) {
		if(minimum(float)>tablica[wiersz][x].zwroc()) {
			minimum =(float) tablica[wiersz][x].zwroc();;
		}
	}
	return minimum;
}

float Tablica::maksimumWiersza(int wiersz) {
	float maksimum =(float) tablica[wiersz][0].zwroc();
	for(int x=0; x<rozmiarX; x++) {
		if(maksimum(float)<tablica[wiersz][x].zwroc()) {
			maksimum =(float) tablica[wiersz][x].zwroc();
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
	float minimum = (float)tablica[0][kolumna].zwroc();
	for(int y=0; y<rozmiarY; y++) {
		if(minimum>(float)tablica[y][kolumna].zwroc()) {
			minimum = (float)tablica[y][kolumna].zwroc();
		}
	}
	return minimum;
}

float Tablica::maksimumKolumny(int kolumna) {
	float maksimum = (float)tablica[0][kolumna].zwroc();
	for(int y=0; y<rozmiarY; y++) {
		if(maksimum<(float)tablica[y][kolumna].zwroc()) {
			maksimum = (float)tablica[y][kolumna].zwroc();
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
	for(int x=0; x<rozmiarX; y++) {
		plik << tablica[x][y].typ << "\t";
	}
	plik << endl;

	for(int x=0; x<rozmiar; x++) {
		for(int y=0; y<rozmiarX; y++) {
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
		for(int x=0; x<odczytano_kolumn; y++) {
			dane >> typyKolumn[x];
		}
		this->utworzTablice(odczytano_kolumn, odczytano_wierszy, typyKolumn);
		
		for(int y=0; y<rozmiarY; y++) {
			for(int x=0; x<rozmiarX; x++) {
				if(typyKolumn[x] == "int") {
					int biezacaKomorka;
					dane >> biezacaKomorka;
					tablica[y][x].ustaw(biezacaKomorka);
				}

				if(typyKolumn[x] == "string") {
					string biezacaKomorka;
					dane >> biezacaKomorka;
					tablica[y][x].ustaw(biezacaKomorka);
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
	}
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
		if(tablica[x] != NULL) delete [] tablica[x];
		tablica[x] = NULL;
		
		if(nowyTyp == "int") {
			tablica[x] = new KomorkaLiczbowa[rozmiarY];
		} else if(nowyTyp == "string") {
			tablica[x] = new KomorkaTekstowa[rozmiarY];
		}

		for(int y=0; y<rozmiarY; y++) {
			if(nowyTyp == "int") {
				tablica[x][y].ustaw(0);
			} else if(nowyTyp == "string") {
				tablica[x][y].ustaw("nic");
			}
		}
	}
	return 0;
}