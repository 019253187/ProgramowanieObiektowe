#ifndef TABLICE_H
#define TABLICE_H
/**@struct Tablica
 * @brief Struktura sluzaca do wygodnego przechowywania tablic
 * @var Tablica::tablica
 * Wlasciwa, dwuwymiarowa tablica typu int(wskaznik wskaznika)
 * @var Tablica::rozmiarX
 * Ilosc komorek w kazdym wierszu tablicy
 * @var Tablica::rozmiarY
 * Ilosc wierszy w calej tablicy
 */
struct Tablica {
	int** tablica;
	int rozmiarX;
	int rozmiarY;
};
/** Inicjalizuje nowa tablice 2D o podanych wymiarach
 *
 * @param tablica Wskaznik do tablicy do zainicjalizowania
 * @param rozmiarX ilosc kolumn w danym wierszu
 * @param rozmiarY ilosc wierszy
 * @return obiekt typu Tablica ze wszystkimi komorkami rownymi 0
*/
int utworzTablice(Tablica* tablica, int rozmiarX, int rozmiarY);

/**
 * Zmienia zawartosc wybranej komorki w tablicy.
 *
 * @param tablica Modyfikowana tablica
 * @param xKomorki Współrzędna X(kolumna) komórki do zmodyfikowania 
 * @param yKomorki Współrzędna Y(wiersz) komórki do zmodyfikowania 
 * @param nowaZawartosc Docelowa zawartosc modyfikowanej komorki
 * @return Kod błędu lub 0 w przypadku powodzenia
 */
int zmienKomorke(Tablica tablica, int xKomorki, int yKomorki, int nowaZawartosc);

int wyswietlTablice(Tablica tablica);

/**
 * Tworzy nowa tablice o podanym rozmiarze i kopiuje zawartosc starej tablicy
 * do nowej na tyle, na ile to mozliwe. Komorki ponad rozmiar starej tablicy sa
 * inicjalizowane jako "0". Stara tablica jest usuwana.
 *
 * @param Tablica Wskaznik do tablicy, ktorej rozmiar ma zostac zmieniony
 * @param nowyRozmiarX Ilosc kolumn w nowej tablicy
 * @param nowyRozmiarY Ilosc wierszy w nowej tablicy
 * @return Kod błędu lub 0 w przypadku błędu
 */
int zmianaRozmiaru(Tablica* tablica, int nowyRozmiarX, int nowyRozmiarY);

/**
 * Zwraca sume wartosci wszystkich komorek danego wiersza.
 *
 * @param tablica Tablica robocza
 * @param wiersz indeks wiersza do zsumowania
 * @return Suma wartosci w danym wierszu 
 */
int sumujWiersz(Tablica tablica, int wiersz);

/**
 * Zwraca sume wartosci wszystkich komorek danej kolumny.
 *
 * @param tablica Tablica robocza
 * @param kolumna indeks kolumny do zsumowania
 * @return Suma wartosci w danej kolumnie 
 */
int sumujKolumne(Tablica tablica, int kolumna);

#endif