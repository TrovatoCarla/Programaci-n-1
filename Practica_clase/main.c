#include <stdio.h>
#include <stdlib.h>
#include "funcionesUTN.h"
int getChar(char *mensaje,char *mensajeError,char maximo,char minimo,int reintentos,char *resultado);
int isValidChar(char letra, char maximo, char minimo);

int main()
{
    char letra;
    int respuesta;
    respuesta=getChar("\nIngrese opcion A B o C","Error","z","a",3,&letra);
    if(respuesta==0)
    {
        printf("\nLa opcion ingresada: %c",letra);
    }

    return 0;
}

int getChar(char *mensaje,char *mensajeError,char maximo,char minimo,int reintentos,char *resultado)
{
    char buffer;
    int retorno=-1;

        if(mensaje!=NULL && mensajeError!=NULL && maximo>=minimo && reintentos>0 && resultado!=NULL)
        {
           do
           {
               printf("%s",mensaje);
               scanf("%c",&buffer);
               if(isValidChar(buffer,maximo,minimo))
               {
                   *resultado=buffer;
                   retorno=0;
                   break;
               }
               else
                printf("%s",mensajeError);
           }while(reintentos>=0);
        }
    return retorno;
}

int isValidChar(char letra, char maximo, char minimo)
{
    if(letra >= minimo && letra <= maximo)
    {
        return 1;
    }
    return 0;
}

