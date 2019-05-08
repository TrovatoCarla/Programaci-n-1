#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Asociado.h"
#include "funcionesUTN.h"
#include "misValid.h"
#define VACIO 1
#define HABILITADO 2
#define INHABILITADO 3
#define MAX_ARRAY 10
#define MAX_CARACTER 50



int main()
{
    Asociado pacientes[MAX_ARRAY];

    char seguir='s';
    int opcion;
    int lugarLibre=-1;
    int auxId;
    int idParaBaja=-1;



    if(aso_initArray(pacientes,MAX_ARRAY)==0)
    {
        printf(" Iniciaizacion correcta\n");
    }

/*
    strncpy(pacientes[0].nombre,"Carla",MAX_CARACTER);
    strncpy(pacientes[0].apellido,"Trovato",MAX_CARACTER);
    strncpy(pacientes[0].DNI,"DNI",MAX_CARACTER);
    pacientes[0].edad=29;
    pacientes[0].idAsociado=0;

    strncpy(pacientes[1].nombre,"karen",MAX_CARACTER);
    strncpy(pacientes[1].apellido,"ramirez",MAX_CARACTER);
    strncpy(pacientes[1].DNI,"DNI",MAX_CARACTER);
    pacientes[1].edad=26;
    pacientes[1].idAsociado=1;

    strncpy(pacientes[2].nombre,"Lucas",MAX_CARACTER);
    strncpy(pacientes[2].apellido,"silva",MAX_CARACTER);
    strncpy(pacientes[2].DNI,"DNI",MAX_CARACTER);
    pacientes[2].edad=27;
    pacientes[2].idAsociado=2;
    aso_muestra(pacientes,MAX_ARRAY);
*/

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
                if(aso_alta(pacientes,"\nError en alta",MAX_CARACTER,lugarLibre)==0)
                {
                    printf("\n ALTA EXITOSA");
                    pacientes[lugarLibre].idAsociado=auxId;
                    auxId++;
                }
                break;

            case 2:
                if(aso_modificacion(pacientes,MAX_ARRAY)==0)
                {
                    printf("\n DATO MODIFICADO CORRECTAMENTE");
                }
                aso_muestra(pacientes,MAX_ARRAY);
                break;
            case 3:

                aso_muestra(pacientes,MAX_ARRAY);
                if(aso_baja(pacientes,MAX_ARRAY,idParaBaja)==0)
                {
                    printf("\n PACIENTE DADO DE BAJA,INHABILITADO");
                }
                break;

        }

    }

    return 0;
}

