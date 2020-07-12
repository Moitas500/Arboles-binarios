#include <iostream>
#include "ArbolB.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	arbolB *arbol = new  arbolB;
	cout<<"Sin nada"<<endl;
	arbol->imprimir();
	cout<<"Con 5"<<endl;
	arbol->insertar(5);
	arbol->imprimir();
	cout<<"Con 3"<<endl;
	arbol->insertar(3);
	arbol->imprimir();
	cout<<"Con 7"<<endl;
	arbol->insertar(7);
	arbol->imprimir();
	return 0;
}
