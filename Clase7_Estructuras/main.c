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
int altaDeUsuario(char* mensaje,
                    char* mensajeError,
                    char* errorNombreExistente,
                    char* errorNoHayPosVacia,
                    int maximo,
                    int minimo,
                    int reintentos,
                    char arrayUsuario[EMPLEADOS][MAXIMO_CARACTER]);
int main()
{
    char usuario[EMPLEADOS][MAXIMO_CARACTER];
    char nombre;
    int i;

    iniciarlizarArrays(usuario,EMPLEADOS);

    strncpy(usuario[0],"\nCarla",20);
    strncpy(usuario[1],"\nKaren",20);
    strncpy(usuario[2],"\nEmilce",20);
    strncpy(usuario[3],"\nGiovanni",20);


    if(strncmp(usuario[0],usuario[1],20)==0)
        printf("Iguales");
    else
        printf("DIstintos");

  // if(altaDeUsuario("Ingrese usuario\n","Usuario invalido","Error,nombre ya existente","Error,no hay posicion disponible",50,2,3,usuario)==0)
  // {
   //     muestraArray(usuario,EMPLEADOS);
  // }

    /*
    Empleado primerEmp;

    primerEmp.idEmpleado=1;
    primerEmp.isEmpty=1;

    strncpy(primerEmp.nombre,"Carla\n",50);

    emp_muestra(&primerEmp,50);
    */

    return 0;
}


int altaDeUsuario(char* mensaje,
                    char* mensajeError,
                    char* errorNombreExistente,
                    char* errorNoHayPosVacia,
                    int maximo,
                    int minimo,
                    int reintentos,
                    char arrayUsuario[EMPLEADOS][MAXIMO_CARACTER])
{
    char arrayBuffer[MAXIMO_CARACTER];
    int retorno=-1;
    int posicionDisponible;
    int posicionNombreExistente;

    if(mensaje!=NULL &&
        mensajeError!=NULL &&
        errorNombreExistente!=NULL &&
        errorNoHayPosVacia!=NULL &&
        maximo>minimo && reintentos>=0 &&
        arrayUsuario!=NULL)
    {

        if(encuentraPosVacia(arrayUsuario,&posicionDisponible,EMPLEADOS)==0)
        {
            getName(mensaje,mensajeError,maximo,minimo,reintentos,arrayBuffer);

            if(buscaSiYaExiste(arrayUsuario,arrayBuffer,&posicionNombreExistente,EMPLEADOS)==-1)
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

