#include <iostream>

using namespace std;

int* utworzTablice(int rozmiarTablicy) {
	int* tabelka = new int[rozmiarTablicy];
	return tabelka;
}

int zmienKomorke(int* tablica, int rozmiarTablicy, int ktoraKomorka, int nowaZawartosc) {
	if(tablica == NULL) {
		return -1;
	}
	if(ktoraKomorka<0) {
		return -2;
	}
	if(ktoraKomorka>=rozmiarTablicy) {
		return -3;
	}

	tablica[ktoraKomorka] = nowaZawartosc;
	return 0;
}

int wyswietlTablice(int* tablica, int rozmiarTablicy) {
	if(tablica == NULL) {
		return -1;
	}
	cout << "Oto twoja tablica o rozmiarze " << rozmiarTablicy <<":" << endl;
	for(int i = 0; i<rozmiarTablicy; i++) {
		cout << tablica[i] << endl;
	}
	return 0;
}

int* zmianaRozmiaru(int* tablica, int& rozmiarTablicy, int nowyRozmiarTablicy) {
	if(tablica == NULL) {
		return NULL;
	}
	int* tabelka = NULL;
	tabelka = new int[nowyRozmiarTablicy];
	if(nowyRozmiarTablicy<rozmiarTablicy) {
		for(int i = 0; i < nowyRozmiarTablicy; i++) {
			tabelka[i] = tablica[i];
		}
	} else if(nowyRozmiarTablicy == rozmiarTablicy) {
		tabelka = tablica;
	} else {
		for(int i = 0; i < rozmiarTablicy; i++) {
			tabelka[i] = tablica[i];
		}
		for(int i = rozmiarTablicy; i < nowyRozmiarTablicy; i++) {
			tabelka[i] = 0;
		}
	}
	rozmiarTablicy = nowyRozmiarTablicy;
	
	delete [] tablica;
	return tabelka;
}
