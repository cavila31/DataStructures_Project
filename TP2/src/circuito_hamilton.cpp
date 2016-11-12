#include "circuito_hamilton.h"

void circuito_hamilton::BEP(int i, vertice_t vActual, grafo_t *G)
{

    vertice_t w = G->primerVerticeAdy(vActual);
    while (w != NULL)
    {
        if (!DVV.Pertenece(w))
        {
            DVV.Agregar(w);
            costoSA += G->peso(vActual, w);
            solAct[i] = w;
            if (i == G->numVertices())
            {

                if (G->existeArista(w, G->primerVertice()))
                {
                    if ((costoSA + G->peso(w, G->primerVertice()) < costoOp))
                    {
                        costoOp = costoSA;
                        for(int i=1; i<=G->numVertices(); i++)
                        {
                            solOp[i] = solAct[i];
                        }
                    }
                }
                else
                {
                    BEP(i+1, w, G);
                }
                DVV.Sacar(w);
                costoSA -= G->peso(vActual, w);
            }
            w = G->siguienteVerticeAdy(vActual, w);
        }
    }
}

void circuito_hamilton::introBEP(grafo_t *G)
{
    solAct[1] = G->primerVertice();
    DVV.Agregar(G->primerVertice());
    BEP(2, G->primerVertice(), G);
    cout<<"La Ganacia Obtenida fue de: "<<costoOp<<endl;
    cout<<"Y su solucion Optima asociada fue: "<<endl;
    for(int i=1; i<=G->numVertices(); i++)
    {
        cout<<"["<<i<<"]= "<<solOp[i]<<", ";
    }
}

void circuito_hamilton::local(grafo_t *G)
{
    bool factible = false;
    vertice_t v = G->primerVertice();
    while (v != 0)
    {
        factible  = greedyAux(G,v,0);
        v = G->siguienteVertice(v);
        if(costoOp < costoSA)
        {
            for (int i = 0; i < 150; ++i)
            {
                solAct[i] = solOp[i];
                costoSA = costoOp;
            }
        }
    }
    for (int i = 0; i < 150; ++i)
    {
        solAct[i] = solOp[i];
        costoSA = costoOp;
    }
}

void circuito_hamilton::greedy(grafo_t *G)
{
    bool factible = false;
    vertice_t v = G->primerVertice();
    while (!factible)
    {
        factible  = greedyAux(G,v,0);
        v = G->siguienteVertice(v);
    }
}

bool circuito_hamilton::greedyAux(grafo_t *G, vertice_t t,int actual)
{
    bool factible = factibilidad(G);
    if (t != 0)
    {
        stack<vertice_t> opciones = mejorOpcion(G,t);
        vertice_t solActual;
        vertice_t x = G->primerVerticeAdy(t);
        while (x != 0 && !factible)
        {
            solActual = opciones.top();
            opciones.pop();
            if (solAct != 0)
            {
                solAct[0]=G->etiqueta(solActual);
                costoOp += G->peso(t,solActual);
                factible = greedyAux(G,solActual,++actual);
                if (!factible)
                {
                    costoOp -= G->peso(t,solActual);
                }
            }
        }
    }
    return factible;
}

stack<vertice_t> circuito_hamilton::mejorOpcion(grafo_t *G, vertice_t v)
{
    stack<vertice_t> pila;
    Diccionario* d;
    int val = 1000000;
    vertice_t z = G->primerVertice();
    while (z !=0)
    {
        vertice_t x = G->primerVertice();
        while (x != 0)
        {
            if (G->peso(v,x)<val && !(d->Pertenece(x)))
            {
                val = G->peso(v,x);
            }
            x = G->siguienteVerticeAdy(v,x);
        }
        pila.push(x);
        z = G->siguienteVerticeAdy(v,z);
    }
    return pila;
}

bool circuito_hamilton::factibilidad(grafo_t *G)
{
    vertice_t v = G->primerVertice();
    while (v != 0 && DVV.Pertenece(v))
    {
        v = G->siguienteVertice(v);
    }
    if(v == 0)
    {
        return true;
    }
    return false;
}

void circuito_hamilton::Solucion()
{
    std::cout << "Solucion optima: "<< std::endl;
    for (int i = 0; i < )
}
