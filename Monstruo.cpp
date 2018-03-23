#include "Monstruo.h"
#include <string>
using namespace std;

int Monstruo::getDefensa(){
	return defensa;
}

void Monstruo::setVida(int vid){
	vida = vid;
}

int Monstruo::getVida(){
	return vida;
}

void Monstruo::Ataque(Heroe*& hero){

}

string Monstruo::getNombre(){
	return nombre;
}
