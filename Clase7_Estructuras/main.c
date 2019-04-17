#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesUTN.h"
#include "misValid.h"
#define QTY_EMPLEADOS 10

int muestraArray(char arrayStr[][50],int limite);//cada uno de los elements puede tener 50 caracteres
int iniciarlizarArrays(char arrayStr [] [50], int limite);
int encuentraPosVacia(char arrayStr [] [50], int limite);

int main()
{
    //char auxName[500] = "test";

    char arrayNombres[QTY_EMPLEADOS][50];


    strncpy(arrayNombres[0],"\nJUAN0",50);
    strncpy(arrayNombres[1],"\nJUAN1",50);
    strncpy(arrayNombres[2],"\nJUAN2\n",50);

    muestraArray(arrayNombres,3);
    if(encuentraPosVacia(arrayNombres,50)==0)
    {
        printf("%d",QTY_EMPLEADOS[i]);

    }
   /* if(getName( "Nombre?: ",
                "Error",
                2,
                5,
                2,
                auxName) == 0)
    {
        printf("OK: %s",auxName);
    }
    else
    {
        printf("ER: %s",auxName);
    }*/
    return 0;
}

int muestraArray(char arrayStr[][50],int limite)
{
    int i;

      for(i=0;i<limite;i++)
    {
        printf("%s",arrayStr[i]);
    }


    return 0;
}

int iniciarlizarArrays(char arrayStr [] [50], int limite)
{
    int i;

    for(i=0;i<limite;i++)
    {
        strncpy(arrayStr[i],"\0",50);
    }

    return 0;
}

int encuentraPosVacia(char arrayStr [] [50], int limite)
{
    int i;
    int retorno=-1;

    for(i=0;i<limite;i++)
    {
        if(strcmp(arrayStr[i],"\0")==0)
        {

            retorno=i;

            break;
         }
         else
         continue;


    }


    return retorno;
}

