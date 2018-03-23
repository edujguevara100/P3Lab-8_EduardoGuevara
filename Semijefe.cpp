#include "Semijefe.h"
#include <string>
#include "Heroe.h"

Semijefe::Semijefe(string nom, int debi){
	nombre = nom;
	debilidad = debi;
	vida = 20;
	defensa = 1;
	ataque = 7;
}

void Semijefe::Ataque(Heroe*& hero){
	if(hero->getDefensa() <= 7){
		hero->setVida(hero->getVida()+hero->getDefensa() - 7);
	}
}

