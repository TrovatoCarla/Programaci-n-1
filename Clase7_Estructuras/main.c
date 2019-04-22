#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesUTN.h"
#include "misValid.h"
#define EMPLEADOS 10

int muestraArray(char arrayStr[][50],int limite);//cada uno de los elements puede tener 50 caracteres
int iniciarlizarArrays(char arrayStr [] [50], int limite);
int encuentraPosVacia(char arrayStr [] [50], int limite);

int main()
{
    char arrayNombres[EMPLEADOS][50];

    iniciarlizarArrays(arrayNombres,EMPLEADOS);

    strncpy(arrayNombres[0],"CARLA\n",EMPLEADOS);
    strncpy(arrayNombres[1],"KAREN\n",EMPLEADOS);
    strncpy(arrayNombres[2],"LUCAS\n",EMPLEADOS);
    strncpy(arrayNombres[3],"EMILCE\n",EMPLEADOS);

    //muestraArray(arrayNombres,EMPLEADOS);
    encuentraPosVacia(arrayNombres,EMPLEADOS);

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

int muestraArray(char arrayStr[][50],int limite)
{
    int i;

      for(i=0;i<limite;i++)
    {
        printf("%s",arrayStr[i]);
    }
    return 0;
}

int encuentraPosVacia(char arrayStr [] [50], int limite)
{
    int i;
    int retorno=-1;

    for(i=0;i<limite;i++)
    {
        if(strncmp(arrayStr[i],"\0",50)==0)
        {
            retorno=0;
            printf("%d",i);
            break;
         }
        else
            continue;
    }
    return retorno;
}

int buscaSiYaExiste(char arrayStr [] [50],char* aux,int limite)
{
    //char aux;
    int i;
    int retorno=-1;

    for (i=0;i<limite;i++)
    {
        if(strncmp(arrayStr[i],aux,50)==0)
        {
            retorno=0;
        }
        else
            continue;
    }
    return retorno;

}

