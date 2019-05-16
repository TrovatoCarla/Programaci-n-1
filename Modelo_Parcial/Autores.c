#ifndef AUTORES_C_INCLUDED
#define AUTORES_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "Autores.h"
#include "Libros.h"
#include "Socios.h"
#include "funcionesUTN.h"
#include "misValid.h"


int aut_listarAutores(Autor* autores,int limite)
{
    int i;
    int retorno=-1;
    for(i=0;i<limite;i++)
    {
        if((autores[i].isEmpty==HABILITADO))
        {
            __fpurge(stdin);
            printf("\nPosicion %d:  Codigo Autor: %d",i,autores[i].codigoAutor);
            printf("\n             Apellido: %s",autores[i].apellido);
            printf("\n             Nombre: %s",autores[i].nombre);
            printf("\n             IsEmpty: %d",autores[i].isEmpty);
            retorno=0;
        }
    }
    return retorno;
}

int aut_ordenaPorApellidoNombre(Autor* autores,int limite,int orderFirst,int orderSecond)                              //cambiar fantasma
{
    int retorno=-1;
    int i;
    Autor buffer;
    int flagSwap;

    if(autores!=NULL && limite>=0)
    {
        do
        {
            flagSwap=0;
            for (i = 0; i < limite-1; i++)
            {
                if(((strcmp(autores[i].apellido,autores[i+1].apellido) < 0) && orderFirst) ||
                    ((strcmp(autores[i].apellido,autores[i+1].apellido) > 0) && !orderFirst))
                {
                    flagSwap=1;
                    buffer = autores[i];
                    autores[i] = autores[i+1];
                    autores[i+1] = buffer;
                }
                else if(strcmp(autores[i].apellido,autores[i+1].apellido) == 0)
                {
                    if( ((strcmp(autores[i].nombre,autores[i+1].nombre)< 0) && orderSecond) ||
                       ( (strcmp(autores[i].nombre,autores[i+1].nombre)> 0) && !orderSecond) )
                    {
                        flagSwap=1;
                        buffer = autores[i];
                        autores[i] = autores[i+1];
                        autores[i+1] = buffer;
                    }
                }
            }
        }while(flagSwap);
        retorno=0;
    }
    return retorno;
}

int aut_initArray(Autor* autores,int limite)
{
    int i;
    int retorno;
    for(i=0;i<limite;i++)
    {
        autores[i].isEmpty=VACIO;
        retorno=0;
    }
    return retorno;
}

int aut_alta(Autor* autores,int limite,int posicionLibre,int id)
{
    int retorno;

    if(aut_buscaPosicionLibre(autores,MAX_ARRAY,&posicionLibre)==0)
    {
        if(getApellido("\nIngrese apellido del autor: ","\nError,apellido invalido",MAXIMO_CARACTER,2,3,autores[posicionLibre].apellido)==0)
        {
            if(getName("\nIngrese nombre: ","\nError,nombre invalido",MAXIMO_CARACTER,2,3,autores[posicionLibre].nombre)==0)
            {
                autores[posicionLibre].isEmpty=HABILITADO;
                autores[posicionLibre].codigoAutor=id;
                retorno=0;
            }
        }
    }
    return retorno;
}

int aut_buscarID(Autor* autores, int limite, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(autores!= NULL && limite>=0)
    {
        for(i=0;i<limite;i++)
        {
            if(autores[i].isEmpty==1)
                continue;
            else if(autores[i].codigoAutor==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int aut_buscaPosicionLibre(Autor* autores,int limite,int* posicionLibre)
{
    int i;
    int retorno;

    for(i=0;i<limite;i++)
    {
        if(autores[i].isEmpty==VACIO)
        {
            *posicionLibre=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}

int aut_modificar(Autor* autores,int limite,int idAmodificar)
{
    int retorno;
    char seguir='s';
    int opcion;
    char auxNombre[MAXIMO_CARACTER];
    char auxApellido[MAXIMO_CARACTER];
    int indiceAmodificar;///Agrego indiceAmodificar


    if(aut_buscarID(autores,MAX_ARRAY,idAmodificar,&indiceAmodificar)==0)///cambio puntero de idMofic aca y puso indiceAmodif
    {
        while(seguir=='s')
        {
            printf("\nMENU DE MOFICICACIONES: \n 1-Apellido \n 2-Nombre\n 3-Salir\n");
            do
            {

            }while(getInt("\nIngrese una opcion: ","\nError,opcion invalida",3,1,2,&opcion));

            switch(opcion)
            {
                case 1:
                    if(getApellido("\nIngrese Apellido: ","\nApellido invalido",MAXIMO_CARACTER,2,3,auxApellido)==0)
                    {
                        strncpy(autores[indiceAmodificar].apellido,auxApellido,MAXIMO_CARACTER);
                        printf("\nAPELLIDO MODIFICADO CORRECTAMENTE\n");
                    }
                break;
                case 2:
                    if(getName("\nIngrese nombre: ","\nNombre invalido\n",MAXIMO_CARACTER,2,3,auxNombre)==0)
                    {
                        strncpy(autores[indiceAmodificar].nombre,auxNombre,MAXIMO_CARACTER);
                        printf("\nNOMBRE MODIFICADO CORRECTAMENTE");
                    }
                    break;
                case 3:
                    seguir='n';
                    retorno=0;
            }
        }
    }
    return retorno;
}

int aut_bajaAutor(Autor* autores,int limite,int idBaja)
{
    int retorno=-1;
    int indice;///agrego variable

    if(aut_buscarID(autores,limite,idBaja,&indice)==0)///y lo utiliza de puntero
    {
        printf(" estoy dando de baja aaaa %d\n",autores[indice].codigoAutor);
        printf(" el estado anterior es %d \n",autores[indice].isEmpty);
        autores[indice].isEmpty=INHABILITADO;
        printf(" el nuevo es %d \n",autores[indice].isEmpty);
        retorno=0;
    }
    else
    {
        printf("\n ID NO ENCONTRADO");
    }
    aut_listarAutores(autores,limite);
return retorno;
}


#endif // AUTORES_C_INCLUDED
