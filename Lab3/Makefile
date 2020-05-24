WERSJA_GCC := $(shell g++ -dumpversion)

kompiluj_calosc: main.cpp menu.cpp tablice.cpp menu.h tablice.h
	#Kompilacja składowych programu do obiektów
	g++ -std=c++11 -c -o "tablice.o" tablice.cpp
	g++ -std=c++11 -c -o "menu.o" menu.cpp
	g++ -std=c++11 -c -o "main.o" main.cpp
	#Linkowanie
	@echo Twoja wersja gcc to ${WERSJA_GCC}
	g++ -std=c++11 tablice.cpp menu.cpp main.cpp -o calosc 
	
clean:
	rm -fv *.o
	rm -fv ./calosc
