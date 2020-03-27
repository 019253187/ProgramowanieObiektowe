#include <iostream>
#include "menu.h"
#include "tablice.h"

using namespace std;

int main() {
	cout << "Witaj w moim programie do obslugi jednowymiarowej tablicy. " << endl;
	int* tablica = NULL; // wskaznik, ktorego potem bedziemy uzywac do wskazywania naszej tablicy
	int rozmiar = 0; //rozmiar naszej tablicy
	int argument = -1; //Uzywany do przekazywania argumentu np. nowego rozmiaru przy zmianie rozmiaru
	int argument2 = -1;
	int opcja = -13;
	while(opcja<5) { 
		// cout << "tablica = " << tablica << endl; //Do debugowania
		opcja = uruchomMenu(argument, argument2);
		switch(opcja) {
			case 1:
				rozmiar = argument;
				tablica = utworzTablice(rozmiar);
				break;
			case 2:
				zmienKomorke(tablica, rozmiar, argument, argument2);
				break;
			case 3:
				wyswietlTablice(tablica, rozmiar);
				break;
			case 4:
				int* nowa_tablica = NULL;
				nowa_tablica = zmianaRozmiaru(tablica, rozmiar, argument);
				tablica = nowa_tablica;
				break;
		}
	}
	if(tablica != NULL) delete [] tablica;
	cout << "Zycze zdrowia." << endl;
	return 0;
}