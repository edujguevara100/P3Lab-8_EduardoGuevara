#ifndef HEROE_H
#define HEROE_H
#include <string>
#include "Monstruo.h"
using namespace std;
#include "Item.h"
class Heroe{
	public:
		Heroe(string);
		void setVida(int);
		int getVida();
		Item* getItem();
		void setItem(Item*);
		int getJef();
		void setJef(int);
		float getDinero();
		void setDinero(float);
		void setDefensa(int);
		void setAtk(int);
		int getDefensa();
		int getAtk();
		int getAtkE();
		void setAtkE(int);
		bool isJoven();
		void setState(bool);
		void useItem(Monstruo*&);
		virtual void Ataque(Monstruo*&) = 0;
		virtual void AtaqueEsp(Monstruo*&) = 0;
		void setVidMax();
		int getVidMax();
		void refresh();
	protected:
		int vidmax;
		string nombre;
		int vida = 12;
		Item* item;
		int cantjef;
		float dinero;
		int defensa;
		int ataque;
		int ataqueEsp;
		bool state;
};
#endif
