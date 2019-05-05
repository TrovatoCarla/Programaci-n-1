#ifndef ASOCIADO_C_INCLUDED
#define ASOCIADO_C_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "Asociado.h"
#define MAX_ARRAY 10
#define MAX_CARACTER 50
#define TRUE 1
#define FALSE 0
#define VACIO 1
#define HABILITADO 2
#define INHABILITADO 3

int aso_modificacion(Asociado* aPaciente,int limite)
{
    int retorno=1;
    int i;
    int bufferId;
    int opcion;
    char seguir='s';
    char auxNuevoNombre[MAX_CARACTER];
    char auxNuevoApellido[MAX_CARACTER];
    char auxNuevoDNI[MAX_CARACTER];
    int auxNuevaEdad;

    aso_muestra(aPaciente,MAX_ARRAY);

    if(aso_buscarId(aPaciente,MAX_ARRAY,"\nIngrese el ID a modificar ","\nError,ID incorrecto",1000,0,3,&bufferId)==0)
    {
        i=bufferId;
        while(seguir=='s')
        {
            printf("\n 1- Nombre");
            printf("\n 2- Apellido");
            printf("\n 3- DNI");
            printf("\n 4- Edad");
            printf("\n 5- Salir de Modificaciones");
            do
            {
                printf("\n\n       INDIQUE EL DATO QUE DESEA MODIFICAR: ");
                scanf("%d",&opcion);
            }while(opcion<1 || opcion>5);

                switch(opcion)
                {
                    case 1:
                        if(getName("\n\n   Ingrese nombre: ","Error",2,50,3,auxNuevoNombre)==0)
                        {
                            strncpy(aPaciente[i].nombre,auxNuevoNombre,MAX_CARACTER);
                            printf("\n      NOMBRE MODIFICADO CORRECTAMENTE\n");
                            break;
                        }
                    case 2:
                        if(getName("\n\n  Ingrese apellido: ","Error",2,50,3,auxNuevoApellido)==0)
                        {
                            strncpy(aPaciente[i].apellido,auxNuevoApellido,MAX_CARACTER);
                            printf("\n\n      APELLIDO MODIFICADO CORRECTAMENTE\n");
                            break;
                        }
                    case 3:
                        if(getDni("\n\n    Ingrese DNI: ","Error",1,999999,3,auxNuevoDNI)==0)
                        {
                            strncpy(aPaciente[i].DNI,auxNuevoDNI,MAX_CARACTER);
                            printf("\n\n      DNI MODIFICADO CORRECTAMENTE\n");
                            break;
                        }
                    case 4:
                        if(getInt("\n\n  Ingrese edad: ","Error",120,0,3,&auxNuevaEdad)==0)
                        {
                            aPaciente[i].edad=auxNuevaEdad;
                            printf("\n\n     Edad modificada correctamente\n");
                            break;
                        }
                    case 5:
                        seguir='n';
                        break;
                }
        }
             retorno=0;
    }
    else
    {
        printf("\n ID no encontrado");
    }
    return retorno;
}
int aso_buscarId(Asociado* aPaciente,int limite,char* msj,char* msjError,int maximo,int minimo,int reintentos,int* idEncontrado)
{
    int i;
    int retorno=1;
    int buffer;

    if(getInt(msj,msjError,maximo,minimo,reintentos,&buffer)==0)
    {
        for(i=0;i<limite;i++)
        {
            if(aPaciente[i].estado==buffer)
            {
                *idEncontrado=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
int aso_alta(Asociado* aPaciente,char* msjError,int limite,int lugarDisponible)
{
    int retorno=-1;

    if(!aso_buscaLugarLibre(aPaciente,MAX_ARRAY,&lugarDisponible))
    {
        if(!getName("\nIngrese nombre: ","\nError nombre invalido",2,MAX_CARACTER,3,aPaciente[lugarDisponible].nombre))
        {
            if(!getName("\nIngrese apellido: ","\nError,apellido invalido",2,MAX_CARACTER,3,aPaciente[lugarDisponible].apellido))
            {
                if(!getDni("\nIngrese DNI: ","\nError,DNI invalido",1,100,3,aPaciente[lugarDisponible].DNI))
                {
                    if(!getInt("\nIngrese edad: ","Error,edad invalida",120,0,3,&aPaciente[lugarDisponible].edad))
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
void aso_muestra(Asociado* aPaciente,int limite)
{
    int i;

     for(i=0;i<limite;i++)
     {
        if(aPaciente[i].estado==HABILITADO)
        {
            printf("\n\nPosicion %d : NOMBRE: %s",i,aPaciente[i].nombre);
            printf("\n\n            : APELLIDO: %s",aPaciente[i].apellido);
            printf("\n\n            : DNI: %s",aPaciente[i].DNI);
            printf("\n\n            : EDAD: %d",aPaciente[i].edad);
            printf("\n\n            : ID: %d\n",aPaciente[i].idAsociado);
            printf("\n            : ESTADO: HABILITADO\n\n");
        }
    }
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
int aso_initArray(Asociado* aPaciente,int limite)
{
    int i;
    int retorno=1;

    for(i=0;i<limite;i++)
    {
        aPaciente[i].estado=VACIO;
        retorno=0;
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
            __fpurge(stdin);
            fgets(buffer,sizeof(buffer),stdin);
            buffer[strlen(buffer)-1]= '\0';
            if(strlen(buffer)<=maximo && strlen(buffer)>=minimo)
            {
                strncpy(resultado,buffer,maximo);
                retorno=0;
                break;
            }
            reintentos--;
            printf("%s",mensajeError);
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



#endif // ASOCIADO_C_INCLUDED
