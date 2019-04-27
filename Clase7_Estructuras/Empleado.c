#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"
#define MAX_CARACTER 100



int emp_muestra(Empleado *arrayEmp,int limite)
{
    printf("%s",arrayEmp->nombre);
    printf("%d",arrayEmp->idEmpleado);
    printf("%d",arrayEmp->isEmpty);

    return 0;
}

void emp_initArray(Empleado* arrayEmp,int limite)
{
    int i;

    for(i=0;i<limite;i++)
    {
        strncpy(arrayEmp[i].isEmpty,"1",MAXIMO_CARACTER);
    }

    return 0;
}

int emp_lugarLibre(Empleado* arrayEmp,int limite,int* indice)
{
    int i;
    int retorno=-1;

    for(i=0;i<limite;i++)
    {
        if(strncmp(arrayEmp[i].nombre," ",MAXIMO_CARACTER)==0)
        {
            *indice=i;
            retorno=0;
        }
    }
    return retorno;
}









