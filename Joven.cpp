#include "Joven.h"
#include <string>
#include "Monstruo.h"
#include "Item.h"
using namespace std;

Joven::Joven(string n, int v, Item* i, int je, float d):Heroe(n){
	nombre = n;
	vidmax = v;
	vida = v;
	item = i;
	cantjef = je;
	dinero = d;
	defensa = 2;
	ataqueEsp = 0;
	ataque = 4;
}

void Joven::Ataque(Monstruo*& mon){
	if(mon->getDefensa() <= 4){
		mon->setVida(mon->getVida()+mon->getDefensa()-4);	
	}
}

void Joven::AtaqueEsp(Monstruo*& mon){

}
