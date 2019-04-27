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

typedef struct

{
    int idEmpleado;
    int isEmpty;// 1 si esta vacio y 0 si esta cargado
    char nombre[50];
}Empleado;

int emp_muestra(Empleado *arrayEmp,int limite);
int emp_initArray(Empleado* arrayEmp,int limite);
int emp_lugarLibre(Empleado* arrayEmp,int limite,int* indice);


int main()
{
    char cadena[EMPLEADOS][MAXIMO_CARACTER];

    iniciarlizarArrays(cadena,EMPLEADOS);

    strncpy(cadena[0],"Carla\n",MAXIMO_CARACTER);
    strncpy(cadena[1],"Zoe\n",MAXIMO_CARACTER);
    strncpy(cadena[2],"Emilce\n",MAXIMO_CARACTER);
    strncpy(cadena[3],"Karen\n",MAXIMO_CARACTER);
    strncpy(cadena[4],"Juan\n",MAXIMO_CARACTER);
    strncpy(cadena[5],"Pedro\n",MAXIMO_CARACTER);

    muestraArray(cadena,EMPLEADOS);

    ordenarArray(cadena,EMPLEADOS);

    muestraArray(cadena,EMPLEADOS);


    return 0;



/*
    Empleado primerEmp;

    primerEmp.idEmpleado=1;
    primerEmp.isEmpty=1;
    int lugarLibre;

    strncpy(primerEmp.nombre,"Carla\n",50);

    emp_muestra(&primerEmp,50);

    //emp_initArray(&primerEmp,MAXIMO_CARACTER);

    //emp_muestra(&primerEmp,MAXIMO_CARACTER);
    emp_lugarLibre(&primerEmp,EMPLEADOS,&lugarLibre);
    printf("%d",lugarLibre);

    return 0;*/
}


int doSwap(int *primerValor, int *segundoValor)
{
    int aux;
    aux = *primerValor;
    *primerValor = *segundoValor;
    *segundoValor = aux;
    return 0;
}








