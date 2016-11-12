#include "Pila_int.h"
#include "Nodo_int.h"
#include <iostream>

using namespace std;

Pila_int::Pila_int()
{
    tope= new Nodo_int();     // Este nodo se mantiene como un nodo vacio inclusive cuando la pila esta llena.
}

void Pila_int::Vaciar()
{
    if(tope != NULL && tope->Get_next() != NULL)
    {
        Nodo_int* porBorrar= tope->Get_next();
        Nodo_int* siguientePorBorrar= porBorrar->Get_next();
        while(porBorrar->Get_next() != NULL)
        {
            delete porBorrar;
            porBorrar= siguientePorBorrar;
            siguientePorBorrar= porBorrar->Get_next();
        }
        delete tope;
        tope= new Nodo_int();
    }
}

bool Pila_int::Vacia()
{
    if(tope->Get_next() == NULL)
        return true;
    else
        return false;
}

void Pila_int::Agregar(int i)
{
    Nodo_int* n= new Nodo_int(tope->Get_next(), i);
    tope->Set_next(n);
}

int Pila_int::Sacar()
{
    if(tope->Get_next() != NULL)
    {
        Nodo_int* segundo= tope->Get_next();
        int t= segundo->Get_int();
        tope->Set_next(segundo->Get_next());
        delete segundo;
        return t;
    }
    else
        return 0;
}

int Pila_int::Tope()
{
    if(tope->Get_next() != NULL)
    {
        Nodo_int* segundo= tope->Get_next();
        return segundo->Get_int();
    }
    else
        return 0;
}

Pila_int::~Pila_int()
{
}
