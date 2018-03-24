#include <string>
#include "Heroe.h"
#include "Item.h"
#include "Monstruo.h"
#include <typeinfo>
#include "Bomba.h"
using namespace std;

Heroe::Heroe(string name){
	nombre = name;
	state = true;
	defensa = 2;
	ataque = 4;
	ataqueEsp = 0;

}
int Heroe::getVidMax(){
	return vidmax;
}
void Heroe::Ataque(Monstruo*&){
	
}

void Heroe::AtaqueEsp(Monstruo*&){

}

void Heroe::useItem(Monstruo*& m){
	m->setVida(m->getVida()-item->Dmg(m));
	if(dynamic_cast<Bomba*>(item)){
		vida-=4;
	}
}

void Heroe::setVidMax(){
	vidmax+=4;
}

void Heroe::refresh(){
	vida = vidmax;
}

void Heroe::setVida(int vid){
	vida = vid;
}

int Heroe::getVida(){
	return vida;
}

Item* Heroe::getItem(){
	return item;
}

void Heroe::setItem(Item* i){
	item = i;
}

void Heroe::setJef(int j){
	cantjef = j;
}

int Heroe::getJef(){
	return cantjef;
}

float Heroe::getDinero(){
	return dinero;
}

void Heroe::setDinero(float d){
	dinero = d;
}

void Heroe::setDefensa(int def){
	defensa = def;
}

int Heroe::getDefensa(){
	return defensa;
}

void Heroe::setAtk(int at){
	ataque = at;
}

int Heroe::getAtk(){
	return ataque;
}

void Heroe::setAtkE(int at){
	ataqueEsp = at;
}

int Heroe::getAtkE(){
	return ataqueEsp;
}

bool Heroe::isJoven(){
	return state;
}

void Heroe::setState(bool j){
	state = j;
}
