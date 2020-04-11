#ifndef TABLICE_H
#define TABLICE_H

int* utworzTablice(int rozmiarTablicy);

/**
 * Zmienia zawartosc wybranej komorki w tablicy.
 *
 * @param tablica Wskaznik do poczatku tablicy intow, ktorej komorke chcemy zmodyfikowac
 * @param rozmiarTablicy Calkowita ilosc elementow danej tablicy
 * @param ktoraKomorka Indeks komorki, ktora ma zostac zmieniona (liczony od 0)
 * @param nowaZawartosc Docelowa zawartosc modyfikowanej komorki
 * @return Kod błędu lub 0 w przypadku powodzenia
 */
int zmienKomorke(int* tablica, int rozmiarTablicy, int ktoraKomorka, int nowaZawartosc);

int wyswietlTablice(int* tablica, int rozmiarTablicy);

/**
 * Tworzy nowa tablice o podanym rozmiarze i kopiuje zawartosc starej tablicy
 * do nowej na tyle, na ile to mozliwe. Komorki ponad rozmiar starej tablicy sa
 * inicjalizowane jako "0". Stara tablica jest usuwana.
 *
 * @param tablica Wskaznik do poczatku tablicy intow, ktorej rozmiar chcemy zmienic
 * @param rozmiarTablicy Dotychczasowy, stary rozmiar tablicy "tablica"
 * @param nowyRozmiarTablicy Rozmiar nowej tablicy
 * @return Wskaznik do nowej tablicy lub NULL w przypadku błędu
 */
int* zmianaRozmiaru(int* tablica, int& rozmiarTablicy, int nowyRozmiarTablicy);

#endif