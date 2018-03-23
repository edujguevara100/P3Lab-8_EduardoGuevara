temp:	main.o Item.o Heroe.o Monstruo.o Joven.o Adulto.o Jefe.o Semijefe.o Comun.o Bomba.o Bumeran.o Arco.o
		g++ main.o Item.o Heroe.o Monstruo.o Joven.o Adulto.o Jefe.o Semijefe.o Comun.o Bomba.o Bumeran.o Arco.o -o temp
main.o:	main.cpp Item.h Heroe.h Monstruo.h Joven.h Adulto.h Jefe.h Semijefe.h Comun.h Bomba.h Bumeran.h Arco.h
		g++ -c main.cpp
Item.o:	Item.cpp Item.h Monstruo.h 
		g++ -c Item.cpp
Heroe.o:	Heroe.h Heroe.cpp Item.h Monstruo.h
		g++ -c Heroe.cpp
Monstruo.o:	Monstruo.cpp Monstruo.h Heroe.h
		g++ -c Monstruo.cpp
Joven.o:	Joven.cpp Joven.h Heroe.h Monstruo.h
		g++ -c Joven.cpp
Adulto.o:	Adulto.cpp Adulto.h Heroe.h Monstruo.h
		g++ -c Adulto.cpp
Jefe.o:	Jefe.cpp Jefe.h Monstruo.h Heroe.h
		g++ -c Jefe.cpp
Semijefe.o:	Semijefe.cpp Semijefe.h Monstruo.h Heroe.h
		g++ -c Semijefe.cpp
Comun.o:	Comun.cpp Comun.h Monstruo.h Heroe.h
		g++ -c Comun.cpp
Bomba.o:	Bomba.cpp Bomba.h Item.h
		g++ -c Bomba.cpp
Bumeran.o:	Bumeran.cpp Bumeran.h Item.h
		g++ -c Bumeran.cpp
Arco.o:	Arco.cpp Arco.h Item.h
		g++ -c Arco.cpp
