WERSJA_GCC := $(shell g++ -dumpversion)

kompiluj_calosc: main.cpp menu.cpp tablice.cpp menu.h tablice.h
	#Kompilacja składowych programu do obiektów
	g++ -std=c++11 -c -o "tablice.o" tablice.cpp
	g++ -std=c++11 -c -o "menu.o" menu.cpp
	g++ -std=c++11 -c -o "main.o" main.cpp
	#Linkowanie
	@echo Twoja wersja gcc to ${WERSJA_GCC}
	ld -dynamic-linker /lib64/ld-linux-x86-64.so.2 -o calosc /usr/lib/x86_64-linux-gnu/crt1.o /usr/lib/x86_64-linux-gnu/crti.o /usr/lib/gcc/x86_64-linux-gnu/${WERSJA_GCC}/crtbegin.o -L/usr/lib/gcc/x86_64-linux-gnu/${WERSJA_GCC} -lstdc++ -lc /usr/lib/gcc/x86_64-linux-gnu/${WERSJA_GCC}/crtend.o /usr/lib/x86_64-linux-gnu/crtn.o main.o menu.o tablice.o

clean:
	rm -fv *.o
	rm -fv ./calosc
