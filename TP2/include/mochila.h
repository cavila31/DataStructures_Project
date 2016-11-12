#ifndef MOCHILA_H
#define MOCHILA_H


class mochila
{
public:
    mochila(int,int,int);
    virtual ~mochila();
    void ExhaustivaPura(int m[150][150],int actual);
    void Solucion();
protected:
private:
    int y;
    int x;
    int solOptima[150]; //cantidad
    int valOptimo;
    int valAct;
    int pesoAct;
    int solAct[150];
    int pesoSol;
    int peso;
};

#endif // MOCHILA_H
