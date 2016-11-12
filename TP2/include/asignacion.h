#ifndef ASIGNACION_H
#define ASIGNACION_H
#include "grafo_t.h"
#include <iostream>
#include <limits.h>

typedef int info_t;

struct cota_aux
{
    bool poda;
    int cota;
    int tarea;
    bool revisado;
    int elegido;
    int e;
};


class asignacion
{
public:
    asignacion();
    void introPura(int val, int y1); //-1 para minimizar, 1 para maximizar
    virtual ~asignacion();
    void introBranchAndBoud();
    void ExhaustivaPura(int m[150][150], int actual);
    void Solucion();
    void Branch_and_Bound(int recurso, int selected);
    void Branch_and_BoundMIN(int recurso, int selected);
    int buscar_cota(int recurso, int i, int selected);
    int buscar_cotaMIN(int recurso, int i, int selected);
    void ramif_acot(int recurso, int tr, int tt);

protected:
private:
    int y;
    int solOptima[150][2];
    int valOptimo;
    int valAct;
    int solAct[150][2];
    int utilizados[150];
    int ganaciaOptima;
    int solucionOptima[150];
    int solucionActual[150];
    int gananciaActual;
    info_t tabla[150][150];
    int Totaltareas;
    int TotalRecursos;
    int TareasAsignadas;
    bool maxi;
    bool podar;
    int escogido;
    int e;

};

#endif // ASIGNACION_H
