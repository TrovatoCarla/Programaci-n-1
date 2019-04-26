#ifndef PANTALLA_C_INCLUDED
#define PANTALLA_C_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_ID 10

typedef struct
{
    int idPantalla;
    int isEmpty;
    char nombre[50];
    char direccion[250];
    float precio;
    char tipo [5];
}Pantalla;

typedef struct
{
    int idPublicidad;
    int isEmpty;
    char cuit[20];
    int dias;
    char archivo[250];
    int idPantalla;
}Publicidad;

int pan_alta(Pantalla* pantallas,char* msjError,int limite)
{
    int retorno=1;
    char auxNombre[50];
    char auxDireccion[250];
    float auxPrecio;
    char auxTipo[5];
    int posicionLibre=-1;

    if(buscaVacio(pantallas,MAX_ID)==0)
    {
        if(getName("Ingrese su nombre","Error",2,50,3,auxNombre)==0)
        {
            if(getString("Ingrese su direccion: ","Error",5,250,auxDireccion)==0)
            {
                if(getFloat("Ingrese precio: ","Error",0,5000,3,auxPrecio)==0)
                {
                    if(getString("Ingrese tipo de pantalla LCD o Led: ","Error",3,6,3,auxTipo)==0)
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

int buscaVacio(Pantalla* pantallas,int limite)
{
    int i;
    int retorno=1;

    for(i=0;i<limite;i++)
    {
        if(pantallas[i].isEmpty==1)
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

int muestraArray(Pantalla* pantallas,int limite,char* mensajeError)
{
    int retorno=1;
    int i;

     for(i=0;i<limite;i++)
     {
        if(pantallas[i].isEmpty==0)
        {
            printf("Posicion %d : Nombre: %s",i,pantallas[i].nombre);
            printf("Posicion %d : direccion: %s",i,pantallas[i].direccion);
            printf("Posicion %d : precio: %f",i,pantallas[i].precio);
            printf("Posicion %d : tipo: %s",i,pantallas[i].tipo);
            retorno=0;
        }
        else
        {
            printf("%s",mensajeError);
        }
     }
    return retorno;
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
            if(isValidInt(buffer, minimum, maximum))
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
        if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
        {
            if(isValidName(bufferStr))
            {
                strncpy(resultado, bufferStr,maximo);
                retorno = 0;
            }
            else
            {
                reintentos--;
                printf ("%s",msgError);
            }
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
            printf("%s",msgError);
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

#endif // PANTALLA_C_INCLUDED
