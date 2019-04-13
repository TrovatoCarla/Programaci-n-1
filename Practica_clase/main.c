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
    char nombre[MAX];

    if(getString("Ingrese nombre: ","ERROR",5,2,3,nombre)==0)
    {
        printf("Su nombre es: %s",nombre);
    }
    else
    {
        printf("ERR %s",nombre);
    }
    return 0;
}




