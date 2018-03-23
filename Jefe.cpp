#include "Jefe.h"
#include <string>
#include "Heroe.h"
using namespace std;

Jefe::Jefe(string nom, int debi){
	nombre = nom;
	debilidad = debi;
	vida = 33;
	defensa = 2;
	ataque = 9;
}

void Jefe::Ataque(Heroe*& hero){
	if(hero->getDefensa() <= 9){
		hero->setVida(hero->getVida()+hero->getDefensa()-9);
	}
}
