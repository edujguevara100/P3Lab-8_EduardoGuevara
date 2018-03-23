#ifndef MONSTRUO_H
#define MONSTRUO_H
#include <string>
class Heroe;
using namespace std;
class Monstruo{
	public:
		int getDefensa();
		string getNombre();
		void setVida(int);
		int getVida();
		virtual void Ataque(Heroe*&) = 0;
	protected:
		string nombre;
		int debilidad;
		int vida;
		int defensa;
		int ataque;

};
#endif
