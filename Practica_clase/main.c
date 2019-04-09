#include <stdio.h>
#include <stdlib.h>
#include "funcionesUTN.h"

int main()
{
    float numero;
    int respuesta;
    respuesta=getFloat("\nIngrese un numero ","Error,numero invalido",10,1,2,&numero);
    if(respuesta==0)
    {
        printf("\nNumero ingresado: %.1f",numero);
    }


    return 0;
}


