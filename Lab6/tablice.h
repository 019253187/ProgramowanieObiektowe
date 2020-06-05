#ifndef TABLICE_H
#define TABLICE_H

#include <string>

/**@class Komorka
 * @brief Klasa podstawowa dla poszczegolnych rodzajow Komorek
 *
 */
class Komorka {
public:
	virtual int ustaw(int wartosc) = 0;
	virtual int ustaw(std::string wartosc) = 0;
	virtual int zwrocInt() = 0;
	virtual std::string zwroc() = 0;
};

/**@class KomorkaLiczbowa
 * @brief Klasa reprezentujaca Komorke zawierajaca wartosc typu int
 *
 * @var typ String reprezentujacy typ komorki (tu zawsze "int")
 * @var zawartosc Zawartosc komorki(liczba typu int)
 */
class KomorkaLiczbowa: public Komorka {
public:
	KomorkaLiczbowa();
	int ustaw(int wartosc);
	int ustaw(std::string wartosc);
	int zwrocInt();
	std::string zwroc();
private:
	int zawartosc;
};

/**@class KomorkaTekstowa
 * @brief Klasa reprezentujaca Komorke zawierajaca wartosc typu string
 *
 * @var typ String reprezentujacy typ danej komorki(tu zawsze "string") - do usuniecia
 * @var zawartosc Zawartosc komorki(ciąg znaków typu string)
 */
class KomorkaTekstowa: public Komorka {
public:
	KomorkaTekstowa();
	int ustaw(std::string wartosc);
	int ustaw(int wartosc);
	int zwrocInt();
	std::string zwroc();
private:
	std::string zawartosc;
};

/**@class Tablica
 * @brief Klasa sluzaca do wygodnego przechowywania i obslugi tablic
 * @var Tablica::tablica
 * Wlasciwa, dwuwymiarowa tablica typu int(wskaznik wskaznika)
 * @var Tablica::rozmiarX
 * Ilosc kolumn w calej tablicy
 * @var Tablica::rozmiarY
 * Ilosc wierszy w kazdej kolumnie tablicy
 * @var Tablica::typyKolumn
 * Tablica nazw typow w poszczegolnych kolumnach
 */
class Tablica {
public:
	Komorka** tablica;
	int rozmiarX;
	int rozmiarY;
	std::string* typyKolumn;

	Tablica(); //Konstruktor do inicjalizowania wartości początkowych
	
	/** Inicjalizuje nowa tablice 2D o podanych wymiarach
	 *
	 * @param rozmiarX ilosc kolumn w danym wierszu
	 * @param rozmiarY ilosc wierszy
	 * @return 0 lub kod błędu
	 */
	int utworzTablice(int rozmiarX, int rozmiarY, std::string typyKolumn[]);

	/**
	 * Zmienia zawartosc wybranej komorki w tablicy.
	 *
	 * @param xKomorki Współrzędna X(kolumna) komórki do zmodyfikowania 
	 * @param yKomorki Współrzędna Y(wiersz) komórki do zmodyfikowania 
	 * @param nowaZawartosc Docelowa zawartosc modyfikowanej komorki
	 * @return Kod błędu lub 0 w przypadku powodzenia
	 */
	int zmienKomorke(int xKomorki, int yKomorki, int nowaZawartosc);

	int zmienKomorke(int xKomorki, int yKomorki, std::string nowaZawartosc);

	int wyswietlTablice(void);

	/**
	 * Tworzy nowa tablice o podanym rozmiarze i kopiuje zawartosc starej tablicy
	 * do nowej na tyle, na ile to mozliwe. Komorki ponad rozmiar starej tablicy sa
	 * inicjalizowane jako komorki liczbowe o wartości "0". Stara tablica jest usuwana. 
	 *
	 * @param nowyRozmiarX Ilosc kolumn w nowej tablicy
	 * @param nowyRozmiarY Ilosc wierszy w nowej tablicy
	 * @return Kod błędu lub 0 w przypadku błędu
	 */
	int zmianaRozmiaru(int nowyRozmiarX, int nowyRozmiarY);

	/**
	 * Zwraca sume wartosci wszystkich komorek danego wiersza.
	 *
	 * @param wiersz indeks wiersza do zsumowania
	 * @return Suma wartosci w danym wierszu 
	 */
	float sumujWiersz(int wiersz);

	/**
	 * Zwraca sume wartosci wszystkich komorek danej kolumny.
	 *
	 * @param kolumna indeks kolumny do zsumowania
	 * @return Suma wartosci w danej kolumnie 
	 */
	float sumujKolumne(int kolumna);

	/**
	 * Zwraca najmniejsza wartosc ze wszystkich komorek danego wiersza.
	 *
	 * @param kolumna indeks kolumny do przeszukania
	 * @return Najmniejsza wartosc w danym wierszu 
	 */
	float minimumWiersza(int kolumna);

	/**
	 * Zwraca najwieksza wartosc ze wszystkich komorek danego wiersza.
	 *
	 * @param kolumna indeks kolumny do przeszukania
	 * @return Najwieksza wartosc w danym wierszu 
	 */
	float maksimumWiersza(int kolumna);

	/**
	 * Zwraca wartosc srednia wszystkich komorek danego wiersza.
	 *
	 * @param kolumna indeks kolumny do przeszukania
	 * @return wartosc srednia danego wiersza 
	 */
	float sredniaWiersza(int kolumna);

	/**
	 * Zwraca najmniejsza wartosc ze wszystkich komorek danej kolumny.
	 *
	 * @param kolumna indeks kolumny do przeszukania
	 * @return Najmniejsza wartosc w danej kolumnie 
	 */
	float minimumKolumny(int kolumna);

	/**
	 * Zwraca najwieksza wartosc ze wszystkich komorek danej kolumny.
	 *
	 * @param kolumna indeks kolumny do przeszukania
	 * @return Najwieksza wartosc w danej kolumnie 
	 */
	float maksimumKolumny(int kolumna);

	/**
	 * Zwraca wartosc srednia wszystkich komorek danej kolumny.
	 *
	 * @param kolumna indeks kolumny do przeszukania
	 * @return wartosc srednia danej kolumny 
	 */
	float sredniaKolumny(int kolumna);

	/** Zapisuje tablice do pliku o podanej nazwie
	 *
	 * @param nazwaPliku nazwa lub sciezka pliku, w ktorym ma zostac zapisana tablica
	 * @return Kod błędu lub 0 w przypadku powodzenia
	 */
	int zapiszTablice(std::string nazwaPliku);

	/** Ładuje tablicę do pliku o podanej nazwie
	 *
	 * @param nazwaPliku nazwa lub sciezka pliku, z ktorego odczytana bedzie tablica
	 * @return Kod błędu lub 0 w przypadku powodzenia
	 */
	int otworzTablice(std::string nazwaPliku);

	/** Zmienia typ danych przechowywanych przez wszystkie komorki danej kolumny
	 *
	 * @param wiersz Współrzędna kolumny, ktorej typ ma byc zmieniony
	 * @param nowyTyp Docelowy typ kolumny
	 * @return Kod błędu lub 0 w przypadku powodzenia
	 */
	int zmienTypKolumny(int kolumny, std::string nowyTyp);

	/** Zmienia typ danych przechowywanych przez kazda komorke w calej tablicy
	 *
	 * @param nowyTyp Docelowy typ calej tablicy
	 * @return Kod błędu lub 0 w przypadku powodzenia
	 */
	int zmienTypTablicy(std::string nowyTyp);
};
#endif