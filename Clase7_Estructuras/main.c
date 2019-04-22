#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesUTN.h"
#include "misValid.h"
#define EMPLEADOS 10
#define MAXIMO_CARACTER 50

int muestraArray(char arrayStr[][50],int limite);//cada uno de los elements puede tener 50 caracteres
int iniciarlizarArrays(char arrayStr [] [50], int limite);
int encuentraPosVacia(char arrayStr [] [50], int limite);
int buscaSiYaExiste(char arrayStr [] [MAXIMO_CARACTER],char* nombre,int* posicionNombreExistente,int limite);

int main()
{
    char arrayNombres[EMPLEADOS][50];
    int posicionRepetida;
    iniciarlizarArrays(arrayNombres,EMPLEADOS);


    strncpy(arrayNombres[0],"CARLA",EMPLEADOS);
    strncpy(arrayNombres[1],"KAREN",EMPLEADOS);
    strncpy(arrayNombres[2],"LUCAS",EMPLEADOS);
    strncpy(arrayNombres[3],"EMILCE",EMPLEADOS);

    //muestraArray(arrayNombres,EMPLEADOS);
    //encuentraPosVacia(arrayNombres,EMPLEADOS);
   if(buscaSiYaExiste(arrayNombres,"GUstavo",&posicionRepetida,MAXIMO_CARACTER)==0)
    {
        printf("%d",posicionRepetida);
    }
    else
    {
        printf("Nombre disponible");
    }

    return 0;
}

int iniciarlizarArrays(char arrayStr [] [MAXIMO_CARACTER], int limite)
{
    int i;

    for(i=0;i<limite;i++)
    {
        strncpy(arrayStr[i],"\0",MAXIMO_CARACTER);
    }

    return 0;
}

int muestraArray(char arrayStr[][MAXIMO_CARACTER],int limite)
{
    int i;

      for(i=0;i<limite;i++)
    {
        printf("%s",arrayStr[i]);
    }
    return 0;
}

int encuentraPosVacia(char arrayStr [] [MAXIMO_CARACTER], int limite)
{
    int i;
    int retorno=-1;

    for(i=0;i<limite;i++)
    {
        if(strncmp(arrayStr[i],"\0",MAXIMO_CARACTER)==0)
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

int buscaSiYaExiste(char arrayStr [] [MAXIMO_CARACTER],char* nombre,int* posicionNombreExistente,int limite)
{

    int i;
    int retorno=-1;

    for (i=0;i<limite;i++)
    {
        if(strncmp(arrayStr[i],nombre,MAXIMO_CARACTER)==0)
        {
            *posicionNombreExistente=i;
            retorno=0;
            break;
        }
    }
    return retorno;

}

