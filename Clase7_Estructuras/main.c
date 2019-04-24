#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesUTN.h"
#include "misValid.h"
#define EMPLEADOS 3
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
    /*
    Empleado primerEmp;

    primerEmp.idEmpleado=1;
    primerEmp.isEmpty=1;

    strncpy(primerEmp.nombre,"Carla\n",50);

    emp_muestra(&primerEmp,50);
    */

    return 0;
}


/*
int altaDeUsuario(char* mensaje,char* mensajeError,char* errorNombreExistente,char* errorNoHayPosVacia,int maximo,int minimo,int reintentos,char arrayUsuario[EMPLEADOS][MAXIMO_CARACTER])
{
    char arrayBuffer[MAXIMO_CARACTER];
    int retorno=-1;
    int posicionDisponible;
    int posicionNombreExistente;

    if(mensaje!=NULL && mensajeError!=NULL && errorNombreExistente!=NULL && errorNoHayPosVacia!=NULL && maximo>minimo && reintentos>=0 && arrayUsuario[EMPLEADOS][MAXIMO_CARACTER]!=NULL)
    {
        encuentraPosVacia(arrayUsuario,posicionDisponible,EMPLEADOS);
        if(posicionDisponible!=-1)
        {
            getName(mensaje,mensajeError,maximo,minimo,reintentos,arrayBuffer);
            buscaSiYaExiste(arrayUsuario,arrayBuffer,&posicionNombreExistente,EMPLEADOS);
            if(posicionNombreExistente!=-1)
            {
                strncpy(arrayUsuario[posicionDisponible],arrayBuffer,MAXIMO_CARACTER);
                retorno=0;
            }
            else
            {
                printf("%s",errorNombreExistente);
            }
        }
        else
        {
            printf("%s",errorNoHayPosVacia);
        }
    }
        return retorno;
}
*/
