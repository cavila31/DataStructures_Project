#include "distribucion.h"

distribucion::distribucion()
{
    tabla[0][0]=2;
    tabla[0][1]=8;
    tabla[0][2]=10;
    tabla[0][3]=12;
    tabla[1][0]=1;
    tabla[1][1]=2;
    tabla[1][2]=5;
    tabla[1][3]=10;
    tabla[2][0]=6;
    tabla[2][1]=7;
    tabla[2][2]=8;
    tabla[2][3]=9;
    tabla[3][0]=3;
    tabla[3][1]=4;
    tabla[3][2]=6;
    tabla[3][3]=7;
    tabla[4][0]=4;
    tabla[4][1]=5;
    tabla[4][2]=5;
    tabla[4][3]=5;
    MaxRecursos=4;
    MinRecursos=1;
    Totaltareas=5;
    TotalRecursos=9;
    RecursosDisp=9;
    podar=false;
    ganaciaOptima=0;
    gananciaActual=0;
    for (int i=0; i<=5; i++)
    {
        solucionActual[i]=INT_MIN;
    }
    re=0;
    acumulador=0;
}

void distribucion::introPura(int v,int y1, int x1)
{
    numMax = v;
    numAct = 0;
    valOptimo = 0;
    valAct = 0;
    x = x1;
    y = y1;
    for (int i = 0;  i <= y; ++i)
    {
        solOptima[i] = 0;
    }
    for (int i = 0;  i <= y; ++i)
    {
        solAct[i] = 0;
    }
}

distribucion::~distribucion()
{
    //dtor
}

void distribucion::Sol()
{
    for (int f=0; f<=MaxRecursos; f++)
    {

        cout<<"En ["<<f<<"]= "<<solucionOptima[f]<<endl;
    }
    cout<<"La Gan Optima Alcanzada fue: "<<ganaciaOptima<<endl;
}

int distribucion::buscar_cota(int tarea, int i, int selected, int r, bool &bandera)
{
    if (bandera==false)
    {
        acumulador+=r;
        bandera=true;
    }
  //  cout<<"acumulador= "<<acumulador <<endl;
    TareasRestantes=Totaltareas-(tarea+1);
   // cout<<"r= "<<r<<endl;
    int cota=tabla[tarea][i];
   // cout<<"tabla[tarea][i]= "<<tabla[tarea][i]<<endl;
    cota+=selected;
   // cout<<"Selected= "<<selected<<endl;
    escogido=tabla[tarea][i];
   // cout<<"cota= "<<cota<<endl;
   // cout<<"TotalRecursos= "<<TotalRecursos<<endl;
    int pool=TotalRecursos-(i+1)-acumulador;
   // cout<<"pool= "<<pool<<endl;
    bool encontrado=false;
    int max1=MaxRecursos;
   // cout<<"max1= "<<max1<<endl;
    if (TareasRestantes > 1)
    {
        while (encontrado!=true &&max1>=MinRecursos)
        {
            int po=pool-max1;
         //   cout<<"po= "<<po<<endl;
            po=po/(TareasRestantes-1);
         //   cout<<"po= "<<po<<endl;
          //  cout<<"--------"<<endl;
            if (po<MinRecursos)
            {
                max1--;
            }
            else
            {
                re=i+1;
                for(int i=tarea+1; i<=Totaltareas-1; i++)
                {
                    cota+=tabla[i][max1-1];
                }

                encontrado=true;
            }
        }
    }
    else
    {
        int po=pool-max1;
       // cout<<po<<endl;
        while (po != 0)
        {
            max1--;
            po=pool-max1;
         //   cout<<po<<endl;
        }

        re=i+1;
        for(int j=tarea+1; j<=Totaltareas-1; j++)
        {
            cota+=tabla[j][max1-1];
        }
    }
    return cota;
}

void distribucion::Branch_and_Bound(int tarea, int selected, int r)
{

    if (tarea<=(Totaltareas-1))
    {
        int a=MaxRecursos-1;
        //cout<<a<<endl;
        cota_aux1 cotas_por_nivel1[a];
        int z=0;
        int m=0;
        bool salir=false;
        bool bandera=false;
        //cout<<MaxRecursos-1<<endl;
        for (int i=0; i<=MaxRecursos-1; i++)
        {
          //  cout<<i<<endl;
          //  cout<<MaxRecursos-1<<endl;
            if(((Totaltareas-(tarea+1)*MinRecursos)<=(RecursosDisp-(i+1)))&&(((Totaltareas-(tarea+1))*MaxRecursos)>=(RecursosDisp-(i+1))))
            {
                // bandera=false;
             //   cout<<"re= "<<re<<endl;
                cotas_por_nivel1[z].cota=buscar_cota(tarea, i, selected, r, bandera);
                cotas_por_nivel1[z].recurso=i+1;
                cotas_por_nivel1[z].elegido=escogido;
                //  cotas_por_nivel1[z].re=re;

                z++;
            }
        }
//        cout<<"Sin Ordenar\n"<<endl;
//        for (int k=0; k<=z-1; k++)
//        {
//            cout<<"La tarea= "<<tarea+1<<" tiene cota= "<< cotas_por_nivel1[k].cota<<" para el recurso= "<<cotas_por_nivel1[k].recurso<<endl;
//            //  cotas_por_nivel2[k]=cotas_por_nivel1[k];
//        }

        int i, j, flag = 1;

        cota_aux1 temp;
        for(i = 1; (i <= z) && flag; i++)
        {
            flag = 0;
            for (j=0; j < (z -1); j++)
            {
                if (cotas_por_nivel1[j+1].cota > cotas_por_nivel1[j].cota)      // para minim changes to <
                {
                    temp = cotas_por_nivel1[j];
                    cotas_por_nivel1[j] = cotas_por_nivel1[j+1];
                    cotas_por_nivel1[j+1] = temp;
                    flag = 1;
                }
            }
        }

        //---Fin Ordenando

//        cout<<"Ordenado\n"<<endl;
//        for (int h=0; h<=z-1; h++)
//        {
//cout<<"La tarea= "<<tarea+1<<" tiene cota= "<< cotas_por_nivel1[h].cota<<" para el recurso= "<<cotas_por_nivel1[h].recurso<<endl;
//        }

        while (m<=z-1 && salir==false && cotas_por_nivel1[m].revisado==false && cotas_por_nivel1[m].poda==false)
        {
            cotas_por_nivel1[m].revisado=true;
            if (podar==true)
            {
                if (ganaciaOptima>cotas_por_nivel1[m].cota)   //  Cambiar para minimi
                {
                    for(int q=m; q<=z; q++)
                    {
                        cotas_por_nivel1[q].poda=true;
                    }
                    salir=true;
                }
            }
            else if(podar==false ||(ganaciaOptima<gananciaActual+cotas_por_nivel1[m].cota) )
            {
                solucionActual[tarea]=cotas_por_nivel1[m].recurso;     //REVISAR
                //  cout<<"\nRecurso "<<cotas_por_nivel1[m].recurso<<endl;
                gananciaActual=cotas_por_nivel1[m].cota;
               // cout<<"\nCon una cota de "<<cotas_por_nivel1[m].cota<<endl;
                RecursosDisp-=cotas_por_nivel1[m].recurso;    //Verificar q este bn
               // cout<<"-------------\n"<<endl;

                if (tarea==Totaltareas-1)
                {
                //    cout<<"\nganacia actual "<<gananciaActual<<endl;


                    if (ganaciaOptima<gananciaActual)
                    {
                        ganaciaOptima=gananciaActual;
                        for (int g=0; g<=TotalRecursos-1; g++)
                        {
                            solucionOptima[g]=solucionActual[g];
                        }
                        podar==true;
                    }
                }
                else
                {
                    re=cotas_por_nivel1[m].recurso;
               //     cout<<"re para la cota= "<<cotas_por_nivel1[m].cota<<" es= "<<re<<endl;
                    e+=cotas_por_nivel1[m].elegido;
                    if (TareasRestantes > 0)
                        Branch_and_Bound(tarea+1, e, re);
                }
            }

            //----Se arrepiente
            gananciaActual-=cotas_por_nivel1[m].cota;
            //TareasAsignadas--;
            RecursosDisp+=cotas_por_nivel1[m].recurso;
            m++;
        }
    }
}

void distribucion::ExhaustivaPura(const int m[150][150],int actual)
{
    for(int i=1; i<=y; i++)
    {
        solAct[actual] = i;
        valAct += m[actual][i-1];
        numAct += i;
        bool factible = true;
        int x1 = 0;
        while (factible && x1 <= y)
        {
            if (solAct[x1] == 0)
            {
                factible = false;
            }
            ++x1;
        }
        if(factible && numAct == numMax && valAct > valOptimo)
        {
            valOptimo = valAct;
            for(int y1 = 0; y1 <= y; ++y1)
            {
                solOptima[y1] = solAct[y1];
            }
        }
        if(actual <= x)
        {
            ExhaustivaPura(m,actual+1);
        }
        solAct[actual] = 0;
        valAct -= m[actual][i-1];
        numAct -= i;
    }
}

void distribucion::Solucion()
{
    for(int i = 0; i <= y ; ++i)
    {
        std::cout << "Para canditato " << i << " -> " << solOptima[i] << std::endl;
    }
    std::cout << "Con un valor de " << valOptimo << std::endl;
}

