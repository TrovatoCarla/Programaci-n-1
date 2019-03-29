#include <stdio.h>
#include <stdlib.h>

int getInt(char *mensaje,char *mensajeError,int minimo,int maximo,int reintentos,int *resultado);
int isValidInt(int numero,int minimo,int maximo);

int main()
{
    int numeroIngresado;
    getInt("Ingrese numero", "error",0,100,2,&numeroIngresado);
    printf("El numero ingresado es: %d", numeroIngresado);
    return 0;
}

int isValidInt(int numero,int minimo,int maximo)
{
    if(numero>=minimo && numero<=maximo)
    {
        return 1;
    }
   // else//NO ES NECESARIO
   //{
        return 0;//HASTA DOS RETORNOS SE PUEDE JUNTOS.3NO
   // }

}

int getInt(char *mensaje,char *mensajeError,int minimo,int maximo,int reintentos,int *resultado)

{
    int buffer;
    int i;
    int retorno=-1;

    if(mensaje!=NULL && mensajeError!=NULL && resultado!=NULL && reintentos>=0 && maximo>=minimo)
    {

        for(i=0;i<=reintentos;i++)
        {
            printf("%s",mensaje);
            scanf("%d",&buffer);
            if(isValidInt(buffer,minimo,maximo))
             {
                *resultado=buffer;
                retorno=0;
                break;
             }
             else
             {
                printf("%s",mensajeError);
            }

        }

    }
    return retorno;
}


