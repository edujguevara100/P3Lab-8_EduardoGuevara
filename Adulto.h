#include "Heroe.h"
#include <string>
#include "Monstruo.h"
#include "Item.h"
using namespace std;
#ifndef ADULTO_H
#define ADULTO_H
class Adulto: public Heroe{
	public:
		Adulto(string,int,Item*,int,float);
		void Ataque(Monstruo*&);
		void AtaqueEsp(Monstruo*&);
};
#endif


