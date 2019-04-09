#include <stdio.h>
#include <stdlib.h>
#include "funcionesUTN.h"

int getInt(char *mensaje,char *mensajeError,int maximo,int minimo,int reintentos,int *resultado)
{
    int auxiliar;
    int i;
    int retorno=-1;
        if(mensaje!=NULL &&
            mensajeError!=NULL &&
            maximo>=minimo &&
            reintentos>=0 &&
            resultado!=NULL)

            for(i=0;i<reintentos;i++)
            {
                printf("%s",mensaje);
                scanf("%d",&auxiliar);
                if(isValidInt(auxiliar,maximo,minimo))
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


    return retorno;
}

int isValidInt(int numero, int maximo, int minimo)
{
    if(numero >= minimo && numero <=maximo)
    {
        return 1;
    }
        return 0;
}

int getFloat(char *mensaje,char *mensajeError,float maximo,float minimo,int reintentos,float *resultado)
{
    float auxiliar;
    int i;
    int retorno=-1;

        if(mensaje!=NULL && mensajeError!=NULL && maximo>=minimo && reintentos>=0 && resultado!=NULL)
        {
            for(i=0;i<reintentos;i++)
            {
                printf("%s",mensaje);
                scanf("%f",&auxiliar);
                if(isValidFloat(auxiliar,maximo,minimo))
                {
                    *resultado=auxiliar;
                    retorno=0;
                    break;
                }
                else
                    printf("%s",mensajeError);
            }
        }
    return retorno;
}
int isValidFloat(float numero, float maximo, float minimo)
{
    if(numero >= minimo && numero <= maximo)
    {
        return 1;
    }

    return 0;
}




