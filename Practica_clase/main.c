#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesUTN.h"
#include "misValid.h"
#define MAX 3000
#define TRUE 1
#define FALSE 0
#define MAX_TELEFONO 20

int isValidMail(char* cadena);
int getMail(char* mensaje,char* mensajeError,char maximo,char minimo,int reintentos,char* resultado);

int main()
{
    char numero[50];

    if(getMail("Ingrese mail: ","Mail invalido\n",50,1,3,numero)==0)
    {
        printf("Su mail es: %s",numero);
    }
    else
    {
        printf("ERROR");
    }
    return 0;
}


int getMail(char* mensaje,char* mensajeError,char maximo,char minimo,int reintentos,char* resultado)
{
    int retorno=-1;
    char buffer[4000];

    if(mensaje!=NULL && mensajeError!=NULL && maximo>minimo && reintentos>=0 && resultado!=NULL)
    {
        if(!getString(mensaje,mensajeError,maximo,minimo,reintentos,buffer))
        {
            if(isValidMail(buffer)==TRUE)
            {
                strncpy(resultado,buffer,maximo);
                retorno=0;
            }
            else
            {
                printf("%s",mensajeError);
            }
        }
     }
    return retorno;
}

int isValidMail(char* cadena)
{
    int i;
    int retorno=TRUE;
    int flag=0;

     for(i=0;cadena[i]!='\0';i++)
    {
        if((cadena[i]<'0' || cadena[i]>'9') &&
            (cadena[i]<'a' || cadena [i]>'z') &&
            (cadena[i]<'-' || cadena[i]>'-') &&
            (cadena[i]<'@' || cadena[i]>'@') &&
            (cadena[i]<'.' || cadena[i]>'.') &&
            (cadena[i]<'_' || cadena[i]>'_'))
        {
            retorno=FALSE;
        }
        if(flag==0)
        {
            if(cadena[i]=='@')
            {
                flag=1;
            }
        }
    }
    return retorno;
}








