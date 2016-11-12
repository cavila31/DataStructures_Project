#include "Diccionario.h"

Diccionario::Diccionario()
{
    //ctor
}

Diccionario::~Diccionario()
{
    //dtor
}

void Diccionario::Agregar(vertice_t v)
{
    DVert.push_back (v);
}

vertice_t Diccionario::Sacar(vertice_t v)
{
    std::list<vertice_t>::iterator ite;

//  it = find (DVert.begin(), DVert.end(), v);
    for (ite=DVert.begin(); ite!=DVert.end(); ++ite)
    {
        if (*ite==v)
        {
            vertice_t a=*ite;
            DVert.erase(ite);
            return a;
        }
    }
    if (ite == DVert.end())
    {
        return 0;
    }
}
//    std::cout << ' ' << *it;
//  std::cout << '\n';
//
//  return 0;
//}
//  if (it != DVert.end()){
//        vertice_t a=*it;
//   DVert.erase (it);
//    return a;
//    }
//  else{
//    return 0;}


bool Diccionario::Pertenece(vertice_t v)
{
    std::list<vertice_t>::iterator ite;

    for (ite=DVert.begin(); ite!=DVert.end(); ++ite)
    {
        if (*ite==v)
        {
            return true;
        }
    }
    if (ite == DVert.end())
    {
        return false;
    }
}
