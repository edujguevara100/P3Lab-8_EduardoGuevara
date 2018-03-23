#include "Item.h"
#ifndef BUMERAN_H
#define BUMERAN_H
class Bumeran: public Item{
	public:
		Bumeran(string,string);
		int Dmg(Monstruo*&);
};
#endif
