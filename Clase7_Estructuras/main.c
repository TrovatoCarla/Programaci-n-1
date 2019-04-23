#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesUTN.h"
#include "misValid.h"
#define EMPLEADOS 5
#define MAXIMO_CARACTER 100
#define TRUE 1
#define FALSE 0


int main()
{
    char arrayUsuario[EMPLEADOS][MAXIMO_CARACTER];
    char nombre[50];

    altaDeUsuario("Ingrese usuario","ERROR usuario incorrecto","Error,usuario existente","Error,no hay posicion disponible",50,2,3,arrayUsuario);



    return 0;
}

int altaDeUsuario(char* mensaje,char* mensajeError,char* errorNombreExistente,char* errorNoHayPosVacia,int maximo,int minimo,int reintentos,char arrayUsuario[EMPLEADOS][MAXIMO_CARACTER])
{
    char arrayBuffer[MAXIMO_CARACTER];
    int i;
    int retorno=-1;
    int posicionDisponible;
    int posicionNombreExistente;

    if(mensaje!=NULL,mensajeError!=NULL,errorNombreExistente!=NULL,errorNoHayPosVacia!=NULL,maximo>minimo,reintentos>=0,arrayUsuario[EMPLEADOS][MAXIMO_CARACTER]!=NULL)
    {
        encuentraPosVacia(arrayUsuario,&posicionDisponible,EMPLEADOS);
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
