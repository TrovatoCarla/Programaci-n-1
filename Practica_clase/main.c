#include <stdio.h>
#include <stdlib.h>
#include "funcionesUTN.h"
int getChar(char *mensaje,char *mensajeError,char maximo,char minimo,int reintentos,char *resultado);
int isValidChar(char letra, char maximo, char minimo);

int main()
{
    char letra;
    int respuesta;
    respuesta=getChar("\nIngrese opcion a b o c : ","Error",'z','a',3,&letra);
    if(respuesta==0)
    {
        printf("\nLa opcion ingresada: %c",letra);
    }

    return 0;
}





