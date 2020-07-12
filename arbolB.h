#include "cola.h"
#include <iostream>
#ifndef ARBOLB_H     
#define AEBOLB_H 
using namespace std;

struct Nodo{int info;
           Nodo *izq, *der;};

class arbolB{Nodo *raiz;
    cola *listInorden, *listPreorden, *listPosorden;
    public: arbolB(){raiz = NULL;
                        listInorden = new cola;
                        listPreorden = new cola;
                        listPosorden = new cola;}

        void insertar(int dato);
        nodo *buscarpadre(int dato, nodo *p);
        void eliminar(int dato);
        nodo *buscar_nodo(int dato, nodo **padre);
        void inorden(nodo *inicio);
        void preorden(nodo *inicio);
        void posorden(nodo *inicio);
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
#endif
