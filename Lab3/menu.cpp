#include <iostream>
#include "tablice.h"

using namespace std;

void wyswietlMenu() {
	cout << "Co chcesz zrobic?" << endl;
	cout << "1. Utworz tablice" << endl;
	cout << "2. Zmien zawartosc komorki tablicy" << endl;
	cout << "3. Wyswietl tablice" << endl;
	cout << "4. Zmien rozmiar tablicy" << endl;
	cout << "5. Zsumuj wedlug wiersza" << endl;
	cout << "6. Zsumuj wedlug kolumny" << endl;
	cout << "7. Znajdz minimum wiersza" << endl;
	cout << "8. Znajdz minimum kolumny" << endl;
	cout << "9. Znajdz maksimum wiersza" << endl;
	cout << "10. Znajdz maksimum kolumny" << endl;
	cout << "11. Znajdz srednia wiersza" << endl;
	cout << "12. Znajdz srednia kolumny" << endl;
	cout << "13. Zapisz tablice do pliku" << endl;
	cout << "14. Odczytaj tablice z pliku" << endl;

	cout << "15. Zakoncz program" << endl;

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
		case 15:
			cout << "Ktory wiersz? ";
			break;
		case 16:
			cout << "Ktora kolumna? ";
			break;
		case 25:
			cout << "Oto suma wiersza " << opcjonalnaLiczba1 << ". : ";
			cout << opcjonalnaLiczba2 << endl;
			break;
		case 26:
			cout << "Oto suma kolumny " << opcjonalnaLiczba1 << ". : ";
			cout << opcjonalnaLiczba2 << endl;
			break;
		case 35:
			cout << "Oto minimum wiersza " << opcjonalnaLiczba1 << ". : ";
			cout << opcjonalnaLiczba2 << endl;
			break;
		case 36:
			cout << "Oto minimum kolumny " << opcjonalnaLiczba1 << ". : ";
			cout << opcjonalnaLiczba2 << endl;
			break;
		case 45:
			cout << "Oto maksimum wiersza " << opcjonalnaLiczba1 << ". : ";
			cout << opcjonalnaLiczba2 << endl;
			break;
		case 46:
			cout << "Oto maksimum kolumny " << opcjonalnaLiczba1 << ". : ";
			cout << opcjonalnaLiczba2 << endl;
			break;
		case 55:
			cout << "Oto srednia wiersza " << opcjonalnaLiczba1 << ". : ";
			cout << opcjonalnaLiczba2 << endl;
			break;
		case 56:
			cout << "Oto srednia kolumny " << opcjonalnaLiczba1 << ". : ";
			cout << opcjonalnaLiczba2 << endl;
			break;
		case 100:
			cout << "Podaj nazwe pliku(wraz z rozszerzeniem) do zapisania: ";
			break; 
		case 101:
			cout << "Podaj nazwe pliku(wraz z rozszerzeniem) do otwarcia: ";
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
	
	while(wybranaOpcja<15) { 
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
				
				tablica.utworzTablice(nowyRozmiarX, nowyRozmiarY);
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
				tablica.zmienKomorke(adresX, adresY, nowaZawartosc);
				break;
			}
			case 3:{
				int zwrot = tablica.wyswietlTablice();
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
				int zwrot = tablica.zmianaRozmiaru(nowyRozmiarX, nowyRozmiarY);
				if(zwrot) {
					wyswietlKomunikat(zwrot);
				}
				break;
			}
			case 5: {
				if(tablica.rozmiarX<=0 || tablica.rozmiarY<=0) {
					wyswietlKomunikat(-1);
					break;
				}
				wyswietlKomunikat(15);
				int adresY = pobierzLiczbe(true, 0, (tablica.rozmiarY-1));
				int suma = tablica.sumujWiersz(adresY);
				wyswietlKomunikat(25, adresY, suma);
				break;
			}
			case 6: {
				if(tablica.rozmiarX<=0 || tablica.rozmiarY<=0) {
					wyswietlKomunikat(-1);
					break;
				}
				wyswietlKomunikat(16);
				int adresX = pobierzLiczbe(true, 0, (tablica.rozmiarX-1));
				int suma = tablica.sumujKolumne(adresX);
				wyswietlKomunikat(26, adresX, suma);
				break;
			}
			case 7: {
				if(tablica.rozmiarX<=0 || tablica.rozmiarY<=0) {
					wyswietlKomunikat(-1);
					break;
				}
				wyswietlKomunikat(15);
				int adresY = pobierzLiczbe(true, 0, (tablica.rozmiarY-1));
				int suma = tablica.minimumWiersza(adresY);
				wyswietlKomunikat(35, adresY, suma);
				break;
			}
			case 8: {
				if(tablica.rozmiarX<=0 || tablica.rozmiarY<=0) {
					wyswietlKomunikat(-1);
					break;
				}
				wyswietlKomunikat(16);
				int adresX = pobierzLiczbe(true, 0, (tablica.rozmiarX-1));
				int suma = tablica.minimumKolumny(adresX);
				wyswietlKomunikat(36, adresX, suma);
				break;
			}
			case 9: {
				if(tablica.rozmiarX<=0 || tablica.rozmiarY<=0) {
					wyswietlKomunikat(-1);
					break;
				}
				wyswietlKomunikat(15);
				int adresY = pobierzLiczbe(true, 0, (tablica.rozmiarY-1));
				int suma = tablica.maksimumWiersza(adresY);
				wyswietlKomunikat(45, adresY, suma);
				break;
			}
			case 10: {
				if(tablica.rozmiarX<=0 || tablica.rozmiarY<=0) {
					wyswietlKomunikat(-1);
					break;
				}
				wyswietlKomunikat(16);
				int adresX = pobierzLiczbe(true, 0, (tablica.rozmiarX-1));
				int suma = tablica.maksimumKolumny(adresX);
				wyswietlKomunikat(46, adresX, suma);
				break;
			}
			case 11: {
				if(tablica.rozmiarX<=0 || tablica.rozmiarY<=0) {
					wyswietlKomunikat(-1);
					break;
				}
				wyswietlKomunikat(15);
				int adresY = pobierzLiczbe(true, 0, (tablica.rozmiarY-1));
				float srednia = tablica.sredniaWiersza(adresY);
				wyswietlKomunikat(55, adresY, srednia);
				break;
			}
			case 12: {
				if(tablica.rozmiarX<=0 || tablica.rozmiarY<=0) {
					wyswietlKomunikat(-1);
					break;
				}
				wyswietlKomunikat(16);
				int adresX = pobierzLiczbe(true, 0, (tablica.rozmiarX-1));
				float srednia = tablica.sredniaKolumny(adresX);
				wyswietlKomunikat(56, adresX, srednia);
				break;
			}
			case 13: {
				if(tablica.rozmiarX<=0 || tablica.rozmiarY<=0) {
					wyswietlKomunikat(-1);
					break;
				}
				string nazwaPliku;
				wyswietlKomunikat(100);
				cin >> nazwaPliku;
				tablica.zapiszTablice(nazwaPliku);
				break;
			}
			case 14: {
				string nazwaPliku;
				wyswietlKomunikat(101);
				cin >> nazwaPliku;
				tablica.otworzTablice(nazwaPliku);
				break;
			}
		}
		wyswietlMenu();
		wybranaOpcja = pobierzLiczbe(true, 1, 15);	
	}
	wyswietlKomunikat(10);
}