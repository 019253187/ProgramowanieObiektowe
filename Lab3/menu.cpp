#include <iostream>
#include "tablice.h"

using namespace std;

void wyswietlMenu() {
	cout << "Co chcesz zrobic?" << endl;
	cout << "1. Utworz tablice" << endl;
	cout << "2. Zmien zawartosc komorki tablicy" << endl;
	cout << "3. Wyswietl tablice" << endl;
	cout << "4. Zmien rozmiar tablicy" << endl;
	cout << "5. Zakoncz program" << endl;

	cout << "Podaj swoj wybor: ";
}

void wyswietlKomunikat(int nrKomunikatu, int opcjonalnaLiczba1 = -5, int opcjonalnaLiczba2 = -42) {
	switch(nrKomunikatu) {
		case -6:
			cout << "Rozmiar tablicy nie moze byc ujemny ani 0." << endl;
			cout << "Podaj poprawny rozmiar tworzonej tablicy: ";
			break;
		case -5:
			cout << "Error. Podaj liczbe calkowita:";
			break;
		case -4:
			cout << "Error. Podaj liczbe calkowita z zakresu od "
			<< opcjonalnaLiczba1 << " do " << opcjonalnaLiczba2 << ":";
			break;
		case -3:
			cout << "ERROR: Indeks wykracza poza tablice." << endl;
			break;
		case -2:
			cout << "ERROR: Indeks musi byc wiekszy od lub rowny zeru." << endl;
			break;
		case -1:
			cout << "ERROR: tablica nie istnieje!" << endl;
			break;
		case 0:
			cout << "Witaj w moim programie do obslugi jednowymiarowej tablicy.";
			cout << endl;
			break;
		case 1:
			cout << "Podaj rozmiar X (ilosc kolumn) tworzonej tablicy: ";
			break;
		case 11:
			cout << "Podaj rozmiar Y (ilosc wierszy) tworzonej tablicy: ";
			break;
		case 2:
			cout << "Utworzylem tablice o rozmiarze " << opcjonalnaLiczba1 << endl;
			break;
		case 3:
			cout << "Elementy tablicy sa numerowane od 0." << endl;
			cout << "Podaj wspolrzedna X komorki, ktora chcesz zmienic: ";
			break;
		case 31:
			cout << "Podaj wspolrzedna Y komorki, ktora chcesz zmienic: ";
			break;
		case 4:
			cout << "Podaj nowa zawartosc elementu (" << opcjonalnaLiczba1;
			cout << "," << opcjonalnaLiczba2 << "): ";
			break;
		case 5:
			cout << "Podaj nowy rozmiar X tablicy: ";
			break;
		case 51:
			cout << "Podaj nowy rozmiar Y tablicy: ";
			break;
		case 6:
			cout << "UWAGA! Nowy rozmiar tablicy jest mniejszy od starego." << endl;
			cout << "Elementy od " << opcjonalnaLiczba1 << " do "; 
			cout << opcjonalnaLiczba2 << " zostaly usuniete." << endl;
			break;
		case 7:
			cout << "Nowy rozmiar jest taki sam jak stary." << endl;
			break;
		case 8:
			cout << "Nowy rozmiar tablicy jest wiekszy od starego." << endl;
			cout << "Nowe elementy (od " << opcjonalnaLiczba1;
			cout << ". wzwyz) zostana zainicjalizowane z zawartoscia 0." << endl;
			break;
		case 10:
			cout << "Zycze zdrowia." << endl;
			break;
		default:
			cout << "Domyslny komunikat" << endl;
	}
}

int pobierzLiczbe(bool ograniczona = false, int zakresMin = 0, int zakresMax = 100) {
	int pobranaLiczba = -1;

	//cout << "Zakres minimalny to " << zakresMin << endl;
	//cout << "Zakres maksymalny to " << zakresMax << endl; //couty do debugowania
	cin >> pobranaLiczba;
	if(ograniczona){
		while(cin.fail() || pobranaLiczba < zakresMin || pobranaLiczba > zakresMax) {
			wyswietlKomunikat(-4, zakresMin, zakresMax);
			cin.clear();
			cin.ignore(256, '\n');
			cin >> pobranaLiczba;
			continue;
		}
	} else {
		while(cin.fail()) {
			wyswietlKomunikat(-5);
			cin.clear();
			cin.ignore(256, '\n');
			cin >> pobranaLiczba;
			continue;
		}
	}
	return pobranaLiczba;
}

void uruchomMenu(Tablica tablica) {
	int  wybranaOpcja = -13;
	wyswietlKomunikat(0);
	
	while(wybranaOpcja<5) { 
		switch(wybranaOpcja) {
			case 1: {
				wyswietlKomunikat(11);
				int nowyRozmiarY = pobierzLiczbe();
				while(nowyRozmiarY<=0) {
					wyswietlKomunikat(-6);
					nowyRozmiarY = pobierzLiczbe();
				}

				wyswietlKomunikat(1);
				int nowyRozmiarX = pobierzLiczbe();
				while(nowyRozmiarX<=0) {
					wyswietlKomunikat(-6);
					nowyRozmiarX = pobierzLiczbe();
				}
/*
				if(tablica.tablica != NULL) {
					delete [] tablica.tablica;
				}*/
				Tablica* naszaTablica = &tablica;
				utworzTablice(naszaTablica, nowyRozmiarX, nowyRozmiarY);
				break;
			}
			case 2: {
				if(tablica.rozmiarX<=0 || tablica.rozmiarY<=0) {
					wyswietlKomunikat(-1);
					break;
				}
				wyswietlKomunikat(3);
				int adresX = pobierzLiczbe(true, 0, (tablica.rozmiarX-1));
				wyswietlKomunikat(31);
				int adresY = pobierzLiczbe(true, 0, (tablica.rozmiarY-1));

				wyswietlKomunikat(4, adresX, adresY);
				int nowaZawartosc = pobierzLiczbe();
				zmienKomorke(tablica, adresX, adresY, nowaZawartosc);
				break;
			}
			case 3:{
				int zwrot = wyswietlTablice(tablica);
				if(zwrot<0) {
					wyswietlKomunikat(zwrot);
				}
				break;
			}
			case 4: {
				wyswietlKomunikat(51);
				int nowyRozmiarY = pobierzLiczbe();
				while(nowyRozmiarY<=0) {
					wyswietlKomunikat(-6);
					nowyRozmiarY = pobierzLiczbe();
				}

				wyswietlKomunikat(5);
				int nowyRozmiarX = pobierzLiczbe();
				while(nowyRozmiarX<=0) {
					wyswietlKomunikat(-6);
					nowyRozmiarX = pobierzLiczbe();
				}
				/*if(nowyRozmiar<(*rozmiarTablicy)) {
					wyswietlKomunikat(6, nowyRozmiar, *rozmiarTablicy);
				} else if(nowyRozmiar == (*rozmiarTablicy)) {
					wyswietlKomunikat(7);
				} else {
					wyswietlKomunikat(8, *rozmiarTablicy);
				}*/
				Tablica* naszaTablica = &tablica;
				int zwrot = zmianaRozmiaru(naszaTablica, nowyRozmiarX, nowyRozmiarY);
				if(zwrot) {
					wyswietlKomunikat(zwrot);
				}
				break;
			}
		}
		wyswietlMenu();
		wybranaOpcja = pobierzLiczbe(true, 1, 5);	
	}
	wyswietlKomunikat(10);
}