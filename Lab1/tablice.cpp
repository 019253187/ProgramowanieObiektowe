#include <iostream>

using namespace std;

int* utworzTablice(int rozmiar) {
	int* tabelka = new int[rozmiar];
	cout << "Utworzylem tablice o rozmiarze " << rozmiar << endl;
	return tabelka;
}

int zmienKomorke(int* tablica, int rozmiar, int ktora, int nowa_zawartosc) {
	if(tablica == NULL) {
		cout << "ERROR: tablica nie istnieje!" << endl;
		return -1;
	}
	if(ktora<0) {
		cout << "ERROR: Indeks musi byc wiekszy od lub rowny zeru." << endl;
		return -1;
	}
	if(ktora>=rozmiar) {
		cout << "ERROR: Indeks wykracza poza tablice." << endl;
		return -1;
	}

	tablica[ktora] = nowa_zawartosc;
	return 0;
}

int wyswietlTablice(int* tablica, int rozmiar) {
	if(tablica == NULL) {
		cout << "ERROR: tablica nie istnieje!" << endl;
		return -1;
	}
	cout << "Oto twoja tablica o rozmiarze " << rozmiar <<":" << endl;
	for(int i = 0; i<rozmiar; i++) {
		cout << tablica[i] << endl;
	}
	return 0;
}

int* zmianaRozmiaru(int* tablica, int& rozmiar, int nowy_rozmiar) {
	if(tablica == NULL) {
		cout << "ERROR: tablica nie istnieje!" << endl;
		return NULL;
	}
	int* tabelka = NULL;
	tabelka = new int[nowy_rozmiar];
	if(nowy_rozmiar<rozmiar) {
		cout << "UWAGA! Nowy rozmiar tablicy jest mniejszy od starego." << endl;
		cout << "Elementy od " << nowy_rozmiar << " do " << rozmiar << " zostaly usuniete." << endl;
		for(int i = 0; i < nowy_rozmiar; i++) {
			tabelka[i] = tablica[i];
		} 
	} else if(nowy_rozmiar == rozmiar) {
		cout << "Nowy rozmiar jest taki sam jak stary." << endl;
		tabelka = tablica;
	} else {
		cout << "Nowy rozmiar tablicy jest wiekszy od starego." << endl;
		cout << "Nowe elementy (od " << rozmiar << ". wzwyz) zostana zainicjalizowane z zawartoscia 0." << endl;
		for(int i = 0; i < rozmiar; i++) {
			tabelka[i] = tablica[i];
		}
		for(int i = rozmiar; i < nowy_rozmiar; i++) {
			tabelka[i] = 0;
		}
	}
	rozmiar = nowy_rozmiar;
	
	delete [] tablica;
	return tabelka;
}
