#ifndef DICCIONARIO_H
#define DICCIONARIO_H
#include "grafo_t.h"
#include <iostream>
#include <list>

typedef  int vertice_t;

class Diccionario
{
    public:
        Diccionario();
        virtual ~Diccionario();
        void Agregar(vertice_t v);
        vertice_t Sacar(vertice_t v);
        bool Pertenece(vertice_t v);
    protected:
    private:
        std::list<vertice_t> DVert;
};

#endif // DICCIONARIO_H
