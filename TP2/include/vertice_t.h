#ifndef VERTICE_T_H
#define VERTICE_T_H
#include <list>
#include "cajaMatriz.h"


class vertice_t
{
    public:
        vertice_t();
        virtual ~vertice_t();
    protected:
    private:
        int etiqueta;
          std::list<cajaMatriz> aristasAdy;

};

#endif // VERTICE_T_H
