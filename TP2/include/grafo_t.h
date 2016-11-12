#ifndef GRAFO_T_H
#define GRAFO_T_H
#include <iostream>
#include "cajaMatriz.h"


typedef  int vertice_t;
typedef  int peso_t;
typedef  int etiqueta_t;

using namespace std;

class grafo_t
{
public:
    grafo_t();
    virtual ~grafo_t();
    void crear();
    void destruir();
    void vaciar();
    bool vacio();
    vertice_t agregarVertice(etiqueta_t e );
    void eliminarVertice(vertice_t v );
    void modificarEtiqueta(vertice_t v, etiqueta_t e );
    etiqueta_t etiqueta(vertice_t v );
    void agregarArista(vertice_t v1, vertice_t v2, peso_t p );     //Se cae, lo cambie
    void eliminarArista(vertice_t v1, vertice_t v2 );
    void modificarPesoArista(vertice_t v1, vertice_t v2, peso_t p);
    peso_t peso(vertice_t v1, vertice_t v2 );
    vertice_t primerVertice( );
    vertice_t siguienteVertice(vertice_t v );
    vertice_t primerVerticeAdy(vertice_t v);
    vertice_t siguienteVerticeAdy(vertice_t v, vertice_t v2);
    int numVertices();
    bool existeArista(vertice_t v1, vertice_t v2);
    vertice_t buscar (etiqueta_t etiqueta); //le agregue este metodo para comunicar con el usuario

protected:
private:
    etiqueta_t vecVertices[150];
    cajaMatriz *MatAdy[150][150];
    int ultimoVec; // porque puntero? se puede hacer -1 para el null ///////////////////////////////////////////

};

#endif // GRAFO_T_H
