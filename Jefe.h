#include "Monstruo.h"
#include <string>
#include "Heroe.h"
#ifndef JEFE_H
#define JEFE_H
class Jefe: public Monstruo{
	public:
		Jefe(string,int);
		void Ataque(Heroe*&);
};
#endif
