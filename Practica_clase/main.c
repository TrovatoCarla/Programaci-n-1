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
    char email[50];

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

    if(mensaje!=NULL && mensajeError!=NULL && maximo>minimo && reintentos>=0 && resultado!=NULL)
    {
        do//No utiliec getStrin porque esta con valid de nombre
        {
            printf("%s",mensaje);
            fgets(buffer,sizeof(buffer),stdin);
            if((strlen(buffer)<=maximo) && (strlen(buffer)>=minimo))
            {
                if(isValidMail(buffer))
                {
                    strncpy(resultado,buffer,maximo);
                    retorno=0;
                    break;
                }
            }
            reintentos--;
            printf("%s",mensajeError);
        }while(reintentos>=0);
    }
    return retorno;
}

int isValidMail(char* cadena)
{
    int retorno= TRUE;
    int i;
    //int flag=0;

    for(i=0;cadena[i]!='\0';i++)
    {
        if((cadena[i]<'a' || cadena[i]>'z')&&(cadena[i]<'@' || cadena [i]>'@'))
        {
            if(cadena[i]<'0' || cadena[i]>'9')
            {
                retorno=FALSE;
            }

        }
       /*if((flag==1) && (cadena[i]='@'))
            {
                flag=1;
            }*/

    }
    return retorno;
}








