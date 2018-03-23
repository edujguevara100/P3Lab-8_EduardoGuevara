#include "Adulto.h"
#include <string>
#include "Monstruo.h"
#include "Item.h"
using namespace std;

Adulto::Adulto(string nom, int vid, Item* i, int jefes, float din):Heroe(nom){
	nombre = nom;
	vidmax = vid;
	vida  = vid;
	item = i;
	cantjef = jefes;
	dinero = din;
	ataque = 8;
	ataqueEsp = 12;
	defensa = 4;
}

void Adulto::Ataque(Monstruo*& mon){
	if(mon->getDefensa() <= 8){
		mon->setVida(mon->getVida()+mon->getDefensa()-8);
	}
}

void Adulto::AtaqueEsp(Monstruo*& mon){
	if(mon->getDefensa() <= 12){
		mon->setVida(mon->getVida()+mon->getDefensa()-12);
	}
}
