#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ABM.h"
#include "funcionesUTN.h"
#include "misValid.h"
#define EMPLEADOS 6
#define MAXIMO_CARACTER 100
#define TRUE 1
#define FALSE 0

int altaDeUsuario(char* mensaje,
                    char* mensajeError,
                    char* errorNombreExistente,
                    char* errorNoHayPosVacia,
                    int maximo,
                    int minimo,
                    int reintentos,
                    char arrayUsuario[][MAXIMO_CARACTER])
{
    char arrayBuffer[MAXIMO_CARACTER];
    int retorno=-1;
    int posicionDisponible=-1;
    int posicionNombreExistente=-1;

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

int modificacionDeUsuario(char* mensaje,
                    char* mensajeError,
                    char* msjErrNoExisteUsuario,
                    char modificacion[MAXIMO_CARACTER],
                    int maximo,
                    int minimo,
                    int reintentos,
                    char arrayUsuario[] [MAXIMO_CARACTER])
{
    char buffer[MAXIMO_CARACTER];
    int posicionAModificar=-1;
    int retorno=-1;

    if(mensaje!=NULL && mensajeError!=NULL && msjErrNoExisteUsuario!=NULL && modificacion!=NULL && maximo>minimo && reintentos>=0 && arrayUsuario!=NULL)
    {
        getName(mensaje,mensajeError,maximo,minimo,reintentos,buffer);
        buscaSiYaExiste(arrayUsuario,buffer,&posicionAModificar,100);
            if(posicionAModificar!=-1)
            {
                strncpy(arrayUsuario[posicionAModificar],"",MAXIMO_CARACTER);
                if(getName(mensaje,mensajeError,maximo,minimo,reintentos,modificacion)==0)
                {
                    strncpy(arrayUsuario[posicionAModificar],modificacion,MAXIMO_CARACTER);///Mirar bien el destino es la posicion encontrada y no " " como estaba poniendo
                    retorno=0;
                }
            }
            else
                printf("%s",msjErrNoExisteUsuario);

    }
    return retorno;
}

int bajaDeUsuario(char* mensaje,
                    char* mensajeError,
                    char* msjErrNoExisteUsuario,
                    int maximo,
                    int minimo,
                    int reintentos,
                    char arrayUsuario[] [MAXIMO_CARACTER])
{
    char arraybuffer[MAXIMO_CARACTER];
    int retorno=-1;
    int posicionABorrar=-1;

    if(mensaje!=NULL && mensajeError!=NULL && msjErrNoExisteUsuario!=NULL && maximo>minimo && reintentos>=0 && arrayUsuario!=NULL)
    {
        if(getName(mensaje,mensajeError,maximo,minimo,reintentos,arraybuffer)==0)
        {
            if(buscaSiYaExiste(arrayUsuario,arraybuffer,&posicionABorrar,MAXIMO_CARACTER)!=-1)
            {
                strncpy(arrayUsuario[posicionABorrar]," ",MAXIMO_CARACTER);
                retorno=0;
            }
            else
            {
                printf("%s",msjErrNoExisteUsuario);
            }
        }
    }
    return retorno;
}




