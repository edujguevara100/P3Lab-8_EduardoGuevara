#include "Bumeran.h"
#include <string>
using namespace std;
Bumeran::Bumeran(string nom, string col):Item(col,nom){
	nombre = nom;
	color = col;
}

int Bumeran::Dmg(Monstruo*& mon){
	if(mon->getDefensa() <= 5){
		return 5-mon->getDefensa();
	}else{
		return 0;
	}
}
