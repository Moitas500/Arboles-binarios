#include "Cola.h"
#include "pila.h"
#include <iostream>
#ifndef ARBOLB_H     
#define AEBOLB_H 
using namespace std;

struct Nodo{int info;
           Nodo *izq, *der;};

class arbolB{Nodo *raiz;
    pila<int> *listInorden;
    pila<int> *listPreorden;
	pila<int> *listPosorden;
    public: arbolB(){raiz = NULL;
    					listInorden = new pila<int>; 
                        listPreorden = new pila<int>;
                        listPosorden = new pila<int>;}

        void insertar(int dato);
        Nodo *buscarpadre(int dato);
        void eliminar(int dato);
        Nodo *buscar_nodo(int dato);
        void inorden();
        void preorden();
        void posorden();
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

Nodo * arbolB::buscarpadre(int dato){
	Nodo *aux= raiz;
	pila<Nodo *> p;
	while(aux != NULL && aux->info != dato){
		p.Push(aux);
		if (dato>aux->info){
			aux=aux->der;
		} else {
			aux=aux->izq;
		}
	}
	if(aux == NULL || aux->info != dato){
		cout<<"No se encontro un nodo con ese dato"<<endl;
		aux=NULL;
		return aux;
	} else {
		return p.Pop();
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

void arbolB::preorden(){
	if(raiz == NULL){
		cout << "El arbol esta vacio";
	}else{
		listPreorden->Push(raiz->info);
		
		while(!listPreorden->PilaVacia()){
			listPreorden->Pop();
			
			if(raiz->der != NULL){
				listPreorden->Push(raiz->der->info);
			}
			if(raiz->izq != NULL){
				listPreorden->Push(raiz->izq->info);
			}
		}
	}
	listPreorden->recorrer();

}

void arbolB::inorden(){
	Nodo *aux;
	aux = raiz;
	while(!listInorden->PilaVacia() || aux != NULL){
		if(aux != NULL){
			listInorden->Push(aux->info);
			aux = aux->izq;
		}else{
			listInorden->Pop();
			aux = aux->der;
		}
	}
	listInorden->recorrer();
}

void arbolB::posorden(){
	Nodo *aux;
	Nodo *aux2;
	aux2 = raiz;
	while(!listPosorden->PilaVacia() || aux2 != NULL){
		if(aux2 != NULL){
			listPosorden->Push(aux2->info);
			aux2 = aux2->izq;
		}else{
			if(aux2->der != NULL && aux != aux2->der){
				aux2 = aux2->der;
			}else{
				listPosorden->Push(aux->info);
			}
		}     
	}	
	listPosorden->recorrer();
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
		padre->der = eliminado->der;
		delete eliminado;
	} else if(eliminado->der == NULL && eliminado->izq != NULL){
		padre->izq = eliminado->izq;
		delete eliminado;
	}else  if(eliminado->der != NULL && eliminado->izq != NULL){
		
	}
	}

#endif
