#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Autores.h"
#include "Libros.h"
#include "Socios.h"
#include "Prestamo.h"
#include "funcionesUTN.h"
#include "misValid.h"
#define MAX_ARRAY 50
#define SORT_UP 1
#define SORT_DOWN 0


int main()
{
    Autor autores[MAX_ARRAY];
    Libro libros[MAX_ARRAY];
    Socio socios[MAX_ARRAY];
    Prestamo prestamos[MAX_ARRAY];
    int opcion;
    int auxIdSocio=0;
    int auxIdPrestamo=0;
    int auxIdLibro=0;

    if((!aut_initArray(autores,MAX_ARRAY))&& (!lib_initArray(libros,MAX_ARRAY))&& (!soc_initArray(socios,MAX_ARRAY))&& (!pre_Inicializar(prestamos,MAX_ARRAY)))
    {
        printf("\n INICIALIZACIONES CORRECTAS\n");
    }

    strcpy(socios[0].nombre,"carla");
    strcpy(socios[0].apellido,"trovato");
    socios[0].isEmpty=HABILITADO;
    socios[0].codigoSocio=1;

    auxIdSocio++;

    strcpy(socios[1].nombre,"ramirez");
    strcpy(socios[1].apellido,"karen");
    socios[1].isEmpty=HABILITADO;
    socios[1].codigoSocio=2;
    auxIdSocio++;

    strcpy(socios[2].nombre,"carolina");
    strcpy(socios[2].apellido,"perez");
    socios[2].isEmpty=HABILITADO;
    socios[2].codigoSocio=3;
    auxIdSocio++;

    libros[0].codigoLibro=0;
    libros[0].isEmpty=0;
    libros[0].codigoAutor=1;
    strcpy(libros[0].titulo,"CCCCC");


    libros[1].codigoLibro=1;
    libros[1].isEmpty=0;
    libros[1].codigoAutor=2;
    strcpy(libros[1].titulo,"AAAAA");


    libros[2].codigoLibro=2;
    libros[2].isEmpty=0;
    libros[2].codigoAutor=3;
    strcpy(libros[2].titulo,"BBBBB");


            do
            {
                getInt("\n 1- ALTA \n 2- MODIFICAR\n 3- BAJA\n 4- LISTAR SOCIOS\n 5- LISTAR LIRBOS\n 6- LISTAR AUTORES\n 7- PRESTAMOS\n 8- Salir\n",
                        "\nError",8,1,1,&opcion);
                system("clear");
                switch(opcion)
                {
                        case 1:
                            if(!soc_alta(socios,MAX_ARRAY,&auxIdSocio))
                            {
                                printf("\nALTA EXITOSA");
                            }
                            break;
                        case 2:
                            if(!soc_modificar(socios,MAX_ARRAY))
                            {
                                printf("\nMODIFICACION EXITOSA");
                            }
                            break;
                        case 3:
                            if(!soc_baja(socios,MAX_ARRAY))
                            {
                                printf("\nBAJA EXITOSA");
                            }
                            break;
                        case 4:
                            if(!soc_ordenaPorApellidoNombre(socios,MAX_ARRAY,SORT_UP,SORT_UP))
                            {
                                soc_listar(socios,MAX_ARRAY);
                            }
                            break;
                        case 5:
                            lib_alta(libros,autores,MAX_ARRAY,auxIdLibro);
                            lib_muestraLibros(libros,autores,MAX_ARRAY);
                            if(!lib_ordenaPorTitulo(libros,MAX_ARRAY,SORT_UP,SORT_UP))
                            {
                                lib_muestraLibros(libros,autores,MAX_ARRAY);
                            }
                            break;
                        case 6:
                            if(!aut_ordenaPorApellidoNombre(autores,MAX_ARRAY,SORT_UP,SORT_UP))
                            {
                                aut_listarAutores(autores,MAX_ARRAY);
                            }
                            break;
                        case 7:
                            if(!pre_alta(prestamos,socios,libros,autores,MAX_ARRAY,MAX_ARRAY,MAX_ARRAY,MAX_ARRAY,&auxIdPrestamo))
                            {
                                pre_listar(prestamos,MAX_ARRAY);
                            }
                            break;
                    /*
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
                        */

                }
             }while(opcion!=9);

     return 0;
}

