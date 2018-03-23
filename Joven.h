#include "Heroe.h"
#include "Monstruo.h"
#include "Item.h"
#include <string>
using namespace std;
#ifndef JOVEN_H
#define JOVEN_H
class Joven: public Heroe{
	public:
		Joven(string, int, Item*, int, float);
		void Ataque(Monstruo*&);
		void AtaqueEsp(Monstruo*&);
};
#endif
