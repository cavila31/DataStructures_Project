#include "asignacion.h"
#include "stdlib.h"


asignacion::asignacion()
{

//constr

}
void asignacion::introPura(int val, int y1)
{
    y = y1;
    valAct = 0;
    if(val == 1)
    {
        valOptimo = -1;
        for (int i = 0;  i <= y; ++i)
        {
            solOptima[i][1] = -1;
            solAct[i][1] = -1;
        }
    }
    else
    {
        valOptimo = 100000000;
        for (int i = 0;  i <= y; ++i)
        {
            solOptima[i][1] = 100000000;
            solAct[i][1] = 100000000;
        }
    }
    for (int i = 0;  i <= y; ++i)
    {
        solOptima[i][0] = y;
        solAct[i][0] = y;
    }
    for (int i = 0;  i <= y; ++i)
    {
        utilizados[i] = -1;
    }
}

asignacion::~asignacion()
{
    //dtor
}

void asignacion::introBranchAndBoud()
{
    valOptimo = -1;
    valAct = 0;
    solAct[0][0] = 0;
    solAct[0][1] = -1;
    solAct[1][0] = 1;
    solAct[1][1] = -1;
    solAct[2][0] = 2;
    solAct[2][1] = -1;
    solOptima[0][0] = 0;
    solOptima[0][1] = -1;
    solOptima[1][0] = 1;
    solOptima[1][1] = -1;
    solOptima[2][0] = 2;
    solOptima[2][1] = -1;
    utilizados[0] = -1;
    utilizados[1] = -1;
    utilizados[2] = -1;

}

void asignacion::ExhaustivaPura(int m[150][150], int actual)
{
    for(int i=0; i<=y; i++)
    {
        bool factible = true;
        int x = 0;
        while (factible && x <=y)
        {
            if(utilizados[x] == i)
            {
                factible = false;
            }
            ++x;
        }
        if (factible)
        {
            solAct[actual][1] = i;
            utilizados[actual] = i;
            valAct = valAct + m[actual][i];
            if(actual == y && valAct>valOptimo)
            {
                valOptimo = valAct;
                for(int y1 = 0; y1 <=y; ++y1)
                {
                    solOptima[y1][1] = solAct[y1][1];
                }
            }
            else if(actual <=y)
            {
                ExhaustivaPura(m,actual+1);
            }
            solAct[actual][1] = -1;
            utilizados[actual] = -1;
            valAct -= m[actual][i];
        }
    }
}

void asignacion::Solucion()
{
    for (int i = 0; i <=y; ++i)
    {
        std::cout << "Para vendedor " << solOptima[i][0] << " -> " << solOptima[i][1] << std::endl;
    }
    std::cout << "Con un valor de " << valOptimo << std::endl;
}

void asignacion::ramif_acot(int recurso, int tr, int tt)
{

    //  Poner Aqui lo de llamar a llenar mat y poner maxi en true=maximizando o false=minimizando
//   tabla[0][0]=9;
//    tabla[0][1]=2;
//    tabla[0][2]=7;
//    tabla[0][3]=8;
//
//    tabla[1][0]=6;
//    tabla[1][1]=4;
//    tabla[1][2]=3;
//    tabla[1][3]=7;
//
//    tabla[2][0]=5;
//    tabla[2][1]=8;
//    tabla[2][2]=1;
//    tabla[2][3]=8;
//
//    tabla[3][0]=7;
//    tabla[3][1]=6;
//    tabla[3][2]=9;
//    tabla[3][3]=4;
//
//    TotalRecursos=4;
//    Totaltareas=4;
//
    TotalRecursos=tr;
    Totaltareas=tt;
    podar=false;
    // ganaciaOptima=INT_MAX;
    ganaciaOptima=0;
    gananciaActual=0;
    TareasAsignadas=0;
    for (int j=0; j<=150; j++)
    {
        solucionActual[j]=INT_MIN;
    }
    if (maxi==true)
    {
        Branch_and_Bound(0, 0);
        for (int f=0; f<=3; f++)
        {

            cout<<"En ["<<f<<"]= "<<solucionOptima[f]<<endl;
        }
        cout<<"La Gan Optima Alcanzada fue: "<<ganaciaOptima<<endl;

    }
    else
    {
        Branch_and_BoundMIN(0, 0);

        for (int f=0; f<=3; f++)
        {
            cout<<"En ["<<f<<"]= "<<solucionOptima[f]<<endl;
        }
        cout<<"La Gan Optima Alcanzada fue: "<<(-INT_MIN+1)+(ganaciaOptima)<<endl;
    }
}

int asignacion::buscar_cota(int recurso, int i, int selected)
{

    int cota=tabla[recurso][i];
    cota+=selected;
    escogido=tabla[recurso][i];
    int max_fila=0;
    for (int k=recurso+1; k<=TotalRecursos; k++)
    {
        for (int j=0; j<=Totaltareas-1; j++)
        {
            if (solucionActual[j]==INT_MIN)
            {
                if (tabla[k][j]>max_fila)
                {
                    max_fila=tabla[k][j];
                }
            }
        }
        cota+=max_fila;
        max_fila=0;
    }

    return cota;
}

int asignacion::buscar_cotaMIN(int recurso, int i, int selected)
{
    int cota=tabla[recurso][i];
    cota+=selected;
    escogido=tabla[recurso][i];
    int max_fila=INT_MAX;
    for (int k=recurso+1; k<=TotalRecursos; k++)
    {
        for (int j=0; j<=Totaltareas-1; j++)
        {
            if (solucionActual[j]==INT_MIN)
            {
                if (tabla[k][j]<max_fila)
                {
                    max_fila=tabla[k][j];
                }
            }
        }
        cota+=max_fila;
        max_fila=INT_MAX;
    }

    return cota;
}


void asignacion::Branch_and_Bound(int recurso, int selected)
{
    if (recurso<=TotalRecursos-1)
    {
        cota_aux cotas_por_nivel[Totaltareas-1];
        int z=0;
        int m=0;
        bool salir=false;
        for (int i=0; i<=Totaltareas-1; i++)
        {
            if (solucionActual[i]==INT_MIN)
            {
                solucionActual[i]=recurso;
                cotas_por_nivel[z].cota=buscar_cota(recurso, i, selected);
                cotas_por_nivel[z].tarea=i;
                cotas_por_nivel[z].elegido=escogido;
                solucionActual[i]=INT_MIN;
                z++;
            }
        }

        //----Ordenando

        int i, j, flag = 1;
        cota_aux temp;
        for(i = 1; (i <= z) && flag; i++)
        {
            flag = 0;
            for (j=0; j < (z -1); j++)
            {
                if (cotas_por_nivel[j+1].cota > cotas_por_nivel[j].cota)      // para minim changes to <
                {
                    temp = cotas_por_nivel[j];
                    cotas_por_nivel[j] = cotas_por_nivel[j+1];
                    cotas_por_nivel[j+1] = temp;
                    flag = 1;
                }
            }
        }
        //---Fin Ordenando

        for (int k=0; k<=z-1; k++)
        {
            cout<<"Recurso ="<<recurso<<" tiene una cota de= "<<cotas_por_nivel[k].cota<< " para la tarea "<<cotas_por_nivel[k].tarea+1<<"\n"<<endl;

        }
        cout<<"z= "<<z<<endl;

        while (m<=z-1 && salir==false && cotas_por_nivel[m].revisado==false && cotas_por_nivel[m].poda==false)
        {

            cout<<"m= "<<m<<endl;
            cotas_por_nivel[m].revisado=true;

//   for (int k=0; k<=z-1; k++){
//   cout<<"Recurso ="<<recurso<<" tiene una cota de= "<<cotas_por_nivel[k].cota<< " para la tarea "<<cotas_por_nivel[k].tarea+1<<"\n"<<endl;
//
//         }
            if (podar==true)
            {
                if (ganaciaOptima>cotas_por_nivel[m].cota)   //  Cambiar para minimi
                {
                    for(int q=m; q<=z; q++)
                    {
                        cotas_por_nivel[q].poda=true;
                    }
                    salir=true;
                }
            }
            else if(podar==false ||(ganaciaOptima<gananciaActual+cotas_por_nivel[m].cota) )
            {
                solucionActual[cotas_por_nivel[m].tarea]=recurso;
                cout<<"\nTarea "<<cotas_por_nivel[m].tarea<<endl;
//                TareasAsignadas++;
                gananciaActual=cotas_por_nivel[m].cota;
                cout<<"\nCon una cota de "<<cotas_por_nivel[m].cota<<endl;
                cout<<"-------------\n"<<endl;

                if (recurso==TotalRecursos-1)
                {
                    cout<<"\nganacia actual "<<gananciaActual<<endl;
                    cout<<"ganancia optima "<<ganaciaOptima<<"\n"<<endl;


                    if (ganaciaOptima<gananciaActual)
                    {
                        ganaciaOptima=gananciaActual;
                        for (int g=0; g<=Totaltareas-1; g++)
                        {
                            solucionOptima[g]=solucionActual[g];
                        }
                        podar==true;
                    }
                }
                else
                {
                    e+=cotas_por_nivel[m].elegido;
                    Branch_and_Bound(recurso+1, e);
                }
            }

            //----Se arrepiente
            gananciaActual-=cotas_por_nivel[m].cota;
            TareasAsignadas--;
            m++;
        }
    }
}

void asignacion::Branch_and_BoundMIN(int recurso, int selected)
{
    if (recurso<=TotalRecursos-1)
    {
        cota_aux cotas_por_nivel[Totaltareas-1];
        int z=0;
        int m=0;
        bool salir=false;
        for (int i=0; i<=Totaltareas-1; i++)
        {
            if (solucionActual[i]==INT_MIN)
            {
                solucionActual[i]=recurso;
                cotas_por_nivel[z].cota=buscar_cotaMIN(recurso, i, selected);
                cotas_por_nivel[z].tarea=i;
                cotas_por_nivel[z].elegido=escogido;
                solucionActual[i]=INT_MIN;
                z++;
            }
        }
        //Ordenando
        int i, j, flag = 1;
        cota_aux temp;
        for(i = 1; (i <= z) && flag; i++)
        {
            flag = 0;
            for (j=0; j < (z -1); j++)
            {
                if (cotas_por_nivel[j+1].cota < cotas_por_nivel[j].cota)      // para minim changes to <
                {
                    temp = cotas_por_nivel[j];
                    cotas_por_nivel[j] = cotas_por_nivel[j+1];
                    cotas_por_nivel[j+1] = temp;
                    flag = 1;
                }
            }
        }


        //---Fin Ordenando

        for (int k=0; k<=z-1; k++)
        {
            cout<<"Recurso ="<<recurso<<" tiene una cota de= "<<cotas_por_nivel[k].cota<< " para la tarea "<<cotas_por_nivel[k].tarea+1<<"\n"<<endl;

        }
        cout<<"z= "<<z<<endl;

        while (m<=z-1 && salir==false && cotas_por_nivel[m].revisado==false && cotas_por_nivel[m].poda==false)
        {

            cout<<"m= "<<m<<endl;
            cotas_por_nivel[m].revisado=true;

//   for (int k=0; k<=z-1; k++){
//   cout<<"Recurso ="<<recurso<<" tiene una cota de= "<<cotas_por_nivel[k].cota<< " para la tarea "<<cotas_por_nivel[k].tarea+1<<"\n"<<endl;
//
//         }
            if (podar==true)
            {
                if (ganaciaOptima<cotas_por_nivel[m].cota)   //  Cambiar para minimi
                {
                    for(int q=m; q<=z; q++)
                    {
                        cotas_por_nivel[q].poda=true;
                    }
                    salir=true;
                }
            }
            else if(podar==false ||(ganaciaOptima<gananciaActual+cotas_por_nivel[m].cota) )
            {
                solucionActual[cotas_por_nivel[m].tarea]=recurso;
                cout<<"\nTarea "<<cotas_por_nivel[m].tarea<<endl;
//                TareasAsignadas++;
                gananciaActual=cotas_por_nivel[m].cota;
                cout<<"\nCon una cota de "<<cotas_por_nivel[m].cota<<endl;
                cout<<"-------------\n"<<endl;

                if (recurso==TotalRecursos-1)
                {
                    cout<<"\nganacia actual "<<gananciaActual<<endl;
                    cout<<"ganancia optima "<<ganaciaOptima<<"\n"<<endl;


                    if (ganaciaOptima>gananciaActual)
                    {
                        ganaciaOptima=gananciaActual;
                        for (int g=0; g<=Totaltareas-1; g++)
                        {
                            solucionOptima[g]=solucionActual[g];
                        }
                        podar==true;
                    }
                }
                else
                {
                    e+=cotas_por_nivel[m].elegido;
                    Branch_and_BoundMIN(recurso+1, e);
                }
            }

            //----Se arrepiente
            gananciaActual-=cotas_por_nivel[m].cota;
            TareasAsignadas--;
            m++;
        }
    }
}
