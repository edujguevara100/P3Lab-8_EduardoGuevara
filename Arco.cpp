#include "Arco.h"
#include <string>
using namespace std;

Arco::Arco(string nom, string col):Item(col,nom){
	nombre = nom;
	color = col;
}

int Arco::Dmg(Monstruo*& mon){
	return 4;
}
