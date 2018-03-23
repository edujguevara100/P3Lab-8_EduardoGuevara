#include "Monstruo.h"
#include <string>
#include "Heroe.h"
using namespace std;
#ifndef COMUN_H
#define COMUN_H
class Comun: public Monstruo{
	public:
		Comun(string,int);
		void Ataque(Heroe*&);
};
#endif
