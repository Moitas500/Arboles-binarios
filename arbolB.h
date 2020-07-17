#include "Cola.h"
#include "pila.h"
#include <iostream>
#ifndef ARBOLB_H     
#define AEBOLB_H 
using namespace std;

struct Nodo{int info;
           Nodo *izq, *der;};

class arbolB{Nodo *raiz;
    pila *listInorden;
    pila *listPreorden;
	pila *listPosorden;
    public: arbolB(){raiz = NULL;
    					listInorden = new pila; 
                        listPreorden = new pila;
                        listPosorden = new pila;}

        void insertar(int dato);
        Nodo *buscarpadre(int dato, Nodo *p);
        void eliminar(int dato);
        Nodo *buscar_nodo(int dato);
        void inorden();
        void preorden(Nodo *inicio);
        void posorden(Nodo *inicio);
        void imprimir();
       	~arbolB();
};

void arbolB::insertar(int dato){
	Nodo *arb,*pre, *aux = new Nodo;
	aux->info=dato;
	aux->izq=NULL;
	aux->der=NULL;
	if (raiz==NULL){
		raiz=aux;
	}else {
		arb=raiz;
		while(arb != NULL){
			pre=arb;
			if(dato>arb->info){
				arb=arb->der;
			}else{
				arb=arb->izq;
			}
		}
		arb=aux;
		if(dato>pre->info){
			pre->der=arb;
		}else {
			pre->izq=arb;
		}
	}
}
void arbolB::imprimir(){
	Nodo *centro,*izquierda= NULL,*derecha=NULL;
	centro=raiz;
	if(centro != NULL){
	izquierda=raiz->izq;
	derecha=raiz->der;
	}
	if (centro != NULL)
	{
		cout<<"Centro "<<centro->info<<endl;
	}
	else {
		cout<<"Centro "<<"Vacio"<<endl;	
	}
	if (izquierda != NULL)
	{
		cout<<"izquierda "<<izquierda->info<<endl;
	}
	else {
		cout<<"izquierda "<<"Vacio"<<endl;	
	}
	if (derecha != NULL)
	{
		cout<<"derecha "<<derecha->info<<endl;
	}
	else {
		cout<<"derecha "<<"Vacio"<<endl;
	}
}

void arbolB::preorden(Nodo *inicio){
/*	if(inicio = NULL){

	}
	
	listPreorden.InsCola(inicio);
	
	while(!listPreorden.PilaVacia()){
		if(inicio.der != NULL){
			listPreorden.InsCola(inicio.der);
		}
		if(inicio.izq != NULL){
			listPreorden.InsCola(inicio.izq);
		}
	}
	*/
}

void arbolB::inorden(){

}
Nodo *arbolB::buscar_nodo(int dato){
	Nodo  *buscado=NULL;
	if(raiz->info == dato){
		return raiz;
	}else{
		buscado=raiz;
		while(buscado != NULL && buscado->info != dato){
			if(dato>buscado->info){
				buscado=buscado->der;
			}else{
				if(dato<buscado->info){
					buscado=buscado->izq;
				}
			}
		}
	}
	return buscado;
	
}
void arbolB::eliminar(int dato){
	Nodo *eliminado= buscar_nodo(dato);
	Nodo *padre, *padreR, *hijoR =NULL;
	//cout<<eliminado->info<<endl;
	if(eliminado->der == NULL && eliminado->izq == NULL){
		//padre= buscar padre(dato o eliminado);
		if(eliminado->info > padre->info){
			padre->der = NULL;
		}else{
			padre->izq = NULL;
		}
	}else if(eliminado->der != NULL && eliminado->izq == NULL){
		
	} else if(eliminado->der == NULL && eliminado->izq != NULL){
		
	}else  if(eliminado->der != NULL && eliminado->izq != NULL){
		
	}
	}

#endif
