#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesUTN.h"
#include "misValid.h"
#define EMPLEADOS 6
#define MAXIMO_CARACTER 100
#define TRUE 1
#define FALSE 0

//Empleado auxiliarEmpleado[500];
///mpleado *pEmpleado;

//pEmpleado=&auxiliarEmpleado[114];
//pEmpleado->apellido;

//int emp_muestra(Empleado *arrayEmp,int limite);





int main()
{


    Empleado primerEmp;

    primerEmp.idEmpleado=1;
    primerEmp.isEmpty=1;

    strncpy(primerEmp.nombre,"Carla\n",50);

    emp_muestra(&primerEmp,50);


    return 0;
}











