#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesUTN.h"
#include "misValid.h"
#define MAX 3000
#define TRUE 1
#define FALSE 0


int main()
{
    char numero[50];

    if(getInt("Ingrese mail: ","Mail invalido\n",50,2,3,numero)==0)
    {
        printf("Su numero es: %s",numero);
    }
    else
    {
        printf("ERR %s",numero);
    }
    return 0;
}
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




/*int getTelefono(char* msj,char* msjError,char maximo,char minimo,int reintentos,char* resultado)
{
    char buffer[20];
    int retorno=-1;

    if(msj!=NULL && msjError!=NULL && maximo>minimo && reintentos>=0 && resultado!=NULL)
    {
        if()

    }


}


/*int getMail(char* mensaje,char* mensajeError,char maximo,char minimo,int reintentos,char* resultado)
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
    int flag=0;

    for(i=0;cadena[i]!='\0';i++)
    {
        if((cadena[i]<'a' || cadena[i]>'z')&&(cadena[i]<'@' || cadena [i]>'@'))
        {
            if(cadena[i]<'0' || cadena[i]>'9')
            {
                retorno=FALSE;
            }

        }
       if((flag==1) && (cadena[i]='@'))
            {
                flag=1;
            }

    }
    return retorno;
}
*/







