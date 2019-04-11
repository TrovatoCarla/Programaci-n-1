#include <stdio.h>
#include <stdlib.h>
#include "funcionesUTN.h"
int getString(char *input,char *msg,char *msgError,int maximo,int minimo);

int main()
{
    char buffer[10];
    char cadena[10];
    int r;
    r=getString(cadena,"nombre: ","El largo debe ser entre 0 y 10",10,0);
    if(r==0)
    {
        printf("%s",buffer);
    }
    return 0;
}

int getString(char *input,char *msg,char *msgError,int maximo,int minimo)
{
    char algo[10];
    int retorno=1;

    if(input!=NULL && msg!=NULL && msgError!=NULL && maximo>=minimo)
    {
        retorno=0;

    }
    else
        printf("Error");


     return retorno;
}
