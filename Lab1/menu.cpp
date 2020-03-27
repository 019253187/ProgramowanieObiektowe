#include <iostream>

using namespace std;

int pobierzLiczbe(bool ograniczona = false, int zakres_min = 0, int zakres_max = 100) { //Wewnetrzna funkcja obslugi menu, stad nie umieszczam jej w pliku naglowkowym "menu.h"
	int pobranaLiczba = -10;

	//cout << "Zakres minimalny to " << zakres_min << endl;
	//cout << "Zakres maksymalny to " << zakres_max << endl; //couty do debugowania
	cin >> pobranaLiczba;
	if(ograniczona){
		while(cin.fail() || pobranaLiczba < zakres_min || pobranaLiczba > zakres_max) { //Weryfikacja, czy uzytkownik wprowadzil liczbe z wlasciwego zakresu
			cout << "Error. Podaj liczbe calkowita z zakresu od " << zakres_min << " do " << zakres_max << ":";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> pobranaLiczba;
			continue;
		}
	} else {
		while(cin.fail()) { //Weryfikacja, czy uzytkownik wprowadzil liczbe z wlasciwego zakresu
			cout << "Error. Podaj liczbe calkowita:";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> pobranaLiczba;
			continue;
		}
	}
	return pobranaLiczba;
}

int uruchomMenu(int& argument, int& argument2) {
	int wybor = -1;
	cout << "Co chcesz zrobic?" << endl;
	cout << "1. Utworz tablice" << endl;
	cout << "2. Zmien zawartosc komorki tablicy" << endl;
	cout << "3. Wyswietl tablice" << endl;
	cout << "4. Zmien rozmiar tablicy" << endl;
	cout << "5. Zakoncz program" << endl;

	cout << "Podaj swoj wybor: ";
	wybor = pobierzLiczbe(true, 1, 5);
	switch(wybor) { //Tutaj program dopytuje sie, jezeli zachodzi potrzeba pozyskania dodatkowych argumentow
		case 1:
			cout << "Podaj rozmiar tworzonej tablicy: ";
			argument = pobierzLiczbe();
			while(argument<=0) {
				cout << "Rozmiar tablicy nie moze byc ujemny ani 0." << endl;
				cout << "Podaj poprawny rozmiar tworzonej tablicy: ";
				argument = pobierzLiczbe();
			}
			break;
		case 2:
			cout << "Elementy tablicy sa numerowane od 0." << endl;
			cout << "Ktory element tablicy chcesz zmienic? ";
			argument = pobierzLiczbe();
			cout << "Podaj nowa zawartosc elementu " << argument << ".: ";
			argument2 = pobierzLiczbe();
			break;
		case 4:
			cout << "Podaj nowy rozmiar tablicy: ";
			argument = pobierzLiczbe();
			while(argument<=0) {
				cout << "Rozmiar tablicy nie moze byc ujemny ani zerowy." << endl;
				cout << "Podaj poprawny nowy rozmiar tablicy: ";
				argument = pobierzLiczbe();
			}
			break;
	}
	return wybor;
}