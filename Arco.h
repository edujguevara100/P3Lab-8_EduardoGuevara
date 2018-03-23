#ifndef ARCO_H
#define ARCO_H
#include "Item.h"
#include <string>
using namespace std;
class Arco: public Item{
	public:
		Arco(string,string);
		int Dmg(Monstruo*&);
};
#endif
