//#ifndef PANTALLA_C_INCLUDED
#define PANTALLA_C_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Pantalla.h"
#define MAX_ID 10
#define MAX_CARACTER 50
#define TRUE 1
#define FALSE 0


int pan_alta(Pantalla* pantallas,char* msjError,int limite,int posicionLibre)
{
    int retorno=1;
    //char auxNombre[50];
    //char auxDireccion[250];
    //float auxPrecio;
    //char auxTipo[5];

    if(buscaVacio(pantallas,MAX_ID,&posicionLibre)==0)
    {
        if(getName("\n Ingrese su nombre: ","Error1",2,50,3,pantallas[posicionLibre].nombre)==0)
        {
            if(getString("\n Ingrese su direccion: ","Error2",5,250,3,pantallas[posicionLibre].direccion)==0)
            {
                if(getFloat("\n Ingrese precio: ","Error3",0,5000,3,&pantallas[posicionLibre].precio)==0)
                {
                    if(getString("\n Ingrese tipo de pantalla LCD o Led: ","Error4",3,6,3,pantallas[posicionLibre].tipo)==0)
                    {
                        pantallas[posicionLibre].isEmpty=0;
                        retorno=0;
                    }
                     else
                    {
                        printf("Error,no se pudo cargar");
                    }
                }
            }
        }
    }
    return retorno;
}

int initArray(Pantalla* pantallas,int limite)
{
    int i;

    for(i=0;i<limite;i++)
    {
        pantallas[i].isEmpty=1;
    }
    return 0;
}

int buscaVacio(Pantalla* pantallas,int limite,int* posicionVacia)
{
    int i;
    int retorno=1;

    for(i=0;i<limite;i++)
    {
        if(pantallas[i].isEmpty==1)
        {
            *posicionVacia=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}

void muestraArray(Pantalla* pantallas,int limite,char* mensajeError)
{
    int i;

     for(i=0;i<limite;i++)
     {
        if(pantallas[i].isEmpty==0)
        {
            printf("\n\nPosicion %d : NOMBRE: %s",i,pantallas[i].nombre);
            printf("\n\n            : DIRECCION: %s",pantallas[i].direccion);
            printf("\n\n            : PRECIO: %f",pantallas[i].precio);
            printf("\n\n            : TIPO DE PANTALLA: %s",pantallas[i].tipo);
            printf("\n\n            : ID: %d\n",pantallas[i].idPantalla);
        }
    }
}

int buscarId(Pantalla* pantallas,int limite,char* msj,char* msjError,int maximo,int minimo,int reintentos,int* idEncontrado)
{
    int i;
    int retorno=1;
    int buffer;

    if(getInt(msj,msjError,minimo,maximo,reintentos,&buffer)==0)
    {
        for(i=0;i<limite;i++)
        {
            if(pantallas[i].idPantalla==buffer)
            {
                *idEncontrado=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

int getInt(char *message, char *errorMessage, int minimum, int maximum, int retries, int *input)
{
    int returnValue = -1;
    int buffer;
    if(message != NULL && errorMessage != NULL && input != NULL && maximum >= minimum && retries >= 0)
    {
        do
        {
            printf("%s", message);
            scanf("%d", &buffer);
            if(isValidInt(buffer,minimum,maximum)==1)
            {
                *input = buffer;
                returnValue = 0;
                break;
            }else
            {
                printf("%s", errorMessage);
            }
            retries--;
        }while(retries >= 0);
    }
    return returnValue;
}

int isValidInt(int number, int minimum, int maximum)
{
    if(number >= minimum && number <= maximum)
    {
        return 1;
    }else
    {
        return 0;
    }
}

int getName (char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {
        if(getString(msg,msgError,minimo,maximo,reintentos,bufferStr)==0)
        {
            if(isValidNombre(bufferStr)==TRUE)
            {
                strncpy(resultado, bufferStr,maximo);
                retorno = 0;
            }
            else
            {
                printf ("%s",msgError);
            }
            reintentos--;
        }
    }
    return retorno;
}

int getString (char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {
        do
        {
            printf("%s",msg);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1] = '\0';
            if(strlen(bufferStr)>=minimo && strlen(bufferStr) <maximo)
            {
                strncpy(resultado,bufferStr,maximo);
                retorno = 0;
                break;
            }
            reintentos--;
           /// printf("%s",msgError);
        }while(reintentos>=0);
    }
    return retorno;
}

int isValidFloat(float number, float minimum, float maximum)
{
    if(number >= minimum && number <= maximum)
    {
        return 1;
    }
    return 0;
}

int getFloat(char *message, char *errorMessage, float minimum, float maximum, int retries, float *input)
{
    int returnValue = -1;
    float buffer;
    if(message != NULL && errorMessage != NULL && input != NULL && maximum>=minimum && retries >= 0)
    {
        do
        {
            printf("%s", message);
            scanf("%f", &buffer);
            if(isValidFloat(buffer, minimum, maximum))
            {
                *input = buffer;
                returnValue = 0;
                break;
            }else
            {
                printf("%s", errorMessage);
            }
            retries--;
        }while(retries >= 0);
    }
    return returnValue;
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

//#endif // PANTALLA_C_INCLUDED
