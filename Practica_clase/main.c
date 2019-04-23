#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesUTN.h"
#include "misValid.h"
#define MAX 3000
#define TRUE 1
#define FALSE 0
#define MAX_TELEFONO 20

int getDomicilio(char* mensaje,char* mensajeAltura,char* mensajeError,char maximo,char minimo,int reintentos,char* resultado);

int main()
{
    char numero[50];

    if(getDomicilio("Ingrese calle: ","Ingrese la altura: ","Domicilio invalido\n",50,1,3,numero)==0)
    {
        printf("Su domicilio es: %s",numero);
    }
    else
    {
        printf("ERROR");
    }
    return 0;
}

int getDomicilio(char* mensaje,char* mensajeAltura,char* mensajeError,char maximo,char minimo,int reintentos,char* resultado)
{
    char calle[100];
    char altura[10];
    int retorno=-1;

    if(mensaje!=NULL && mensajeAltura!=NULL && mensajeError!=NULL && maximo>minimo && reintentos>=0 && resultado!=NULL)
    {
        if(!getApellido(mensaje,mensajeError,maximo,minimo,reintentos,calle))
        {
            strncpy(resultado,calle,maximo);

            if(!getStringInt(mensaje,mensajeError,maximo,minimo,reintentos,altura))
            {
                if(isValidStringNumber(altura)==TRUE)
                {
                    strncpy(resultado,altura,maximo);
                    retorno=0;
                    //break;
                }
            }

        }
         else
        {
            printf("%s",mensajeError);
        }

    }
    return retorno;
}
















/* PREGUNTAR POR LA VALIDACION DEL MAIL PARA QUE SOLO ME TOME 1 @
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
    }
    return retorno;
}
*/







