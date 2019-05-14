#ifndef FECHA_C_INCLUDED
#define FECHA_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fecha.h"
#include "funcionesUTN.h"
#include "misValid.h"
#define VACIO 0
#define HABILITADO 1
#define INHABILITADO 2

int fec_initArray(Fecha* fechas,int limite)
{
    int i;
    int retorno;
    for(i=0;i<limite;i++)
    {
        fechas[i].isEmpty=VACIO;
        retorno=0;
    }
    return retorno;
}

int fec_alta(Fecha* fechas,int limite,int posicionLibre,int id)
{
    int retorno=-1;

    if(getInt("\nIngrese dia de asociado: ","\nError dia invalido ",31,1,2,&fechas[posicionLibre].dia)==0)
    {
        if(getInt("\nIngrese mes de asociado: ","\nError mes invalido ",31,1,2,&fechas[posicionLibre].mes)==0)
        {
            if(getInt("\nIngrese año de asociado: ","\nError año invalido ",31,1,2,&fechas[posicionLibre].anio)==0)
            {
                fechas[posicionLibre].isEmpty=0;
                fechas[posicionLibre].idFecha=id;
                retorno=0;
            }
        }
    }
    return retorno;
}

int fec_buscaPorId(Fecha* fechas,int limite,int idBusqueda,int* indice)///Agrego idBusqueda e indice
{
    int i;
    int retorno=-1;
    ///Saco bufferID y lo reemplazo por idBusqueda
    ///Quito el getInt de aca y lo agrego al main.

    for(i=0;i<limite;i++)
    {
        if(idBusqueda==fechas[i].idFecha)
        {
            *indice=i;///Cambio idEncontrado por indice
            retorno=0;
            break;
        }
    }
    return retorno;
}

int fec_buscaPosicionLibre(Fecha* fechas,int len,int* posicionLibre)
{
    int i;
    int retorno;

    for(i=0;i<len;i++)
    {
        if(fechas[i].isEmpty==1)
        {
            *posicionLibre=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}

int fec_modificar(Fecha* fechas,int limite,int idAmodificar)
{
    int retorno;
    char seguir='s';
    int opcion;
    int auxDia;
    int auxMes;
    int auxAnio;
    int indiceAmodificar;///Agrego indiceAmodificar

    if(fec_buscaPorId(fechas,limite,idAmodificar,&indiceAmodificar)==0)///cambio puntero de idMofic aca y puso indiceAmodif
    {
        while(seguir=='s')
        {
            printf("\nMENU DE MOFICICACIONES: \n 1-Dia \n 2-Mes\n 3-Anio\n 4-Salir\n");
            do
            {

            }while(getInt("\nIngrese una opcion: ","\nError,opcion invalida",3,1,2,&opcion));

            switch(opcion)
            {
                case 1:
                    if(getInt("\nIngrese dia: ","\nDia invalido",31,1,3,&auxDia)==0)
                    {
                        fechas[idAmodificar].dia=auxDia;
                        printf("\nDIA MODIFICADO CORRECTAMENTE\n");
                    }
                break;
                case 2:
                     if(getInt("\nIngrese mes: ","\nMes invalido",12,1,3,&auxMes)==0)
                    {
                        fechas[idAmodificar].mes=auxMes;
                        printf("\nMES MODIFICADO CORRECTAMENTE\n");
                    }
                    break;
                case 3:
                      if(getInt("\nIngrese anio: ","\nAnio invalido",2020,1900,3,&auxAnio)==0)
                    {
                        fechas[idAmodificar].anio=auxAnio;
                        printf("\nANIO MODIFICADO CORRECTAMENTE\n");
                    }
                    break;
                case 4:
                    seguir='n';
                    retorno=0;
            }
        }
    }
    return retorno;
}


int fec_bajaAutor(Fecha* fechas,int limite,int idBaja)
{
    int retorno=-1;
    int indice;///agrego variable

    if(fec_buscaPorId(fechas,limite,idBaja,&indice)==0)///y lo utiliza de puntero
    {
        fechas[indice].isEmpty=2;
        retorno=0;
    }
    else
    {
        printf("\n ID NO ENCONTRADO");
    }
    return retorno;
}

#endif // FECHA_C_INCLUDED
