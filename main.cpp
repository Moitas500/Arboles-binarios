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
	cout<<"Buscando el padre "<<endl;
	cout<<"El padre de 7 es "<<arbol->buscarpadre(7)->info<<endl;
	cout<<arbol->buscar_nodo(3) ->info<<endl;
	arbol->imprimir();
	arbol->inorden();
	arbol->eliminar(7);


	//arbol->preorden();
	
	return 0;
}
