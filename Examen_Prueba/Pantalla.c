//#ifndef PANTALLA_C_INCLUDED
#define PANTALLA_C_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Pantalla.h"
#include "Publicidad.h"
#define MAX_ID 10
#define MAX_CARACTER 50
#define TRUE 1
#define FALSE 0

int pan_modificacion(Pantalla* pantallas,char limite)
{
    int retorno=1;
    int i;
    int bufferId;
    int opcion;
    char seguir='s';
    char auxNuevoNombre[MAX_CARACTER];
    char auxNuevaDireccion[MAX_CARACTER];
    float auxNuevoPrecio;
    char auxNuevoTipo[10];

    muestraArrayPantalla(pantallas,MAX_ID);


    if(buscarId(pantallas,MAX_ID,"\nIngrese el ID a modificar ","\nError,ID incorrecto",1000,0,3,&bufferId)==0)
    {
        i=bufferId;
        while(seguir=='s')
        {
            printf("\n 1- Nombre");
            printf("\n 2- Direccion");
            printf("\n 3- Precio");
            printf("\n 4- Tipo de pantalla");
            printf("\n 5- Salir de Modificaciones");
            do
            {
                printf("\n\n       INDIQUE EL DATO QUE DESEA MODIFICAR: ");
                scanf("%d",&opcion);
            }while(opcion<1 || opcion>4);

                switch(opcion)
                {
                    case 1:
                        if(getName("\n\n   Ingrese nombre: ","Error",2,50,3,auxNuevoNombre)==0)
                        {
                            strncpy(pantallas[i].nombre,auxNuevoNombre,MAX_CARACTER);
                            printf("\n      NOMBRE MODIFICADO CORRECTAMENTE\n");
                            break;
                        }
                    case 2:
                        if(getString("\n\n  Ingrese direccion: ","Error",2,50,3,auxNuevaDireccion)==0)
                        {
                            strncpy(pantallas[i].direccion,auxNuevaDireccion,MAX_CARACTER);
                            printf("\n\n      DIRECCION MODIFICADA CORRECTAMENTE\n");
                            break;
                        }
                    case 3:
                        if(getFloat("\n\n    Ingrese precio: ","Error",1,999999,3,&auxNuevoPrecio)==0)
                        {
                            pantallas[i].precio=auxNuevoPrecio;
                            printf("\n\n      PRECIO MODIFICADO CORRECTAMENTE\n");
                            break;
                        }
                    case 4:
                        if(getString("\n\n  Ingrese tipo de pantalla Led o LCD: ","Error",3,6,3,auxNuevoTipo)==0)
                        {
                            strncpy(pantallas[i].tipo,auxNuevoTipo,MAX_CARACTER);
                            printf("\n\n     Tipo de pantalla modificado correctamente\n");
                            break;
                        }
                    case 5:
                        seguir='n';
                        break;
                }
        }
             retorno=0;
    }
    return retorno;
}

int pan_baja(Pantalla* pantallas,char limite)
{

    int posicionAdarDeBaja;
    int retorno=-1;
    muestraArrayPantalla(pantallas,MAX_ID);

    switch (buscarId(pantallas,MAX_ID,"\nIngrese el ID a dar de baja ","\nError,ID incorrecto",1000,0,3,&posicionAdarDeBaja))
    {
        case 0:
            pantallas[posicionAdarDeBaja].isEmpty=1;
            retorno=0;
            break;
        case 1:
            printf("\n      ID NO ENCONTRADO PARA LA BAJA");
            break;
    }
    return retorno;
}

int pan_alta(Pantalla* pantallas,char* msjError,int limite,int posicionLibre)
{
    int retorno=1;
   // int auxID=0;

    if(!buscaVacio(pantallas,MAX_ID,&posicionLibre))
    {
        if(!getName("\n Ingrese su nombre: ","\nERROR, no es un nombre",2,50,3,pantallas[posicionLibre].nombre))
        {
            if(!getString("\n Ingrese su direccion: ","Error",5,250,3,pantallas[posicionLibre].direccion))
            {
                if(!getFloat("\n Ingrese precio: ","Error",0,5000,3,&pantallas[posicionLibre].precio))
                {
                    if(!getString("\n Ingrese tipo de pantalla LCD o Led: ","Error",3,6,3,pantallas[posicionLibre].tipo))
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

int initArrayPantalla(Pantalla* pantallas,int limite)
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

void muestraArrayPantalla(Pantalla* pantallas,int limite)
{
    int i;

     for(i=0;i<limite;i++)
     {
        if(pantallas[i].isEmpty==0)
        {
            printf("\n\nPosicion %d : NOMBRE: %s",i,pantallas[i].nombre);
            printf("\n\n            : DIRECCION: %s",pantallas[i].direccion);
            printf("\n\n            : PRECIO: %.2f",pantallas[i].precio);
            printf("\n\n            : TIPO DE PANTALLA: %s",pantallas[i].tipo);
            printf("\n\n            : ID: %d\n",pantallas[i].idPantalla);
        }
    }
    //return 0;
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
