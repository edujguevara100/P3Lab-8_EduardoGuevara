#include "Item.h"
#include <string>
#include "Monstruo.h"
using namespace std;
Item::Item(string c, string n){
	nombre = n;
	color = c;
}

int Item::Dmg(Monstruo*& mon){
	return -1;
}
