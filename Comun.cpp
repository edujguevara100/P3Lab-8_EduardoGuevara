#include "Comun.h"
#include <string>
#include "Heroe.h"
using namespace std;

Comun::Comun(string nom, int debi){
	nombre = nom;
	debilidad = debi;
	vida = 8;
	defensa = 0;
	ataque = 5;
}

void Comun::Ataque(Heroe*& hero){
	if(hero->getDefensa() <= 5){
		hero->setVida(hero->getVida()+hero->getDefensa() - 5);
	}
}
