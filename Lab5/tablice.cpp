#include <iostream>
#include <fstream>
#include <string>
#include "tablice.h"

using namespace std;

Komorka::Komorka() {
	zawartoscInt = 0;
	zawartoscFloat = 0.0;
	zawartoscString = "nic";
	typ = "int";
}

Komorka::Komorka(string typKomorki) {
	typ = typKomorki;

	zawartoscInt = 0;
	zawartoscFloat = 0.0;
	zawartoscString = "nic";
}

int Komorka::ustaw(int wartosc) {
	zawartoscInt = wartosc;
	zawartoscFloat = (float)wartosc;
	zawartoscString = to_string(wartosc);

	if(typ != "int") {
		typ = "int";
		return 1;
	}
	return 0;
}
	
int Komorka::ustaw(float wartosc) {
	zawartoscFloat = wartosc;
	zawartoscInt = (int)wartosc;
	zawartoscString = to_string(wartosc);

	if(typ != "float") {
		typ = "float";
		return 1;
	}
	return 0;
}
int Komorka::ustaw(std::string wartosc) {
	zawartoscString = wartosc;
	if(typ != "string") {
		typ = "string";
		return 1;
	}
	return 0;
}

int Komorka::zwrocInt() {
	return zawartoscInt;
}

float Komorka::zwrocFloat() {
	return zawartoscFloat;
}

std::string Komorka::zwrocString() {
	return zawartoscString;
}

int Komorka::ustawTyp(std::string typKomorki) {
	typ = typKomorki;
	return 0;
}


Tablica::Tablica() {
	tablica = NULL;
	rozmiarX = 0;
	rozmiarY = 0;
}

int Tablica::utworzTablice(int rozmiarX, int rozmiarY) {
	//cout << "Tablica::utworzTablice():"<<endl;
	if(this->tablica != NULL) {
		//cout << "utworzTablice(): tablica nie jest NULL"<<endl;
		for(int y=0; y<this->rozmiarY; y++) {
			//cout << "Usuwam " << y << ". wiersz tablicy o adr.:" << this->tablica[y] << endl;
			delete [] this->tablica[y];
		}
		//cout << "Usuwam cala tablice o adr.:" << this->tablica << endl;
		delete [] this->tablica;
	}

	this->rozmiarX = rozmiarX;
	this->rozmiarY = rozmiarY;
	this->tablica = new Komorka*[rozmiarY];
	//cout << "Nowa tablica o adresie: " << this->tablica << endl;
	for(int y=0; y<(this->rozmiarY); y++) {
		this->tablica[y] = new Komorka[rozmiarX];
		//cout << "Inicjalizuje wiersz "<<y<< " o adr.: "<<this->tablica[y]<<endl;
		for(int x=0; x<(this->rozmiarX); x++) {
			//cout << "Inicjalizuje komorke("<<x<<","<<y<<") adr.:"<<&(this->tablica[y][x])<<" jako 0."<<endl;
			this->tablica[y][x].ustaw(0);
			//cout << "Komorka("<<x<<","<<y<<") adr.:"<<&(this->tablica[y][x])<<" = "<<this->tablica[y][x]<<endl;
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

int Tablica::zmienKomorke(int xKomorki, int yKomorki, float nowaZawartosc) {
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
	for(int y=0; y<rozmiarY; y++) {
		//cout << "Adr. wiersza: " << tablica[y]<<endl;
		for(int x=0; x<rozmiarX; x++) {
			//cout << "Komorka " << &tablica[y][x]<< " = ";
			cout << tablica[y][x].zwrocString() << "\t";
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
					tabelka.tablica[y][x].ustaw(tablica[y][x].zwrocInt());
				}// else cout<<endl;
			}
		}
	}
/*	for(int y=0; y<rozmiarY; y++) {
		delete [] tablica[y];
	}
	delete [] tablica; //Zwalnianie pamieci juz jest w utworzTablice()
*/
	this->utworzTablice(nowyRozmiarX, nowyRozmiarY);
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
		suma += tablica[wiersz][x].zwrocFloat();
	}
	return suma;
}

float Tablica::sumujKolumne(int kolumna) {
	float suma = 0;
	for(int y=0; y<rozmiarY; y++) {
		suma += tablica[y][kolumna].zwrocFloat();
	}
	return suma;
}

float Tablica::minimumWiersza(int wiersz) {
	float minimum = tablica[wiersz][0].zwrocFloat();
	for(int x=0; x<rozmiarX; x++) {
		if(minimum>tablica[wiersz][x].zwrocFloat()) {
			minimum = tablica[wiersz][x].zwrocFloat();;
		}
	}
	return minimum;
}

float Tablica::maksimumWiersza(int wiersz) {
	float maksimum = tablica[wiersz][0].zwrocFloat();
	for(int x=0; x<rozmiarX; x++) {
		if(maksimum<tablica[wiersz][x].zwrocFloat()) {
			maksimum = tablica[wiersz][x].zwrocFloat();
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
	float minimum = tablica[0][kolumna].zwrocFloat();
	for(int y=0; y<rozmiarY; y++) {
		if(minimum>tablica[y][kolumna].zwrocFloat()) {
			minimum = tablica[y][kolumna].zwrocFloat();
		}
	}
	return minimum;
}

float Tablica::maksimumKolumny(int kolumna) {
	float maksimum = tablica[0][kolumna].zwrocFloat();
	for(int y=0; y<rozmiarY; y++) {
		if(maksimum<tablica[y][kolumna].zwrocFloat()) {
			maksimum = tablica[y][kolumna].zwrocFloat();
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
	for(int y=0; y<rozmiarY; y++) {
		for(int x=0; x<rozmiarX; x++) {
			plik << tablica[y][x].typ << "\t";
			plik << tablica[y][x].zwrocString() << "\t";
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
		dane >> odczytano_wierszy;
		cout << "Odczytano ilosc wierszy: " << odczytano_wierszy << endl;
		if(!(odczytano_wierszy > 0) || (!(odczytano_kolumn > 0))) {
			return -1;
		}
		this->utworzTablice(odczytano_kolumn, odczytano_wierszy);
		
		string biezacyTyp = "int";
		for(int y=0; y<rozmiarY; y++) {
			for(int x=0; x<rozmiarX; x++) {
				dane >> biezacyTyp;
				tablica[y][x].ustawTyp(biezacyTyp);

				if(biezacyTyp == "int") {
					int biezacaKomorka;
					dane >> biezacaKomorka;
					tablica[y][x].ustaw(biezacaKomorka);
				}

				if(biezacyTyp == "float") {
					float biezacaKomorka;
					dane >> biezacaKomorka;
					tablica[y][x].ustaw(biezacaKomorka);
				}

				if(biezacyTyp == "string") {
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