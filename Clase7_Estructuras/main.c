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
/*int altaDeUsuario(char* mensaje,
                    char* mensajeError,
                    char* errorNombreExistente,
                    char* errorNoHayPosVacia,
                    int maximo,
                    int minimo,
                    int reintentos,
                    char arrayUsuario[EMPLEADOS][MAXIMO_CARACTER]);

int bajaDeUsuario(char* mensaje,
                    char* mensajeError,
                    char* msjErrNoExisteUsuario,
                    int maximo,
                    int minimo,
                    int reintentos,
                    char* arrayUsuario[] [MAXIMO_CARACTER]);*/


int buscaSiYaExiste(char arrayStr[][MAXIMO_CARACTER],char* nombre,int limite);
int main()
{
    char usuario[EMPLEADOS][MAXIMO_CARACTER];

    iniciarlizarArrays(usuario,EMPLEADOS);

    strncpy(usuario[0],"\nCarla",20);
    strncpy(usuario[1],"\nKaren",20);
    strncpy(usuario[2],"\nEmilce",20);
    strncpy(usuario[3],"\nGiovanni",20);

    muestraArray(usuario,EMPLEADOS);
  if(buscaSiYaExiste(usuario,"Carla",EMPLEADOS)==TRUE)
  {
    printf("ENcontrado");
  }
  else
  printf("NADA");





   /*  if(bajaDeUsuario("Indique nombre a MODIFICAR\n","ERROR","NO existe nombre",50,2,3,aCambiar)==0)
   {
        muestraArray(usuario,EMPLEADOS);
    }*/

    /*
    Empleado primerEmp;

    primerEmp.idEmpleado=1;
    primerEmp.isEmpty=1;

    strncpy(primerEmp.nombre,"Carla\n",50);

    emp_muestra(&primerEmp,50);
    */

    return 0;
}

int buscaSiYaExiste(char arrayStr[][MAXIMO_CARACTER],char* nombre,int limite)
{

    int i;
    int retorno=FALSE;

    for (i=0;i<limite;i++)
    {
        if(strncmp(arrayStr[i],nombre,MAXIMO_CARACTER)==TRUE)
        {
            retorno=TRUE;
            break;
        }
    }
    return retorno;
}




/*
int bajaDeUsuario(char* mensaje,
                    char* mensajeError,
                    char* msjErrNoExisteUsuario,
                    int maximo,
                    int minimo,
                    int reintentos,
                    char* arrayUsuario[] [MAXIMO_CARACTER])
{
    char buffer[MAXIMO_CARACTER];
    int posicionAModificar;
    char datoNuevo[MAXIMO_CARACTER];
    int retorno=-1;

    if(mensaje!=NULL && mensajeError!=NULL && msjErrNoExisteUsuario!=NULL && maximo>minimo && reintentos>=0 && arrayUsuario!=NULL)
    {
        if(getName(mensaje,mensajeError,maximo,minimo,reintentos,buffer)==0)
        {
            if(buscaSiYaExiste(arrayUsuario[][MAXIMO_CARACTER],buffer,&posicionAModificar,EMPLEADOS)!=FALSE)
            {
                strncpy(arrayUsuario[posicionAModificar],"\0",MAXIMO_CARACTER);
                if(getName(mensaje,mensajeError,maximo,minimo,reintentos,datoNuevo)==0)
                {
                    strncpy(" ",datoNuevo,MAXIMO_CARACTER);
                    retorno=0;
                }
            }
            else
                printf("%s",msjErrNoExisteUsuario);
        }
    }
    return retorno;
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

            if(buscaSiYaExiste(arrayUsuario,arrayBuffer,&posicionNombreExistente,EMPLEADOS)!=0)
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
