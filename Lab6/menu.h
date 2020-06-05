#ifndef MENU_H
#define MENU_H
#include "tablice.h"

void wyswietlMenu();
/**
 * Wewnetrzna funkcja uzywana przez menu.cpp
 * Sluzy do wyswietlania pojedynczych komunikatow oraz bledow
 * Ma mozliwosc wyswietlania zarowno intow jak i floatow
 *
 * @param nrKomunikatu Numer komunikatu do wyswietlenia na ekranie
 * @param opcjonalnaLiczba1 Ewentualna zmienna/wartość do wyświetlenia inline (komunikaty -4,2,4,6,8)
 * @param opcjonalnaLiczba2 Wartość/zmienna do wyświetlenia(komunikat 4)
 */
void wyswietlKomunikat(int nrKomunikatu, int opcjonalnaLiczba1, int opcjonalnaLiczba2, float opcjonalnaLiczba3);

/**
 * Wewnetrzna funkcja uzywana przez menu.cpp
 * Odczytuje liczbe calkowita z wejscia standardowego(na ogol terminala). 
 * Porzuca czesc dziesietna, a jezeli zostanie wprowadzony ciag znakow niemozliwy 
 * do odczytania jako liczba, prosi uzytkownika o ponowne wprowadzenie liczby.
 *
 * @param ograniczona Dla "true" sprawdza, czy podana liczba miesci sie w zakresie
 * @param zakresMin Dolna granica zakresu wartosci przyjmowanych przez funkcje
 * @param zakresMin Gorna granica zakresu wartosci przyjmowanych przez funkcje
 * @return Liczba calkowita wprowadzona przez uzytkownika lub -1 w razie bledu
 */
int pobierzInt(bool ograniczona, int zakresMin, int zakresMax);

/**
 * Wewnetrzna funkcja uzywana przez menu.cpp
 * Odczytuje liczbe typu float z wejscia standardowego.
 *
 * @return Liczba zmiennoprzecinkowa wprowadzona przez uzytkownika
 */
float pobierzFloat();

/**
 * Wewnetrzna funkcja uzywana przez menu.cpp
 * Pobiera zadany typ danych od uzytkownika, sprawdzajac czy jest on jednym
 * z dopuszczonych typow(int, string)
 *
 * @return String informujacy o wybranym typie danych
 */

std::string pobierzTyp();

/**
 * Glowna funkcja do uruchamiania menu.
 * 
 * @param tablica Tablica robocza
 */

void uruchomMenu(Tablica tablica);

#endif