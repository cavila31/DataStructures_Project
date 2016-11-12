#ifndef PILA_INT_H
#define PILA_INT_H
#include "Nodo_int.h"
#include <iostream>

using namespace std;
class Pila_int
{
public:
    /** \brief Constructor, crea una pila vacia
    */
    Pila_int();
    /** \brief
    * EFE: destruye los elementos de una pila y la deja vacia
    * REQ: pila inicializada
    * MOD: pila
    */
    void Vaciar();
    /** \brief
    * EFE: verifica si hay por lo menos 1 elemento en la pila
    * REQ: pila inicializada
    * MOD: n/a
    */
    bool Vacia();
    /** \brief
    * EFE: agrega un elemento i a la pila
    * REQ: pila inicializada, i elemento valido
    * MOD: pila
    */
    void Agregar(int i);
    /** \brief
    * EFE: saca y muestra el elemento en el tope de la pila
    * REQ: pila inicilaializada
    * MOD: pila
    */
    int Sacar();
    /** \brief
    * EFE: muestra el elemento que esta en el tope de la pila
    * REQ: pila inicializada
    * MOD: n/a
    */
    int Tope();
    /** \brief Destructor, destruye la pila
    */
    virtual ~Pila_int();
protected:
private:
    Nodo_int* tope; /**< puntero al tope de la cola */
};

#endif
