#include <iostream>
#include "visualizador.h"
#include "asignacion.h"
#include "distribucion.h"
#include "Diccionario.h"
#include "grafo_t.h"
#include "circuito_hamilton.h"
#include "mochila.h"

using namespace std;

void llenarMatriz(int tabla[150][150],int &x, int &y)
{
    bool end;
    bool end2 = false;
    while (!end2)
    {
        std::cout << "Digite los valores de la matriz de uno en uno, presione -1 para pasar de fila y -2 para finalizar la entrada" << std::endl;
        int val;
        end = false;
        x = 0;
        y = 0;
        while (!end)
        {
            std::cin >> val;
            if(val == -1)
            {
                ++y;
                x=0;
            }
            else if(val == -2)
            {
                end = true;
            }
            else
            {
                tabla[y][x] = val;
                ++x;
            }
        }
        std::cout << "La matriz es la siguiente:" << std::endl;
        for (int i = 0; i <= y; i++)
        {
            for (int j = 0; j < x; j++)
            {
                std::cout << tabla[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "Digite s para aceptar la matriz o n para rechazarla" << std::endl;
        char acepta;
        std::cin >> acepta;
        if (acepta == 's')
        {
            std::cout << "Matriz aceptada" << std::endl;
            end2 = true;
            --x;
        }
        else
        {
            std::cout << "Matriz no aceptada" << std::endl;
        }
    }
}

void pruebasPredeterminadas()
{
}

int main()
{
    int x;
    int y;
    int M[150][150];
    grafo_t *G;
    int opcion;
    bool fin = false;

    string menu_inicial = "\t\t Digite 1 si desea digitar su propio problema matricial \n"
                          "\t\t Digite 2 si desea digitar su propio problema  de grafos\n";

    string menu = "\n       * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         \n\n"
                  "\t\t   Menu de opciones               \n\n"
                  "\t\t   Digite 1 Circuito Hamilton de Menor Costo \n"
                  "\t\t   Digite 2 Problema de Distribucion     \n"
                  "\t\t   Digite 3 Problema d e Asignacion      \n"
                  "\t\t   Digite 4 Problema de Mochila      \n"
                  "\t\t   Digite 5 Salir     \n\n"

                  "        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         \n";
    string creditos="\n\t Implementado por: \n\n"
                    "\t\t Danilo Acosta V.    B30044\n"
                    "\t\t Carolina Avila A.   B30721\n";
    cout<<creditos<<endl;
    cout<<menu_inicial<<endl;
    cin >> opcion;
    if (opcion == 1)
    {
        llenarMatriz(M,x,y);
    }
    else if (opcion == 2)
    {
        G = new grafo_t();
        G->crear();
        bool end = false;
        cout << "\t\t Digite 1 para destruir el grafo\n"
             "\t\t Digite 2 para vaciar al grafo\n"
             "\t\t Digite 3 para saber si esta vacío\n"
             "\t\t Digite 4 para agregar un vértice\n"
             "\t\t Digite 5 para eliminar un vértice\n"
             "\t\t Digite 6 para modificar un vértice\n"
             "\t\t Digite 7 para ver la etiqueta de un vértice\n"
             "\t\t Digite 8 para agregar una arista\n"
             "\t\t Digite 9 para eliminar una arista\n"
             "\t\t Digite 10 para modificar el peso de una arista\n"
             "\t\t Digite 11 para saber el peso de una arista\n"
             "\t\t Digite 12 para ver el primer vértice\n"
             "\t\t Digite 13 para el siguiente vértice\n"
             "\t\t Digite 14 para ver el primer vértice adyacente\n"
             "\t\t Digite 15 para ver el siguiente vértice adyacente\n"
             "\t\t Digite 16 para ver el número de vértices\n"
             "\t\t Digite 17 para saber e\n"
             "\t\t Digite 18 para salir\n";
        int opcion2;
        while (!end)
        {
            cin >> opcion2;
            switch(opcion2)
            {
            case 1:
            {
                G->destruir();
                cout<< "Saliendo del programa";
                return 0;
            }
            break;
            case 2:
            {
                G->vaciar();
                cout << "Grafo vaciado" << endl;
            }
            break;
            case 3:
            {
                if (G->vacio())
                {
                    cout<< "Grafo vacío" << endl;
                }
                else
                {
                    cout << "Grafo no vacío" << endl;
                }
            }
            break;
            case 4:
            {
                int val;
                cout << "Digite la etiqueta del vértice" << endl;
                cin >> val;
                G->agregarVertice(val);
                cout << "Vértice agregado" << endl;
            }
            break;
            case 5:
            {
                int val;
                cout << "Digite la etiqueta del vértice a eliminar" << endl;
                cin >> val;
                G->eliminarVertice(G->buscar(val));
                cout << "Vértice eliminado" << endl;
            }
            break;
            case 6:
            {
                int val;
                int val2;
                cout << "Digite la etiqueta del vértice a cambiar con la nueva etiqueta" << endl;
                cin >> val;
                cin >> val2;
                G->modificarEtiqueta(G->buscar(val),val2);
                cout << "Vértice cambiado" << endl;
            }
            break;
            case 7:
            {
                int val;
                cout << "Digite la etiqueta a averiguar" << endl;
                cin >> val;
                cout << "La etiqueta es " << val << endl;
            }
            break;
            case 8:
            {
                int val;
                int val1;
                int val2;
                cout << "Digite la etiqueta del vértice 1, la del 2 y el peso de la arista a agregar" << endl;
                cin >> val;
                cin >> val1;
                cin >> val2;
                G->agregarArista(G->buscar(val),G->buscar(val1),val2);
                cout << "Arista agregada" << endl;
            }
            break;
            case 9:
            {
                int val;
                int val1;
                cout << "Digite la etiqueta del vértice 1 y 2 de los cuales quiere elimiar el arista" << endl;
                cin >> val;
                cin >> val1;
                G->eliminarArista(G->buscar(val), G->buscar(val1));
                cout << "Arista eliminada" << endl;
            }
            break;
            case 10:
            {
                int val;
                int val1;
                int val2;
                cout << "Digite la etiqueta del vértice 1, la del 2 y el peso de la arista a modificar" << endl;
                cin >> val;
                cin >> val1;
                cin >> val2;
                G->modificarPesoArista(G->buscar(val),G->buscar(val1),val2);
                cout << "Arista modificada" << endl;
            }
            break;
            case 11:
            {
                int val;
                int val1;
                cout << "Digite la etiqueta del vértice 1 y 2 para ver el peso" << endl;
                cin >> val;
                cin >> val1;
                cout << "Peso: " << G->peso(G->buscar(val),G->buscar(val1)) << endl;
            }
            break;
            case 12:
            {
                cout << "Primer vértice " << G->etiqueta(G->primerVertice()) << endl;
            }
            break;
            case 13:
            {
                int val;
                cout << "Digite la etiqueta del vértice para saber el siguiente" << endl;
                cin >> val;
                cout << G->etiqueta(G->siguienteVertice(G->buscar(val))) << endl;
            }
            break;
            case 14:
            {
                int val;
                cout << "Digite la etiqueta del vértice para saber el primer vertice adyacente" << endl;
                cin >> val;
                cout << G->etiqueta(G->primerVerticeAdy(G->buscar(val))) << endl;
            }
            break;
            case 15:
            {
                int val;
                int val1;
                cout << "Digite la etiqueta del vértice y del adyacente para saber el siguiente" << endl;
                cin >> val;
                cin >> val1;
                cout << G->etiqueta(G->siguienteVerticeAdy(G->buscar(val),G->buscar(val1))) << endl;
            }
            break;
            case 16:
            {
                cout << "Número de vértices: " << G->numVertices() << endl;
            }
            break;
            case 17:
            {
                int val;
                int val1;
                cout << "Digite la etiqueta del de 2 vértices para saber si existe una arista" << endl;
                cin >> val;
                cin >> val1;
                if(G->existeArista(G->buscar(val),G->buscar(val1)))
                {
                    cout << "Sí existe" << endl;
                }
                else
                {
                    cout << "No existe" << endl;
                }
            }
            break;
            case 18:
            {
                end = true;
            }
            break;
            }
        }
    }
    else
    {
        cout << "Opción no válida";
        return 1;
    }
    while (!fin)
    {
        cout<<menu<<endl;
        cin>>opcion;
        cin.ignore();
        switch(opcion)
        {
        case 1:
        {
            int opcion1;
            bool fin3 = false;
            string menu3 = "\n       * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         \n\n"
                           "\t\t   Circuito de Hamilton                \n\n"
                           "\t\t   Digite 1 Busqueda Exhaustiva Pura       \n"
                           "\t\t   Digite 2 BE con Ramificacion y Acotamiento      \n"
                           "\t\t   Digite 3 Busqueda Greedy                    \n"
                           "\t\t   Digite 4 Busqueda Local                  \n"
                           "\t\t   Digite 5 Volver al Inicio                  \n\n"

                           "        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         \n";
            while (!fin3)
            {
                circuito_hamilton *ch = new circuito_hamilton ();
                cout << menu3 << endl;
                cin >> opcion1;
                cin.ignore();
                switch(opcion1)
                {
                case 1:
                {
                    //ch->BEP();////////////////////////////////////////////////////////////////////////////////////
                    //ch->introBEP();//////////////////////////////////////////////////////////////////////////////
                }
                break;
                case 2:
                {
                    //ch->Exhaustiva();//////////////////////////////////////////////////////////////////////////////////
                }
                break;
                case 3:
                {
                    ch->greedy(G);
                }
                break;
                case 4:
                {
                    ch->local();
                }
                break;
                case 5:
                {
                    cout << "\t\tRegresando...\n" << endl;
                    fin3=true;
                }
                break;
                }
            }
        }
        break;
        //Fin Hamilton
        case 2:
        {
            int opcion5;
            bool fin5 = false;
            string menu5 = "\n       * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         \n\n"
                           "\t\t   Problema de Distribucion                 \n\n"
                           "\t\t   Digite 1 Busqueda Exhaustiva Pura       \n"
                           "\t\t   Digite 2 BE con Ramificación y Acotamiento      \n"
                           "\t\t   Digite 3 Volver al Inicio                  \n\n"

                           "        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         \n";
            while (!fin5)
            {
                distribucion *d = new distribucion();
                cout << menu5 << endl;
                cin >> opcion5;
                cin.ignore();
                switch(opcion5)
                {
                case 1:
                {
                    int val;
                    cout << "Inserte el valor de la distribucion" << endl;
                    cin >> val;
                    d->introPura(val,y,x);
                    d->ExhaustivaPura(M,0);
                    d->Solucion();
                }
                break;
                case 2:
                {
                    ////////////////////////////////////////////////////////////////////////////////////////////////////
                }
                break;
                case 3:
                {
                    cout << "\t\tRegresando...\n" << endl;
                    fin5=true;
                }
                break;
                }
            }
        }
        break;
        //Fin Distribucion
        case 3:
        {
            int opcion6;
            bool fin6 = false;
            string menu6 = "\n       * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         \n\n"
                           "\t\t   Problema de Asignacion                  \n\n"
                           "\t\t   Digite 1 Busqueda Exhaustiva Pura       \n"
                           "\t\t   Digite 2 BE con Ramificacion y Acotamiento      \n"
                           "\t\t   Digite 3 Volver al Inicio                  \n\n"

                           "        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         \n";
            while (!fin6)
            {
                asignacion *a = new asignacion();
                cout << menu6 << endl;
                cin >> opcion6;
                cin.ignore();
                switch(opcion6)
                {
                case 1:
                {
                    int val;
                    cout << "Digite el tamaño a asignar, 1 para maximizar y -1 para minimizar" << endl;
                    cin >> val;
                    a->introPura(val,y);
                    a->ExhaustivaPura(M,0);
                    a->Solucion();
                }
                break;
                case 2:
                {
                    ///////////////////////////////////////////////////////////////////////////////////////////////////
                }
                break;
                case 3:
                {
                    cout << "\t\tRegresando...\n" << endl;
                    fin6=true;
                }
                }
            }
        }
        break;
        //Fin Asignacion
        case 4:
        {
            int opcion7;
            bool fin7 = false;
            string menu7 = "\n       * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         \n\n"
                           "\t\t   Problema de Mochila                  \n\n"
                           "\t\t   Digite 1 Busqueda Exhaustiva Pura       \n"
                           "\t\t   Digite 2 BE con Ramificacion y Acotamiento      \n"
                           "\t\t   Digite 3 Volver al Inicio                  \n\n"

                           "        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         \n";
            while (!fin7)
            {
                cout << menu7 << endl;
                cin >> opcion7;
                cin.ignore();
                switch(opcion7)
                {
                case 1:
                {
                    int val;
                    cout << "Digite el tamaño de la mochila" << endl;
                    cin >> val;
                    mochila *m = new mochila(val,y,x);
                    m->ExhaustivaPura(M,0);
                    m->Solucion();
                }
                break;
                case 2:
                {
                    ///////////////////////////////////////////////////////////////////////////////////////
                }
                break;
                case 3:
                {
                    cout << "\t\tRegresando...\n" << endl;
                    fin7=true;
                }
                }
            }
        }
        break;
        //Fin Mochila
        case 5:
        {
            cout << "\nBye!" << endl;
            fin=true;
        }
        break;
        }
    }

}
