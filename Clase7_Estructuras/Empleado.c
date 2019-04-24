#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"



int emp_muestra(Empleado *arrayEmp,int limite)
{
    printf("%s",arrayEmp->nombre);
    printf("%d",arrayEmp->idEmpleado);
    printf("%d",arrayEmp->isEmpty);

    return 0;
}

