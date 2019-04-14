#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesUTN.h"
#include "misValid.h"
#define MAX 3000
#define TRUE 1
#define FALSE 0

int isValidApellido(char* cadena);
int getApellido(char* msg,char* msgError,char maximo,char minimo,int reintentos,char* resultado);

int main()
{
    char apellido[10];

    if(getApellido("Ingrese apellido: ","ERROR",10,2,3,apellido)==0)
    {
        printf("Su apellido es: %s",apellido);
    }
    else
    {
        printf("ERR %s",apellido);
    }
    return 0;
}











