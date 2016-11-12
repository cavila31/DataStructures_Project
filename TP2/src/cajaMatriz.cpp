#include "cajaMatriz.h"
cajaMatriz::cajaMatriz()
{
}

cajaMatriz::~cajaMatriz()
{
}

void cajaMatriz::setPeso(int a)
{
    peso=a;
}
void cajaMatriz::setExiste(bool a)
{
    existe=a;
}
int cajaMatriz::getPeso()
{
    return peso;
}
bool cajaMatriz::getExiste()
{
    return existe;
}
