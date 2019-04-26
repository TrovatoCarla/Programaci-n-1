#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ID 10
#define MAXIMO_CARACTER 50
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

int initArray(Pantalla* pantallas,int limite);
int buscaVacio(Pantalla* pantallas,int limite);
int muestraArray(Pantalla* pantallas,int limite,char* mensajeError);
int buscarId(Pantalla* pantallas,int limite,char* msj,char* msjError,int maximo,int minimo,int reintentos,int* idEncontrado);
int getInt(char *message, char *errorMessage, int minimum, int maximum, int retries, int *input);
int isValidInt(int number, int minimum, int maximum);



int main()
{


    return 0;
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
