///_____________________________________///
///|                                   |///
///|       Evolución Diferencial       |///
///|___________________________________|///

#include <iostream>
#include <math.h>
#include <cstdio>
#include <cstdlib>
#include <time.h>

using namespace std;

const int generaciones = 1000;
const int poblacion = 50;
const double F = 1;
const double Cr = 0.6;
const double pi = 3.14159265358979323846;
const double up = 5;
const double low = -5;

double Rand(void)
{
    return (rand()/(double)RAND_MAX);
}

bool validarRandom(int pos, int r1, int r2, int r3)
{
    if(pos != r1 and pos != r2 and pos != r3 and r1 != r2 and r1 != r3 and r2 != r3)
    {
        return true;
    }
    return false;
}

int generarRandom()
{
    return rand() %poblacion;
}

double Griewank(double x,double y)
{
    
}

double Rastrigin(double x,double y)
{
    
}

double Sphere(double x,double y)
{
    return (x*x) + (y*y);
}

void Evolucion_Diferencial_Griewank()
{
    double vector_x[poblacion], vector_y[poblacion];
    double mutado_x[poblacion], mutado_y[poblacion];
    double prueba_X[poblacion], prueba_y[poblacion];


    for(int i = 0; i < 50; i++)
    {
        vector_x[i] = low + ((up - low)*Rand());
        vector_y[i] = low + ((up - low)*Rand());
    }

    for(int i = 0; i < generaciones; i++)
    {
        for(int j = 0; j < poblacion; j++)
        {
            int r1,r2,r3;
            do
            {
                r1 = generarRandom();
                r2 = generarRandom();
                r3 = generarRandom();
            }while(!validarRandom(j,r1,r2,r3));
            mutado_x[j] = vector_x[r1] + F*(vector_x[r2] - vector_x[r3]);
            mutado_y[j] = vector_y[r1] + F*(vector_y[r2] - vector_y[r3]);
        }

        for(int j = 0; j < poblacion; j++)
        {
            if(Rand() < Cr)
            {
                prueba_X[j] = mutado_x[j];
                prueba_y[j] = mutado_y[j];
            }
            else
            {
                prueba_X[j] = vector_x[j];
                prueba_y[j] = vector_y[j];
            }
        }

        for(int j = 0; j < poblacion; j++)
        {
            if(Griewank(prueba_X[j],prueba_y[j]) < Griewank(vector_x[j],vector_y[j]))
            {
                vector_x[j] = prueba_X[j];
                vector_y[j] = prueba_y[j];
            }
        }
    }
}


void Evolucion_Diferencial_Rastrigin()
{
    double vector_x[poblacion], vector_y[poblacion];
    double mutado_x[poblacion], mutado_y[poblacion];
    double prueba_X[poblacion], prueba_y[poblacion];


    for(int i = 0; i < 50; i++)
    {
        vector_x[i] = low + ((up - low)*Rand());
        vector_y[i] = low + ((up - low)*Rand());
    }

    for(int i = 0; i < generaciones; i++)
    {
        for(int j = 0; j < poblacion; j++)
        {
            int r1,r2,r3;
            do
            {
                r1 = generarRandom();
                r2 = generarRandom();
                r3 = generarRandom();
            }while(!validarRandom(j,r1,r2,r3));
            mutado_x[j] = vector_x[r1] + F*(vector_x[r2] - vector_x[r3]);
            mutado_y[j] = vector_y[r1] + F*(vector_y[r2] - vector_y[r3]);
        }

        for(int j = 0; j < poblacion; j++)
        {
            if(Rand() < Cr)
            {
                prueba_X[j] = mutado_x[j];
                prueba_y[j] = mutado_y[j];
            }
            else
            {
                prueba_X[j] = vector_x[j];
                prueba_y[j] = vector_y[j];
            }
        }

        for(int j = 0; j < poblacion; j++)
        {
            if(Rastrigin(prueba_X[j],prueba_y[j]) < Rastrigin(vector_x[j],vector_y[j]))
            {
                vector_x[j] = prueba_X[j];
                vector_y[j] = prueba_y[j];
            }
        }
    }

}

void Evolucion_Diferencial_Sphere()
{
    double vector_x[poblacion], vector_y[poblacion];
    double mutado_x[poblacion], mutado_y[poblacion];
    double prueba_X[poblacion], prueba_y[poblacion];


    for(int i = 0; i < 50; i++)
    {
        vector_x[i] = low + ((up - low)*Rand());
        vector_y[i] = low + ((up - low)*Rand());
    }

    for(int i = 0; i < generaciones; i++)
    {
        for(int j = 0; j < poblacion; j++)
        {
            int r1,r2,r3;
            do
            {
                r1 = generarRandom();
                r2 = generarRandom();
                r3 = generarRandom();
            }while(!validarRandom(j,r1,r2,r3));
            mutado_x[j] = vector_x[r1] + F*(vector_x[r2] - vector_x[r3]);
            mutado_y[j] = vector_y[r1] + F*(vector_y[r2] - vector_y[r3]);
        }

        for(int j = 0; j < poblacion; j++)
        {
            if(Rand() < Cr)
            {
                prueba_X[j] = mutado_x[j];
                prueba_y[j] = mutado_y[j];
            }
            else
            {
                prueba_X[j] = vector_x[j];
                prueba_y[j] = vector_y[j];
            }
        }

        for(int j = 0; j < poblacion; j++)
        {
            if(Sphere(prueba_X[j],prueba_y[j]) < Sphere(vector_x[j],vector_y[j]))
            {
                vector_x[j] = prueba_X[j];
                vector_y[j] = prueba_y[j];
            }
        }
    }

}

int main()
{
    srand (time(NULL));
    return 0;
}
