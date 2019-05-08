#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Autores.h"
#include "funcionesUTN.h"
#include "misValid.h"
#define MAX_ARRAY 50
#define VACIO 1
#define HABILITADO 0
#define INHABILITADO 2
int main()
{
    Autor prueba[MAX_ARRAY];
    char seguir='s';
    int opcion;
    int posicionLibre=-1;
    int idAmodificar=-1;
    int idBaja=-1;
    int auxId=0;



    if(aut_initArray(prueba,MAX_ARRAY)==0)
    {
        printf("\n INICIALIZAZION CORRECTA\n");
    }

    strcpy(prueba[0].nombre,"carla");
    strcpy(prueba[0].apellido,"trovato");
    prueba[0].isEmpty=HABILITADO;
    prueba[0].codigoAutor=1;

    strcpy(prueba[1].nombre,"ramirez");
    strcpy(prueba[1].apellido,"karen");
    prueba[1].isEmpty=HABILITADO;
    prueba[1].codigoAutor=2;

    strcpy(prueba[2].nombre,"carolina");
    strcpy(prueba[2].apellido,"perez");
    prueba[2].isEmpty=HABILITADO;
    prueba[2].codigoAutor=3;

        while(seguir=='s')
        {
            printf("\n 1- ALTA");
            printf("\n 2- MODIFICAR");
            printf("\n 3- BAJA");
            printf("\n 4- LISTAR");

            do
            {
                printf("\nIngrese una opcion: ");
                scanf("%d",&opcion);
                system("clear");
            }while(opcion<1 || opcion>4);
                switch(opcion)
                {
                    case 1:

                        if(aut_alta(prueba,MAX_ARRAY,posicionLibre,auxId)==0)
                        {
                            printf("\nALTA EXITOSA\n");
                            auxId++;

                        }
                        break;
                    case 2:
                        aut_muestraAutores(prueba,MAX_ARRAY);
                        if(aut_modificar(prueba,MAX_ARRAY,idAmodificar)==0)
                        {
                            printf("\nMODIFICACION EXITOSA\n");
                        }
                        break;
                    case 3:
                    if(aut_bajaAutor(prueba,MAX_ARRAY,idBaja)==0)
                    {
                        printf("\nBAJA EXITOSA\n");
                    }
                        break;
                    case 4:
                    aut_muestraAutores(prueba,MAX_ARRAY);
                }
        }


    return 0;
}
