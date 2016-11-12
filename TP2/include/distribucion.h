#ifndef DISTRIBUCION_H
#define DISTRIBUCION_H
#include <limits.h>
#include <iostream>


struct cota_aux1
{
    bool poda;
    int cota;
    int recurso;
    bool revisado;
    int elegido;
    int e;
    int re;
};

using namespace std;

class distribucion
{
public:
    distribucion();
    void introPura(int v,int y1, int x1);   //Danilo, esto es lo q ud habia metido en el constructor, es q yo ya habia metido cosas mias entonces le hice este metodo
    virtual ~distribucion();
    int buscar_cota(int recurso, int i, int selected, int r, bool &bandera);
    void Branch_and_Bound(int recurso, int selected, int r);
    void Sol();
    void ExhaustivaPura(const int m[150][150],int actual);
    void Solucion();
protected:
private:
    int ganaciaOptima;
    int gananciaActual;
    int Totaltareas;
    int TotalRecursos;
    int TareasRestantes;
    bool podar;
    int escogido;
    int e;
    int re;
    int MinRecursos;
    int MaxRecursos;
    int RecursosDisp;
    int acumulador;
    int numMax;
    int numAct;
    int valOptimo;
    int valAct;
    int x;
    int y;
    int solucionOptima[150];
    int solucionActual[150];
    int tabla[150][150];
    int solOptima[150];
    int solAct[150];
};

#endif // DISTRIBUCION_H
