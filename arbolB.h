#include "cola.h"
#include "pila.h"
#include <iostream>
#ifndef ARBOLB_H     
#define AEBOLB_H 
using namespace std;

struct Nodo{int info;
           Nodo *izq, *der;};

class arbolB{Nodo *raiz;
    pila *listInorden;
	cola *listPreorden,*listPosorden;
    public: arbolB(){raiz = NULL;
                        listInorden = new pila;
                        listPreorden = new cola;
                        listPosorden = new cola;}

        void insertar(int dato);
        nodo *buscarpadre(int dato, Nodo *p);
        void eliminar(int dato);
        nodo *buscar_nodo(int dato, Nodo **padre);
        void inorden(Nodo *inicio);
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
	if(inicio = NULL){
		return 
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
	
}

void arbolB::inorden(Nodo *inicio){
	while(!listInorden.PilaVacia()|| inicio != NULL ){
		if(inicio != NULL){
			listInorden.Push();
			inicio->inicio.iz;
		}else{
			inicio-> listInorden.Pop();
			inicio-> inicio.der;
		}
	}
}
#endif
