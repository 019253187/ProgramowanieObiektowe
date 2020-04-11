#include <iostream>
#include "menu.h"


using namespace std;

int main() {
	int* tablica = NULL;
	int  rozmiarTablicy = 0;
	uruchomMenu(tablica, &rozmiarTablicy);
	
	if(tablica != NULL) delete [] tablica;
	return 0;
}