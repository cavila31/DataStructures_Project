#include "grafo_t.h"

grafo_t::grafo_t()
{
}

grafo_t::~grafo_t()
{
}

void grafo_t:: crear()
{
    ultimoVec=0;
}
void grafo_t:: destruir()
{
        ultimoVec=0;

}
void grafo_t:: vaciar()
{
        ultimoVec=0;

}
bool grafo_t:: vacio()
{

    if (ultimoVec==0)
    {

        return true;
    }
    else
    {
        return false;
    }
}

vertice_t grafo_t:: agregarVertice(etiqueta_t e )
{
    ultimoVec++;
    vecVertices[ultimoVec]=e;

    return ultimoVec;
}
void grafo_t:: eliminarVertice(vertice_t v )
{

for(int k=v; k<=ultimoVec; k++){
    for(int j=v; j<=ultimoVec; j++){
        MatAdy[k][j]=MatAdy[k+1][j+1];
    }

    for(int i=v+1; i<=ultimoVec; i++){
    vecVertices[i-1]=vecVertices[i];
}

ultimoVec++;
}

}
void grafo_t:: modificarEtiqueta(vertice_t v, etiqueta_t e )
{
    vecVertices[v]=e;
}
etiqueta_t grafo_t:: etiqueta(vertice_t v )
{
    return vecVertices[v];
}
void grafo_t:: agregarArista(vertice_t v1, vertice_t v2, peso_t p )
{
cajaMatriz *a=new cajaMatriz();
a->setExiste(true);
a->setPeso(p);
MatAdy[v1][v2]=a;
MatAdy[v2][v1]=a;
}
void grafo_t:: eliminarArista(vertice_t v1, vertice_t v2 )
{
MatAdy[v1][v2]->setExiste(false);
MatAdy[v2][v1]->setExiste(false);
}
void grafo_t:: modificarPesoArista(vertice_t v1, vertice_t v2, peso_t p)
{
    MatAdy[v1][v2]->setPeso(p);
MatAdy[v2][v1]->setPeso(p);

}
peso_t grafo_t:: peso(vertice_t v1, vertice_t v2 )
{
    return MatAdy[v1][v2]->getPeso();
}
vertice_t grafo_t:: primerVertice( )
{
    return 1;
}
vertice_t grafo_t:: siguienteVertice(vertice_t v )
{
    return v+1;
}
vertice_t grafo_t:: primerVerticeAdy(vertice_t v)
{
    bool encontrado=false;
    int i=1;
    int a=NULL;
    while (i<=ultimoVec && !encontrado){
        if (MatAdy[v][i]!=NULL){
            a=i;
            encontrado=true;
        }
        else {
            i++;
        }
    }
    return a;
}


vertice_t grafo_t:: siguienteVerticeAdy(vertice_t v, vertice_t v2 )
{
    bool encontrado=false;
    int i=v2+1;
    int a=NULL;
    while (1<=ultimoVec && !encontrado){
        if (MatAdy[v][i]->getExiste()){
            a=i;
            encontrado=true;
        }
        else {
            i++;
        }
    }
    return a;


}

int grafo_t:: numVertices()
{
    return ultimoVec;
}
bool grafo_t:: existeArista(vertice_t v1, vertice_t v2)
{
if(MatAdy[v1][v2]->getExiste()){
    return true;
}
else {
        return false;
}
}

vertice_t grafo_t::buscar (etiqueta_t etiqueta)
{
    if(ultimoVec != -1)
    {
        int aux = 0;
        while (aux != ultimoVec+1 && vecVertices[aux] != etiqueta)
        {
            ++aux;
        }
        return aux;
    }
    return -1;
}
