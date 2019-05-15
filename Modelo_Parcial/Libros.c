#ifndef LIBROS_C_INCLUDED
#define LIBROS_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "Autores.h"
#include "funcionesUTN.h"
#include "misValid.h"
#include "Libros.h"
#define MAX_DIG 100
#define MIN_DIG 0


int lib_initArray(Libro* libros,int limite)
{
    int i;
    int retorno;
    for(i=0;i<limite;i++)
    {
        libros[i].isEmpty=VACIO;
        retorno=0;
    }
    return retorno;
}

int lib_alta(Libro* libros,Autor* autores,int limite,int* contadorID)///OK
{
    int retorno=-1;
    int posicion;
    int auxIdAutor;
    int posicionAutor;

    if(libros!=NULL && autores!=NULL && limite>0 && contadorID!=NULL)
    {
        aut_listarAutores(autores,MAX_ARRAY);
        getInt("\nIngrese codigo de autor: ","\nError",MAX_DIG,MIN_DIG,2,&auxIdAutor);

        if(!aut_buscarID(autores,MAX_ARRAY,auxIdAutor,&posicionAutor))
        {
            if(lib_buscaPosicionLibre(libros,MAX_ARRAY,&posicion)!=0)
            {
                printf("\n NO HAY LUGAR DISPONIBLE-LIBROS-\n");
            }
            else
            {
                (*contadorID)++;
                libros[posicion].codigoLibro=*contadorID;
                libros[posicion].isEmpty=0;
                libros[posicion].codigoAutor=auxIdAutor;
                if(!getName("\nIngrese titulo: ","\nError",MAXIMO_CARACTER,1,2,libros[posicion].titulo))
                {
                    printf("\nTitulo: %s\n Codigo de titulo: %d\n Autor: %s\n Codigo de autor: %d\n ",libros[posicion].titulo,
                        libros[posicion].codigoLibro,autores[posicionAutor].apellido,autores[posicionAutor].codigoAutor);
                        retorno=0;
                }
            }
        }
    }
    return retorno;
}

int lib_buscaPorId(Libro* libros,int limite,int idBusqueda,int* indice)///Agrego idBusqueda e indice
{
    int i;
    int retorno=-1;
    ///Saco bufferID y lo reemplazo por idBusqueda
    ///Quito el getInt de aca y lo agrego al main.

    for(i=0;i<limite;i++)
    {
        if(idBusqueda==libros[i].codigoLibro)
        {
            *indice=i;///Cambio idEncontrado por indice
            retorno=0;
            break;
        }
    }

    return retorno;
}

int lib_buscaPosicionLibre(Libro* libros,int len,int* posicionLibre)
{
    int i;
    int retorno=-1;

    for(i=0;i<len;i++)
    {
        if(libros[i].isEmpty==VACIO)
        {
            *posicionLibre=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}

int lib_modificar(Libro* libros,Autor* autores,int limite)
{
    int retorno;
    int posicion;
    int id;
    int opcion;

    char auxTitulo[MAXIMO_CARACTER];
    int auxCodigoAutor=-1;

    if(libros!=NULL && autores!=NULL && limite>0)
    {
        lib_muestraLibros(libros,autores,MAX_ARRAY);
        getInt("\nIngrese codigo de libro a modificar: ","\nError",MAX_DIG,MIN_DIG,2,&id);
        if(lib_buscaPorId(libros,MAX_ARRAY,id,&posicion)!=0)
        {
            printf("\nID NO ENCONTRADO");
        }
        else
        {
            do
            {
                printf("\nTitulo: %s\n Codigo de libro: %d\n Codigo de autor: %d\n ",libros[posicion].titulo,///copio el print de alta
                    libros[posicion].codigoLibro,libros[posicion].codigoAutor);

                getInt("\nModificar:\n 1-Titulo\n 2-Codigo de autor\n 3-(salir)\n","\nError,opcion invalida\n",MAX_DIG,MIN_DIG,2,&opcion);
                switch(opcion)
                {
                    case 1:
                        if(getName("\nIngrese titulo: ","\nTitulo invalido",MAXIMO_CARACTER,2,3,auxTitulo)==0)
                        {
                            strncpy(libros[posicion].titulo,auxTitulo,MAXIMO_CARACTER);
                            printf("\nTITULO MODIFICADO CORRECTAMENTE\n");
                        }
                        break;
                    case 2:
                        if(getInt("\nIngrese codigo de autor: ","\nCodigo invalido\n",MAX_DIG,MIN_DIG,3,&auxCodigoAutor)==0)
                        {
                            libros[posicion].codigoAutor=auxCodigoAutor;
                            printf("\nCODIGO DE AUTOR MODIFICADO CORRECTAMENTE");
                        }
                        break;
                    case 3:
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!=3);
            retorno=0;
        }
    }
     return retorno;
}

int lib_bajaLibros(Libro* libros,Autor* autores, int limite)
{
    int retorno=-1;
    int posicion;
    int id;
    if(libros!=NULL && limite>0)
    {
        lib_muestraLibros(libros,autores,MAX_ARRAY);
        getInt("\nIngrese Codigo de libro a cancelar: ","\nError",MAX_DIG,MIN_DIG,2,&id); ///cambiar si no se busca por ID
        if(lib_buscaPorId(libros,limite,id,&posicion)!=0)         ///cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");  ///cambiar si no se busca por ID
        }
        else
        {
            libros[posicion].isEmpty=1;
            libros[posicion].codigoLibro=INHABILITADO;            ///cambiar campo id
            libros[posicion].codigoAutor=0; ///cambiar campo apellido
            strcpy(libros[posicion].titulo,"");    ///cambiar campo nombre
            //libros[posicion].auxInt=0;             ///cambiar campo auxInt
            //libros[posicion].auxFloat=0;           ///cambiar campo auxFloar

            retorno=0;
        }
    }

    return retorno;
}

int lib_muestraLibros(Libro* libros,Autor* autores,int limite)
{
    int i;
    int retorno=-1;
    for(i=0;i<limite;i++)
    {
        if((libros[i].isEmpty==HABILITADO)&&(autores[i].isEmpty==HABILITADO))
        {
            __fpurge(stdin);
            printf("\nPosicion %d:  Codigo Libro: %d",i,libros[i].codigoLibro);
            printf("\n             Titulo: %s",libros[i].titulo);
            printf("\n             Codigo Autor: %d",libros[i].codigoAutor);
            printf("\n             IsEmpty: %d",libros[i].isEmpty);
            retorno=0;
        }
    }
    return retorno;
}

int lib_ordenaPorTitulo(Libro* libros,int limite,int orderFirst,int orderSecond)                              //cambiar fantasma
{
    int retorno=-1;
    int i;
    Libro buffer;
    int flagSwap;

    if(libros!=NULL && limite>=0)
    {
        do
        {
            flagSwap=0;
            for (i=0; i<limite-1; i++)
            {
                if(((strcmp(libros[i].titulo,libros[i+1].titulo) < 0) && orderFirst) ||
                    ((strcmp(libros[i].titulo,libros[i+1].titulo) > 0) && !orderFirst))
                {
                    flagSwap=1;
                    buffer = libros[i];
                    libros[i] = libros[i+1];
                    libros[i+1] = buffer;
                }/*
                else if(strcmp(libros[i].apellido,libros[i+1].apellido) == 0)
                {
                    if( ((strcmp(libros[i].nombre,libros[i+1].nombre)< 0) && orderSecond) ||
                       ( (strcmp(libros[i].nombre,libros[i+1].nombre)> 0) && !orderSecond) )
                    {
                        flagSwap=1;
                        buffer = libros[i];
                        libros[i] = libros[i+1];
                        libros[i+1] = buffer;
                    }
                }*/
            }
        }while(flagSwap);
        retorno=0;
    }
    return retorno;
}


#endif // LIBROS_C_INCLUDED
