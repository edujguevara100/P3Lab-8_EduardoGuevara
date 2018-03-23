#include "Bomba.h"
#include <string>
Bomba::Bomba(string nom, string col):Item(col,nom){
	nombre = nom;
	color = col;
}

int Bomba::Dmg(Monstruo*& mon){
	if(mon->getDefensa() <= 10){
		return 10-mon->getDefensa();
	}else{
		return 0;
	}
}
