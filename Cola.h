#include <cstdlib>
#include <iostream>
#include "estructura.h"

#ifndef COLA_H     
#define COLA_H 

using namespace std;

class cola{nodo<int> *cab,*fin;
      public: cola(){cab=fin=NULL;}
      void InsCola(int i);
      char AtenderCola();
      void ImprimirCola();
      bool ColaVacia();
      ~cola();
 };

void cola::InsCola(int i){
     nodo<int> *nuevo;
     nuevo= new nodo<int>;
     nuevo->dato=i;
     nuevo->sig= NULL;
     if (cab==NULL)
         {cab=nuevo;}
     else {fin->sig = nuevo;}
     fin=nuevo;
}



char cola::AtenderCola()
{   char x;
    nodo<int> *aux = cab; 
    cab=aux->sig;
    x=aux->dato;
    delete aux;
    return x;
    }

void cola::ImprimirCola(){
     nodo<int> *aux;
     aux=cab;
     while(aux!=NULL){
       cout<<aux->dato<<" ";
       aux=aux->sig;}    
}

bool cola::ColaVacia(){
     return (cab==NULL);
     }

cola::~cola(){
     nodo<int> *aux;
     while(cab!=NULL)
       {aux= cab;
        cab=aux->sig;
        delete aux;}
     delete cab;
     }

#endif

