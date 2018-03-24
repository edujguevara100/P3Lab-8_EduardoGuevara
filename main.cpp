#include <iostream>
#include <string>
#include "Heroe.h"
#include "Monstruo.h"
#include "Jefe.h"
#include "Semijefe.h"
#include "Comun.h"
#include "Joven.h"
#include "Adulto.h"
#include "Item.h"
#include "Bomba.h"
#include "Arco.h"
#include "Bumeran.h"
#include <vector>
#include <fstream>
using namespace std;

int menu();
Monstruo* create();
Item* select();
Monstruo* enemy(vector<Monstruo*>);
void pelea(Heroe*,Monstruo*);
int mfigth();
void elim(vector<Monstruo*>&);
void read(Heroe*&);
void write(Heroe*&);

int main(){
	Heroe* link = new Joven("Link",12,new Bomba("Rojo","Bomba"), 0, 2000);
	read(link);
	link->setDinero(2000);
	vector<Monstruo*> monsters;
	Monstruo* enem;
	int flag = 0;
	while(flag != 7){
		switch(flag = menu()){
			case 1:
				monsters.push_back(create());
				break;
			case 2:
				if(link->getJef() >= 3){
					if(dynamic_cast<Joven*>(link)){
						link = new Adulto("Link",link->getVidMax(),link->getItem(),link->getJef(),link->getDinero());
					}else{
						link = new Joven("Link",link->getVidMax(),link->getItem(),link->getJef(),link->getDinero());
					}
				}else{
					cout<<"No se han vencido suficientes jefes"<<endl;
				}
				break;
			case 3:
				if(monsters.size() > 0){
					link->setItem(select());
					enem = enemy(monsters);
					pelea(link,enem);
				}else{
					cout<<"No hay monstruos para pelear"<<endl;
				}
				break;
			case 4:
				if(link->getDinero() >= 200){
					link->setVidMax();
					link->setVida(link->getVidMax());
					link->setDinero(link->getDinero()-200);
				}else{
					cout<<"No tiene suficiente dinero"<<endl;
				}
				break;
			case 5:
				elim(monsters);
				break;
			case 6:
				write(link);
				break;
			default:
				flag = 7;
				break;
		}
	}
	return 0;
}

void read(Heroe*& link){
	ifstream in("Partida.zd",ios::binary);
	int vida;
	in.read(reinterpret_cast<char*>(&vida),sizeof(int));
	link->setVida(vida);
	int jefes;
	in.read(reinterpret_cast<char*>(&jefes),sizeof(int));
	link->setJef(jefes);
	int type;
	in.read(reinterpret_cast<char*>(&type),sizeof(int));
	if(type == 1){
		link->setItem(new Bomba("Bomba","Bomba"));
	}else if(type == 2){
		link->setItem(new Bumeran("Bumeran","Bumeran"));
	}else{
		link->setItem(new Arco("Arco","Arco"));
	}
	float dinero;
	in.read(reinterpret_cast<char*>(&dinero),sizeof(float));
	link->setDinero(dinero);
}

void write(Heroe*& link){
	int vida = link->getVida();
	float dinero = link->getDinero();
	int jefes = link->getJef();
	int item;
	if(dynamic_cast<Bomba*>(link->getItem())){
		item = 1;
	}else if(dynamic_cast<Bumeran*>(link->getItem())){
		item = 2;
	}else{
		item = 3;
	}
	ofstream out("Partida.zd",ios::binary);
	if(out.is_open()){
		out.write(reinterpret_cast<char*>(&vida),sizeof(int));
		out.write(reinterpret_cast<char*>(&jefes),sizeof(int));
		out.write(reinterpret_cast<char*>(&item),sizeof(int));
		out.write(reinterpret_cast<char*>(&dinero), sizeof(float));
		out.close();
	}
	
}

void elim(vector<Monstruo*>& monsters){
	int op;
	cout<<"Seleccione un monstruo para eliminar"<<endl;
	for(int i = 0; i < monsters.size(); i++){
		cout<<i<<" "<<monsters[i]->getNombre()<<endl;
	}
	cin>>op;
	monsters.erase(monsters.begin()+op);
}

Monstruo* enemy(vector<Monstruo*> monsters){
	int op;
	cout<<"Seleccione un monstruo:"<<endl;
	for(int i = 0; i < monsters.size(); i++){
		cout<<i<<" "<<monsters[i]->getNombre()<<endl;
	}
	cin>>op;
	return monsters[op];
}

int mfigth(){
	int op;
	cout<<"1: Atacar"<<endl
		<<"2: Usar Item"<<endl
		<<"3: Ataque Especial"<<endl
		<<"4: Huir"<<endl;
	cin>>op;
	return op;
}

void pelea(Heroe* link, Monstruo* enemy){
	bool flag = true;
	int turn = 0, accion, vidmaxen;
	vidmaxen = enemy->getVida();
	while(flag){
		if(turn%2 == 0){
			switch(accion = mfigth()){
				//ataque
				case 1:
					link->Ataque(enemy);
					break;
				//usar item
				case 2:
					link->useItem(enemy);
					break;
				//ataque especial
				case 3:
					link->AtaqueEsp(enemy);
					break;
				//huir
				case 4:
					flag = false;
					break;
				default:
					flag = false;
					break;

			}
		}else{
			enemy->Ataque(link);
		}
		turn++;
		cout<<"Vida del heroe: "<<link->getVida()<<endl;
		cout<<"Vida del enemigo: "<<enemy->getVida()<<endl;
		if(link->getVida() <= 0){
			link->refresh();
			enemy->setVida(vidmaxen);
			flag = false;
		}else if(enemy->getVida() <= 0){
			if(dynamic_cast<Jefe*>(enemy)){
				link->setVidMax();
				link->setJef(link->getJef()+1);
				link->refresh();
			}else if(dynamic_cast<Semijefe*>(enemy)){
				link->setDinero(link->getDinero()+100);
				link->refresh();
			}else{
				link->setDinero(link->getDinero()+40);
				link->refresh();
			}
			enemy->setVida(vidmaxen);
			flag = false;
		}
	}
}

Item* select(){
	int type;
	cout<<"Ingrese el item con el que quiere pelear(1 Bumeran, 2 Arco, 3 Bombas)"<<endl;
	cin>>type;
	switch(type){
		case 1:
			return new Bumeran("Bumeran","Bumeran");
			break;
		case 2:
			return new Arco("Arco","Arco");
			break;
		case 3:
			return new Bomba("Bombas","Bombas");
			break;
		default:
			return new Bomba("Bombas","Bombas");
	}
}

Monstruo* create(){
	string nombre;
	int debi,type;
	cout<<"Ingrese el nombre del monstruo"<<endl;
	cin>>nombre;
	cout<<"Ingrese la debilidad del monstruo(1 Bumeran, 2 Arco, 3 Bombas)"<<endl;
	cin>>debi;
	cout<<"Ingrese el tipo de monstruo(1 Jefe, 2 Semijefe, 3 Comun)"<<endl;
	cin>>type;
	switch(type){
		case 1:
			return new Jefe(nombre,debi);
			break;
		case 2:
			return new Semijefe(nombre,debi);
			break;
		case 3:
			return new Comun(nombre,debi);
			break;
		default:
			return new Jefe(nombre,debi);
			break;
	}
}

int menu(){
	int op;
	cout<<"1: Crear Monstruo"<<endl
		<<"2: Convetirse a Adulto o Joven"<<endl
		<<"3: Pelear"<<endl
		<<"4: Comprar corazones"<<endl
		<<"5: Eliminar Monstruo"<<endl
		<<"6: Guardar Partida"<<endl
		<<"7: Salir"<<endl;
	cin>>op;
	return op;
}
