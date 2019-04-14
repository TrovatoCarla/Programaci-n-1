#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesUTN.h"
#include "misValid.h"
#define MAX 3000
#define TRUE 1
#define FALSE 0
int getMail(char* mensaje,char* mensajeError,char maximo,char minimo,int reintentos,char* resultado);
int isValidMail(char* cadena);

int main()
{
    char email[10];

    if(getMail("Ingrese mail: ","Mail invalido\n",50,2,3,email)==0)
    {
        printf("Su mail es: %s",email);
    }
    else
    {
        printf("ERR %s",email);
    }
    return 0;
}

int getMail(char* mensaje,char* mensajeError,char maximo,char minimo,int reintentos,char* resultado)
{
    int retorno=-1;
    char buffer[4000];

    if(!getString(mensaje,mensajeError,maximo,minimo,reintentos,buffer))
    {
        if(isValidMail(buffer))
        {
            strncpy(resultado,buffer,maximo);
            retorno=0;
        }
    }
    return retorno;

}

int isValidMail(char* cadena)
{
    int retorno=FALSE;
    int i;
    int flag=0;
    for(i=0;cadena[i]!='\n';i++)
    {
        if((cadena[i]>'a' && cadena[i]<'z') &&
            (cadena[i]>='0' && cadena<='9') &&
            (cadena[i]='.') &&
            (cadena[i]='_') &&
            (cadena[i]='-'))
        {
            retorno=TRUE;
        }
        if((flag==0) && (cadena[i]='@'))
        {
            flag=1;
        }

    }
    return retorno;
}







