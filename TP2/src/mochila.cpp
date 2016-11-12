#include "mochila.h"
#include <iostream>

mochila::mochila(int val, int y1, int x1)
{
    y = y1;
    x = x1;
    for (int i = 0; i<=x; ++i)
    {
        solOptima[i] = 0;
        solAct[i] = 0;
    }
    valOptimo = 0;
    valAct = 0;
    pesoAct = 0;
    pesoSol = 0;
    peso = val;
}

mochila::~mochila()
{
}

void mochila::ExhaustivaPura(int m[150][150],int actual)
{
    for(int i=0; i<=y; i++)
    {
        solAct[actual] = i;
        pesoAct += (m[0][actual]*i);
        valAct += (m[1][actual]*i);
        if(pesoAct <= peso && valAct>valOptimo)
        {
            valOptimo = valAct;
            for(int y1 = 0; y1 <=x; ++y1)
            {
                solOptima[y1] = solAct[y1];
            }
        }
        if(actual <=x)
        {
            ExhaustivaPura(m,actual+1);
        }
        solAct[actual] = 0;
        pesoAct -= (m[0][actual]*i);
        valAct -= (m[1][actual]*i);
    }
}
void mochila::Solucion()
{
    for(int i = 0; i <=x ; ++i)
    {
        std::cout << "Para vendedor " << i << " -> " << solOptima[i] << std::endl;
    }
    std::cout << "Con un valor de " << valOptimo << std::endl;
}
