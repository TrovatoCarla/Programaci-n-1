#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Autores.h"
#include "Libros.h"
#include "funcionesUTN.h"
#include "misValid.h"
#define MAX_ARRAY 50
#define SORT_UP 1
#define SORT_DOWN 0


int main()
{
    Autor autores[MAX_ARRAY];
    Libro libros[MAX_ARRAY];
    int opcion;
    int posicionLibreAutor=-1;
    int idAmodificarAutor=-1;
    //int posicionLibreLibro=-1;
    //int idAmodificarLibro=-1;
    int idBajaAutor=-1;
    //int idBajaLibro=-1;
    int auxIdAutor=0;
    int auxIdLibro=0;

    if(aut_initArray(autores,MAX_ARRAY)==0)
    {
        printf("\n INICIALIZAZION AUTORES CORRECTA\n");
    }
    if(lib_initArray(libros,MAX_ARRAY)==0)
    {
        printf("\n INICIALIZAZION LIBROS CORRECTA\n");
    }

    strcpy(autores[0].nombre,"carla");
    strcpy(autores[0].apellido,"trovato");
    autores[0].isEmpty=HABILITADO;
    autores[0].codigoAutor=1;

    auxIdAutor++;

    strcpy(autores[1].nombre,"ramirez");
    strcpy(autores[1].apellido,"karen");
    autores[1].isEmpty=HABILITADO;
    autores[1].codigoAutor=2;
    auxIdAutor++;

    strcpy(autores[2].nombre,"carolina");
    strcpy(autores[2].apellido,"perez");
    autores[2].isEmpty=HABILITADO;
    autores[2].codigoAutor=3;
    auxIdAutor++;

            do
            {
                getInt("\n 1- ALTA DE AUTOR\n 2- MODIFICAR AUTOR\n 3- BAJA DE AUTORES\n 4- LISTAR AUTORES\n 5-ALTA DE LIRBOS\n 6-MODIFICAR LIBRO\n 7-BAJA LIBRO\n 8-LISTAR LIBROS\n 9-Salir\n",
                        "\nError",10,1,1,&opcion);
                system("clear");
                switch(opcion)
                {
                    case 1:
                        if(aut_alta(autores,MAX_ARRAY,posicionLibreAutor,auxIdAutor)==0)
                        {
                            printf("\nALTA EXITOSA\n");
                            auxIdAutor++;
                        }
                        break;
                    case 2:
                        aut_listarAutores(autores,MAX_ARRAY);
                        if(getInt("\nIngrese Codigo de Autor: ","\nError,codigo no encontrado",MAXIMO_CARACTER,0,3,&idAmodificarAutor)==0)
                        {
                            if(aut_modificar(autores,MAX_ARRAY,idAmodificarAutor)==0)
                            {
                                printf("\nMODIFICACION EXITOSA\n");
                            }
                        }
                        break;
                    case 3:
                        if(getInt("\nIngrese Codigo de Autor: ","\nError,codigo no encontrado",MAXIMO_CARACTER,0,3,&idBajaAutor)==0)///Agrego getInt
                        {
                            if(aut_bajaAutor(autores,MAX_ARRAY,idBajaAutor)==0)
                            {
                                printf("\nBAJA EXITOSA\n");
                            }
                        }
                        break;
                    case 4:
                        if(!aut_ordenaPorApellidoNombre(autores,MAX_ARRAY,SORT_DOWN,SORT_DOWN))
                        {
                            aut_listarAutores(autores,MAX_ARRAY);
                        }
                        break;
                    case 5:
                        if(!lib_alta(libros,autores,MAX_ARRAY,&auxIdLibro))
                        {
                            printf("\nALTA EXITOSA");
                        }
                        break;
                    case 6:
                        if(lib_modificar(libros,autores,MAX_ARRAY)==0)
                        {
                            printf("\nMODIFICACION EXITOSA\n");
                        }
                        break;
                    case 7:
                        if(!lib_bajaLibros(libros,autores,MAX_ARRAY))
                        {
                            printf("\nBAJA DE LIBRO EXITOSA\n");
                            lib_muestraLibros(libros,autores,MAX_ARRAY);
                        }
                        break;
                   case 8:
                        printf("\nHOLAAAAAAAAAAA");
                        lib_muestraLibros(libros,autores,MAX_ARRAY);
                        if(lib_ordenaPorTitulo(libros,MAX_ARRAY,SORT_DOWN,SORT_DOWN)==0)
                        {
                            lib_muestraLibros(libros,autores,MAX_ARRAY);
                        }
                        else
                            printf("nada");

                        break;
                    case 9:
                        break;


                }
             }while(opcion!=9);

     return 0;
}

