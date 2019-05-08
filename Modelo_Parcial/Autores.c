#ifndef AUTORES_C_INCLUDED
#define AUTORES_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "Autores.h"
#include "funcionesUTN.h"
#include "misValid.h"
#define MAX_ARRAY 50
#define VACIO 1
#define HABILITADO 0
#define INHABILITADO 2
#define MAXIMO_CARACTER 31

int aut_muestraAutores(Autor* autores,int limite)
{
    int i;
    int retorno=-1;
    for(i=0;i<limite;i++)
    {
        //if(autores[i].isEmpty==HABILITADO)
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

    //__fpurge(stdin);

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

int aut_buscaPorId(Autor* autores,int limite,int* idEncontrado)
{
    int i;
    int retorno=-1;
    int bufferId;

    if(getInt("\nIngrese Codigo de Autor: ","\nError,codigo no encontrado",MAXIMO_CARACTER,0,3,&bufferId)==0)
    {
        for(i=0;i<limite;i++)
        {
            if(bufferId==autores[i].codigoAutor)
            {
                *idEncontrado=i;
                retorno=0;
            }
        }
    }
    return retorno;
}

int aut_buscaPosicionLibre(Autor* autores,int len,int* posicionLibre)
{
    int i;
    int retorno;

    for(i=0;i<len;i++)
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


    if(aut_buscaPorId(autores,MAX_ARRAY,&idAmodificar)==0)
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
                        strncpy(autores[idAmodificar].apellido,auxApellido,MAXIMO_CARACTER);
                        printf("\nAPELLIDO MODIFICADO CORRECTAMENTE\n");
                    }
                break;
                case 2:
                    if(getName("\nIngrese nombre: ","\nNombre invalido\n",MAXIMO_CARACTER,2,3,auxNombre)==0)
                    {
                        strncpy(autores[idAmodificar].nombre,auxNombre,MAXIMO_CARACTER);
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

    if(aut_buscaPorId(autores,limite,&idBaja)==0)
    {
        printf(" estoy dando de baja aaaa %d\n",autores[idBaja].codigoAutor);
        printf(" el estado anterior es %d \n",autores[idBaja].isEmpty);
        autores[idBaja].isEmpty=INHABILITADO;
        printf(" el nuevo es %d \n",autores[idBaja].isEmpty);
        retorno=0;
    }
    else
    {
        printf("\n ID NO ENCONTRADO");
    }
    aut_muestraAutores(autores,limite);
return retorno;
}

#endif // AUTORES_C_INCLUDED
