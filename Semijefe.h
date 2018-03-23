#include "Monstruo.h"
#include "Heroe.h"
#include <string>
using namespace std;
#ifndef SEMIJEFE_H
#define SEMIJEFE_H
class Semijefe: public Monstruo{
	public:
		Semijefe(string,int);
		void Ataque(Heroe*&);
};
#endif
