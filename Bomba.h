#include "Item.h"
#ifndef BOMBA_H
#define BOMBA_H
#include <string>
class Bomba: public Item{
	public:
		Bomba(string,string);
		int Dmg(Monstruo*&);
};
#endif
