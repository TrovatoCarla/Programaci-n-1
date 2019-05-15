#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"

int main()
{
    Empleado *pArrayEmpleado[1000];
    int ultimoElementoArrayEmpleado = 0;
    int indiceActual;
    int auxInt;
    float auxPeso;
    char auxNombre[20];
    indiceActual = ultimoElementoArrayEmpleado;
    pArrayEmpleado[indiceActual] =  Emp_new();


    if(pArrayEmpleado[indiceActual] != NULL)
    {
        ultimoElementoArrayEmpleado++;
        printf("OK");
        if(!Emp_setId(pArrayEmpleado[indiceActual],14))
        {
            Emp_getId(pArrayEmpleado[indiceActual],&auxInt);
            printf("\n El id es %d",auxInt);

        }
        if(!Emp_setNombre(pArrayEmpleado[indiceActual],"carla"))
        {
            Emp_getNombre(pArrayEmpleado[indiceActual],auxNombre);
            printf("\n El nombre es %s",auxNombre);
        }

        if(!Emp_setPeso(pArrayEmpleado[indiceActual],50.15))
        {
            Emp_getPeso(pArrayEmpleado[indiceActual],&auxPeso);
            printf("\n El peso es %f",auxPeso);

        }

    }



    return 0;
}
