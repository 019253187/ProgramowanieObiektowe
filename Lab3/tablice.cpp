#include <iostream>

using namespace std;

struct Tablica {
	int** tablica = NULL;
	int rozmiarX = 0;
	int rozmiarY = 0;
};

int utworzTablice(Tablica* tabelka, int rozmiarX, int rozmiarY) {
	tabelka->rozmiarX = rozmiarX;
	tabelka->rozmiarY = rozmiarY;
	tabelka->tablica = new int*[rozmiarY];
	for(int y=0; y<tabelka->rozmiarY; y++) {
		tabelka->tablica[y] = new int[rozmiarX];
		for(int x=0; x<tabelka->rozmiarX; x++) {
			tabelka->tablica[y][x] = 0;
		}
	}
	return 0;
}

int zmienKomorke(Tablica tablica, int xKomorki, int yKomorki, int nowaZawartosc) {
	if(tablica.rozmiarX<=0 || tablica.rozmiarY<=0) {
		return -1;
	}
	if(xKomorki<0 || yKomorki<0) {
		return -2;
	}
	if(yKomorki>=tablica.rozmiarY || xKomorki>=tablica.rozmiarX) {
		return -3;
	}

	tablica.tablica[yKomorki][xKomorki] = nowaZawartosc;
	return 0;
}

int wyswietlTablice(Tablica tablica) {
	if(tablica.rozmiarX<=0 || tablica.rozmiarY<=0) {			
		return -1;
	}
	cout << "Oto twoja tablica o rozmiarze ";
	cout << tablica.rozmiarX << " kolumn na  "; 
	cout << tablica.rozmiarY << " wierszy:" << endl;
	for(int y=0; y<tablica.rozmiarY; y++) {
		for(int x=0; x<tablica.rozmiarX; x++) {
			cout << tablica.tablica[y][x] << "\t";
		}
		cout << endl;
	}
	return 0;
}

int zmianaRozmiaru(Tablica* tablica, int nowyRozmiarX, int nowyRozmiarY) {
	if(tablica->rozmiarX<=0 || tablica->rozmiarY<=0) {
		return -1;
	}
	Tablica tabelka;
	utworzTablice(&tabelka, nowyRozmiarX, nowyRozmiarY);
	for(int y=0; y<nowyRozmiarY; y++) {
		for(int x=0; x<nowyRozmiarX; x++) {
			if(x<(tablica->rozmiarX)) {
				tabelka.tablica[y][x] = ((tablica->tablica)[y][x]);
			}
		}
	}
	//Wywala segfault przy powiekszaniu tablicy
	tablica->tablica = tabelka.tablica;
	tablica->rozmiarX = nowyRozmiarX;
	tablica->rozmiarY = nowyRozmiarY;
	return 0;
}

int sumujWiersz(Tablica tablica, int wiersz) {
	int suma = 0;
	for(int x=0; x<tablica.rozmiarX; x++) {
		suma += tablica.tablica[wiersz][x];
	}
	return suma;
}

int sumujKolumne(Tablica tablica, int kolumna) {
	int suma = 0;
	for(int y=0; y<tablica.rozmiarY; y++) {
		suma += tablica.tablica[y][kolumna];
	}
	return suma;
}