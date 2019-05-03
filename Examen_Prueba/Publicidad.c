#ifndef PUBLICIDAD_C_INCLUDED
#define PUBLICIDAD_C_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Publicidad.h"
#include "Pantalla.h"
#define MAX_ID 10
#define MAX_CARACTER 50


int pub_alta(Publicidad* publicidades,Pantalla* pantallas,int limite,int posicionEncontrada)
{
    int retorno=1;

    muestraArrayPantalla(pantallas,MAX_ID);

    if(getInt("\nIngrese ID de la pantalla que desea contratar","\nError,ID inexistente",1,100,3,&publicidades[posicionEncontrada].idPublicidad))
    {
        if(getCuit("\n Ingrese su cuit: ","\nERROR, no es un cuit",9,20,3,publicidades[posicionEncontrada].cuit)==0)
        {
            if(getInt("\n Ingrese cantidad de dias de publicacion: ","Error",1,100,3,&publicidades[posicionEncontrada].dias)==0)
            {
                if(getString("\n Ingrese nombre del archivo video: ","Error",0,500,3,publicidades[posicionEncontrada].archivo)==0)
                {
                        publicidades[posicionEncontrada].isEmpty=0;
                        //pantallas[posicionLibre].idPantalla=auxID;
                        retorno=0;
                }
                else
                {
                    printf("Error,no se pudo cargar publicidad");
                }
            }
        }
    }
    return retorno;
}


int pub_baja(Publicidad* publicidades,Pantalla* pantallas,char limite)
{
    int posicionAdarDeBaja;
    int retorno=-1;

    muestraArrayPublicidad(publicidades,MAX_ID);

    switch (buscarPantallaPorID(pantallas,MAX_ID,"\nIngrese el ID a dar de baja ","\nError,ID incorrecto",1000,0,3,&posicionAdarDeBaja))
    {
        case 0:
            publicidades[posicionAdarDeBaja].isEmpty=1;
            retorno=0;
            break;
        case 1:
            printf("\n      ID NO ENCONTRADO PARA LA BAJA");
            break;
    }
    return retorno;
}

int pub_modificacion(Publicidad* publicidades,Pantalla* pantallas,char limite)
{
    int retorno=1;
    int i;
    int bufferId;
    int opcion;
    char seguir='s';
    char auxNuevoCuit[MAX_CARACTER];
    char auxNuevoArchivo[MAX_CARACTER];
    int auxNuevosDias=0;

    muestraArrayPantalla(pantallas,MAX_ID);

    if(buscarPantallaPorID(pantallas,MAX_ID,"\nIngrese el ID a modificar ","\nError,ID incorrecto",1000,0,3,&bufferId)==0)
    {
        i=bufferId;
        while(seguir=='s')
        {
            printf("\n 1- Cuit");
            printf("\n 2- Dias de contratacion");
            printf("\n 3- Archivo");
            printf("\n 4- Salir de Modificaciones");
            do
            {
                printf("\n\n       INDIQUE EL DATO QUE DESEA MODIFICAR: ");
                scanf("%d",&opcion);
            }while(opcion<1 || opcion>4);

                switch(opcion)
                {
                    case 1:
                        if(!getCuit("\n\n   Ingrese el nuevo Cuit: ","Error",10,20,3,auxNuevoCuit))
                        {
                            strncpy(publicidades[i].cuit,auxNuevoCuit,MAX_CARACTER);
                            printf("\n      CUIT MODIFICADO CORRECTAMENTE\n");
                            break;
                        }
                    case 2:
                        if(!getInt("\n\n  Ingrese dias de contratacion: ","Error",0,1000,3,&auxNuevosDias))
                        {
                            publicidades[i].dias=auxNuevosDias;
                            printf("\n\n      DIAS MODIFICADOS CORRECTAMENTE\n");
                            break;
                        }
                    case 3:
                        if(!getString("\n\n    Ingrese archivo: ","Error",1,999999,3,auxNuevoArchivo))
                        {
                            strncpy(publicidades[i].archivo,auxNuevoArchivo,MAX_CARACTER);
                            printf("\n\n      ARCHIVO MODIFICADO CORRECTAMENTE\n");
                            break;
                        }
                    case 4:
                        seguir='n';
                        break;
                }
        }
             retorno=0;
    }
    return retorno;
}

int buscarPantallaPorID(Pantalla* pantallas,int limite,char* msj,char* msjError,int maximo,int minimo,int reintentos,int* idEncontrado)
{
    int i;
    int retorno=-1;
    int bufferID;


    if(getInt(msj,msjError,minimo,maximo,reintentos,&bufferID)==0)
    {
        for(i=0;i<limite;i++)
        {
            if(pantallas[i].idPantalla==bufferID)
            {
                *idEncontrado=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;


}

int initArrayPublicidad(Publicidad* publicidades,int limite)
{
    int i;

    for(i=0;i<limite;i++)
    {
        publicidades[i].isEmpty=1;
    }
    return 0;
}

int getCuit(char* msj,char* msjError,char minimo,char maximo,int reintentos,char* cuil)
{
    int i;
    char bufferCuit[20];
    int retorno;

    if(msj!=NULL && msjError!=NULL && minimo<maximo && reintentos>=0 && cuil!=NULL)
    {
        for(i=0;i<reintentos;i++)
        {
            if(!getString(msj,msjError,minimo,maximo,reintentos,bufferCuit))
            {
                if(isValidCuit(bufferCuit)==1)
                {
                    strncpy(cuil,bufferCuit,MAX_CARACTER);
                    retorno=0;
                    break;
                }
                else
                    printf("\n\nCuil invaldio");
            }
        }

    }
    return retorno;
}

int isValidCuit(char cadena[])
{
    int i=0;
    int retorno=-1;
    int contadorGuiones=0;

    while(cadena[i]!= '\0')
    {
        if((cadena[i]!=' ') && (cadena[i]<'0' || cadena[i]>'9') && (cadena[i]<'a' || cadena[i]>'z'))
        {
            retorno=0;
        }
        if(cadena[i]=='-')
        {
            contadorGuiones++;
        }
     i++;
    }
       if(contadorGuiones==2)
        {
            retorno=1;
        }
        return retorno;
}

/*int getString (char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado)
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
}*/

void muestraArrayPublicidad(Publicidad* publicidades,int limite)
{
    int i;

     for(i=0;i<limite;i++)
     {
        if(publicidades[i].isEmpty==0)
        {
            printf("\n\nPosicion %d : CUIT: %s",i,publicidades[i].cuit);
            printf("\n\n            : DIAS: %d",publicidades[i].dias);
            printf("\n\n            : ARCHIVO: %s",publicidades[i].archivo);
            printf("\n\n            : ID: %d\n",publicidades[i].idPublicidad);

        }
    }
    //return 0;
}
#endif // PUBLICIDAD_C_INCLUDED
