#ifndef TABLICE_H
#define TABLICE_H

#include <string>

class Komorka {
public:
	std::string typ;

	Komorka();
	Komorka(std::string typKomorki);
	int ustaw(int wartosc);
	int ustaw(float wartosc);
	int ustaw(std::string wartosc);
	int zwrocInt();
	float zwrocFloat();
	std::string zwrocString();
	int ustawTyp(std::string typKomorki);
	
private:
	int zawartoscInt;
	float zawartoscFloat;
	std::string zawartoscString;
};


/**@class Tablica
 * @brief Klasa sluzaca do wygodnego przechowywania i obslugi tablic
 * @var Tablica::tablica
 * Wlasciwa, dwuwymiarowa tablica typu int(wskaznik wskaznika)
 * @var Tablica::rozmiarX
 * Ilosc komorek w kazdym wierszu tablicy
 * @var Tablica::rozmiarY
 * Ilosc wierszy w calej tablicy
 */
class Tablica {
public:
	Komorka** tablica;
	int rozmiarX;
	int rozmiarY;
	
	Tablica(); //Konstruktor do inicjalizowania wartości początkowych
	
	/** Inicjalizuje nowa tablice 2D o podanych wymiarach
	 *
	 * @param tablica Wskaznik do tablicy do zainicjalizowania
	 * @param rozmiarX ilosc kolumn w danym wierszu
	 * @param rozmiarY ilosc wierszy
	 * @return obiekt typu Tablica ze wszystkimi komorkami rownymi 0
	 */
	int utworzTablice(int rozmiarX, int rozmiarY);

	/**
	 * Zmienia zawartosc wybranej komorki w tablicy.
	 *
	 * @param tablica Modyfikowana tablica
	 * @param xKomorki Współrzędna X(kolumna) komórki do zmodyfikowania 
	 * @param yKomorki Współrzędna Y(wiersz) komórki do zmodyfikowania 
	 * @param nowaZawartosc Docelowa zawartosc modyfikowanej komorki
	 * @return Kod błędu lub 0 w przypadku powodzenia
	 */
	int zmienKomorke(int xKomorki, int yKomorki, int nowaZawartosc);

	int zmienKomorke(int xKomorki, int yKomorki, float nowaZawartosc);

	int zmienKomorke(int xKomorki, int yKomorki, std::string nowaZawartosc);

	int wyswietlTablice(void);

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
	int zmianaRozmiaru(int nowyRozmiarX, int nowyRozmiarY);

	/**
	 * Zwraca sume wartosci wszystkich komorek danego wiersza.
	 *
	 * @param tablica Tablica robocza
	 * @param wiersz indeks wiersza do zsumowania
	 * @return Suma wartosci w danym wierszu 
	 */
	float sumujWiersz(int wiersz);

	/**
	 * Zwraca sume wartosci wszystkich komorek danej kolumny.
	 *
	 * @param tablica Tablica robocza
	 * @param kolumna indeks kolumny do zsumowania
	 * @return Suma wartosci w danej kolumnie 
	 */
	float sumujKolumne(int kolumna);

	/**
	 * Zwraca najmniejsza wartosc ze wszystkich komorek danego wiersza.
	 *
	 * @param tablica Tablica robocza
	 * @param kolumna indeks kolumny do przeszukania
	 * @return Najmniejsza wartosc w danym wierszu 
	 */
	float minimumWiersza(int kolumna);

	/**
	 * Zwraca najwieksza wartosc ze wszystkich komorek danego wiersza.
	 *
	 * @param tablica Tablica robocza
	 * @param kolumna indeks kolumny do przeszukania
	 * @return Najwieksza wartosc w danym wierszu 
	 */
	float maksimumWiersza(int kolumna);

	/**
	 * Zwraca wartosc srednia wszystkich komorek danego wiersza.
	 *
	 * @param tablica Tablica robocza
	 * @param kolumna indeks kolumny do przeszukania
	 * @return wartosc srednia danego wiersza 
	 */
	float sredniaWiersza(int kolumna);

	/**
	 * Zwraca najmniejsza wartosc ze wszystkich komorek danej kolumny.
	 *
	 * @param tablica Tablica robocza
	 * @param kolumna indeks kolumny do przeszukania
	 * @return Najmniejsza wartosc w danej kolumnie 
	 */
	float minimumKolumny(int kolumna);

	/**
	 * Zwraca najwieksza wartosc ze wszystkich komorek danej kolumny.
	 *
	 * @param tablica Tablica robocza
	 * @param kolumna indeks kolumny do przeszukania
	 * @return Najwieksza wartosc w danej kolumnie 
	 */
	float maksimumKolumny(int kolumna);

	/**
	 * Zwraca wartosc srednia wszystkich komorek danej kolumny.
	 *
	 * @param tablica Tablica robocza
	 * @param kolumna indeks kolumny do przeszukania
	 * @return wartosc srednia danej kolumny 
	 */
	float sredniaKolumny(int kolumna);

	/** Zapisuje tablice do pliku o podanej nazwie
	 *
	 * @param tablica Tablica do zapisania
	 * @param nazwaPliku nazwa lub sciezka pliku, w ktorym ma zostac zapisana tablica
	 * @return Kod błędu lub 0 w przypadku powodzenia
	*/
	int zapiszTablice(std::string nazwaPliku);

	/** Ładuje tablicę do pliku o podanej nazwie
	 *
	 * @param tablica Tablica, ktora ma zostac zainicjalizowana z pliku
	 * @param nazwaPliku nazwa lub sciezka pliku, z ktorego odczytana bedzie tablica
	 * @return Kod błędu lub 0 w przypadku powodzenia
	*/
	int otworzTablice(std::string nazwaPliku);
};
#endif