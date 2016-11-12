#ifndef CIRCUITO_HAMILTON_H
#define CIRCUITO_HAMILTON_H
#include "grafo_t.h"
#include <iostream>
#include <list>
#include "Diccionario.h"
#include <stack>

class circuito_hamilton
{
public:
    circuito_hamilton(){};
    virtual ~circuito_hamilton(){};
    void BEP(int i, vertice_t vActual, grafo_t *G);
    void introBEP(grafo_t *G);
    void greedy(grafo_t *G);
    void local(grafo_t *G);
protected:
private:
    stack<vertice_t> mejorOpcion(grafo_t *G, vertice_t v);
    bool factibilidad(grafo_t *G);
    bool greedyAux(grafo_t *G, vertice_t t,int actual);
    int solOp[150];
    int solAct[150];
    int costoOp;
    int costoSA;
    Diccionario DVV;
};

#endif // CIRCUITO_HAMILTON _H
