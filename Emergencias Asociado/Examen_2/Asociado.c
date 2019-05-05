#ifndef ASOCIADO_C_INCLUDED
#define ASOCIADO_C_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Asociado.h"
#define MAX_ARRAY 10
#define MAX_CARACTER 50
#define TRUE 1
#define FALSE 0
#define VACIO 1
#define HABILITADO 2
#define INHABILITADO 3

int aso_alta(Asociado* aPaciente,char* msjError,int limite,int lugarDisponible)
{
    int retorno=-1;

    if(aso_buscaLugarLibre(aPaciente,MAX_ARRAY,&lugarDisponible)==0)
    {
        if(getName("\nIngrese nombre: ","\nError nombre invalido",2,MAX_CARACTER,3,aPaciente[lugarDisponible].nombre)==0)
        {
            if(getName("\nIngrese apellido: ","\nError,apellido invalido",2,MAX_CARACTER,3,aPaciente[lugarDisponible].apellido)==0)
            {
                if(getDni("\nIngrese DNI: ","\nError,DNI invalido",1,100,3,aPaciente[lugarDisponible].DNI)==0)
                {
                    if(getInt("\nIngrese edad: ","Error,edad invalida",120,0,3,&aPaciente[lugarDisponible].edad)==0)
                    {
                        aPaciente[lugarDisponible].estado=HABILITADO;
                        retorno=0;
                    }
                 }
             }
         }
    }
    else
    {
        printf("\n No hay lugar libre");
    }
    return retorno;
}

int aso_buscaLugarLibre(Asociado* aPaciente,int limite,int* posicionVacia)
{
    int i;
    int retorno=-1;

    for(i=0;i<limite;i++)
    {
        if(aPaciente[i].estado==VACIO)
        {
            *posicionVacia=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}

int getName (char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos, char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(mensaje != NULL && mensajeError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {
        if(getString(mensaje,mensajeError,minimo,maximo,reintentos,bufferStr)==0)
        {
            if(isValidNombre(bufferStr)==TRUE)
            {
                strncpy(resultado, bufferStr,maximo);
                retorno = 0;
            }
            else
            {
                printf ("%s",mensajeError);
                reintentos--;
            }
        }
    }
    return retorno;
}

int isValidNombre(char *cadena)
{
    int retorno= TRUE;
    int i;

    for(i=0;cadena[i]!= '\0';i++)
    {
        if((cadena[i] <'A' || cadena[i] >'Z') && (cadena[i] <'a' || cadena[i] >'z'))
        {
            if(cadena[i]<= '9' && cadena[i]>='0')
            {
                retorno= FALSE;
            }
        }
    }
    return retorno;
}

int isValidIntArray(char* cadena)
{
    int i;
    int retorno=1;

    for(i=0;cadena[i]!='\0';i++)
    {
        if(cadena[i]<'0' || cadena[i]>'9')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

int getString(char *mensaje,char *mensajeError,char minimo,char maximo,int reintentos,char *resultado)
{
    char buffer[MAX_CARACTER];
    int retorno=-1;

    if(mensaje!=NULL && mensajeError!=NULL && minimo<maximo && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            printf("%s",mensaje);
            fgets(buffer,sizeof(buffer),stdin);
            buffer[strlen(buffer)-1]= '\0';
            if(strlen(buffer)<=maximo && strlen(buffer)>=minimo)
            {
                strncpy(resultado,buffer,maximo);
                retorno=0;
                break;
            }
            reintentos--;
        }while(reintentos>=0);
    }
     return retorno;
}

int getDni(char *msj,char *msjError,int minimo,int maximo,int reintentos,char *resultado)
{
    int retorno = -1;
    char bufferDNI[4000];
    if(msj != NULL && msjError!=NULL && minimo<maximo && reintentos>=0 && resultado!=NULL)
    {
        if(getString(msj,msjError,minimo,maximo,reintentos,bufferDNI)==0)
        {
            if(isValidIntArray(bufferDNI)==TRUE)
            {
               strncpy(resultado,bufferDNI,maximo);
                retorno = 0;
            }
            else
            {
                printf ("%s",msjError);
                reintentos--;
            }

        }
    }
    return retorno;
}

int getInt(char *mensaje,char *mensajeError,int maximo,int minimo,int reintentos,int* resultado)
{
    int auxiliar;
    int i;
    int retorno=-1;
        if(mensaje!=NULL &&
            mensajeError!=NULL &&
            maximo>minimo &&
            reintentos>=0 &&
            resultado!=NULL)
        {
            for(i=0;i<reintentos;i++)
            {
                printf("%s",mensaje);
                scanf("%d",&auxiliar);
                if(!isValidInt(auxiliar,maximo))
                {
                    *resultado=auxiliar;
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",mensajeError);
                }
            }
        }

    return retorno;
}

int isValidInt(int numero, int maximo)
{
    int i;
    int retorno=TRUE;
    for(i=0;i<maximo;i++)
    {
        if(numero<'0' || numero>'9')
        {
            retorno=FALSE;
        }
    }
    return retorno;
}
int aso_initArray(Asociado* paciente,int limite)
{
    int i;
    int retorno=1;

    for(i=0;i<limite;i++)
    {
        paciente[i].estado=VACIO;
        retorno=0;
    }
    return retorno;
}
void aso_muestra(Asociado* paciente,int limite)
{
    int i;

}
#endif // ASOCIADO_C_INCLUDED
