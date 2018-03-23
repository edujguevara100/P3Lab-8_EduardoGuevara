#ifndef ITEM_H
#define ITEM_H
#include <string>
#include "Monstruo.h"
using namespace std;
class Item{
	public:
		virtual int Dmg(Monstruo*&) = 0;
		Item(string,string);
	protected:
		string color;
		string nombre;
};
#endif
