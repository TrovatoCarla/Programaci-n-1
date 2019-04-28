#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ABM.h"
#include "funcionesUTN.h"
#include "misValid.h"
#define EMPLEADOS 6
#define MAXIMO_CARACTER 100
#define TRUE 1
#define FALSE 0


//Empleado auxiliarEmpleado[500];
///mpleado *pEmpleado;

//pEmpleado=&auxiliarEmpleado[114];
//pEmpleado->apellido;

typedef struct

{
    int idEmpleado;
    int isEmpty;// 1 si esta vacio y 0 si esta cargado
    char nombre[50];
}Empleado;


int main()
{
  int opcion;
  char nombres[EMPLEADOS][MAXIMO_CARACTER];
  char seguir='s';


 /* if(iniciarlizarArrays(nombres,EMPLEADOS)==0)
    {
        printf("\n\nNombres Inicializados correctamente");
    }*/

  while(seguir=='s')
  {
    printf("MENU ");
    printf("\n\n 1 ALTA");
    printf("\n\n 2 BAJA");
    printf("\n\n 3 MOSTRAR");
    printf("\n\n 4 SALIR");

    do
    {
        printf("\n\nIngrese opcion: ");
        scanf("%d",&opcion);
    }while(opcion<1|| opcion>4);

        switch(opcion)
        {
            case 1:

                if(altaDeUsuario("Ingrese nombre ","Nombre invalido ","Ya existe nombre","No hay posicion disponible",50,2,3,nombres)==0)
                {

                    break;

                }

        }




    }



  }











/*
    Empleado primerEmp;

    primerEmp.idEmpleado=1;
    primerEmp.isEmpty=1;
    int lugarLibre;

    strncpy(primerEmp.nombre,"Carla\n",50);

    emp_muestra(&primerEmp,50);

    //emp_initArray(&primerEmp,MAXIMO_CARACTER);

    //emp_muestra(&primerEmp,MAXIMO_CARACTER);
    emp_lugarLibre(&primerEmp,EMPLEADOS,&lugarLibre);
    printf("%d",lugarLibre);

    return 0;*/












