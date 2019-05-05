#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Asociado.h"
#define VACIO 1
#define HABILITADO 2
#define INHABILITADO 3
#define MAX_ARRAY 10


int main()
{
    Asociado pacientes[MAX_ARRAY];

    char seguir='s';
    int opcion;
    int lugarLibre=1;
    int auxId=0;

    if(aso_initArray(pacientes,MAX_ARRAY)==0)
    {
        printf(" Iniciaizacion correcta\n");
    }

    while(seguir=='s')
    {
        printf("\n MENU\n");
        printf("\n 1- ALTA");
        printf("\n 2- MODIFICAR");
        printf("\n 3- BAJA");
        printf("\n 4- NUEVA LLAMADA");
        printf("\n 5- ASIGNAR AMBULANCIA");
        printf("\n 6- INFORMAR");
        printf("\n 7- SALIR");

        do
        {
            printf("\n\n Ingrese la opcion a realizar: ");
            scanf("%d",&opcion);
        }while(opcion<1 || opcion>7);

        switch(opcion)
        {
            case 1:
                if(aso_alta(pacientes,"\nError",MAX_ARRAY,lugarLibre)==0)
                {
                    printf("\n ALTA EXITOSA");
                    pacientes[lugarLibre].idAsociado=auxId;
                    auxId++;
                }
            break;

        }

    }

    return 0;
}

